/**
 * Naomi Macias Honti a01282098
 * 16 de Marzo 2018
 * Tiempo no estimado.
 * Recibe una cantidad de casos. Cada caso tiene una cantidad de cuartos y pasillos. Los pasillos tienen lugar de inicio, final y un costo. Se calculan los costos menores para cada camino y se muestra el mas costoso.
 */
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    int casos;
    cin >> casos;
    for(int cont=0; cont<casos; cont++){
        int cuartos,pasillos;
        cin >> cuartos >> pasillos;
        vector<vector<int>> matriz(cuartos,vector<int> (cuartos,numeric_limits<int>::max()));

        for(int cont1=0; cont1<cuartos; cont1++){
            matriz[cont1][cont1]=0;
        }
        for(int cont1=0; cont1<pasillos; cont1++){
            char letra1,letra2;
            int costo;
            cin >> letra1 >> letra2 >> costo;
            matriz[letra1-'A'][letra2-'A']= matriz[letra2-'A'][letra1-'A'] = costo;
        }

        vector<int> matrizCosto(cuartos,numeric_limits<int>::max());
        vector<bool> matrizEncont(cuartos,false);
        for(int cont1=0; cont1<cuartos; cont1++){
            matrizCosto[cont1]=matriz[0][cont1];
        }

        for(int cont1=1; cont1<cuartos; cont1++){
            int costMin = numeric_limits<int>::max();
            int camMin = 0;
            for(int a=1; a<cuartos; a++){
                if(!matrizEncont[a] && 0<matrizCosto[a] && matrizCosto[a]<costMin){
                    costMin = matrizCosto[a];
                    camMin = a;
                }
            }
            for(int b=1; b<cuartos; b++){
                if(matriz[camMin][b]!=numeric_limits<int>::max() && matriz[camMin][b]+ matrizCosto[camMin] < matrizCosto[b]){
                    matrizCosto[b] = matriz[camMin][b]+ matrizCosto[camMin];
                }
            }
            matrizEncont[camMin]=true;
        }
        int mayor=matrizCosto[0];
        char maxCaso= 'A';
        for(int cont1=1; cont1<cuartos; cont1++){
            if(matrizCosto[cont1] > mayor){
                mayor=matrizCosto[cont1];
                maxCaso = cont1+ 'A';
            }
        }
        cout << "Case " << cont+1 << ": " << maxCaso << endl;
    }
    return 0;
}
