#include "chain.h"
/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 20 September 2024
 */

/**
 * @brief Constructs a Chain object with the given string.
 * 
 * @param aux The string to initialize the Chain object with.
 */
Chain::Chain(std::string aux) {
  set_var(aux);
}

/**
 * @brief Reverses the characters in the Chain object and returns a new Chain object with the reversed characters.
 * 
 * @return A new Chain object with the reversed characters.
 */
Chain Chain::Reverse() const {
  std::string aux(get_var());
  std::reverse(aux.begin(), aux.end());
  return Chain(aux);
}

/**
 * @brief Returns the character at the specified position in the Chain object.
 * 
 * @param position The position of the character to retrieve.
 * @return The character at the specified position.
 */
char Chain::at(const unsigned& position) const {
  return var_[position];
}

/**
 * @brief Overloaded input stream extraction operator.
 * 
 * @param in The input stream to extract from.
 * @param chain The Chain object to store the extracted value.
 * @return The input stream after extraction.
 */
std::istream& operator>>(std::istream& in, Chain& chain) {
  in >> chain.var_;
  return in;
}

/**
 * @brief Overloaded output stream insertion operator.
 * 
 * @param os The output stream to insert into.
 * @param chain The Chain object to insert into the output stream.
 * @return The output stream after insertion.
 */
std::ostream& operator<<(std::ostream& os, const Chain& chain) {
    os << chain.var_;
    return os;
}

bool Chain::operator<(const Chain& other) const {
  if (this -> var_.length() != other.var_.length()) {
    return this -> var_.length() < other.var_.length();
  }
  return this -> var_ < other.var_;
}




Language Chain::Prefix() {
  std::string word{get_var()};
  std::string temp{""};
  Language language;
  for(char c : word) {
    temp += c;
    language.set_chain(temp);
  }
  return language;
}
 
/**
 * @brief Inserts suffixes of a given word into the language set.
 * @param aux The Chain object containing the word.
 */
Language Chain::Sufix() {
  std::string word{get_var()};
  std::string temp{""};
  Language language;
  for(std::size_t i = 0; i < word.size(); i++) {
    temp = word.substr(i);
    language.set_chain(temp);
  }
  return language;
}