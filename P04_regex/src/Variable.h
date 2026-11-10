/**
 * * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 8 October 2024
 */
// File: Variable.h
#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>

class Variable {
public:
	Variable(const std::string& type, const std::string& name, int line, std::string value = "");
  
  /**
   * @brief Converts the variable to its string representation.
   * 
   * @return A string that represents the variable.
   */
	std::string ToString() const;

private:
	std::string type_;
	std::string name_;
	int line_;
	std::string value_;
};

#endif // VARIABLE_H
