#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

char tab[102][102];

void readtab(int y,int x)
{
    char c;
    for(int i=0;i<y;++i)
    {
        for(int j=0;j<x;++j)
        {
            cin>>c;
            if(c=='*')
            {
                tab[i][j]='*';
                if(i-1>=0 && tab[i-1][j]!='*'){tab[i-1][j]+=1;}
                if(i-1>=0 && j-1>=0 && tab[i-1][j-1]!='*'){tab[i-1][j-1]+=1;}
                if(j-1>=0 && tab[i][j-1]!='*'){tab[i][j-1]+=1;}
                if(i+1<y && j-1>=0 && tab[i+1][j-1]!='*'){tab[i+1][j-1]+=1;}
                if(i+1<y && tab[i+1][j]!='*'){tab[i+1][j]+=1;}
                if(i+1<y && j+1<x && tab[i+1][j+1]!='*'){tab[i+1][j+1]+=1;}
                if(j+1<x && tab[i][j+1]!='*'){tab[i][j+1]+=1;}
                if(i-1>=0 && j+1<x && tab[i-1][j+1]!='*'){tab[i-1][j+1]+=1;}
            }
        }
    }
}

void printab(int y,int x)
{
    for(int i=0;i<y;++i)
    {
       for(int j=0;j<x;++j)
        {
            cout<<tab[i][j];
        }cout<<endl;
    }
}

int main()
{
   IOS
   freopen("out.txt","w",stdout);
   int y,x,f=1;
   bool aux=0;
   while(cin>>y>>x)
   {
        if(y==0&&x==0)break;
        if(aux)cout<<endl;
        memset(tab,'0',sizeof tab);
        readtab(y,x);
        cout<<"Field #"<<f<<":"<<endl;
        printab(y,x);
        aux=true;
        ++f;
   }
}
