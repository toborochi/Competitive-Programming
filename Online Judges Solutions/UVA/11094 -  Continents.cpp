#include <iostream>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int m,n,ypos,xpos,tam,answer;

int dirx[] = {1,0,-1,0};
int diry[] = {0,1,0,-1};

char land[25][25];
char island;

void input()
{
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>land[i][j];
        }
    }
}

void flood(int y,int x)
{
    ++tam;
    land[y][x] = '*';
    for(int i=0;i<4;++i)
    {
        int xx = x + dirx[i];
        int yy = y + diry[i];
        if(xx==n && land[yy][0]==island)
        {
            flood(yy,0);
        }else
        if(xx==-1 && land[yy][n-1]==island)
        {
            flood(yy,n-1);
        }else
        if(xx>=0 && xx<n && yy>=0 && yy<m && land[yy][xx]==island)
        {
            flood(yy,xx);
        }
    }
}

void solve()
{
    answer = 0;
    island = land[ypos][xpos];
    flood(ypos,xpos);
    ///cout<<island<<endl;
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(land[i][j]==island)
            {
                tam=0;
                flood(i,j);
                answer = max(answer,tam);
            }
        }
    }
    cout<<answer<<'\n';
}

int main()
{
    IOS
    ///freopen("out.txt","w",stdout);
    while(cin>>m>>n)
    {
        input();
        cin>>ypos>>xpos;
        solve();
    }
}
