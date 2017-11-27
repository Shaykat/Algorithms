//#include<bits/stdc++.h>
#include <iostream>
#include <deque>
#include <vector>
#include <cstring>
#include <stdio.h>
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
//typedef priority_queue<int> pq;

// @Shaykat@
/////////////////////////////////// template //////////////////////////////
#define s 1000110
deque < pii > dq;
deque < pii > DQ;

vector<int>mn;
vector<int>mx;

int n,k,t;
int a[s];

void init(){
    mn.clear();
    mx.clear();
    while(!dq.empty()){
        dq.pop_front();
    }
    while(!DQ.empty()){
        DQ.pop_front();
    }
}

int main(){
    int p,T=1;
    while(sff(n,k) != EOF){
        For(i, 0, n-1){
            sf(p);
            a[i] = p;
        }
        // min
        int j = 0;
        //cout << k << endl;
        while(j < n){
            while(dq.size()  && dq.front().ff >= a[j])  {
                dq.pop_front();
            }
            while(DQ.size()  && DQ.front().ff <= a[j])  {
                DQ.pop_front();
            }
            dq.push_front(make_pair(a[j],j));
            DQ.push_front(make_pair(a[j],j));

            while(dq.size()  &&  dq.back().se <= j-k  && (j-k) >= 0) {
                dq.pop_back();
            }
            while(DQ.size()  &&  DQ.back().se <= j-k  && (j-k) >= 0) {
                DQ.pop_back();
            }
            if(j >= k-1){
                mn.pb(dq.back().ff);
                mx.pb(DQ.back().ff);
            }
            j++;
        }

        For(i,0,mn.size()-2){
            pf("%d ",mn[i]);
        }
        pf("%d\n",mn[mn.size()-1]);

        For(i,0,mx.size()-2){
            pf("%d ",mx[i]);
        }
        pf("%d\n",mx[mx.size()-1]);
        init();
    }
    return 0;
}
