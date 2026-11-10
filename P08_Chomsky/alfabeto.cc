/**
 * * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 22 Octubre 2024
 * @brief Implementación de la clase Alfabeto.
 *
 * Esta clase representa un alfabeto, que es un conjunto de símbolos.
 * Proporciona métodos para verificar si un símbolo pertenece al alfabeto
 * y para obtener el conjunto de símbolos del alfabeto.
 *
 * @class Alfabeto
 * @param simbolos_ Conjunto de símbolos que forman el alfabeto.
 *
 * @method Alfabeto::Alfabeto Constructor que inicializa el alfabeto con un
 * conjunto de símbolos.
 * @param simbolos Conjunto de símbolos para inicializar el alfabeto.
 *
 * @method bool Alfabeto::contiene Verifica si un símbolo está en el alfabeto.
 * @param simbolo Símbolo a verificar.
 * @return true si el símbolo está en el alfabeto, false en caso contrario.
 *
 * @method std::set<char> Alfabeto::getSimbolos Obtiene el conjunto de símbolos
 * del alfabeto.
 * @return Conjunto de símbolos del alfabeto.
 */

#include "alfabeto.h"

// Constructor
Alfabeto::Alfabeto(const std::set<char>& simbolos) : simbolos_(simbolos) {}

// Verificar si el símbolo está en el alfabeto
bool Alfabeto::contiene(char simbolo) const {
  return simbolos_.find(simbolo) != simbolos_.end();
}

// Obtener el conjunto de símbolos
std::set<char> Alfabeto::getSimbolos() const { return simbolos_; }
