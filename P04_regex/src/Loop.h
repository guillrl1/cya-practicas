/**
 * * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 8 October 2024
 */
// File: Loop.h
#ifndef LOOP_H
#define LOOP_H
#include <string>

/**
 * @class Loop
 * @brief Represents a loop construct with a specific type and line number.
 *
 * The Loop class encapsulates information about a loop, including its type
 * (e.g., for, while) and the line number where it is defined.
 */

/**
 * @brief Constructs a Loop object with the specified type and line number.
 * 
 * @param type The type of the loop (e.g., "for", "while").
 * @param line The line number where the loop is defined.
 */
 
/**
 * @brief Returns a string representation of the Loop object.
 * 
 * @return A string that describes the Loop object.
 */
class Loop {
public:
	Loop(const std::string& type, int line);
	std::string ToString() const;
private:
  std::string type_;
	int line_;
};

#endif // LOOP_H
