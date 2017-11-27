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

#define mx 100010
int n,m;
vector<int>G[mx];
vector<int>cost[mx];
vector<int>rs;
long long dis[mx];
int parent[mx];
int nod,edge;

class node{
public:
    int n,per;
    long long w;
    node(int a, long long b,int p):n(a),w(b),per(p){}
    bool operator < (const node &a) const{
        return a.w<w;
    }
 };

 long long dij(int src,int dest){

    memset(dis,1,sizeof(dis));
    priority_queue <node> pq;
    dis[src]=0;
    pq.push(node(src,0,-1));
    while(!pq.empty()){
        int u=pq.top().n;
        if(u==dest){
            return dis[dest];
        }
        pq.pop();
        int ln=G[u].size();
        for(int i=0; i<ln ; i++){
            int v=G[u][i];
            if((dis[u]+cost[u][i])<dis[v]){
                dis[v]=dis[u]+cost[u][i];
                pq.push(node(v,dis[v],u));
                parent[v]=u;
            }
        }
    }
    return -1;

}

int main(){
    int x,y,c;
    sff(n,m);

    For(i,0,m-1){
        sff(x,y);
        sf(c);

        G[x].pb(y);
        G[y].pb(x);

        cost[x].pb(c);
        cost[y].pb(c);
    }

    int r = dij(1,n);
    if(r == -1){
        cout << r << endl;
    }
    else {
        int v = n;
        while(1){
            if(parent[v] == 0){
                rs.pb(v);
                break;
            }
            rs.pb(v);
            v = parent[v];
        }
        Ror(i,rs.size()-1,0){
            cout<<rs[i]<<" ";
        }
        cout << endl;
    }
    return 0;
}
