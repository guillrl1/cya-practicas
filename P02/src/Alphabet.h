/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 20 September 2024
 */

#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <string>
#include <set>
#include "chain.h"
class Alphabet {
  public:
    Alphabet(std::string);
    Alphabet(Chain);
    std::set<char> get_symbols() const { return symbols_; };
    int get_size() const { return symbols_.size(); }
 

    friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);
  
  private:
    std::set<char> symbols_;
};


#endif