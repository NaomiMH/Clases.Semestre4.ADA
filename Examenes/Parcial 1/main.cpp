/**
 * Naomi Macias Honti a01282098
 * 11 de Febrero 2018
 * 19 min.
 * Recibe una oracion, voltea el orden de las palabras usando recursividad.
 */
#include <iostream>
#include <string>

using namespace std;

string voltea(string oracion)
{
    if(oracion.find(" ")==-1)
        return oracion.substr(0,oracion.find(" "));
    else
        return voltea(oracion.substr(oracion.find(" ")+1,oracion.length()-oracion.find(" ")+1)) + " " + oracion.substr(0,oracion.find(" "));
}

int main()
{
    string oracion;
    getline(cin,oracion);
    cout << voltea(oracion) << endl;
    return 0;
}
