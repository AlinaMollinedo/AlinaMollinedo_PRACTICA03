// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 05/09/2023

// Fecha modificación: 06/09/2023

// Número de ejericio: 3

// Problema planteado: Generar una matriz de N x N con números al azar entre A y B, y determinar:
// • La suma de la última columna
// • El producto total de la última fila
// • Obtener el mayor valor y su posición
// • Obtener la desviación estándar de todos los elementos de la matriz

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;
int n, a, b, highest = -1, hrow, hcol;
double sumTotal;

int main(){
    cout << "Ingrese el numero de filas y columnas de la matriz: ";
    cin >> n;

    cout << "Ingrese el limite inferior del rango: ";
    cin >> a;
    cout << "Ingrese el limite superior del rango: ";
    cin >> b;

    int matrix[n][n];

    for(int i = 0; i < n; i++){ // Llena la matriz con valores al azar en el rango entre A y B
        for(int j = 0; j < n; j++){
            int num = a + rand() % b;
            matrix[i][j] = num;
            sumTotal += num; // Suma todos los valores de la matriz
            if(num > highest){ // Determina el numero mayor y su posicion
                highest = num;
                hrow = i + 1;
                hcol = j + 1;
            }
        }
    }

    cout << endl;

    for(int i = 0; i < n; i++){ // Imprime la matriz
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int sumColN = 0, prodRowN = 1;

    for(int i = 0; i < n; i++){
        sumColN += matrix[i][n - 1]; // Suma los elementos de la columna n
        prodRowN *= matrix[n - 1][i]; // Multiplica los elementos de la fila n
    }

    double mean = sumTotal / n / n, summation = 0; // Calcula la media

    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < n; j++){
            summation += pow(matrix[i][j] - mean, 2.0); // Calcula la sumatoria de cada elemento menos la media al cuadrado
        }
    }

    double stdesv = pow(summation / (n * n - 1),1.0/2); // Calcula la desviacion estandar

    cout << "\nLa suma de la ultima columna es: " << sumColN << endl;
    cout << "El producto total de la ultima fila es: " << prodRowN << endl;
    cout << "El mayor valor es " << highest << " y su posicion es " << hrow  << " " << hcol << endl;
    cout << "la desviacion estandar de todos los elementos de la matriz es: " << stdesv << endl;
    return 0;
}