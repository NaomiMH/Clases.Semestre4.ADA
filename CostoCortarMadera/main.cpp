/**
 * Naomi Macias Honti a01282098
 * 1 de Marzo 2018
 * Tiempo no estimado.
 * Recibe el tamano de la madera, la cantidad de cortes y el valor donde se hara el corte de la madera. Cada corte tiene un costo diferente dependiendo de la longitud del corte. Se calcula el costo minimo para cortar la madera en los cortes dados.
 */
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    int madera;
    cin >> madera;
    while(madera!=0){
        int n;
        cin >> n;
        n++;
        vector<vector<int>> matriz(n,vector<int> (n,numeric_limits<int>::max()));
        for(int cont=0; cont<n; cont++){
            matriz[cont][cont]=0;
        }
        int arr[n+1];
        arr[0]=0;
        arr[n]=madera;
        for(int cont=1; cont< n; cont++){
            cin >> arr[cont];
        }
        for(int diag=1; diag<n; diag++){
            for(int i=0; i<n-diag; i++){
                int j = i + diag;
                for(int k=i; k<j; k++){
                    matriz[i][j]= min(matriz[i][j],matriz[i][k]+matriz[k+1][j]);
                }
                matriz[i][j]+=(arr[j+1]-arr[i]);
            }
        }
        cout << "The minimum cutting is " << matriz[0][n-1] << "." << endl;
        cin >> madera;
    }
    return 0;
}
