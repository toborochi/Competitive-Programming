#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
#define printmtrx(tam,d) for(int i=0;i<tam;++i){for(int j=0;j<tam;++j){cout<<aux[i][j][d];}cout<<endl;}
using namespace std;

char tab[100][100];
char aux[100][100][4];
int ans[4];

void readtab(int n,int m)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>tab[i][j];
        }
    }
    char c;
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>c;
            aux[i][j][0]=c;
            aux[j][m-1-i][1]=c;
            aux[m-1-i][m-1-j][2]=c;
            aux[m-1-j][i][3]=c;
        }
    }
    ///printmtrx(m,3);
}

void checktab(int n,int m)
{
    int t1,t2,t3,t4;
    for(int i=0;i<=n-m;++i)
    {

        for(int j=0;j<=n-m;++j)
        {
            /// Revisar ***
            t1=t2=t3=t4=0;
            int ylim=i+m,xlim=j+m,l=0,g=0;

            for(int k=i;k<ylim;++k)
            {
                l=0;
                  for(int p=j;p<xlim;++p)
                  {
                        if(aux[g][l][0]==tab[k][p])++t1;
                        if(aux[g][l][1]==tab[k][p])++t2;
                        if(aux[g][l][2]==tab[k][p])++t3;
                        if(aux[g][l][3]==tab[k][p])++t4;
                        ///cout<<tab[k][p];
                        ++l;
                  }
                  ++g;
                  ///cout<<endl;
            }
            if(t1==m*m)ans[0]++;
            if(t2==m*m)ans[1]++;
            if(t3==m*m)ans[2]++;
            if(t4==m*m)ans[3]++;
            ///cout<<"---"<<endl;
            /// *** *** ***
        }
    }
}

int main()
{
    IOS
    int S,s;
    while(cin>>S>>s)
    {
        if(S==0&&s==0)break;
        readtab(S,s);
        memset(ans,0,sizeof ans);
        checktab(S,s);
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<" "<<endl;
    }


}
