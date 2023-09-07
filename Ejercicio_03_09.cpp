// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejericio: 9

// Problema planteado: Trasponer una matriz de N x M

#include <iostream>

using namespace std;
int n, m;

int main(){
    cout << "Ingrese el numero de filas de la matriz: ";
    cin >> n;
    cout << "Ingrese el numero de columnas de la matriz: ";
    cin >> m;

    int matrix[n][m], trans[m][n];

    for(int i = 0; i < n; i++){ // Llena la matriz con valores introducidos por el usuario
        for(int j = 0; j < m; j++){
            int num;
            cout << "Ingrese el termino " << i + 1 << " " << j + 1 << ": ";
            cin >> num;
            matrix[i][j] = num;
        }
    }

    for(int i = 0; i < m; i++){ // Coloca las columnas de matrix como las filas de trans
        for(int j = 0; j < n; j++){
            trans[i][j] = matrix[j][i];
        }
    }
    cout << endl;
    for(int i = 0; i < m; i++){ // Imprime la matriz transpuesta
        for(int j = 0; j < n; j++){
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}