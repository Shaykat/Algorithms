#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<stack>
using namespace std;
#define max 100
vector<int>graph[max];
vector<int>tpsrt;
int time[2][max],color[max];
int node,edge,t=0,flag = 0;;
void dfs(int u)
{
    color[u] = 1;
    time[0][u] = ++t;
    //printf("%d ",u);
    for(int i=0;i<graph[u].size();i++)
    {
        if(color[graph[u][i]] == 0)
        {
            //printf("%d --> %d is a tree edge\n",u,graph[u][i]);
            dfs(graph[u][i]);
        }
        else if(color[graph[u][i]] == 1){
            flag = 1;
            cout << graph[u][i] << endl;
            cout << "topological sort is not possible" << endl;
        }
    }
    tpsrt.push_back(u);
    color[u] = 2;
    time[1][u] = ++t;
    //cout << t << endl;
}
int main()
{
    int x,y;
    int u;
    scanf("%d%d",&node,&edge);
    for(int i=0;i<edge;i++) // take input and make adjecency matrix
    {
        scanf("%d%d",&x,&y);
        graph[x].push_back(y);
        //graph[y].push_back(x);
    }
    memset(color,0,sizeof(color));
    int temp,ft,no_node=0;
    for(int i=1;i<=node;i++)
    {
        if(color[i] == 0)
        {
            dfs(i);
        }
    }
    if(flag == 0) {
        cout << "topologically sorted nodes: " << endl;
        for(int i = tpsrt.size()-1; i >= 0; i--){
            cout << tpsrt[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
