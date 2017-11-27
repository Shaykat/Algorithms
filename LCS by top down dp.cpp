
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

//operator overloading
class Compare{
    public:
    bool operator()(const int& l, const int& r){
       return l > r;
   }
};

// typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<int, string> pis;
typedef priority_queue<int> pq; // for max heap
typedef priority_queue<int,vector<int>, Compare > PQ; // for min heap

// constants
const int MOD = 1000000007;
const double EPS = 1e-11;
const double INF = 2e30;
const double PI = 2 * acos( 0.0 );

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

/////////////////////////////////// template //////////////////////////////
int n;
string a,b,res,mnres;
int dp[110][110];
void init(){
    mnres = "";
    For(i,0,100){
        mnres += 'z';
    }
}
int LCS(int i, int j){
    if(i >= a.size() || j >= b.size()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;

    if(a[i] == b[j]) ans = 1 + LCS(i+1,j+1);
    else{
        int temp1 = LCS(i+1,j);
        int temp2 = LCS(i,j+1);

        ans = max(temp1,temp2);
    }
    return dp[i][j] = ans;
}


void printAllLCS(int i, int j){
    if(i == a.size() || j == b.size()){
        if(res <= mnres) mnres = res;
        //cout << res << endl;
        return;
    }

    if(a[i] == b[j]){
        res += a[i];
        printAllLCS(i+1,j+1);
        res.erase(res.end()-1);
	}
	else
	{
		if(dp[i+1][j] > dp[i][j+1]) printAllLCS(i+1,j);
		else if(dp[i+1][j]<dp[i][j+1]) printAllLCS(i,j+1);
		else
		{
			printAllLCS(i+1,j);
			printAllLCS(i,j+1);
		}
	}
}

int main(){
    sf(n);
    For(i,1,n){
        init();
        mem(dp,-1);
        cin >> a;
        cin >> b;
        if(LCS(0,0) == 0) pf("Case %d: :(\n",i);
        else {
            printAllLCS(0,0);
            cout << "Case " << i << ": "<< mnres << endl;
        }
        res = "";
    }
}
