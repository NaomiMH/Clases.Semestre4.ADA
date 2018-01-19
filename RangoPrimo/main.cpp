/**
 * Naomi Macias Honti a01282098
 * 19 de enero 2017
 * Tiempo no estimado.
 * Recibe primero un numero x de la cantidad de numeros y a ser ingresados, despues saca x parejas de numeros que son los primos (menor y mayor) mas cercanos a cada numero y.
 */
#include <iostream>

using namespace std;

int main()
{
    int cant;
    int primos[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    cin >> cant;
    int dato;
    int rango[cant][2];
    bool estado=false;
    for(int cont=0; cont<cant; cont++){
        cin >> dato;
        estado = false;
        for(int cont2=0; cont2<25 && !estado; cont2++){
            if(primos[cont2]==dato){
                rango[cont][0]=rango[cont][1]=dato;
                estado = true;
            }
            else if(primos[cont2]>dato && primos[cont2-1]<dato){
                rango[cont][0]=primos[cont2-1];
                rango[cont][1]=primos[cont2];
                estado = true;
            }
            else if(cont2==16){
                rango[cont][0]=rango[cont][1]=-1;
            }
        }
    }
    for(int cont=0; cont<cant; cont++){
        cout << rango[cont][0] << " " << rango[cont][1] << endl;
    }
    return 0;
}
