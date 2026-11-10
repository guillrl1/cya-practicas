/**
 * * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 22 Octubre 2024
 */


#include "tools.h"
#include <fstream>
#include <sstream>

/**
 * @brief Muestra el uso correcto del programa.
 * 
 * Esta función muestra un mensaje con el uso correcto del programa y termina la ejecución del mismo.
 * 
 * @param argc Número de argumentos pasados al programa.
 * @param argv Array de punteros a los argumentos pasados al programa.
 */
void Usage(int argc, char *argv[]) {
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << "\n\nEste programa dado un fichero de texto en el que figura la especificación de una gramática\n"; 
    std::cout << "y un fichero de texto con extensión.gra sobre el que escrbir la Foma Normal de Chomsky\n"; 
    std::cout << "Aplica el algoritmo de conversión y escribe el resultado en la output dado\n";
    std::cout << "\nEjemplo de uso: ./Grammar2CNF input.gra output.gra\n\n";
    exit(EXIT_SUCCESS);
  }
  else if (argc != 3) {
    std::cout << "\n" << argv[0] << "\n: Los argumentos introducidos no son válidos" << std::endl;
    std::cout << "Debe introducir como parámetros el fichero de entrada .gra junto al de salida con misma extensión" << std::endl;
    std::cout << "\nEjemplo de uso: ./Grammar2CNF input.gra output.gra" << std::endl;
    std::cout << "\nPruebe " << argv[0] << " --help para más información\n" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/**
 * @brief Analiza el fichero de entrada y crea una gramática.
 * 
 * Esta función lee un fichero de entrada y crea una gramática a partir de los datos leídos.
 * 
 * @param ficheroEntrada Ruta del fichero de entrada.
 * @return Gramatica La gramática creada a partir del fichero de entrada.
 */
Gramatica Analiza(const std::string& ficheroEntrada) {
  std::ifstream fichero(ficheroEntrada);
  std::string linea;
  std::getline(fichero, linea);
  int contador = std::stoi(linea);

  // Bucle para crear el alfabeto
  std::set<char> terminales;
  for(int i = 0; i < contador; i++) {
    std::getline(fichero, linea);
    terminales.emplace(linea[0]);
    //Comprueba que no se introduzca la cadena vacía como terminal
    if(linea[0] == '&') {
      std::cerr << "Error: El símbolo & no puede ser un terminal" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  Alfabeto alfabeto(terminales);

  //Bucle para almacenar los no terminales
  std::getline(fichero, linea);
  contador = std::stoi(linea);
  std::set<char> noTerminales;
  for(int i = 0; i < contador; i++) {
    std::getline(fichero, linea);
    noTerminales.emplace(linea[0]);
  }
/**
 * @brief Analiza el fichero de entrada y crea una gramática.
 */
  //Bucle para las producciones
  std::getline(fichero, linea);
  contador = std::stoi(linea);
  std::multimap<char, std::string> producciones; 
  for(int i = 0; i < contador; i++) {
    std::getline(fichero, linea);
    std::istringstream stream(linea);
    char noTerminal;
    std::string produccion;
    stream >> noTerminal >> produccion;
    producciones.emplace(noTerminal, produccion);
    //Comprueba que no haya producciones unitarias
    if(produccion.size() == 1 && !alfabeto.contiene(produccion[0]) && produccion[0] != '&') {
      std::cerr << "Error: La gramática no puede contener producciones unitarias" << std::endl;
      exit(EXIT_FAILURE);
    }
    if(produccion.find('&') != std::string::npos) {
      std::cerr << "Error: La producción no puede contener '&'" << std::endl;
      exit(EXIT_FAILURE);
    }
    //Comprueba que no haya producciones vacías
    if(produccion.size() == 1 && produccion[0] == '&' && noTerminal != 'S') {
      std::cerr << "Error: La gramática no puede contener producciones vacías" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  return Gramatica(alfabeto, noTerminales, producciones);
}
