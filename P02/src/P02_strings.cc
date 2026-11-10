/**
 * * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 20 September 2024
 * @file P02_strings.cc
 * @brief Implementation of string manipulation functions.
 */

#include "P02_strings.h"

/**
 * @brief Writes the alphabet representation of each word in the input file to the output file.
 * 
 * This function reads words from the input file, converts them to their alphabet representation using the Alphabet class,
 * and writes the result to the output file.
 * 
 * @param file_input The path to the input file.
 * @param file_output The path to the output file.
 */
void Write_Alphabet(const std::string& file_input, const std::string& file_output) {
  std::ifstream input(file_input);
  std::ofstream output(file_output);
  Chain cad;
  while(input >> cad) {
    input >> cad;
    Alphabet alpha(cad);
    output << alpha << std::endl;
  
  }
  input.close();
  output.close();
}

/**
 * @brief Writes the length of each word in the input file to the output file.
 * 
 * This function reads words from the input file, calculates their length using the get_size() method of the Chain class,
 * and writes the result to the output file.
 * 
 * @param file_input The path to the input file.
 * @param file_output The path to the output file.
 */
void Check_Lenght(const std::string& file_input, const std::string& file_output) {
  std::ifstream input(file_input);
  std::ofstream output(file_output);
  Chain cad;
  while(input >> cad) {
    output << cad.get_size() << std::endl;
    input >> cad;
  }
  input.close();
  output.close();
}

/**
 * @brief Writes the reverse of each word in the input file to the output file.
 * 
 * This function reads words from the input file, reverses them using the Reverse() method of the Chain class,
 * and writes the result to the output file.
 * 
 * @param file_input The path to the input file.
 * @param file_output The path to the output file.
 */
void Reverse(const std::string& file_input, const std::string& file_output) {
  std::ifstream input(file_input);
  std::ofstream output(file_output);
  Chain cad;
  while(input >> cad) {
    output << cad.Reverse() << std::endl;
    input >> cad;
  }
  input.close();
  output.close();
}

/**
 * @brief Writes the prefix of each word in the input file to the output file.
 * 
 * This function reads words from the input file, calculates their prefix using the Prefix() method of the Language class,
 * and writes the result to the output file.
 * 
 * @param file_input The path to the input file.
 * @param file_output The path to the output file.
 */
void Write_Prefix(const std::string& file_input, const std::string& file_output) {
  std::ifstream input(file_input);
  std::ofstream output(file_output);
  Chain cad;
  while(input >> cad) {
    Language aux;
    aux = cad.Sufix();
    output << aux << std::endl;
    input >> cad;
  }
  input.close();
  output.close();
}

/**
 * @brief Writes the suffix of each word in the input file to the output file.
 * 
 * This function reads words from the input file, calculates their suffix using the Sufix() method of the Language class,
 * and writes the result to the output file.
 * 
 * @param file_input The path to the input file.
 * @param file_output The path to the output file.
 */
void Write_Sufix(const std::string& file_input, const std::string& file_output) {
  std::ifstream input(file_input);
  std::ofstream output(file_output);
  Chain cad;
  while(input >> cad) {
    Language aux;
    aux = cad.Sufix();
    output << aux << std::endl;
    input >> cad;
  }
  input.close();
  output.close();
}
