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
vector<int>G[1010];
vector<int>comp[1010];
stack<int>S;
bool stackmem[2010],color[2010];
int dis[1010],low[1010];
int n,e,t = 1,cmp = 1;

void dfs(int u){
    color[u] = true;
    stackmem[u] = true;
    dis[u] = t;
    low[u] = t++;
    S.push(u);
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(!color[v]){
            dfs(v);
            low[u] = min(low[u],low[v]);
        }
        else if(stackmem[v]){
            cout << "cycle" << endl;
            low[u] = min(low[u],dis[v]);
        }
    }
    color[u] = 2;
    if(low[u] == dis[u]){
        int w = -1;
        while(low[S.top()] != dis[S.top()]){
            w = S.top();
            comp[cmp].pb(w);
            S.pop();
            stackmem[w] = false;
        }
        w = S.top();
        comp[cmp++].pb(w);
        S.pop();
        stackmem[w] = false;
    }
}

int main(){
    int x,y;
    sff(n,e);
    For(i,0,e-1){
        sff(x,y);
        G[x].pb(y);
    }

    For(i,1,n){
        if(!color[i]){
            dfs(i);
        }
    }
    For(i,0,cmp-2){
        for(int j = 0; j < comp[i].size(); j++){
            cout << comp[i][j] << " ";
        }
        cout << endl;
    }
    /*For(j,0,5){
        cout << low[j] << " ";
    }*/
}
/*
6 7
1 0
0 2
2 1
0 3
3 4
4 5
5 3
*/
