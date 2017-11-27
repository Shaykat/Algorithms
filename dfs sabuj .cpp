#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define inf 123456
int cell[501][501];
int vis[501][501];
int lev[501][501];
int lev2[501][501];
queue<pair<int,int> >q;
int fr[]={0,0,1,-1};
int fc[]={1,-1,0,0};
int row,col,ans=0,c;
void bfs(int i,int j)
{
    lev[i][j]=0;
    vis[i][j]=1;
    q.push(make_pair(i,j));
    int p1,p2,ns=inf;
    while(!q.empty())
    {
         pii pp=q.front();
         q.pop();
         p1=pp.first;
         p2=pp.second;
         for(int k=0;k<4;k++)
         {
             int x=p1+fr[k];
             int y=p2+fc[k];
             if(x<row&&x>=0&&y<col&&y>=0&&cell[x][y]==0&&vis[x][y]==0)
             {
                 vis[x][y]=1;

                 if(lev[x][y]==-1)
                 {
                     lev[x][y]=lev[p1][p2]+1;
                     q.push(make_pair(x,y));
                 }
                 else if(lev[x][y]>lev[p1][p2]+1)
                 {
                     lev[x][y]=min(lev[x][y],lev[p1][p2]+1);
                     q.push(make_pair(x,y));
                     //cout<<x<<"  "<<y<<endl;
                 }
                 //cout<<lev[p1][p2]<<" "<<lev[x][y]<<endl;

             }
             if(x<row&&x>=0&&y<col&&y>=0&&cell[x][y]==3&&vis[x][y]==0)
             {
                 ns=min(ns,lev[p1][p2]+1);
             }
         }
    }
    ans=max(ans,ns);
}
int main()
{
    int n1,n,m,t,i,j,x,y,ns,a1,a2,b1,b2,c1,c2;
    char ch;
    char ch2;

   cin>>n1;
    for(t=1;t<=n1;t++)
    {
       cin>>n>>m;
        row=n;
        //memset(vis,0,sizeof(vis));

        col=m;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>ch;
                if(ch=='.')
                {
                    cell[i][j]=0;
                }
                else if(ch=='#')
                {
                    cell[i][j]=-1;
                }
                else if(ch=='m')
                {
                    cell[i][j]=-1;
                }
                else if(ch=='a')
                {
                    cell[i][j]=0;
                    a1=i;
                    a2=j;
                }
                else if(ch=='b')
                {
                    cell[i][j]=0;
                    b1=i;
                    b2=j;
                }
                else if(ch=='c')
                {
                    cell[i][j]=0;
                    c1=i;
                    c2=j;
                }
                else
                {
                    cell[i][j]=3;
                }
            }
        }

        memset(vis,0,sizeof(vis));
        memset(lev,-1,sizeof(lev));
        ans=0;
        bfs(a1,a2);
        memset(vis,0,sizeof(vis));
        memset(lev,-1,sizeof(lev));
        bfs(b1,b2);
        memset(vis,0,sizeof(vis));
        memset(lev,-1,sizeof(lev));
        bfs(c1,c2);

        cout<<"Case "<<t<<": "<<ans<<endl;

    }

return 0;

}
