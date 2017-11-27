#include<bits/stdc++.h>
using namespace std;
#define s 1010
#define inf 1000000000
int d[s];
int M[s][s];
int S[s][s];
int n;
void MCM(){
    int len;
    for(int j = 1; j <= n; j++){
        M[j][j] = 0;
    }
    for(int len = 2; len <= n; len++){
        for(int i = 1; i <= (n - len+1); i++){
            int j = i + (len-1);
            M[i][j] = inf;
            for(int k = i; k < j; k++){
                int q = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
                if(q < M[i][j]){
                    M[i][j] = q;
                    S[i][j] = k;
                    cout << M[i][j] << endl;
                    //cout << i << " " << j << " " << M[i][j] << endl;
                }
            }
        }
    }
    //return M[1][n];
}

int main(){
    cin >> n;
    for(int i = 0; i <= n; i++){
        cin >> d[i];
    }
    MCM();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << S[i][j] << "\t";
        }
        cout << endl;
    }
}
