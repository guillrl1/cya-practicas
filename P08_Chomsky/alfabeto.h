/**
 * * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 22 Octubre 2024
 */

#ifndef ALFABETO_H
#define ALFABETO_H

#include <set>

/**
 * @class Alfabeto
 * @brief Representa un alfabeto como un conjunto de símbolos.
 * 
 * La clase Alfabeto permite manejar un conjunto de símbolos y proporciona
 * métodos para verificar si un símbolo pertenece al alfabeto y para obtener
 * el conjunto de símbolos.
 */

class Alfabeto {
private:
    std::set<char> simbolos_;  // Conjunto de símbolos

public:

    // Constructor
    Alfabeto(const std::set<char>& simbolos);

    // Verificar si un símbolo pertenece al alfabeto
    bool contiene(char simbolo) const;

    // Obtener el conjunto de símbolos
    std::set<char> getSimbolos() const;

    // Obetener el tamaño
    int getSize() const { return simbolos_.size(); }
};

#endif // ALFABETO_H
