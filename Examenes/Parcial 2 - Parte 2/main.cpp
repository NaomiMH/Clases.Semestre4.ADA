/**
 * Naomi Macias Honti a01282098
 * 11 de Febrero 2018
 * Tiempo no estimado.
 * Recibe la cantidad de cuartos y pasillos, cada pasillo contiene un lugar de inicio, final y un costo. Recibe la cantidad de pedidos, cuales tienen los siguientes eventos:
 * B - bloqueo de la calle que conecta i con j
 * D - desbloqueo de la calle que conecta i con j
 * P - pavimentación (reducción de carriles) de la calle que conecta i con j
 * T - terminación de pavimento  de la calle que conecta i con j
 * C - consulta de el tiempo para ir de i a j
 */
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    int cuartos,pasillos;
    cin >> cuartos >> pasillos;
    vector<vector<int>> matriz(cuartos,vector<int> (cuartos,numeric_limits<int>::max()));
    vector<vector<int>> matrizOrig;

    for(int cont1=0; cont1<cuartos; cont1++){
        matriz[cont1][cont1]=0;
    }
    for(int cont=0; cont<pasillos; cont++){
        int num1, num2, val;
        cin >> num1 >> num2 >> val;
        num1--;
        num2--;
        matriz[num1][num2]=matriz[num2][num1]=val;
    }
    matrizOrig = matriz;


    int pedidos;
    cin >> pedidos;
    for(int cont=0; cont<pedidos; cont++){
        char dato;
        cin >> dato;
        int num1, num2;
        switch (dato)
        {
        case 'b':
            //bloqueo de la calle que conecta i con j
            //a veces bloquean calles sin poder transitar por un tiempo
            cin >> num1 >> num2;
            num1--;
            num2--;
            matriz[num1][num2]=matriz[num2][num1]=numeric_limits<int>::max();
            break;
        case 'd':
            //desbloqueo de la calle que conecta i con j
            cin >> num1 >> num2;
            num1--;
            num2--;
            matriz[num1][num2]=matriz[num2][num1]=matrizOrig[num1][num2];
            break;
        case 'p':
            //pavimentación (reducción de carriles) de la calle que conecta i con j
            //a veces simplemente reducen carriles lo cual duplica el tiempo de transito en esa calle en un determinado momento
            cin >> num1 >> num2;
            num1--;
            num2--;
            matriz[num1][num2]=matriz[num2][num1]=matriz[num2][num1]*2;

            break;
        case 't':
            //terminación de pavimento  de la calle que conecta i con j
            cin >> num1 >> num2;
            num1--;
            num2--;
            matriz[num1][num2]=matriz[num2][num1]=matriz[num2][num1]/2;

            break;
        case 'q':
            //consulta de el tiempo para ir de i a j
            int del, al;
            cin >> del >> al;
            del--;
            al--;

            vector<int> matrizCosto(cuartos,numeric_limits<int>::max());
            vector<bool> matrizEncont(cuartos,false);
            for(int cont1=0; cont1<cuartos; cont1++){
                matrizCosto[cont1]=matriz[del][cont1];
            }

            for(int cont1=1; cont1<cuartos; cont1++){
                int costMin = numeric_limits<int>::max();
                int camMin = 0;
                for(int a=0; a<cuartos; a++){
                    if(!matrizEncont[a] && 0<matrizCosto[a] && matrizCosto[a]<costMin){
                        costMin = matrizCosto[a];
                        camMin = a;
                    }
                }
                for(int b=0; b<cuartos; b++){
                    if(matriz[camMin][b]!=numeric_limits<int>::max() && matriz[camMin][b]+ matrizCosto[camMin] < matrizCosto[b]){
                        matrizCosto[b] = matriz[camMin][b]+ matrizCosto[camMin];
                    }
                }
                matrizEncont[camMin]=true;
            }

            cout << matrizCosto[al] << endl;
            break;
        }

    }
    return 0;
}
