// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 06/09/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 8

// Problema planteado: Multiplique dos matrices una de N x M y la otra de M x N

#include <iostream>

using namespace std;
int n, m;

int main(){
    cout << "Ingrese el numero de filas de la matriz: ";
    cin >> n;
    cout << "Ingrese el numero de columnas de la matriz: ";
    cin >> m;

    int matrix1[n][m], matrix2[m][n];

    cout << "\nMatriz 1: " << endl; // Pide los terminos de la matriz 1
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < m; j++){
            int num;
            cout << "Ingrese el termino " << i + 1 << " " << j + 1 << ": ";
            cin >> num;
            matrix1[i][j] = num;
        }
    }
    cout << "\nMatriz 2: " << endl; // Pide los terminos de la matriz 2
    for(int i = 0; i < m; i++){ 
        for(int j = 0; j < n; j++){
            int num;
            cout << "Ingrese el termino " << i + 1 << " " << j + 1 << ": ";
            cin >> num;
            matrix2[i][j] = num;
        }
    }
    cout << "\nMatriz 1: " << endl; // Muestra la matriz 1
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix1[i][j] << " ";
        }  
        cout << endl;
    }
    cout << "\nMatriz 2: " << endl; // Muestra la matriz 2
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << matrix2[i][j] << " ";
        }  
        cout << endl;
    }
    cout << endl;

    int prod[n][n];

    for(int i = 0; i < n; i++){ // Itera cada fila de la matriz 1
        for(int k = 0; k < n; k++){ // Itera cada columna de la matriz 2
            int suma = 0;
            for(int j = 0; j < m; j++){
                suma += matrix1[i][j] * matrix2[j][k]; // Realiza el producto y suma de los terminos correspondientes
            }
            prod[i][k] = suma; // Almacena la anterior suma en la posicion indicada de la matriz producto
        }
    }

    cout << "\nMatriz 1 x Matriz 2: " << endl; // Muestra la matriz producto
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << prod[i][j] << " ";
        }  
        cout << endl;
    }

    return 0;
}