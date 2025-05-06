#include <stdio.h>

void imprimirBinario(int n){
    if(n > 1) {
        imprimirBinario(n >> 1);
    }
    printf("%d", n & 1);
}

int main() {
    int num;
    int resultado;

    do {
    printf("Ingrese un numero entero positivo: ");
    resultado = scanf("%d", &num);
    printf("*Nota: Si ingresó un número con decimales, solo se tomó en cuenta su parte entera. ");
    printf("\n");

    if (resultado != 1) {
        printf("Error: Entrada invalida. Debe ingresar un numero entero.\n");
        while (getchar() != '\n'); // Limpiar el buffer
    } else if (num < 0) {
        printf("Error: El numero debe ser positivo.\n");
    }
} while (resultado != 1 || num < 0);

printf("El numero ingresado en binario es: ");
imprimirBinario(num);
printf("\n");

return 0;
}