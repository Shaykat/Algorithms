#include <bits/stdc++.h>

using namespace std;

#define READ() 	    freopen("in.txt","r",stdin)
#define WRITE()     freopen("out.txt","w",stdout)
#define sf(n) 	    scanf("%d",&n)
#define sl(x)       scanf("%I64d",&x)
#define lsf(n) 	    scanf("%lld", &n)
#define pb(n) 	    push_back(n)
#define mem(x,y)    memset(x,y,sizeof(x))
#define DBG(x)      cout << #x << " = " << x << endl
#define YOLO        cout << "YOLO" << endl
#define NL			printf("\n")
#define EPS 	    1e-10
#define INF         INT_MAX
#define MAX         5000010
#define MOD         1000000007
#define LL          long long
#define endl        "\n"
#define pi          2.0*acos(0.0)
#define cnd         tree[idx]
#define lnd         tree[left]
#define rnd         tree[right]
#define callLeft    left,st,mid
#define callRight   right,mid+1,ed

#define emp 0

struct info /// custom data type
{
    int arr[5][5];
    info()
    {
https://github.com/Shaykat/RSS-Reader.git
    }

};


/// chk two info are equal or not
bool isEql(info x1, info x2)
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(x1.arr[i][j] != x2.arr[i][j])return false;
        }
    }
    return true;
}

int goal[5][5];
int init[5][5];
int tempArr[5][5]; /// all -1 /// working main arr
int tempArr1D[15];

/// see tempArr
void seeTempArr()
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
//            printf
            cout << tempArr[i][j] << " ";
        } cout << endl;
    }
    cout << endl << endl;
}

/// true if tempArr is eql to GOAL
bool chkGoal()
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(goal[i][j] != tempArr[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

/// 2d to 1d
void tempArrTo1D()
{
    int cnt = 0;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)tempArr1D[cnt++] = tempArr[i][j];
    }
}

/// generate random
int fArr[10];
int val[10];
void genRandom()
{
    memset(fArr,0,sizeof(fArr));

    for(int i=0;i<9;i++)
    {
        bool found = false;
        while(!found)
        {
            int x = rand() % 9;

            if(fArr[x] == 0)
            {
                found = true;
                fArr[x] = 1;
                val[i] = x;
            }
        }
    }

    int cnt = 0;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)init[i][j] = val[cnt++];
    }
}


/// find empty cell
int eI; int eJ;
void findEmp()
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(tempArr[i][j] == emp)
            {
                eI = i;
                eJ = j;
                return;
            }
        }
    }
}

/// get Possible moves
vector < pair <int,int> > getMove;
int dir[2] = {1,-1};
void genMove()
{
    getMove.clear();
    findEmp();
    int empI = eI; int empJ = eJ;

    /// up down
    for(int i=0;i<2;i++)
    {
        if( tempArr[ empI+dir[i] ][empJ]  != -1 )getMove.pb(make_pair(empI+dir[i] , empJ));
    }

    /// left right
    for(int i=0;i<2;i++)
    {
        if( tempArr[empI][ empJ+dir[i] ]  != -1 )getMove.pb(make_pair(empI , empJ+dir[i]));
    }
}


/// make visit the tempArr
vector <int> visited[MAX];
int visitCnt = 0;
//bool visitedArr[10][10][10][10][10][10][10][10][10][10]; /// too much memory
set <string> stVisited;
void makeVisit()
{
    string s = "";
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
//            visited[visitCnt].pb(tempArr[i][j]);
            char c = tempArr[i][j] + 48;
            s += c;
        }
    }
    stVisited.insert(s);
//    visitCnt++;
}


/// check if tempArr is visited
bool chkVisited() /// main complexity is increased a lot here!
{
    string s = "";
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
//            visited[visitCnt].pb(tempArr[i][j]);
            char c = tempArr[i][j] + 48;
            s += c;
        }
    }
    if(stVisited.find(s) == stVisited.end())return false;
    else return true;

    }
}


/// create tempArr from info
void makeTempArr(info xx)
{
    memset(tempArr,-1,sizeof(tempArr));
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)tempArr[i][j] = xx.arr[i][j];
    }
}

string infoToString(info xx)
{
    string s = "";
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
//            visited[visitCnt].pb(tempArr[i][j]);
            char c = xx.arr[i][j] + 48;
            s += c;
        }
    }
    return s;
}

/// print path
map < string, string > par;
map < string, int > level;
void printPath(string SS)
{
//    YOLO;
    if( par[SS] == SS )
    {
        cout << "Step: " << level[SS] << endl;
        for(int i=0;i<SS.size();i++)
        {
            cout << SS[i] << " ";
            if( (i+1) % 3 == 0)cout << endl;
        }
        cout << endl;
        return;
    }


    printPath(par[SS]);

    cout << "Step: " << level[SS] << endl;
    for(int i=0;i<SS.size();i++)
    {
        cout << SS[i] << " ";
        if( (i+1) % 3 == 0)cout << endl;
    }
    cout << endl;

    return ;
}

void BFS()
{
    int cnt = 0;
//    printf("%d\n",cnt++);
    queue <info> que;
    info xx;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            xx.arr[i][j] = init[i][j];
            tempArr[i][j] = init[i][j];
        }
    }
    makeVisit();
    que.push(xx);

    string s = infoToString(xx);
    par[s] = s;
    level[s] = 0;

    bool found = false;
    while(!que.empty() && !found)
    {
        info u = que.front();
        makeTempArr(u);
        string sU = infoToString(u);

//        cout << "PARENT: " << endl;
//        seeTempArr();

        genMove();
        int empUI = eI; int empUJ = eJ;

//        cout << "Child: " << endl;
        for(int i=0;i<getMove.size();i++)
        {

            int empVI = getMove[i].first;
            int empVJ = getMove[i].second;
            makeTempArr(u);
            swap(tempArr[empUI][empUJ] , tempArr[empVI][empVJ]);

            if(!chkVisited())
            {
//                seeTempArr();
//                printf("%d\n",cnt++);

                info v;
                for(int ii=1;ii<=3;ii++)
                {
                    for(int jj=1;jj<=3;jj++)
                    {
                        v.arr[ii][jj] = tempArr[ii][jj];
                    }
                }
                makeVisit();
                que.push(v);

                string sV = infoToString(v);
                level[sV] = level[sU] + 1;
                par[sV] = sU;

                if(chkGoal())
                {
                    printPath(sV);
                    found = true;
                    cout << "found" << endl;
                    break;
                }
            }
        }
        que.pop();
    }
    if(!found)cout << "It can not be solved." << endl;
}

/// initialize everything
void initEverything()
{
    par.clear();
    level.clear();
    stVisited.clear();
    getMove.clear();
    memset(tempArr,-1,sizeof(tempArr));
}

int main()
{
//        clock_t t1,t2;
//    t1=clock();

//	ios_base::sync_with_stdio(false);
//    cin.tie(0); /// use "\n" instead of endl
//    READ();
//    WRITE();
    srand (time(NULL));
    /// goal
//    int cntG = 1;
//    for(int i=1;i<=3;i++)
//    {
//        for(int j=1;j<=3;j++)goal[i][j] = cntG++;
//    }
//    goal[3][3] = emp;


    /// init
    init[1][1] = 2;
    init[1][2] = 5;
    init[1][3] = 3;
    init[2][1] = 1;
    init[2][2] = 6;
    init[2][3] = 4;
    init[3][1] = 7;
    init[3][2] = emp;
    init[3][3] = 8;


    /// goal test
    goal[1][1] = 1;
    goal[1][2] = 2;
    goal[1][3] = 3;
    goal[2][1] = 8;
    goal[2][2] = 0;
    goal[2][3] = 4;
    goal[3][1] = 7;
    goal[3][2] = 6;
    goal[3][3] = 5;

    cout << "initial state:" << endl;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)cout << init[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    cout << endl;

    while(1)
    {
        initEverything();
        int x;
        cout << "Press 1 for Random Generate " << endl;
        cout << "Press 2 for Step by Step Solution " << endl;
        cout << "Press 3 for END " << endl;
        cin >> x;

        if(x == 1)
        {
            genRandom();

            cout << "initial state:" << endl;
            for(int i=1;i<=3;i++)
            {
                for(int j=1;j<=3;j++)cout << init[i][j] << " ";
                cout << endl;
            }
            cout << endl;
            cout << endl;
        }
        if(x == 2)
        {

            bool chkInit = true; /// checking if the init is goal it self!
            for(int i=1;i<=3;i++)
            {
                for(int j=1;j<=3;j++)
                {
                    if(goal[i][j] != init[i][j])
                    {
                        chkInit = false;
                        break;
                    }
                }
            }
            if(chkInit)
            {
                cout << "IT IS THE SOLUTION IT SELF" << endl;
            }
            else
            {
                cout << "Solution Starts: "<< endl;
                BFS();
                cout << "DONE" << endl;
            }
        }
        if(x == 3)
        {
            break;
        }
    }

//    t2=clock();
//    float diff ((float)t2-(float)t1);
//    float seconds = diff / CLOCKS_PER_SEC;
//    cout<<seconds<<endl;
//    system ("pause");

//	main();
    return 0;
}


