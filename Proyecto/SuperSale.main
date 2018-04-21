/**
 * Naomi Macias Honti a01282098
 * 20 de abril 2018
 * Tiempo no estimado.
 * Recibe un numero de casos, cada caso tiene una cantidad de objetos, con su respectivo valor y peso, y una cantidad de personas, con el respectivo peso que pueden llevar. Se muestra el valor maximo que se puede llevar todas las personas sin exceder el peso maximo que pueden llevar.
 */
#include <iostream>
#include <algorithm>

using namespace std;

struct lista
{
    int peso;
    int valor;
    int vaPe;
};

bool comp2Ele (lista m, lista n)
{
    return (m.vaPe>n.vaPe);
}

void busca (int cont, vector<lista> obj, int valorAcum, int pesoAcum, int &valorMax, int pesoMax)
{
    if(cont<(int)obj.size() && pesoAcum<=pesoMax){
        if(valorAcum>valorMax){
            valorMax=valorAcum;
        }
        int pesoPos,cont2;
        double valorPos;
        valorPos=valorAcum;
        pesoPos=pesoAcum;
        for(cont2=cont+1; cont2<obj.size() && pesoPos+obj[cont2].peso<=pesoMax; cont2++){
            pesoPos+=obj[cont2].peso;
            valorPos+=obj[cont2].valor;
        }
        if(cont2<obj.size()){
            valorPos+=(obj[cont2].vaPe*(pesoMax-pesoPos));
        }
        if(valorPos>valorMax){
            busca(cont+1,obj,valorAcum+obj[cont+1].valor,pesoAcum+obj[cont+1].peso,valorMax,pesoMax);
            busca(cont+1,obj,valorAcum,pesoAcum,valorMax,pesoMax);
        }
    }
}

int main()
{
    int casos;
    cin >> casos;
    while(casos>0){
        int cantObj;
        cin >> cantObj;
        vector<lista> obj(cantObj);
        for(int cont=0; cont<cantObj; cont++){
            int peso, valor;
            cin >> valor >> peso;
            obj[cont].valor=valor;
            obj[cont].peso=peso;
            obj[cont].vaPe=valor*1.0/peso;
        }
        sort(obj.begin(),obj.end(),comp2Ele);
        int personas,valorUlt;
        valorUlt=0;
        cin >> personas;
        for(int cont=0; cont<personas; cont++){
            int peso,valorMax;
            valorMax=0;
            cin >> peso;
            busca(-1,obj,0,0,valorMax,peso);
            valorUlt+=valorMax;
        }
        cout << valorUlt << endl;
        casos--;
    }
    return 0;
}
