int soma_numeros(int n) {
  int soma = 0;                  // constante c1
  for (int i = 1; i <= n; i++) { // c2 * n
    soma += i;                   // c3 * n
  }
  return soma; // c4
}

// T(n) = c1 + c2*n + c3n  + c4
// T(n) = c1 + n(c2+c3) + c4
// T(n) = A + n(c2+c3)
// T(n) = O(n)
