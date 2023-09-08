// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 05/09/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 2

// Problema planteado: Generar la matriz espiral para un orden n.

#include <iostream>

using namespace std;
int n;

int main(){
    cout << "Ingrese el orden de la matriz espiral: ";
    cin >> n;

    int matrix[n][n] = {}, x = 1, i = 0, j = 0, N = n;

    while(x != (N * N) + 1){ // Se detiene cuando x es igual al cuadrado del orden de la matriz
        for(int a = 0; a < n; a++){ // Dirije los numeros de derecha a izquierda
            matrix[i][j] = x;
            x++;
            j++;
        }
        i++;
        j--;
        for(int a = 0; a < n - 1; a++){ // Dirije los numeros de arriba a abajo
            matrix[i][j] = x;
            x++;
            i++;
        }
        i--;
        j--;
        for(int a = 0; a < n - 1; a++){ // Dirije los numeros de izquierda a derecha
            matrix[i][j] = x;
            x++;
            j--;
        }
        i--;
        j++;
        for(int a = 0; a < n - 2; a++){ // Dirije los numeros de abajo a arriba
            matrix[i][j] = x;
            x++;
            i--;
        }
        i++;
        j++;
        n -= 2;   
    
    }

    for(int a = 0; a < N; a++){ // Imprime la matriz espiral
        for(int b = 0; b < N; b++){
            cout << matrix[a][b] << "\t";
        }
        cout << endl;
    }
    return 0;
}