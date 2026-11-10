#include "gramatica.h"

#include <iostream>  //debug

/**
 * @brief Constructor de la clase Gramatica.
 */
Gramatica::Gramatica(Alfabeto terminales, std::set<char> noTerminales,
                     std::multimap<char, std::string> producciones)
    : simbolosTerminales_{terminales},
      simbolosNoTerminales_{noTerminales},
      producciones_{producciones} {}


/**
 * @brief Asigna una letra no terminal que no esté en el conjunto de símbolos no terminales.
 * 
 * Esta función busca una letra mayúscula del alfabeto inglés que no esté presente en el conjunto
 * de símbolos no terminales (`simbolosNoTerminales_`). Si encuentra una letra disponible, la retorna.
 * En caso de que todas las letras mayúsculas estén ocupadas, muestra un mensaje de error y termina
 * la ejecución del programa.
 * 
 * @return char La letra no terminal asignada.
 */
char Gramatica::asignaLetra() {
  char letra = 'A';
  while (true) {
    if (simbolosNoTerminales_.find(letra) == simbolosNoTerminales_.end())
      return letra;
    if (letra > 'Z') {
      std::cerr << "Error: No hay más letras disponibles" << std::endl;
      exit(EXIT_FAILURE);
    } else
      letra += 1;
  }
}

/**
 * @brief Realiza el primer bucle de procesamiento de la gramática.
 * 
 * Esta función recorre las producciones de la gramática en busca de terminales.
 * Si encuentra más de un terminal o si hay no terminales, aplica un algoritmo
 * para sustituir los terminales por nuevos no terminales. Luego, guarda las 
 * nuevas producciones en el multimap original.
 * 
 * @details 
 * - Recorre las producciones en busca de terminales.
 * - Si hay más de un terminal o no terminales, aplica un algoritmo de sustitución.
 * - Sustituye los terminales por nuevos no terminales.
 * - Guarda las nuevas producciones en el multimap original.
 */
void Gramatica::primerBucle() {
  std::map<char, char> nuevosNoTerminales;  // <s, S>
  bool noTerminales = false;

  for (auto it = producciones_.begin(); it != producciones_.end(); ++it) {
    std::string produccion =
        it->second;  // Almacena la regla de producción en un string
    std::vector<char> terminalesEncontrados;
    noTerminales = false;
    for (char c : produccion) {  // recorre la producción en busca de terminales
      if (simbolosTerminales_.contiene(c))
        terminalesEncontrados.push_back(c);
      else
        noTerminales = true;
    }

    // Si hay más de dos, o no está solo se aplica el algoritmo
    if (terminalesEncontrados.size() > 1 || noTerminales) {
      for (size_t i; terminalesEncontrados.size() > i; i++) {
        char terminal = terminalesEncontrados[i];
        auto range = nuevosNoTerminales.equal_range(
            terminal);  // Comprobar si la producción ya ha sido creada
        if (range.first ==
            range.second) {  // Si el par no existe todavía, entonces se crea
          nuevosNoTerminales.emplace(terminal, asignaLetra());
          simbolosNoTerminales_.emplace(asignaLetra());  // Se añade al conjunto
        }
      }
    }

    // Bucle para sustituir los terminales por los nuevos no terminales
    if (terminalesEncontrados.size() > 1 || noTerminales) {
      std::string aux;
      for (char c : produccion) {
        // Si es un terminal, se sustituye por el no terminal creado.
        if (simbolosTerminales_.contiene(c)) {
          auto range = nuevosNoTerminales.equal_range(c);
          aux += range.first->second;
        }
        // Si es un no terminal se almacena sin más
        else
          aux += c;
      }
      it->second = aux;
    }
  }

  // Guardar las nuevas producciones al multimap original

  // Invertir los pares (a, A) a (A, a)
  for (const auto& par : nuevosNoTerminales) {
    producciones_.emplace(par.second, std::string(1, par.first));
  }
}


/**
 * @brief Realiza un segundo bucle sobre las producciones de la gramática para 
 *        modificar las producciones que tienen más de dos símbolos en el lado derecho.
 * 
 * La función itera sobre las producciones de la gramática y, para cada producción 
 * que tenga más de dos símbolos en el lado derecho, crea una nueva producción con 
 * los dos últimos símbolos y reemplaza estos dos símbolos en la producción original 
 * con un nuevo símbolo no terminal. Este proceso se repite hasta que no se realicen 
 * más cambios en las producciones.
 * 
 * @note La función utiliza un bucle while que se ejecuta mientras se realicen cambios 
 *       en las producciones. Dentro del bucle, se itera sobre las producciones y se 
 *       realizan las modificaciones necesarias.
 * 
 * @note La función asume que existe un método `asignaLetra()` que asigna un nuevo 
 *       símbolo no terminal.
 * 
 * @note La función modifica las producciones y los símbolos no terminales de la 
 *       gramática.
 */
void Gramatica::segundoBucle() {
  bool cambios = true;
  while (cambios) {
    cambios = false;
    // Recorremos las producciones
    for (auto it = producciones_.begin(); it != producciones_.end(); ++it) {
      std::string produccion =
          it->second;  // Almacena la regla de producción en un string
      if (produccion.size() > 2) {
        // añadir la pareja a un string auxiliar
        std::string aux = std::string(1, produccion[produccion.size() - 2]) +
                          std::string(1, produccion[produccion.size() - 1]);
        char nuevaLetra = asignaLetra();
        producciones_.emplace(nuevaLetra,
                              aux);  // Crea una nueva produccion con el par
        // Modificar la cadena original con el nuevo no terminal
        size_t pos = it->second.size() - 2;
        it->second = it->second.replace(pos, 2, std::string(1, nuevaLetra));
        simbolosNoTerminales_.emplace(
            nuevaLetra);  // Se añade a los simbolos no terminales
        cambios = true;
      }
    }
  }
}


/**
 * @brief Transforma la gramática a la Forma Normal de Chomsky (FNC).
 * 
 * Esta función transforma la gramática actual a la Forma Normal de Chomsky
 * utilizando dos pasos principales: primerBucle y segundoBucle.
 */
void Gramatica::transformaFNC() {
  primerBucle();
  segundoBucle();
}

/**
 * @brief Escribe la gramática en un fichero de salida.
 *
 * Esta función escribe los símbolos terminales, los símbolos no terminales y las producciones
 * de la gramática en un fichero especificado por el parámetro `ficheroSalida`.
 *
 * @param ficheroSalida Ruta del fichero donde se escribirá la gramática.
 */
void Gramatica::Escribe(const std::string& ficheroSalida) {
  // Escribir los terminales
  int contador = simbolosTerminales_.getSize();
  std::ofstream salida(ficheroSalida);
  std::set<char> terminales = simbolosTerminales_.getSimbolos();
  salida << contador << "\n";
  for (auto it = terminales.begin(); it != terminales.end(); ++it) {
    salida << *it << "\n";
  }

  // Escribir los no terminales
  contador = simbolosNoTerminales_.size();
  salida << contador << "\n";
  for (auto it = simbolosNoTerminales_.begin();
       it != simbolosNoTerminales_.end(); ++it) {
    salida << *it << "\n";
  }

  // Escribir las producciones
  contador = producciones_.size();
  salida << contador << "\n";
  for (auto it = producciones_.begin(); it != producciones_.end(); ++it) {
    salida << it->first << " " << it->second << "\n";
  }
}