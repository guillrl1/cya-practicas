bool Sudoku::solve(void) {
  short row, col;
  if(!find_empty_cell(row, col))  // Condicion de parada
    return true;

  for(short it = 0; it <= N; it++) { 
    if(check_all(row, col, it)) { // Probamos el número
      m_(row, col) = it;          // caso favorable: lo ponemos y llamamos a solve para la siquiente celda

      if(solve()) return true;    // Propagación de true si es válido
    }
  } 
  m_(row, col) = 0;               // Caso de fracaso: no se ha podido rellenar la celda
  return false;
}