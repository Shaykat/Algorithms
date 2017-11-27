#include<bits/stdc++.h>
using namespace std;


//int graph[100][100];
vector<int> graph[100];
int V,E;
void printSolution(int color[]);

bool isSafe (int v, int color[], int c)
{
    for (int i = 0; i < graph[v].size(); i++){
        int u = graph[v][i];
        if (c == color[u])  return false;
    }
    return true;
}

bool graphColoringUtil(int m, int color[], int v)
{
    if (v == V)
        return true;
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, color, c))
        {
           color[v] = c;
           if (graphColoringUtil (m, color, v+1) == true)
             return true;

           color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
       color[i] = 0;
    if (graphColoringUtil(m, color, 0) == false)
    {
      printf("Solution does not exist");
      return false;
    }

    // Print the solution
    printSolution(color);
    return true;
}

/* A utility function to print solution */
void printSolution(int color[])
{
    cout << "Solution Exists: " << endl;
    cout << "Following are the assigned colors" << endl;
    for (int i = 0; i < V; i++){
      cout << color[i] << " ";
    }
    cout << endl;
}

int main()
{
    /*
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    int m;
    cout << "Enter number of virtex: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    int a,b;
    for(int i = 0; i < E; i++){
        cin >> a >> b;
        //graph[a][b] = 1;
        //graph[b][a] = 1;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    /*
    0 1
    0 2
    0 3
    2 1
    3 2
    */
    cout << "Enter number of Colors: ";
    cin >> m;
    graphColoring (m);
    return 0;
}
