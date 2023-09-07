// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 07/09/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 13

// Problema planteado: La farmacia FARMACARP tiene N sucursales, leer sus ventas por mes de un
// año entero de cada sucursal y calcule:
// a. Total, de ventas
// b. Total, de ventas por sucursal.
// c. Sucursal que más ha vendido.
// d. Sucursal que menos ha vendido.

#include <iostream>
#include <string>

using namespace std;
int n, total = 0;
string months[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

int main(){
    cout << "Ingrese el numero de sucursales: ";
    cin >> n;

    int totals[n] = {};

    for(int i = 0; i < n; i++){ // Pide los datos de n sucursales
        cout << "\nSucursal " << i + 1 << ": " << endl;
        for(int j = 0; j < 12; j++){ // Pide las ventas de los 12 meses del año
            int sale;
            cout << "Ingrese las ventas de " << months[j] << ": ";
            cin >> sale;
            totals[i] += sale; // Suma las ventas de cada sucursal
            total += sale; // Suma las ventas totales
        }
    }

    int highest = -1, lowest = 100000, hstore = 0, lstore = 0;
    for(int i = 0; i < n; i++){
        if(totals[i] > highest){ // Determina la sucursal que vendio mas
            hstore = i;
            highest = totals[i];
        }
        if(totals[i] < lowest){ // Determina la sucursal que vendio menos
            lstore = i;
            lowest = totals[i];
        }
    }

    cout << "\nEl total de ventas es: Bs." << total << endl;
    cout << "El total de ventas por sucursal es: " << endl;
    for(int i = 0; i < n; i++){
        cout << "- Sucursal " << i + 1 << ": Bs." << totals[i] << endl;
    }
    cout << "La sucursal que más ha vendido es la Sucursal " << hstore + 1 << endl;
    cout << "La sucursal que menos ha vendido es la Sucursal " << lstore + 1 << endl;

    return 0;
}