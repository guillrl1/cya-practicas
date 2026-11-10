/**
 * * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 8 October 2024
 */
// File: Comments.cc
#include "Comments.h"
#include <sstream>

Comments::Comments(const std::string& type, int startLine, int endLine, const std::string& content)
	: type_(type), startLine_(startLine), endLine_(endLine), content_(content) {}

/**
 * @brief Converts the comment object to a string representation.
 *
 * This function generates a string that represents the comment object.
 * If the comment type is "DESCRIPTION", it includes the start and end line numbers
 * and the word "DESCRIPTION". Otherwise, it includes the start line number and the comment content.
 *
 * @return A string representation of the comment object.
 */
std::string Comments::ToString() const {
	std::stringstream ss;
	if (type_ == "DESCRIPTION") {
		ss << "[Line " << startLine_ << "-" << endLine_ << "] DESCRIPTION\n";
	} else {
		ss << "[Line " << startLine_ << "] // " << content_;
	}
	return ss.str();
}
