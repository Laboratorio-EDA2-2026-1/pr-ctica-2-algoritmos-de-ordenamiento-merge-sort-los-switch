#include <stdio.h>
#include <stdlib.h>

/*
    Ejercicio: Implementación de Merge Sort

    Descripción:
    Se reciben n arreglos lineales, cada uno de tamaño n.
    El programa debe combinarlos en un solo arreglo de tamaño n*n
    y ordenarlo en orden creciente usando Merge Sort.

    Entrada:
    - Un número entero n
    - n arreglos de tamaño n (n*n enteros en total)

    Salida:
    - Un solo arreglo de tamaño n*n con los elementos ordenados en orden creciente

    Ejemplo:

    Input:
    3
    3 1 5
    2 9 4
    8 7 6

    Output:
    1 2 3 4 5 6 7 8 9
*/

// ---- Prototipos ----
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    int n;
    printf("Ingrese el número de arreglos (n): ");
    scanf("%d", &n);  // Leer el número de arreglos

    int total = n * n;  
    int *arr = (int *)malloc(total * sizeof(int));

    printf("Ingrese %d números (%d arreglos de %d elementos):\n", total, n, n);
    
    // Leer n arreglos de tamaño n
    for (int i = 0; i < total; i++) {
        printf("Número [%d] del arreglo: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Ordenar usando merge sort
    mergeSort(arr, 0, total - 1);
    
    printf("\nArreglo ordenado:\n");
    
    // Imprimir el arreglo ordenado
    for (int i = 0; i < total; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

// ---- Implementación de mergeSort ----
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Calcular el punto medio correctamente
        int mid = left + (right - left) / 2;
        
        // Ordenar la primera mitad
        mergeSort(arr, left, mid);
        
        // Ordenar la segunda mitad
        mergeSort(arr, mid + 1, right);

        // Combinar las dos mitades ordenadas
        merge(arr, left, mid, right);
    }
}

// ---- Implementación de merge ----
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int s1 = mid - left + 1;
    int s2 = right - mid;
    
    // Usar asignación dinámica para evitar problemas de stack overflow
    int *left_arr = (int *)malloc(s1 * sizeof(int));
    int *right_arr = (int *)malloc(s2 * sizeof(int));
    
    if (left_arr == NULL || right_arr == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        exit(1);
    }
    
    for(i = 0; i < s1; i++) {
        left_arr[i] = arr[left + i];
    }
    
    for (j = 0; j < s2; j++) {
        right_arr[j] = arr[mid + 1 + j];
    }
    
    i = 0, j = 0;
    k = left;
    
    while(i < s1 && j < s2) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    
    while (i < s1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    
    while (j < s2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
    
    // Liberar memoria de los arreglos temporales
    free(left_arr);
    free(right_arr);
}
