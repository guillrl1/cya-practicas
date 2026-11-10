/**
 * * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 8 October 2024
 */
// File: Loop.cc
#include "Loop.h"
#include <sstream>

Loop::Loop(const std::string& type, int line) : type_(type), line_(line) {}

/**
 * @brief Converts the Loop object to a string representation.
 * 
 * This method creates a string representation of the Loop object,
 * including the line number and the type of loop.
 * 
 * @return A string representing the Loop object.
 */
std::string Loop::ToString() const {
	std::stringstream ss;
	ss << "[Line " << line_ << "] LOOP: " << type_;
	return ss.str();
}
