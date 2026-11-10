/**
 * * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 8 October 2024
 */

#include <iostream>
#include "tools.h"

/**
 * Displays the usage information for the program.
 * 
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 */
void Usage(int argc, char *argv[]) {
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << "This program, given a .cc code, analyzes its internal structure in:\n";
    std::cout << "PROGRAM: \n";
    std::cout << "DESCRIPTION: \n";
    std::cout << "VARIABLES: \n";
    std::cout << "STATEMENTS\n";
    std::cout << "MAIN\n";
    std::cout << "COMMENTS: \n";
    std::cout << "\nUsage example: " << argv[0] << " code.cc fileout.txt\n";
    exit(EXIT_SUCCESS);
  }
  else if (argc != 3) {
    std::cout << argv[0] << ": The provided arguments are not valid" << std::endl;
    std::cout << "You must provide the input file followed by the output file as parameters" << std::endl;
    std::cout << "Usage example: ./p04_code_analyzer code.cc fileout.txt" << std::endl;
    std::cout << "\nTry " << argv[0] << " --help for more information" << std::endl;
    exit(EXIT_SUCCESS);
  }
}
