/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 20 September 2024
 */

#include "Alphabet.h"
#include "P02_strings.h"
#include "chain.h"
#include "tools.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string filename_input{argv[1]};
  std::string filename_output{argv[2]};
  int opcode{std::stoi(argv[3])};
  Menu(opcode, filename_input, filename_output);
  

  return 0;
}
