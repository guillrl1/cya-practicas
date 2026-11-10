/**
 * * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 8 October 2024
 */
// File: Comments.h
#ifndef COMMENTS_H
#define COMMENTS_H

#include <string>

/**
 * @class Comments
 * @brief Represents a comment block in the code.
 *
 * This class is used to store information about a comment block, including its type,
 * the lines it spans, and its content.
 */
class Comments {
public:
	Comments(const std::string& type, int startLine, int endLine, const std::string& content);
	std::string ToString() const;
private:
  std::string type_;  // "DESCRIPTION" or "COMMENT"
	int startLine_;
	int endLine_;
	std::string content_;
};

#endif // COMMENTS_H
