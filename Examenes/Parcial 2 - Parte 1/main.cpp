/**
 * Naomi Macias Honti a01282098
 * 11 de Febrero 2018
 * 28 min.
 * Recibe dos strings, busca que los caracteres del segundo string esten en orden, no necesariamente seguidos, dentro del primer string.
 */
#include <iostream>

using namespace std;

bool busca1(string s1, string s2)
{
    if(s2=="")
        return true;
    if(s1.find(s2[0])==-1)
        return false;
    return busca1(s1.substr(s1.find(s2[0])+1),s2.substr(1,s2.length()-1));
}

string voltea(string s)
{
    string sFinal="";
    for (int cont=s.length(); cont>=0; cont--)
        sFinal+=s[cont];
    return sFinal.erase(0,1);
}

int main()
{
    string oracion1,oracion2;
    cin >> oracion1;
    cin >> oracion2;
    if(busca1(oracion1,oracion2) || busca1(oracion1,voltea(oracion2)))
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
