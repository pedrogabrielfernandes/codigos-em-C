int soma(int arr[], int n) {    // c1 * n, c2
  int soma = 0;                 // c3
  for (int i = 0; i < n; i++) { // c4
    soma += arr[i];             // c5, c6 * n
  }
  return soma;
}

// E(n) = c1*n + c2 + c3 + c4 + c5+ c6*n
// E(n) = n(c1+c6) + A
// E(n) = Bn + A
// E(n) = O(n)
