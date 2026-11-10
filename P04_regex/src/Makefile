# Universidad de La Laguna
# Escuela Superior de Ingenieria y Tecnologia
# Grado en Ingenieria Informatica
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Autor: Guillermo López Concepción
# Correo: guillrl1@users.noreply.github.com
# Archivo: Makefile

# Nombre del archivo de salida
TARGET = p04_code_analyzer

# Lista de archivos fuente
SOURCES = CodeAnalyzer.cc Comments.cc Loop.cc tools.cc Variable.cc main.cc

# Dependencias de los archivos fuente
DEPENDENCIES = CodeAnalyzer.h Comments.h Loop.h tools.h Variable.h

# Opciones de compilación
CXX = g++
CXXFLAGS = -std=c++11

# Regla para compilar el programa
$(TARGET): $(SOURCES) $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) *.o

# Regla por defecto
default: $(TARGET)
