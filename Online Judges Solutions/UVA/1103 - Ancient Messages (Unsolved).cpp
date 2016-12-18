#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
#define printab(y,x) for(int i=0;i<y;++i){for(int j=0;j<x*4;++j){cout<<tab[i][j];}cout<<endl;}
using namespace std;

char tab[200][200];
int dirx[]={1,1,0,-1,-1,-1,0,1};
int diry[]={0,1,1,1,0,-1,-1,-1};

int dirx2[]={1,0,-1,0};
int diry2[]={0,1,0,-1};


int limx,limy,inside=0;
vector<char> answer;

string hexans(char c)
{
    switch(c)
    {
        case '0' : return "0000"; break;
        case '1' : return "0001"; break;
        case '2' : return "0010"; break;
        case '3' : return "0011"; break;
        case '4' : return "0100"; break;
        case '5' : return "0101"; break;
        case '6' : return "0110"; break;
        case '7' : return "0111"; break;
        case '8' : return "1000"; break;
        case '9' : return "1001"; break;
        case 'a' : return "1010"; break;
        case 'b' : return "1011"; break;
        case 'c' : return "1100"; break;
        case 'd' : return "1101"; break;
        case 'e' : return "1110"; break;
        case 'f' : return "1111"; break;
    }
}

/// floodfill inicial
void floodfill(int y,int x)
{
    tab[y][x]='-';
    int xpos,ypos;
    for(int i=0;i<8;++i)
    {
        xpos=x+dirx[i];
        ypos=y+diry[i];
        if(xpos < 0 || xpos >=limx*4  || ypos < 0 || ypos >=limy  || tab[ypos][xpos]!='0')
            continue;
        floodfill(ypos,xpos);
    }
}

/// floodfill interiores
void floodfill2(int y,int x)
{
    tab[y][x]='-';
    int xpos,ypos;
    for(int i=0;i<8;++i)
    {
        xpos=x+dirx[i];
        ypos=y+diry[i];
        if(xpos < 0 || xpos >=limx*4  || ypos < 0 || ypos >=limy  || tab[ypos][xpos]!='0')
            continue;
        floodfill2(ypos,xpos);
    }
}

/// floodfill contorno
void floodfill3(int y,int x)
{
    tab[y][x]='*';
    int xpos,ypos;
    for(int i=0;i<4;++i)
    {
        xpos=x+dirx2[i];
        ypos=y+diry2[i];
        if(tab[ypos][xpos]=='0'){++inside; floodfill2(ypos,xpos);}
        if(xpos < 0 || xpos >=limx*4  || ypos < 0 || ypos >=limy  || tab[ypos][xpos]!='1')
            continue;
        floodfill3(ypos,xpos);
    }
}


void readtab(int y,int x)
{
    char c;
    string tmp;
    for(int i=0;i<y;++i)
    {
        for(int j=0;j<x;++j)
        {
            cin>>c;
            tmp = hexans(c);
            tab[i][j*4]=tmp[0];
            tab[i][j*4+1]=tmp[1];
            tab[i][j*4+2]=tmp[2];
            tab[i][j*4+3]=tmp[3];
        }
    }
}

void checktab(int y,int x)
{
    for(int i=0;i<y;++i)
    {
       for(int j=0;j<x*4;++j)
       {
            if(tab[i][j]=='1')
            {
                inside=0;
                floodfill3(i,j);
                switch(inside)
                {
                    case 0: answer.push_back('W'); break;
                    case 1: answer.push_back('A'); break;
                    case 2: answer.push_back('K'); break;
                    case 3: answer.push_back('J'); break;
                    case 4: answer.push_back('S'); break;
                    case 5: answer.push_back('D'); break;
                }
            }
       }
    }
}

int main()
{
    IOS
    int c=1;
    while(cin>>limy>>limx,limy&&limx){
    readtab(limy,limx);
    ///printab(limy,limx);
    floodfill(0,0);
    checktab(limy,limx);
    ///printab(limy,limx);
    cout<<"Case "<<c<<": ";
    sort(answer.begin(),answer.end());
    for(int i=0;i<answer.size();++i)
    {
        cout<<answer[i];
    }cout<<endl;
    answer.clear();
    ++c;
    }
}
