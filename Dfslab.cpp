#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstring>
using namespace std;
int matrix[100][100];
vector<int>graph[100];
int time[2][100],color[100];
int node,edge;
int t=0;

void dfs(int u)
{
    color[u] = 1;
    time[0][u] = ++t;
    for(int i=0;i<node;i++)
    {
        if(matrix[u][i] == 1 && color[i] == 0)
        {
            dfs(i);
        }
    }
    color[u] = 2;
    time[1][u] = ++t;
}
int main()
{
    int x,y,v;
    cin >> node >> edge;
    memset(color,0,sizeof(color));

    for(int i=0;i<edge;i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        matrix[x][y] = 1;
        matrix[y][x] = 1;


    }

    /*for(int i=0;i<node;i++)
    {
        cout << i << " : ";
        for(int j=0;j<graph[i].size();j++)
        {
            cout  << matrix[i][j] << " ";
        }
        cout << endl;
    }*/

    // adjecensi matrix;
    /*for(int i=0;i<node;i++)
    {

        for(int j=0;j<node;j++)
        {
            if(matrix[i][j]== 1)
            {
                cout << matrix[i][j] << " " ;
            }
            cout << endl;
        }
    }*/
    int component = 0;
    int ft,tm,n;
    for(int i =0;i<node;i++)
    {
        tm = t;
        if(color[i] == 0)
        {
            dfs(i);
            component ++;
        }
        ft = t - tm;
         cout << "number of node in component " << component << ": " << ft/2 << endl;

    }
    cout << "component :" << component << endl;
    //getch();

    return 0;
}
/*
10 11
0 6
0 9
6 1
6 7
7 3
0 1
1 9
1 3
9 4
3 4
8 2
*/
