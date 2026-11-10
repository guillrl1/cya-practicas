/**
 * * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 8 October 2024
 */
// File: CodeAnalyzer.h
#ifndef CODEANALYZER_H
#define CODEANALYZER_H

#include "Variable.h"
#include "Loop.h"
#include "Comments.h"
#include <string>
#include <vector>

/**
 * @class CodeAnalyzer
 * @brief Analyzes source code to extract variables, loops, and comments.
 */
class CodeAnalyzer {
public:
  /**
   * @brief Analyzes the given source code file and writes the analysis report to the output file.
   * @param code The source code to analyze.
   * @param inputFile The path to the input file containing the source code.
   * @param outputFile The path to the output file where the analysis report will be written.
   */
  void AnalyzeFile(const std::string& code, const std::string& inputFile, const std::string& outputFile);

private:
  std::vector<Variable> variables;   ///< Stores the variables found in the code
  std::vector<Loop> loops;           ///< Stores the loops found in the code
  std::vector<Comments> comments;    ///< Stores the comments found in the code
  bool hasMainFunction = false;      ///< Indicates if there is a main function in the code
  std::string multi_comment_content; ///< Stores the content of a multiline comment

  /**
   * @brief Analyzes a single line of code.
   * @param line The line of code to analyze.
   * @param lineNumber The current line number in the source code.
   * @param multi_comment Flag indicating if the current line is within a multiline comment.
   * @param descriptionCaptured Flag indicating if a description has been captured.
   * @param commentStartLine The line number where the current comment started.
   */
  void AnalyzeLine(const std::string& line, int lineNumber, bool& multi_comment, bool& descriptionCaptured, int& commentStartLine);

  /**
   * @brief Writes the analysis report to the output file.
   * @param code The source code that was analyzed.
   * @param outputFile The path to the output file where the report will be written.
   */
  void WriteReport(const std::string& code, const std::string& outputFile) const;
};

#endif // CODEANALYZER_H
