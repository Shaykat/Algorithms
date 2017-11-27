#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
vector<int>G[100];
void BFS(int n,int src)
{
    queue<int>Q;
    Q.push(src);
    int level[100],parent[100],visited[100]={0};
    int u,v;
    visited[src] = 1;
    level[src] = 0;
    while(!Q.empty())
    {
        u = Q.front();
        for(int i=0;i<G[u].size();i++)
        {
            v = G[u][i];
            if(!visited[v])
            {
                visited[v] = 1;
                level[v] = level[u] + 1;
                parent[v] = u;
                Q.push(v);
            }
        }
        Q.pop();
    }

    for(int i=1;i<=n;i++)
    {
        cout << src << " to " << i << " distance " << level[i] << endl;
    }
}

int main()
{
    int n,src,x,y,nd,edg;
    cin >> n;
    src = 1;
    cin >> nd >> edg;
    for(int i=0;i<edg;i++)
    {
        cin >> x >> y;
        G[x].push_back(y);
    }
    BFS(n,src);

}
