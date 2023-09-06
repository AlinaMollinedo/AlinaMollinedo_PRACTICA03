// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 05/09/2023

// Fecha modificación: 05/09/2023

// Número de ejericio: 1

// Problema planteado: Elabore un programa que lea una matriz de orden n x n y la cambie la fila 1 por
// la fila n.

#include <iostream>

using namespace std;
int n;

int main(){
    cout << "Ingrese el numero de filas y columnas de la matriz: ";
    cin >> n;

    int matrix[n][n];

    for(int i = 0; i < n; i++){ // Llena la matriz con valores introducidos por el usuario
        for(int j = 0; j < n; j++){
            int num;
            cout << "Ingrese el termino " << i + 1 << " " << j + 1 << ": ";
            cin >> num;
            matrix[i][j] = num;
        }
    }

    cout << endl;

    for(int i = 0; i < n; i++){ // Imprime la matriz
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < n; i++){ // Reemplaza la fila 1 por la fila n
        int temp = matrix[0][i];
        matrix[0][i] = matrix[n - 1][i];
        matrix[n - 1][i] = temp;
    }

    cout << endl;

    for(int i = 0; i < n; i++){ // Imprime la matriz modificada
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}