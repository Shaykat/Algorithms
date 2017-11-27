#include<bits/stdc++.h>
using namespace std;

string inputString[5];
int decArray[5],fx[5],fita[5];
double sum = 0, avg = 0, mx = 0, sumr = 0,mxr = 0;
double fit[5],avgf = 0, avgr = 0,mxf = 0,sumf = 0;
string str1,str2;

void init(){
    sum = 0;
    avg = 0;
    mx = 0;
    mxr = 0;
    mxf = 0;
    sumr = 0;
    avgf = 0;
    avgr = 0;
    mxf = 0;
    sumf = 0;
}
int dec(string binr){
    int f = 1,l = binr.size();
    int deci = 0;
    for(int i = l-1; i >= 0; i--){
        if(binr[i] == '1'){
            deci += f;
        }
        f *= 2;
    }
    return deci;
}

void decConvert(){
    for(int i = 0; i < 4; i++){
        decArray[i] = dec(inputString[i]);
        fx[i] = decArray[i]*decArray[i];
        sum += fx[i];
        if(fx[i] > mx) mx = fx[i];
    }
    avg = sum/4;
}

void fitness(){
    for(int i = 0; i < 4; i++){
        fit[i] = round(fx[i]/avg);
        fita[i] = round(fit[i]);
        sumf += fit[i];
        sumr += fita[i];
        if(fit[i] > mxf)    mxf = fit[i];
        if(fita[i] > mxr)    mxr = fita[i];
    }
    avgf = sumf/4;
    avgr = sumr/4;
}
void str_Cut(string p,int pos){
    int  l = p.size();
    str1 = "", str2 = "";
    for(int i = 0; i < pos; i++){
        str1 += p[i];
    }

    for(int i = pos; i < l; i++){
        str2 += p[i];
    }
}

void crosOver(int a, int b){
    string ind11,ind12,ind21,ind22;
    str_Cut(inputString[0],a);
    ind11 = str1;
    ind12 = str2;
    str_Cut(inputString[1],a);
    ind21 = str1;
    ind22 = str2;

    inputString[0] = ind11+ind22;
    inputString[1] = ind21+ind12;

    str_Cut(inputString[2],b);
    ind11 = str1;
    ind12 = str2;
    str_Cut(inputString[3],b);
    ind21 = str1;
    ind22 = str2;
    inputString[2] = ind11+ind22;
    inputString[3] = ind21+ind12;
}

bool check(){
     for(int i = 0; i < 4; i++){
        int v = dec(inputString[i]);
        if(v == 31) return true;
    }
    return false;
}

void input(){
    cout << "Enter Chromosome set: \n";
    for(int i = 0; i < 4; i++){
        cin >> inputString[i];
    }
}

void mutation(int a,int b){
    char p = inputString[a][b];
    if(p == '0'){
        inputString[a][b] = '1';
    }
    else{
        inputString[a][b] = '0';
    }
}


int main(){
    input();

    /*for(int i = 0; i < 4; i++){
        cout << inputString[i] << endl;
    }*/
    decConvert();
    fitness();
    crosOver(4,2);
    mutation(2,3);
    /*int cnt = 0;
    while(check() == false){
        cnt++;
        decConvert();
        fitness();
        crosOver(4,2);
        mutation(2,3);
        init();
    }
*/
    for(int i = 0; i < 4; i++){
        cout << inputString[i] << endl;
    }
    //cout << cnt << endl;*/
    return 0;
}

/*
    01101
    11000
    01000
    10011
*/
