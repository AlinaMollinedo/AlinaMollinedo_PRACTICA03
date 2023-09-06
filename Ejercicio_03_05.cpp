// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejericio: 5

// Problema planteado: Generar la matriz para un orden NxN
// Sea n=5
// 1 2 3 4 5
// 3 4 5 6 7
// 5 6 7 8 9
// 7 8 9 10 11
// 9 10 11 12 13

#include <iostream>

using namespace std;
int n;

int main(){
    cout << "Ingrese el numero de filas y columnas de la matriz: ";
    cin >> n;

    for(int i = 1; i < n * 2; i += 2){ // Empieza cada vuelta con numeros impares despues del 1
        for(int j = i; j < i + n ; j++){ // Imprime n numeros consecutivos al impar con el que empieza ;a vuelta
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}