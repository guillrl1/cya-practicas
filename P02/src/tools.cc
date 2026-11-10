/**
 * * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 20 September 2024
 * @file tools.cc
 * @brief Implementation of functions for string manipulation.
 */

#include <iostream>
#include <string>
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
    std::cout << "Este programa dado un fichero de entrada con la especificación de cadenas junto con sus respectivos alfabetos, realiza un conjunto de comprobaciones básicas sobre ellas.\n";
    std::cout << "Opciones del opcode: \n";
    std::cout << "1. Alfabeto\n";
    std::cout << "2. Longitud\n";
    std::cout << "3. Inversa\n";
    std::cout << "4. Prefijos\n";
    std::cout << "5. Sufijos\n";
    std::cout << "Ejemplo de uso: ./p02_strings filein.txt fileout.txt opcode\n";
    exit(EXIT_SUCCESS);
  }
  else if (argc != 4) {
    std::cout << argv[0] << ": Los argumentos introducidos no son válidos" << std::endl;
    std::cout << "Debe introducir como parámetros el fichero de entrada seguido por el de salida seguido de la opción a ejecutar" << std::endl;
    std::cout << "Ejemplo de uso: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/**
 * Displays the menu options based on the opcode and calls the corresponding functions.
 * 
 * @param opcode The opcode representing the desired operation.
 * @param file_input The input file name.
 * @param file_output The output file name.
 */
void Menu(const int& opcode, const std::string& file_input, const std::string& file_output) {
  switch(opcode) {
    case 1:
      Write_Alphabet(file_input, file_output);
      break;
    case 2:
      Check_Lenght(file_input, file_output);
      break;
    case 3:
      Reverse(file_input, file_output);
      break;
    case 4:
      Write_Prefix(file_input, file_output);
      break;
    case 5:
      Write_Sufix(file_input, file_output);
      break;
    default:
      std::cout << "El Opcode introducido es erróneo, pruebe --help para mas información" << std::endl;
  }
}
