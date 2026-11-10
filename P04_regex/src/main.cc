/**
 * * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 8 October 2024
 */
// File: main.cc
#include "CodeAnalyzer.h"
#include "tools.h"
#include <iostream>

/**
 * @brief Entry point of the program.
 *
 * This function expects exactly two command-line arguments: an input file and an output file.
 * It initializes a CodeAnalyzer object and performs analysis on the input file, writing the results to the output file.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return int Returns 0 on successful completion, or 1 if the number of arguments is incorrect.
 */
int main(int argc, char* argv[]) {
	Usage(argc, argv);

	std::string inputFile = argv[1];
	std::string outputFile = argv[2];

	CodeAnalyzer analyzer;
	analyzer.AnalyzeFile(inputFile, inputFile, outputFile);

	std::cout << "Analysis complete. Results written to " << outputFile << std::endl;

	return 0;
}
