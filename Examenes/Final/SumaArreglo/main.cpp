/**
 * Naomi Macias Honti a01282098
 * 6 de mayo 2018
 * Tiempo no estimado.
 * Recibe un tamano de arreglo y numeros aleatorios enteros. Regresa la diferencia mas grande entre los enteros.
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int cont=0; cont<n; cont++){
        cin >> arr[cont];
    }
    sort(&arr[0],&arr[n]);
    cout << arr[n-1]-arr[0];
    return 0;
}
