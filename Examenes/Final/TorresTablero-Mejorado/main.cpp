/**
 * Naomi Macias Honti a01282098
 * 6 de mayo 2018
 * 1 hora.
 * Recibe el tamano de un tablero, el numero de torres y las cordenadas de cada torre. Se tiene que mostrar el numero de cuadros que quedan fuera del alcance de las torres.
 */
#include <iostream>
#include <algorithm>

using namespace std;

int calcular(vector<int> coorX, vector<int> coorY)
{
    int maxX=0;
    int maxY=0;
    for(int cont=1; cont<(int)coorX.size(); cont++){
        int dif=coorX[cont]-coorX[cont-1];
        if(dif>1 && dif-1>maxX){
            maxX=dif-1;
        }
    }
    for(int cont=1; cont<(int)coorY.size();cont++){
        int dif=coorY[cont]-coorY[cont-1];
        if(dif>1 && dif-1>maxY){
            maxY=dif-1;
        }
    }
    return maxX*maxY;
}

int main()
{
    int maxX, maxY, tor;
    cin >> maxX >> maxY >> tor;
    vector<int> coorX(tor+2,-1);
    vector<int> coorY(tor+2,-1);
    for(int cont=1; cont<=tor; cont++){
        cin >> coorX[cont] >> coorY[cont];
    }
    coorX[tor+1]=maxX;
    coorY[tor+1]=maxY;
    sort(&coorX[0],&coorX[tor+2]);
    sort(&coorY[0],&coorY[tor+2]);
    cout << calcular(coorX,coorY) << endl;
    return 0;
}
