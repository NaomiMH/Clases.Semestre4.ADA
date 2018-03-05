#include <bits/stdc++.h>

using namespace std;

string angryProfessor(int k, vector <int> a) {
    int cant=0;
    for(int cont=0; cont<a.size(); cont++){
        if(a[cont]<=0)
            cant++;
    }
    if(cant<k)
        return "YES";
    return "NO";
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        string result = angryProfessor(k, a);
        cout << result << endl;
    }
    return 0;
}
