/**
 * * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 8 October 2024
 */
// File: Variable.cc
#include "Variable.h"
#include <sstream>

Variable::Variable(const std::string& type, const std::string& name, int line, std::string value)
	: type_(type), name_(name), line_(line), value_(value) {}

/**
 * @brief Converts the Variable object to a string representation.
 *
 * This method constructs a string that includes the line number, type, 
 * and name of the variable. If the variable has a value, it appends 
 * the value to the string.
 *
 * @return A string representation of the Variable object.
 */
std::string Variable::ToString() const {
	std::stringstream ss;
	ss << "[Line " << line_ << "] " << type_ << ": " << name_;
	if(value_ != "") ss << " = " << value_;
	return ss.str();
}
