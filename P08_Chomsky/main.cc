#include "tools.h"

/**
 * @brief Función principal del programa.
 * 
 * @param argc Número de argumentos pasados al programa.
 * @param argv Array de punteros a los argumentos pasados al programa.
 * 
 * La función principal se encarga de:
 * 1. Llamar a la función Usage para verificar el uso correcto del programa.
 * 2. Analizar el archivo de gramática pasado como argumento.
 * 3. Transformar la gramática a la Forma Normal de Chomsky (FNC).
 * 4. Escribir la gramática transformada en el archivo de salida especificado.
 * 
 * @return int Código de salida del programa.
 */
int main(int argc, char *argv[]) {
  Usage(argc, argv);
  Gramatica gramatica = Analiza(argv[1]);
  gramatica.transformaFNC();
  gramatica.Escribe(argv[2]);
  return 0;

}