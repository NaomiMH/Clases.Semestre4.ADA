/**
 * Naomi Macias Honti a01282098
 * 6 de mayo 2018
 * Tiempo no estimado.
 * Suma de los elementos potenciales de 3, desde 3^0 hasta 3^k, donde 3^k es menor o igual a n.
 */
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << (pow(3,(log(n)/log(3))+1)-1)/(3-1);
    return 0;
}
