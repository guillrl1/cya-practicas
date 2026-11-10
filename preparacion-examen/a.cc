matrix mul_T(const matrix& A) {
  matrix C(n, n);
  
    matrix A11, A12, A21, A22, C11, C12, C21, C22;

    A11 = submatrix(A, 1, 1, n/2);
    A12 = submatrix(A, n/2, 1, n/2);
    A21 = submatrix(A, 1, n/2, n/2);
    A22 = submatrix(A, n/2, n/2, n/2);

    C11 = mul(A11, T(A11)) + mul(A12, T(A12));
    C12 = mul(A12, T(A21)) + mul(A12, T(A22));
    C22 = mul(A21, T(A21)) + mul(A22, T(A22));

    set_submatrix(C, C11, 1, 1);
    set_submatrix(C, C12, 1, n/2);
    set_submatrix(C, C12, n/2, 1);
    set_submatrix(C, C22, n/2, n/2);
  }
  return C;
}