/**
 * Naomi Macias Honti a01282098
 * 9 de Marzo 2018
 * Tiempo no estimado.
 * Recibe datos acomodados en forma de arbol, cada padre tiene dos hijos y el hijo de la izquierda se comparte con el padre de la izquierda, o de la derecha respectivamente. Suma al padre el hijo que de el mayor numero. Finalmente muestra el valor final de la raiz.
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int numCasos,cont=0;
    cin >> numCasos;
    while(cont<numCasos){
        int n;
        cin >> n;
        vector<vector<int>> matriz(n);
        for(int cont2=0; cont2<n; cont2++){
            for(int cont3=0; cont3<=cont2; cont3++){
                int num;
                cin >> num;
                matriz[cont2].push_back(num);
            }
        }
        for(int cont2=n-2; cont2>=0; cont2--){
            for(int cont3=0; cont3<=cont2; cont3++){
                matriz[cont2][cont3]=max(matriz[cont2][cont3]+matriz[cont2+1][cont3],matriz[cont2][cont3]+matriz[cont2+1][cont3+1]);
            }
        }
        cout << matriz[0][0];
        cont++;
    }
    return 0;
}
