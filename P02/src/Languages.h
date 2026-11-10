/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 20 September 2024
 */
#ifndef LANGUAGES_H
#define LANGUAGES_H

#include <iostream>
#include <string>
#include <set>

class Language {
  public:
    Language() : language_{} {}
    //getters
    std::set<std::string> get_language() const { return language_; }
    int get_size() const { return language_.size(); }
    void set_chain(std::string chain) { language_.insert(chain); }
    //Overload
    friend std::ostream& operator<<(std::ostream& os, const Language& language);
    bool operator<(const Language& other) const;
  private:
    std::set<std::string> language_;
};

#endif