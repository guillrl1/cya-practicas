/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * @author Guillermo López Concepción guillrl1@users.noreply.github.com
 * @date 20 September 2024
 */

#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>
#include "Languages.h"

class Chain {
  public:
    //setter
    void set_var(std::string var) { var_ = var; }
    //getter
    std::string get_var() const { return var_; }
    unsigned get_size() const { return var_.size(); }
    //Constructores
    Chain() : var_{""} {}
    Chain(std::string);
    //Métodos
    Chain Reverse() const;
    char at(const unsigned&) const;
    Language Prefix(void);
    Language Sufix(void);

    friend std::istream& operator>>(std::istream& in, Chain& chain);
    friend std::ostream& operator<<(std::ostream& os, const Chain& chain);
    bool operator<(const Chain& other) const;
    
  private:
    std::string var_;
};

#endif