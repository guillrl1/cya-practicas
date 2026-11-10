/**
 * * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 20 September 2024
 * @file Languages.cc
 * @brief Implementation of the Language class member functions.
 */

#include "Languages.h"

/**
 * @brief Inserts prefixes of a given word into the language set.
 * @param aux The Chain object containing the word.
 */

/**
 * @brief Overloaded stream insertion operator for Language objects.
 * @param os The output stream.
 * @param language The Language object to be inserted into the stream.
 * @return The output stream after inserting the Language object.
 */
std::ostream& operator<<(std::ostream& os, const Language& language) {
  os << "{&";
  unsigned count{0};
  for(const auto& aux : language.get_language()) {
      os << ", " << aux;
  }
  os << "}";

  return os;
}

bool Language::operator<(const Language& other) const {
  if (this -> language_.size() != other.language_.size()) {
    return this -> language_.size() < other.language_.size();
  }
  return this -> language_ < other.language_;
}