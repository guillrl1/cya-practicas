/**
 * * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 8 October 2024
 * @file CodeAnalyzer.cc
 * @brief This file contains the implementation of the CodeAnalyzer class.
 */
// File: 
#include "CodeAnalyzer.h"
#include <regex>
#include <fstream>
#include <iostream>

/**
 * @brief Analyzes the content of a file and generates a report.
 *
 * This function reads the content of the specified input file line by line,
 * analyzes each line for specific patterns or comments, and writes the analysis
 * results to the specified output file.
 *
 * @param code The code to be analyzed.
 * @param inputFile The path to the input file to be analyzed.
 * @param outputFile The path to the output file where the analysis report will be written.
 */
void CodeAnalyzer::AnalyzeFile(const std::string& code, const std::string& inputFile, const std::string& outputFile) {
	std::ifstream file(inputFile);
	if (!file.is_open()) {
		std::cerr << "Error: Cannot open file " << inputFile << std::endl;
		return;
	}

	std::string line;
	int lineNumber = 0;
	bool multi_comment = false;
	bool descriptionCaptured = false;  // Nuevo parámetro inicializado

	while (std::getline(file, line)) {
		int commentStartLine = 1; // Initialize the missing argument
		AnalyzeLine(line, ++lineNumber, multi_comment, descriptionCaptured, commentStartLine);
	}

	WriteReport(code, outputFile);
}
/**
 * @brief Analyzes a line of code and extracts relevant information.
 * @param line The line of code to be analyzed.
 * @param lineNumber The line number of the code.
 * @param multi_comment A flag indicating if the code is part of a multi-line comment.
 * @param descriptionCaptured A flag indicating if the description has been captured.
 * @param commentStartLine The line number where the comment started.
 */
void CodeAnalyzer::AnalyzeLine(const std::string& line, int lineNumber, bool& multi_comment, bool& descriptionCaptured, int& commentStartLine) {
	std::regex intVarRegex(R"(^\s*int\s+(\w+)(\s*=\s*(\d+))?;)");
	std::regex doubleVarRegex(R"(\bdouble\s+(\w+)(\s*=\s*(\d+.\d+))?;)");
	std::regex forLoopRegex(R"(\bfor\s*\()");
	std::regex whileLoopRegex(R"(\bwhile\s*\()");
	std::regex singleLineCommentRegex(R"(^\/\/(.+))");
	std::regex startMultipleLineCommentRegex(R"(/\*\*)");
	std::regex endMultipleLineCommentRegex(R"(\*\/)");
	std::regex mainFuncRegex(R"(\bint\s+main\s*\()");

	std::smatch match;
	
	if (multi_comment) {
		multi_comment_content += "\n" + line;
	}

	if (std::regex_search(line, match, intVarRegex)) {
		variables.emplace_back("INT", match[1], lineNumber, match[3]);
	}
	if (std::regex_search(line, match, doubleVarRegex)) {
		variables.emplace_back("DOUBLE", match[1], lineNumber, match[3]);
	}
	if (std::regex_search(line, match, forLoopRegex)) {
		loops.emplace_back("for", lineNumber);
	}
	if (std::regex_search(line, match, whileLoopRegex)) {
		loops.emplace_back("while", lineNumber);
	}
	if (std::regex_search(line, match, singleLineCommentRegex)) {
		comments.emplace_back("COMMENT", lineNumber, lineNumber, match[1]);
	}
	
	if (std::regex_search(line, mainFuncRegex)) {
		hasMainFunction = true;
	}

	if (std::regex_search(line, match, startMultipleLineCommentRegex)) {
		multi_comment_content = line;
		multi_comment = true;
		commentStartLine = lineNumber;
	}

	if (multi_comment && std::regex_search(line, match, endMultipleLineCommentRegex)) {
		multi_comment_content += "\n";  // Agregar la línea final del comentario
		multi_comment = false;

		if (!descriptionCaptured) {
			comments.emplace_back("DESCRIPTION", commentStartLine, lineNumber, multi_comment_content);
			descriptionCaptured = true;  // Establecer la captura como true
		} else {
			comments.emplace_back("Multi-line", commentStartLine, lineNumber, multi_comment_content);
		}
	}
}

/**
 * @brief Writes a detailed report of the analyzed code to the specified output file.
 *
 * This function generates a report containing the program name, description, variables,
 * statements, presence of the main function, and comments found in the code. The report
 * is written to the specified output file.
 *
 * @param code The name or identifier of the program being analyzed.
 * @param outputFile The path to the file where the report will be written.
 */
void CodeAnalyzer::WriteReport(const std::string& code, const std::string& outputFile) const {
	std::ofstream outFile(outputFile);
	if (!outFile.is_open()) {
		std::cerr << "Error: Cannot open output file " << outputFile << std::endl;
		return;
	}

	outFile << "PROGRAM: " << code << "\n";

	outFile << "DESCRIPTION: " << "\n" << multi_comment_content << "\n";

	outFile << "VARIABLES:\n";
	for (const auto& var : variables) {
		outFile << var.ToString() << "\n";
	}

	outFile << "\nSTATEMENTS:\n";
	for (const auto& loop : loops) {
		outFile << loop.ToString() << "\n";
	}

	outFile << "\nMAIN:\n";
	outFile << (hasMainFunction ? "True\n" : "False\n");

	outFile << "\nCOMMENTS:\n";
	for (const auto& comment : comments) {
		outFile << comment.ToString() << "\n";
	}
}
