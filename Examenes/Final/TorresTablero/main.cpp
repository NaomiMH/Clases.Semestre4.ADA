/**
 * Naomi Macias Honti a01282098
 * 6 de mayo 2018
 * 1 hora y 25 min.
 * Recibe el tamano de un tablero, el numero de torres y las cordenadas de cada torre. Se tiene que mostrar el numero de cuadros que quedan fuera del alcance de las torres.
 */
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tablero;

int calcular(int x, int y, int maxX, int maxY)
{
    int grp=0;
    if(x<maxX && y<maxY){
        if(tablero[x][y]==1){
            tablero[x][y]==2;
            return max(calcular(x+1,y,maxX,maxY),calcular(x,y+1,maxX,maxY));
        }
        else if(tablero[x][y]==0){
            int contX,contY;
            for(contX=x; contX<maxX && tablero[contX][y]==0; contX++){
                for(contY=y; contY<maxY && tablero[contX][contY]==0; contY++){
                    grp++;
                    tablero[contX][contY]==2;
                }
            }
            if(contX<maxX && contY<maxY){
                if(tablero[contX][contY]!=2){
                    if(tablero[x][contY]!=2){
                        if(tablero[contX][y]!=2)
                            return max(grp,max(calcular(contX,contY,maxX,maxY),max(calcular(x,contY,maxX,maxY),calcular(contX,y,maxX,maxY))));
                        return max(grp,max(calcular(contX,contY,maxX,maxY),calcular(x,contY,maxX,maxY)));
                    }
                    return max(grp,calcular(contX,contY,maxX,maxY));
                }
                else if(tablero[x][contY]!=2){
                    if(tablero[contX][y]!=2)
                        return max(grp,max(calcular(x,contY,maxX,maxY),calcular(contX,y,maxX,maxY)));
                    return max(grp,calcular(x,contY,maxX,maxY));
                }
                else if(tablero[contX][y]!=2)
                    return max(grp,calcular(contX,y,maxX,maxY));
            }
            return grp;
        }
    }
    return 0;
}

int main()
{
    int maxX, maxY, tor;
    cin >> maxX >> maxY >> tor;
    vector<vector<int>> temp(maxX,vector<int>(maxY,0));
    tablero = temp;
    for(int cont=0; cont<tor; cont++){
        int x,y;
        cin >> x >> y;
        for(int cont1=0; cont1<maxY; cont1++){
            tablero[x][cont1]=1;
        }
        for(int cont2=0; cont2<maxX; cont2++){
            tablero[cont2][y]=1;
        }
    }
    cout << calcular(0,0,maxX,maxY) << endl;
    return 0;
}
