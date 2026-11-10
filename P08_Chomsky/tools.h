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
#include <fstream>
#include <string>
#include <map>
#include "alfabeto.h"
#include "gramatica.h"

/**
 * @brief Muestra el uso correcto del programa.
 * 
 * Esta función muestra un mensaje con el uso correcto del programa y termina la ejecución del mismo.
 * 
 * @param argc Número de argumentos pasados al programa.
 * @param argv Array de punteros a los argumentos pasados al programa.
 */
void Usage(int argc, char *argv[]);
/**
 * @brief Analiza el fichero de entrada y crea una gramática.
 * 
 * Esta función lee un fichero de entrada y crea una gramática a partir de los datos leídos.
 * 
 * @param ficheroEntrada Ruta del fichero de entrada.
 * @return Gramatica La gramática creada a partir del fichero de entrada.
 */
Gramatica Analiza(const std::string& ficheroEntrada);

#endif
