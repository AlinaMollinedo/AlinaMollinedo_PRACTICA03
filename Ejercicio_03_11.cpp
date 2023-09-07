// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 07/09/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 11

// Problema planteado: Realizar el típico juego del 3 en raya, donde habrá dos jugadores que tengan que
// hacer el 3 en raya, los signos serán el X y el O, cuando haya una posición vacía
// habrá un – El tablero de juego, será una matriz de 3×3 de char.
// El juego termina cuando uno de los jugadores hace 3 en raya o si no hay más
// posiciones que poner.
// El juego debe pedir las posiciones donde el jugador actual quiera poner su
// marca, esta debe ser validada y por supuesto que no haya una marca ya puesta.
// Por último mostrar la matriz del juego y muestra al ganador.

#include <iostream>

using namespace std;
char board[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};

int main(){
    bool end = false;
    int play = 0;

    for(int i = 0; i < 3; i++){ // Muestra el tablero
        for(int j = 0; j < 3; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    while(end != true){
        int row, col;
        cout << "\nIngrese la fila: ";
        cin >> row;
        cout << "Ingrese la columna: ";
        cin >> col;

        if(board[row][col] == '-'){ // Verifica que el espacio este vacio
            if(play % 2 == 0){ // Alterna entre X y O en cada jugada
                board[row][col] = 'X';
            }
            else{
                board[row][col] = 'O';
            }
            play++; // Cuenta las jugadas
            for(int i = 0; i < 3; i++){ // Muestra el tablero
                for(int j = 0; j < 3; j++){
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
            int xrow, xcol, orow, ocol;
            for(int i = 0; i < 3; i++){
                xrow = 0, xcol = 0, orow = 0, ocol = 0;
                for(int j = 0; j < 3; j++){
                    if(board[i][j] == 'X'){
                        xrow++; // Cuenta las X en una fila
                    }
                    if(board[j][i] == 'X'){
                        xcol++; // Cuenta las X en una columna
                    }
                    if(board[i][j] == 'O'){
                        orow++; // Cuenta las O en una fila
                    }
                    if(board[j][i] == 'O'){
                        ocol++; // Cuenta las O en una columna
                    }
                }
                if(xcol == 3 || xrow == 3){
                cout << "Gana X!" << endl;
                end = true;
                }
                if(orow == 3 || ocol == 3){
                    cout << "Gana O!" << endl;
                    end = true;
                }
            }
            // Verifica las diagonales para X
            if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
                cout << "Gana X!" << endl;
                end = true;
            }
            if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X'){
                cout << "Gana X!" << endl;
                end = true;
            }

            // Verifica las diagonales para O
            if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
                cout << "Gana O!" << endl;
                end = true;
            }
            if(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O'){
                cout << "Gana O!" << endl;
                end = true;
            }

            if(play == 9){ // Si el tablero ya no tiene espacios vacios, termina el juego
                cout << "Nadie gana!" << endl;
                end = true;
            }
        }
        else{
            cout << "Posicion invalida." << endl;
        }
    }
    return 0;
}