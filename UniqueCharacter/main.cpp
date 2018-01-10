/**
 * Naomi Macias Honti a01282098
 * 9 de enero 2017
 * 30 min.
 * Recibe un texto de letras en mayusculas, las cuales estan repetidas y seguidas excepto por una, la cual es encontrada y mostrada en pantalla.
 */
#include <iostream>
#include <vector>

using namespace std;

char letraUnica(string palabra)
{
    char l;
    for(int cont=0; cont<=palabra.length();cont++){
        l=palabra[cont];
        if(l!=palabra[cont-1]&&l!=palabra[cont+1])
            return l;
    }
    return '0';
}

int main()
{
    string letras;
    cin >> letras;
    cout << letraUnica(letras) << endl;
    return 0;
}
