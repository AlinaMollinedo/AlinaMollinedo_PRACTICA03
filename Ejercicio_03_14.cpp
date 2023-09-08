// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 07/09/2023

// Fecha modificación: 08/09/2023

// Número de ejericio: 14

// Problema planteado: Simule una elección de nuestro país Bolivia. En ello se mostrará las elecciones
// por departamento y existirá N candidatos.
// El programa debe pedir la cantidad de votos por departamento y candidato y
// almacenarlos en una matriz.
// El programa debe calcular lo siguiente:
// • Si un candidato gana con el 50% + 1 voto es ganador absoluto.
// • Si no ningún candidato que logre el 50% + 1 voto el programa debe sacar
// los dos mas votados para una segunda vuelta.

#include <iostream>
#include <string>

using namespace std;
int n;
string deps[] = {"LPZ", "SCZ", "CBBA", "TJA", "CHQ", "PSI", "ORU", "BNI", "PND"};

int main(){
    cout << "Ingrese la cantidad de canditados: ";
    cin >> n;

    int votes[9][n], total = 0, totals[n] = {};

    for(int i = 0; i < 9; i++){ // Pide la cantidad de votos por departamento y candidato
        cout << "\nVotos de " << deps[i] << endl;
        cout << "Ingrese los votos por: " << endl;
        for(int j = 0; j < n; j++){
            int vote;
            cout << "Candidato #" << j + 1 << ": ";
            cin >> vote;
            votes[i][j] = vote;
            total += vote;
        }
    }

    for(int i = 0; i < n; i++){ // Suma el total de votos por candidato
        for(int j = 0; j < 9; j++){
            totals[i] += votes[j][i];
        }
    }

    int mostvotes, first, second, h = -1;
    for(int i = 0; i < n; i++){ // Saca el candidato con mas votos
        if(totals[i] > h){
            h = totals[i];
            first = i;
        }
    }
    mostvotes = totals[first]; // Guarda sus votos en mostvotes
    totals[first] = -2;

    h = -1;
    for(int i = 0; i < n; i++){ // Saca el segundo candidato con mas votos
        if(totals[i] > h){
            h = totals[i];
            second = i;
        }
    }
    
    if(mostvotes > (total * 0.5) + 1){ // Decide si hay un ganador o una segunda vuelta
        cout << "\nEl ganador es el candidato #" << first + 1 << "!" << endl;
    }
    else{
        cout << "\nLos dos candidatos mas votados son el candidato #" << first + 1 << " y el candidato #" << second + 1 << endl;
        cout << "Habra una segunda vuelta!" << endl;
    }

    return 0;
}

