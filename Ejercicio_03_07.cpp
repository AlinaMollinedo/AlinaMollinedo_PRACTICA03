// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejericio: 7

// Problema planteado: Efectuar la suma de una matriz tridimensional de orden n x n x n


#include <iostream>

using namespace std;
int n;

int main(){
    cout << "Ingrese el orden de la matriz tridimensional: ";
    cin >> n;

    int matrix[n][n][n], suma = 0;

    for(int i = 0; i < n; i++){ // Llena la matriz tridimensional con valores introducidos por el usuario
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                int num;
                cout << "Ingrese el termino " << i + 1 << " " << j + 1 << " " << k + 1 << ": ";
                cin >> num;
                matrix[i][j][k] = num;
                suma += num; // Suma los terminos de la matriz
            }
            cout << endl;
        }
    }
    cout << endl;
    for(int i = 0; i < n; i++){ // Imprime la matriz
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cout << matrix[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "La suma de los terminos de la matriz es: " << suma << endl;
    return 0;
}