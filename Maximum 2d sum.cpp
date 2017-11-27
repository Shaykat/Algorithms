#include<bits/stdc++.h>
using namespace std;

// input output
#define pf           printf
#define sf(n)        scanf("%d", &n)
#define sfl(n)        scanf("%lld", &n)
#define sfc(n)        scanf("%c", &n)
#define sff(a,b)     scanf("%d %d", &a, &b)
#define sfff(a,b,c)  scanf("%d %d %d", &a, &b, &c)
#define INP          freopen("in.txt", "r", stdin);  // file input
#define OUT          freopen("out.txt", "w", stdout);  // file output

// operations
#define pb           push_back
#define mem(n, val)  memset((n), val, sizeof(n))
#define mp           make_pair
#define ff first
#define se second

// constant
#define MOD          1000000007
#define inf   1<<30                                           //infinity value
#define eps   1e-9

// Loop
#define For(i, a, b) for(int i = a; i <= b; i++)
#define Ror(i, a, b) for(int i = a; i >= b; i--)
#define all(v)       v.begin(), v.end()

// functions
#define gcd(a,b)     ll _gcd(int a,int b){ if(b%a == 0) return a; _gcd(b%a,a); }
#define lcm(a,b)     ((a*b)/gcd(a,b))

// binary tree || segment tree
#define cnd          tr[idx]
#define lnd          tr[idx << 1]
#define rnd          tr[lnd + 1]
#define leftcl       lnd,st,mid
#define rightcl      rnd,mid+1,ed

// typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<int, string> pis;
typedef priority_queue<int> pq;

// @Shaykat@
/////////////////////////////////// template //////////////////////////////
#define sz 110
#define  INF   -199999999
int temp[sz],start,finish,n,t,mxsum=0,left,right;
int a[sz][sz];

void init(){
    mem(a,0);
    mem(temp,0);
    mxsum = INF;
}

int Dsum()
{
    // initialize sum, maxSum and
    int sum = 0,i;
    int mXsum = INF;
    finish = -1;

    // local variable
    int s = 0;

    for (i = 0; i < n; ++i)
    {
        sum += temp[i];
        if (sum < 0)
        {
            sum = 0;
            s = i+1;
        }
        else if (sum > mXsum)
        {
            mXsum = sum;
            start = s;
            finish = i;
        }
    }

     // There is at-least one non-negative number
    if (finish != -1)
        return mXsum;

    // Special Case: When all numbers in temp[] are negative
    mXsum = temp[0];
    start = finish = 0;

    // Find the maximum element in array
    for (i = 1; i < n; i++)
    {
        if (temp[i] > mXsum)
        {
            mXsum = temp[i];
            start = finish = i;
        }
    }
    return mXsum;
}

void findMaxSum(){
    mxsum = INF;
    For(left,0,n-1){
        mem(temp,0);
        For(right,left,n-1){
            For(i,0,n-1){
                temp[i] += a[i][right];
            }
            int sum = Dsum();
            //cout << sum << "left: " << left << endl;
            if(sum > mxsum){
                mxsum = sum;
                //cout << "msum: " << mxsum << endl;
             }
        }
    }
    cout << mxsum << endl;
}

int main(){
    while(sf(n)!=EOF){
        For(i,0,n-1){
            For(j,0,n-1){
                sf(a[i][j]);
            }
        }
        findMaxSum();
        init();
    }
    return 0;
}
/*
4
0 -2 -7  0 9  2 -6  2
-4  1 -4  1 -1
8  0 -2

4
0 -2 -7  0 2  1 -6  2
-4  0 -4  1 -1
8  0 -2
*/
