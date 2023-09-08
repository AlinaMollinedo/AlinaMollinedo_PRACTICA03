// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 06/09/2023

// Fecha modificación: 08/09/2023

// Número de ejericio: 12

// Problema planteado: Ingresa una matriz de NxN y a continuación:
// a. Elimine una fila ingresada por el usuario.
// b. Elimine una columna ingresada por el usuario.
// c. Inserte una fila por un valor determinado por el usuario.
// d. Inserte una columna por un valor determinado por el usuario.


#include <iostream>

using namespace std;
int n;

int main(){
    cout << "Ingrese el orden de la matriz: ";
    cin >> n;

    int matrix[n][n];

    for(int i = 0; i < n; i++){ // Llena la matriz con valores introducidos por el usuario
        for(int j = 0; j < n; j++){
            int num;
            cout << "Ingrese el termino " << i + 1 << " " << j + 1 << ": ";
            cin >> num;
            matrix[i][j] = num;
        }
        cout << endl;
    }

    cout << endl;
    for(int i = 0; i < n; i++){ // Imprime la matriz ingresada
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    int delrow, delcol, addrow, addcol;
    int matrix1[n - 1][n] = {}, matrix2[n][n - 1] = {}, matrix3[n + 1][n] = {}, matrix4[n][n + 1] = {};

    cout << "\nQue fila desea eliminar?: ";
    cin >> delrow;

    int posr = 0;
    for(int i = 0; i < n; i++){ // Elimina la fila ingresada por el usuario
        int posc = 0;
        if(i != delrow - 1){
            for(int j = 0; j < n; j++){
                matrix1[posr][posc] = matrix[i][j];
                posc++;
                
            }
            posr++;
        }
    }

    cout << endl;
    for(int i = 0; i < n - 1; i++){ // Imprime la matriz con la fila eliminada
        for(int j = 0; j < n; j++){
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nQue columna desea eliminar?: ";
    cin >> delcol;

    int posc = 0;
    for(int i = 0; i < n; i++){ // Elimina la columna ingresada por el usuario
        int posr = 0;
        if(i != delcol - 1){
            for(int j = 0; j < n; j++){
                matrix2[posr][posc] = matrix[j][i];
                posr++;
                
            }
            posc++;
        }
    }

    cout << endl;
    for(int i = 0; i < n; i++){ // Imprime la matriz con la columna eliminada
        for(int j = 0; j < n - 1; j++){
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    int element;
    cout << "\nEn que posicion desea inserta la fila?: ";
    cin >> addrow;
    cout << "Que numero desea insertar en la fila nueva?: ";
    cin >> element;

    posr = 0;
    for(int i = 0; i < n + 1; i++){ // Inserta una fila del numero ingresado en la posicion ingresada
        int posc = 0;
        if(i == addrow - 1){
            for(int j = 0; j < n; j++){
                matrix3[i][j] = element;
            }
        }
        else{
            for(int j = 0; j < n; j++){ 
                matrix3[i][j] = matrix[posr][posc];
                posc++;
            }
            posr++;
        }
    }
    
    cout << endl;
    for(int i = 0; i < n + 1; i++){ // Imprime la matriz con la fila insertada
        for(int j = 0; j < n; j++){
            cout << matrix3[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nEn que posicion desea inserta la columna?: ";
    cin >> addcol;
    cout << "Que numero desea insertar en la columna nueva?: ";
    cin >> element;

    posc = 0;
    for(int i = 0; i < n + 1; i++){ // Inserta una columna del numero ingresado en la posicion ingresada
        int posr = 0;
        if(i == addcol - 1){
            for(int j = 0; j < n; j++){
                matrix4[j][i] = element;
            }
        }
        else{
            for(int j = 0; j < n; j++){
                matrix4[j][i] = matrix[posr][posc];
                posr++;
            }
            posc++;
        }
    }

    cout << endl;
    for(int i = 0; i < n; i++){ // Imprime la matriz con la columna insertada
        for(int j = 0; j < n + 1; j++){
            cout << matrix4[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}