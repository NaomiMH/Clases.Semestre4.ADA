#include <bits/stdc++.h>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main()
{
    int n, arista;
    cin >> n >> arista;
    vector<vector<int>> matriz(n,vector<int> (n,numeric_limits<int>::max()));
    for(int cont=0; cont<n; cont++){
        matriz[cont][cont]=0;
    }
    
    for(int cont=0; cont<arista; cont++){
        int num1, num2, val;
        cin >> num1 >> num2 >> val;
        num1--;
        num2--;
        matriz[num1][num2]=val;
    }
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matriz[i][k]!=numeric_limits<int>::max() && matriz[k][j]!=numeric_limits<int>::max())
                    matriz[i][j] = min(matriz[i][j],matriz[i][k]+matriz[k][j]);
            }
        }
    }
    vector <int> result;
    int query;
    cin >> query;
    for(int cont=0; cont<query; cont++){
        int del, al;
        cin >> del >> al;
        del--;
        al--;
        if(matriz[del][al] != numeric_limits<int>::max())
            result.push_back(matriz[del][al]);
        else
            result.push_back(-1);
    }

    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
