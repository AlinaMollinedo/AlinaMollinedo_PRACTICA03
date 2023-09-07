// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejericio: 6

// Problema planteado: Generar una matriz NxN, que se llene con la serie de Fibonacci


#include <iostream>

using namespace std;
int n;

int main(){
    cout << "Ingrese el orden de la matriz: ";
    cin >> n;

    int matrix[n][n], x = 0, y = 1, z = 0;;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = x;
            // Genera un termino de la secuencia Fibonacci
            z = x + y;
            x = y;
            y = z;
        }
    }
    for(int i = 0; i < n; i++){ // Imprime la matriz
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}