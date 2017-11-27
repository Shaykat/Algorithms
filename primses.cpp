#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<climits>

using namespace std;

#define SIZE 100
#define DISCONNECTED -1  // disconnect akta variable value -1 kora hoise

struct Node // structure die node name node nea hoise
{
	int name;
	int pred;
	int key;
};

struct CompareNode // node compare kore aikhane j kon node er value coto, oitake upore rakhe queue er
{
	bool operator()(Node& n1, Node& n2)
	{
		return n1.key > n2.key;
	}
};

vector<Node> A; // Minimum spanning store korar jonno vector nea hoise
priority_queue<Node, vector<Node>, CompareNode> Q; // priority queue always coto key k upore rakhbe

int graph[SIZE + 1][SIZE + 1], cost[SIZE + 1]; // graph 2D array ta graph input near jonno, cost min cost er jonno
int no_of_nodes, no_of_edges, source;

void read_graph()
{
	int x, y, c;

	printf("Enter no of nodes: "); // number of node input
	cin >> no_of_nodes;
	printf("Enter no of edges: "); // number of edge input
	cin >> no_of_edges;

	for (int i = 1; i <= no_of_nodes; i++)
	for (int j = 1; j <= no_of_nodes; j++)
		graph[i][j] = DISCONNECTED; // graph 2D array or matrix take -1 die initialize kora hoise

	for (int i = 1; i <= no_of_edges; i++)
	{
		cin >> x >> y >> c; // in[ut node x ,y & ai dui node die jei edge hobe tar cost
		graph[x][y] = graph[y][x] = c; // 2D array or matrixx er x,y or y,x tomo indext a cost rakha hoise
	}

	printf("Enter Source: ");  // graph er source or first node konta hobe ta input dite hobe
	cin >> source;
}

void prims()  // prims algo er function suru
{
	for (int i = 0; i<no_of_nodes; i++)  // loop suru number of node porjonto cholbe
	{
		Node n; // node type er n akta object or variable
		n.name = i + 1; // n object er name a node name or number rakha hoise
		n.pred = INT_MAX; // node er parent rakha hoise
		n.key = (source == n.name) ? 0 : INT_MAX;// oi node a jaoar cost koto ta key te rakha hoise

		Q.push(n); // queue te node k push kora hoise
		cost[n.name] = n.key; // cost er modde ai node  er jonno cost save kora hoise
	}

	while (!Q.empty()) // jotokkhn queue khali na hobe totokkhn while loop cholbe
	{
		Node u = Q.top();  // node type er  u variable er modde queue er top node ta nibe
		Q.pop();  // queue theke ai node k pop kore dibe
		A.push_back(u);  // spanning tree er jonno vector A te u ke push kora holo

		struct Node NodeRec[SIZE];
		for (int v = 1; v <= no_of_nodes; v++)
		{
			if (graph[u.name][v] != DISCONNECTED && cost[v] > graph[u.name][v]) // jode graph a u theke v node connect thake & v er cost jode u theke  v te jaoar cost er chae beshi hoi if er vitore dhukbe
			{
				int n = Q.size(); // queue er size n a nea hoise
				for (int i = 0; i<n; i++)
				{
					NodeRec[i] = Q.top(); // theke jaoa jai emn sob node queue te nea hoise ai loop a
					Q.pop(); // then pop kora hoise
				}

				for (int i = 0; i<n; i++) //
				{
					if (NodeRec[i].name == v) // ager loop a push kora node er key name parent agula define kora hoise aikhane
					{
						NodeRec[i].pred = u.name;
						NodeRec[i].key = graph[u.name][v];
						cost[v] = graph[u.name][v];
					}
					Q.push(NodeRec[i]); // then queue te push kora hoise
				}
			}
		}
	}
}

int main()
{
	read_graph(); // grapg input nibe
	prims(); // prims function call kora hoise

	for (int i = 1; i < A.size(); i++) spanning tree ta output dea hobe
	{
		printf("%d %d %d\n", A.at(i).pred, A.at(i).name, A.at(i).key);
	}


	return 0;
}
