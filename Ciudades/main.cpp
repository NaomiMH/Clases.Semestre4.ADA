/**
 * Naomi Macias Honti a01282098
 * 23 de Febrero 2018
 * Tiempo no estimado.
 * Recibe una cantidad de casos. Cada caso tiene una cantidad de ciudades (n), caminos (arista) y pedidos (query). Cada camino tiene un inicio, final y tiempo de viaje. Cada pedido pide un costo de tiempo de un lugar a otro.
 */
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main()
{
    int vueltas;
    cin >> vueltas;
    for(int cont=1; cont<=vueltas; cont++){
        cout << "Case " << cont << ":" << endl;
        int n;
        cin >> n;
        vector<vector<int>> matriz(n,vector<int> (n,numeric_limits<int>::max()));
        int arista;
        cin >> arista;
        int query;
        cin >> query;
        for(int cont=0; cont<arista; cont++){
            int num1;
            int num2;
            int val;
            cin >> num1;
            cin >> num2;
            cin >> val;
            num1--;
            num2--;
            matriz[num1][num2]=val;
            matriz[num2][num1]=val;
        }
        for(int cont=0; cont<n; cont++){
            matriz[cont][cont]=0;
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    matriz[i][j] = min(matriz[i][j],max(matriz[i][k],matriz[k][j]));
                }
            }
        }
        for(int cont=0; cont<query; cont++){
            int del;
            int al;
            cin >> del;
            cin >> al;
            del--;
            al--;
            if(matriz[del][al] != numeric_limits<int>::max())
                cout << matriz[del][al] << endl;
            else
                cout << "no path" << endl;
        }
    }
    return 0;
}
