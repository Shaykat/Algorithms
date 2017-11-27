#include<bits/stdc++.h>
using namespace std;
int a[4][4],flag = 0,t=1;
bool check(int a[][]){
    t = 1;
    for(int i = 1;i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            if(i == 3){
                cout << a[i][j] << " l";
                if(t != a[i][j] && j != 3){
                    flag = 1;
                    //break;
                }
            }
            else{
                cout << a[i][j] << " ";
                if(t != a[i][j]){
                    flag = 1;
                    //break;
                }
            }
            t++;
        }
        cout << endl;
        if(flag == 1) break;
    }
    //cout << flag << endl;
    if(flag) return false;
    return true;
}
int pazzle(int i, int j,int b[]){

    if(check(int b)){
        return true;
    }
    int cnt = 1000000000,cnt2 = 1000000000,cnt3 = 1000000000,cnt4 = 1000000000;
    if(i < 3){
        cnt = min(cnt,pazzle(swap(b[i+1],b[j]))+1);
    }
    if(j < 3){
        cnt = min(cnt,pazzle(swap(b[i],b[j+1]))+1);
    }
    if(i > 1){
        cnt = min(cnt,pazzle(swap(b[i-1],b[j]))+1);
    }
    if(j > 1){
        cnt = min(cnt,pazzle(swap(b[i],b[j-1]))+1);
    }
    return cnt;
}

int main(){
    int p,q;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            cin >> a[i][j];
            if(a[i][j] == 0) {
                p = i;
                q = j;
            }
        }
    }

    cout << pazzle(p,q) << endl;
}
