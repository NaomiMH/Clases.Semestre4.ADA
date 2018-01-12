/**
 * Naomi Macias Honti a01282098
 * 12 de enero 2017
 * 16 min.
 * Se da una longitud de un string y el string, a partir de lo cual se tiene que regresar la cantidad de numeros que quedarian si se eligieran aleatoriamente dos numeros y dichos numeros fueran borrados siempre que resultaran ser un 0 y un 1.
 */
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int suma=0;
    char dato;
    for(int cont=0;cont<num;cont++){
        cin >> dato;
        if(dato==49)
            suma++;
    }
    cout << abs(num-suma*2) << endl;
    return 0;
}
