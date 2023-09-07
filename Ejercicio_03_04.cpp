// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejericio: 4

// Problema planteado: En la segunda temporada de The Walking Dead, los personajes llegaron a una
// cárcel para refugiarse. La cárcel estaba rodeada de vallas por lo que los muertos
// vivientes no podían entrar en ella. Sin embargo, dentro de las instalaciones aun
// existían muertos vivientes que amenazaban a los personajes. Por tanto, Rick y
// otros miembros del grupo decidieron ir a investigar las instalaciones con el fin
// de determinar cuáles eran los lugares seguros. Para lograr su objetivo
// construyeron un mapa basado en una matriz que indicaba las zonas seguras.
// Después de un tiempo, tu grupo llega al mismo complejo y encuentra el mapa
// hecho por Rick. Para mantener a salvo a tus amigos decides diseñar e
// implementar un programa que te ayude a determinar las zonas seguras.

// Tu trabajo es determinar los siguientes datos:
// a) Mostrar la matriz que describe el área.
// b) Mostrar el número de filas y columnas que no tienen un muerto viviente.
// c) Determinar las coordenadas de los muertos vivientes en la matriz. Utilice vectores
// paralelos para almacenar la posición de los muertos vivientes. Un vector almacenara el
// índice de la fila y otro vector almacenara el índice de la columna.
// d) La cantidad de muertos vivientes que existen en toda la matriz.
// e) Determinar si dos o más muertos vivientes se encuentran en la primera columna. Si
// es así imprimir “no es posible entrar al complejo” de otro modo imprimir “es posible
// entrar al complejo”.

#include <iostream>

using namespace std;
int n, m, notsafe = 0;

int main(){
    cout << "Ingrese el numero de filas de la matriz: ";
    cin >> n;
    cout << "Ingrese el numero de columnas de la matriz: ";
    cin >> m;
    cout << endl;

    char matrix[n][m];

    for(int i = 0; i < n; i++){ // Pide al usuario llenar la matriz con las zonas seguras y no seguras
        for(int j = 0; j < m; j++){
            char spot;
            cout << "Ingrese si la posicion " << i + 1 << " " << j + 1 << " es segura o no : ";
            cin >> spot;
            matrix[i][j] = spot;
            if(spot == 'x'){ // Cuenta la cantidad de muertos vivientes
                notsafe++;
            }
        }
        cout << endl;
    }

    cout << "\na) Mostrar matriz:" << endl;

    for(int i = 0; i < n; i++){ // Imprime la matriz
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nb)\n";

    int saferow = 0, safecol = 0, rowpos[notsafe], colpos[notsafe], pos = 0;

    for(int i = 0; i < n; i++){
        bool safe = true;
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 'x'){ // Determina si una fila es segura o no
                safe = false; 
                // Almacenan las posiciones de los muertos vivientes
                rowpos[pos] = i;
                colpos[pos] = j;
                pos++;
            }
        }
        if(safe){
            saferow++; // Cuenta las filas seguras
        }
    }

    for(int i = 0; i < m; i++){
        bool safe = true;
        for(int j = 0; j < n; j++){
            if(matrix[j][i] == 'x'){ // Determina si una columna es segura o no
                safe = false; 
            }
        }
        if(safe){
            safecol++; // Cuenta las columnas seguras
        }
    }

    cout << "Filas libres: " << saferow << endl;
    cout << "Columnas libres: " << safecol << endl;

    cout << "\nc) Posiciones en la matriz: " << endl;

    for(int i = 0; i < notsafe; i++){
        cout << rowpos[i] << " -- " << colpos[i] << endl;
    }

    cout << "\nd) Total de muertos vivientes: " << notsafe << endl;

    int counter = 0;
    for(int i = 0; i < m; i++){
        if(matrix[0][i] == 'x'){ // Cuenta cuantos muertos vivientes hay en la columna 0
            counter++;
        }
    }
    if(counter > 1){
        cout << "\nd) Es posible entrar al complejo!" << endl;
    }
    else{
        cout << "\nd) No es posible entrar al complejo!" << endl;
    }
    
    return 0;
}