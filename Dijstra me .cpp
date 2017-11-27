#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;

#define max 100
vector<int>G[max];
queue<int> Q;
int min_cost[max];
int mat[max][max];

void init(){

    //memset(min_cost,100000,sizeof(min_cost));
    memset(mat,0,sizeof(mat));
    for(int i = 0; i < max; i++){
        min_cost[i] = 100000;
    }
}

void dijstra(int u){

    int v;

    Q.push(u);
    min_cost[u] = 0;

    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        for(int i = 0; i < G[u].size(); i++){

            v = G[u][i];

            if((min_cost[u] + mat[u][v]) < min_cost[v]){
                min_cost[v] = min_cost[u] + mat[u][v];
                Q.push(G[u][i]);
            }
        }
    }

}

int main(){

    init();
    int x,y,n,e,c,p;
    cin >> n >> e;

    for(int i = 0; i < e; i++){
        cin >> x >> y >> c;

        G[x].push_back(y);
        G[y].push_back(x);
        mat[x][y] = c;
        mat[y][x] = c;
    }
    cout << "from which node you want to calculate the shortest cost: ";
    cin >> p;
    dijstra(p);

    for(int i = 0; i <n; i++){

        cout << "cost from 3 to " << i << " is: " << min_cost[i] << endl;
    }
}
