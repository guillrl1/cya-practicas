/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 20 September 2024
 * @file Alphabet.cc
 * @brief Implementation file for the Alphabet class.
 * 
 * This file contains the implementation of the Alphabet class, which represents a collection of symbols.
 * The Alphabet class provides constructors to initialize the object with a string or a Chain object.
 * It also provides an overloaded << operator to print the symbols in the Alphabet object.
 */

#include "Alphabet.h"
#include "P02_strings.h"
#include "chain.h"

/**
 * @brief Constructs an Alphabet object based on the given string.
 * 
 * This constructor initializes the Alphabet object by extracting the characters from the
 * provided string and storing them in the symbols_ set.
 * 
 * @param aux The string from which to extract the characters.
 */
Alphabet::Alphabet(std::string aux) {
  for(char c : aux)
    symbols_.insert(c);
}

/**
 * @brief Constructs an Alphabet object based on the given Chain object.
 * 
 * This constructor initializes the Alphabet object by extracting the characters from the
 * provided Chain object and storing them in the symbols_ set.
 * 
 * @param var The Chain object from which to extract the characters.
 */
Alphabet::Alphabet(Chain var) {
  std::string aux{var.get_var()};
  for(char c : aux)
    symbols_.insert(c);
}

/**
 * @brief Overloaded << operator to print the symbols in the Alphabet object.
 * 
 * This operator prints the symbols in the Alphabet object in the format "{symbol1, symbol2, ...}".
 * 
 * @param os The output stream to write the symbols to.
 * @param alphabet The Alphabet object to print.
 * @return The output stream after writing the symbols.
 */
std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
    unsigned count{0};
    os << "{";
    for (const auto& symbol : alphabet.get_symbols()) {
      os << symbol;
      if(count != alphabet.get_size() - 1) {
        os << ", ";
      }
      count++;
    }
    os << "}";
    return os;
}