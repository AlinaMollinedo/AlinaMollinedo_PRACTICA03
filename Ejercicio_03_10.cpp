// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 07/09/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 10

// Problema planteado: Queremos realizar una encuesta a 10 personas, en esta encuesta indicaremos el
// sexo (1=masculino, 2=femenino), si trabaja (1=si trabaja, 2= no trabaja) y su
// sueldo (si tiene un trabajo, sino sera un cero) estará entre 600 y 2000 (valor
// entero). Los valores pueden ser generados aleatoriamente. Calcula y muestra lo
// siguiente:
// • Porcentaje de hombres (tengan o no trabajo).
// • Porcentaje de mujeres (tengan o no trabajo).
// • Porcentaje de hombres que trabajan.
// • Porcentaje de mujeres que trabajan.
// • El sueldo promedio de las hombres que trabajan.
// • EL sueldo promedio de las mujeres que trabajan

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct people{
    int sexo, employed, salary;
};

int main(){
    srand(time(NULL));
    people person[10];

    for(int i = 0; i < 10; i++){ // Asigna valores al azar a 10 personas
        int s = 1 + rand() % 2, e = 1 + rand() % 2, sal = 600 + rand() % (2000 - 600);
        person[i] = (people){.sexo = s, .employed = e, .salary = sal};
        cout << "Persona " << i + 1 << ": " << person[i].sexo << " " << person[i].employed << " " << person[i].salary << endl;
    }

    double male = 0, female = 0, emplmale = 0, emplfemale = 0, malemean = 0, femalemean = 0;
    for(int i = 0; i < 10; i++){
        if(person[i].sexo == 1){ 
            male++; // Cuenta los hombres
            if(person[i].employed == 1){ 
                emplmale++; // Cuenta los hombres que trabajan
                malemean += person[i].salary; // Suma sus salarios
            }
        }
        else{
            female++; // Cuenta las mujeres
            if(person[i].employed == 1){
                emplfemale++; // Cuenta las mujeres que trabajan
                femalemean += person[i].salary; // Suma sus salarios
            }
        }
    }

    cout << "\nPorcentaje de hombres (tengan o no trabajo): " << male * 10 << "%" << endl;
    cout << "Porcentaje de mujeres (tengan o no trabajo): " << female * 10 << "%" << endl;
    cout << "Porcentaje de hombres que trabajan: " << emplmale * 100 / male << "%" << endl;
    cout << "Porcentaje de mujeres que trabajan: " << emplfemale * 100 / female << "%" << endl;
    cout << "Sueldo promedio de las hombres que trabajan: Bs." << malemean / emplmale << endl;
    cout << "Sueldo promedio de las mujeres que trabajan: Bs." << femalemean / emplfemale << endl;
    return 0;
}