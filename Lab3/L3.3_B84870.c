#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO 2 

int encontrar_secuencia_mas_larga(int matriz[TAMANO][TAMANO]) {
    int max_longitud = 0;
    int longitud_actual = 0;

    // Recorrido de la matriz
    for (int suma = 0; suma <= 2 * (TAMANO - 1); suma++) {
        for (int i = 0; i < TAMANO; i++) {
            int j = suma - i;
            if (j >= 0 && j < TAMANO) {
                if (matriz[i][j] == 1) {
                    longitud_actual++;
                    if (longitud_actual > max_longitud) {
                        max_longitud = longitud_actual;
                    }
                } else {
                    longitud_actual = 0;  // Reiniciar solo si hay un 0
                }
            }
        }
    }

    return max_longitud;
}

void llenar_matriz_aleatoria(int matriz[TAMANO][TAMANO]) {
    srand(time(NULL));
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            matriz[i][j] = rand() % 2;
        }
    }
}

void imprimir_matriz(int matriz[TAMANO][TAMANO]) {
    printf("Matriz (%dx%d):\n", TAMANO, TAMANO);
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Ejemplo con matriz del documento
    /*
    int matriz[TAMANO][TAMANO] = {
        {1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 1}
    };
    */
    int matriz[TAMANO][TAMANO];
    
    llenar_matriz_aleatoria(matriz);
    imprimir_matriz(matriz);
        
    int resultado = encontrar_secuencia_mas_larga(matriz);
    printf("La secuencia de 1s mas larga en direccion ↓↙ es: %d\n", resultado);

    return 0;
}