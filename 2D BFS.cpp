#include<bits/stdc++.h>
using namespace std;

#define s 10005
#define p pair<int,int>

int visited[s][s];
int cell[s][s];
int level[s][s];
int parent[s][s];
int row,colom;
queue<pair<int,int> >Q;
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};

void tdbfs(int g,int h){
    visited[g][h] = 1;
    Q.push(make_pair(g,h));
    int p1,p2,x,y;
   while(!Q.empty()){
        cout << "hjhgjh" << endl;
        p mp = Q.front();
        Q.pop();
        p1 = mp.first;
        p2 = mp.second;
        int i;
        for(i = 0; i < 4; i++){
            x = p1+fy[i];
            y = p2+fx[i];
            cout << x << " " << y << endl;
            if(x>=0 && x<row && y>=0 && y<colom && visited[x][y] == 0){
                visited[x][y] = 1;
                parent[x][y] = cell[p1][p2];
                //cout << "hjhgjh" << endl;
                level[x][y] = level[p1][p2]+1;
                Q.push(make_pair(x,y));
            }
        }
   }
}
void init(){
    memset(visited,0,sizeof(visited));
    memset(level,0,sizeof(level));
    memset(parent,0,sizeof(parent));

}
int main(){

    init();
    cin >> row >> colom;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < colom; j++){
            cin >> cell[i][j];
        }
    }

    tdbfs(0,0);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < colom; j++){
            cout << level[i][j] << " " << parent[i][j] << "\t";
        }
        cout << endl;
    }
}
/*
4 3
1 2 3
4 5 6
7 8 9
10 11 12
*/
