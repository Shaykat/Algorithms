#include<bits/stdc++.h>
using namespace std;

// input output
#define pf              printf
#define sf(n)           scanf("%d", &n)
#define sfl(n)          scanf("%lld", &n)
#define sfc(n)          scanf("%c", &n)
#define sff(a,b)        scanf("%d %d", &a, &b)
#define sfff(a,b,c)     scanf("%d %d %d", &a, &b, &c)
#define INP             freopen("in.txt", "r", stdin);  // file input
#define OUT             freopen("out.txt", "w", stdout);  // file output

// operations
#define pb              push_back
#define ppb             pop_back
#define mem(n, val)     memset((n), val, sizeof(n))
#define mp              make_pair
#define ff first
#define se second

// constant
#define MOD             1000000007
#define inf             1<<30                                           //infinity value
#define eps             1e-9

// Loop
#define For(i, a, b)    for(int i = a; i <= b; i++)
#define Ror(i, a, b)    for(int i = a; i >= b; i--)
#define all(v)          v.begin(), v.end()

// functions
#define gcd(a,b)        ll _gcd(int a,int b){ if(b%a == 0) return a; _gcd(b%a,a); }
#define lcm(a,b)        ((a*b)/gcd(a,b))

// binary tree || segment tree
#define cnd             tr[idx]
#define lnd             tr[idx << 1]
#define rnd             tr[lnd + 1]
#define leftcl          lnd,st,mid
#define rightcl         rnd,mid+1,ed

// compare
// functions
#define cmpr            bool compare(const pair<int,int>&i,const pair<int,int>&j)   {return i.first < j.first;}
#define tostring(a)     string To_Upper(string a)   {for(int i = 0;i < a.size()-1;i++){  if(islower(a[i])) a[i] = toupper(a[i]); } return a; }

// typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<int, string> pis;
typedef priority_queue<int> pq;

// manual division
int divide(string a,int base)   {int b = a.size(),c = 0,r = 0,i = 0;
    while(i < b)    {c = c*base + a[i++]-'0';
    if(c/b > 0) {r = r*base + c/b; c = c%b;}}
    if(c == 0) return r;
    return 0;
}

// binary operations
int Bset(int N,int pos){return N=N | (1<<pos);}
int Breset(int N,int pos){return N= N & ~(1<<pos);}
bool Bcheck(int N,int pos){return (bool)(N & (1<<pos));}
// @Shaykat@
/////////////////////////////////// template //////////////////////////////

map<int,string>Map;
vector<int>numa;
stack<string>roman;
string input;

void mapping(){
    Map[1] = "I";
    Map[5] = "V";
    Map[10] = "X";
    Map[50] = "L";
    Map[100] = "C";
    Map[500] = "D";
    Map[1000] = "M";
}

/*void int_to_Roman_Converter(){
    int p = input.size(),dec = 1,temp = 0;
    Ror(i,p-1,0){
        temp = 0;
        if(input[i] == '0'){
            while(input[i] != '0'){
                temp = temp + (input[i]+'0')*dec;
                i--;
                dec *= 10;
            }
            temp = temp + (input[i]+'0')*dec;
            To_Roman(temp);
        }
        else{
            temp = dec*(input[i]+'0');
            To_Roman(temp);
        }
        dec *= 10;
    }
}*/

void To_Roman(int num){
    if(Map.find(num) != Map.end()){
        roman.push(Map[num]);
    }
    else if((num%100 == 0 && num/100 == 9) || (num%10 == 0 && num/10 == 9) || num == 9) {
        if(num == 9) {
            roman.push(Map[10]);
            roman.push(Map[1]);
        }
        else if(num%9 == 0 && num%100 == 0) {
            roman.push(Map[1000]);
            roman.push(Map[100]);
        }
        else if(num%9 == 0 && num%10 == 0) {
            roman.push(Map[100]);
            roman.push(Map[10]);
        }
    }
    else if((num%100 == 0 && (num/100 >= 6 && num/100 <= 8)) || (num%10 == 0 && (num/10 >= 6 && num/10 <= 8)) || (num >= 6 && num <= 8)){
        if(num >= 6 && num <= 8){
            For(i,0,num-6){
                roman.push(Map[1]);
            }
            roman.push(Map[5]);
        }
        else if((num%6 == 0 || num%7 == 0 || num%8 == 0) && (num%100 == 0)) {
            For(i,0,(num/100)-6){
                roman.push(Map[100]);
            }
            roman.push(Map[500]);
        }
        else if((num%6 == 0 || num%7 == 0 || num%8 == 0) && (num%10 == 0)) {
            For(i,0,(num/10)-6){
                roman.push(Map[10]);
            }
            roman.push(Map[50]);
        }
    }
    else if((num%1000 == 0 && num/1000 == 4) || (num%100 == 0 && num/100 == 4) || (num%10 == 0 && num/10 == 4) || num == 4) {
        if(num == 4) {
            roman.push(Map[5]);
            roman.push(Map[1]);
        }
        else if(num%4 == 0 && num%1000 == 0) {
            //cout << num << endl;
            For(i,0,3){
                roman.push(Map[1000]);
            }
        }
        else if(num%4 == 0 && num%100 == 0) {
            //cout << num << endl;
            roman.push(Map[500]);
            roman.push(Map[100]);
        }
        else if(num%4 == 0 && num%10 == 0) {
            //cout <<num << endl;
            roman.push(Map[50]);
            roman.push(Map[10]);
        }
    }
    else if((num%1000 == 0 && (num/1000 >= 2 && num/1000 <= 3)) || (num%100 == 0 && (num/100 >= 2 && num/100 <= 3)) || (num%10 == 0 && (num/10 >= 2 && num/10 <= 3)) || (num >= 2 && num <= 3)){
        if(num >= 1 && num <= 3){
            For(i,0,num-1){
                roman.push(Map[1]);
            }
        }
        else if((num%2 == 0 || num%3 == 0) && (num%1000 == 0)) {
            For(i,0,(num/1000)-1){
                roman.push(Map[1000]);
            }
        }
        else if((num%2 == 0 || num%3 == 0) && (num%100 == 0)) {
            For(i,0,(num/100)-1){
                //cout << num << endl;
                roman.push(Map[100]);
            }
        }
        else if((num%2 == 0 || num%3 == 0) && (num%10 == 0)) {
            For(i,0,(num/10)-1){
                roman.push(Map[10]);
            }
        }
    }
}


int main(){
    pf("Enter The Input String: ");
    cin >> input;
    mapping();
    //int_to_Roman_Converter();

    //******************
    int p = input.size(),dec = 1,temp = 0;
    if(p == 4 && input[0]-'0' >= 5){
        cout << "Please Enter a Number less Then 5000!\nThank You.!\n";
        return 0;
    }
    Ror(i,p-1,0){
        temp = 0;
        if(input[i] == '0'){
            while(input[i] == '0'){
                //cout << input[i];
                temp = temp + (input[i]-'0')*dec;
                i--;
                dec *= 10;
            }
            temp = temp + (input[i]-'0')*dec;
            //cout << input[i] << " " << i << endl;
            To_Roman(temp);
        }
        else{
            temp = dec*(input[i]-'0');
            To_Roman(temp);
        }
        dec *= 10;
    }
    //***********************
    while(!roman.empty()){
        cout << roman.top();
        roman.pop();
    }

    return 0;
}
