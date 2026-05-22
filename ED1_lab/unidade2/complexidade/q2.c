#include <stdio.h>

void algoritmo_a(int n) {         // c1
  for (int i = 0; i < n; i++) {   // n vezes, c2*n
    for (int j = 0; j < n; j++) { // c3*n*n
      printf("%d, %d\n", i, j);   // c4*n*n
    }
  }
}

// T(n) = c1 + c2*n c3*n² + c4n²
// T(n) = c1 + n²(c2 + c3) + n(c2)
// T(n) = An² + Bn + C
// T(n) = n² + n
// T(n) = O(n²)

void algoritmo_b(int n) {       // c1
  for (int i = 0; i < n; i++) { // c2*n
    printf("%d\n", i);          // c3*n
  }
  for (int j = 0; j < n; j++) { // c4*n
    printf("%d\n", j);          // c5*n
  }
}

// T(n) =  c1+ n(c2 + c3 + c4 + c5)
// T(n) = A + Bn
// T(n) = O(n)
//
// logo o algoritmo mais eficiente é o b por ser linear
