#ifndef GRAMATICA_H
#define GRAMATICA_H

#include <fstream>
#include <map>
#include <set>

#include "alfabeto.h"

class Gramatica {
 public:
  Gramatica(Alfabeto, std::set<char>, std::multimap<char, std::string>);
  void transformaFNC();
  void primerBucle();
  void segundoBucle();
  char asignaLetra();
  void Escribe(const std::string& ficheroSalida);

 private:
  Alfabeto simbolosTerminales_;
  std::set<char> simbolosNoTerminales_;
  std::multimap<char, std::string> producciones_;
};

#endif  // GRAMATICA_H