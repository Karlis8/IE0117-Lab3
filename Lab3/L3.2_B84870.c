#include <stdio.h>

#define MAX 100

void mostrarMatriz(int matriz[][MAX], int n) {
    printf("Matriz ingresada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

void sumarDiagonalesDescendentes(int matriz[][MAX], int n) {
    printf("\nSumas de diagonales descendentes (\\):\n");
    for (int d = 0; d < 2 * n - 1; d++) {
        int suma = 0;
        int filaInicio = (d < n) ? n - 1 - d : 0;
        int colInicio = (d < n) ? 0 : d - n + 1;

        for (int i = filaInicio, j = colInicio; i < n && j < n; i++, j++) {
            suma += matriz[i][j];
        }
        printf("Diagonal %d: %d\n", d + 1, suma);
    }
}

void sumarDiagonalesAscendentes(int matriz[][MAX], int n) {
    printf("\nSumas de diagonales ascendentes (/):\n");
    for (int d = 0; d < 2 * n - 1; d++) {
        int suma = 0;
        int filaInicio = (d < n) ? d : n - 1;
        int colInicio = (d < n) ? 0 : d - n + 1;

        for (int i = filaInicio, j = colInicio; i >= 0 && j < n; i--, j++) {
            suma += matriz[i][j];
        }
        printf("Diagonal %d: %d\n", d + 1, suma);
    }
}

int main() {
    int n = 2;  // Tamano de la matriz
    int matriz[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    mostrarMatriz(matriz, n);
    sumarDiagonalesDescendentes(matriz, n);
    sumarDiagonalesAscendentes(matriz, n);

    return 0;
}