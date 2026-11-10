/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 20 September 2024
 */

#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include "P02_strings.h"

void Usage(int argc, char *argv[]);
void Menu(const int& opcode, const std::string& file_input, const std::string& file_output);

#endif