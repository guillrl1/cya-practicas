/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 20 September 2024
 */

#ifndef P02_STRINGS_H
#define P02_STRINGS_H

#include <fstream>
#include <iostream>
#include <string>

#include "chain.h"
#include "Alphabet.h"
#include "Languages.h"

void Write_Alphabet(const std::string& file_input, const std::string& file_output);
void Check_Lenght(const std::string& file_input, const std::string& file_output);
void Reverse(const std::string& file_input, const std::string& file_output);
void Write_Prefix(const std::string& file_input, const std::string& file_output);
void Write_Sufix(const std::string& file_input, const std::string& file_output);

#endif  //P02_STRINGS_H