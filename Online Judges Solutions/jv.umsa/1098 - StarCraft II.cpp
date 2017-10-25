#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
 
double p_to_p(int x1,int y1,int x2,int y2)
{
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(false);
    int cases;
    cin>>cases;
    while(cases--)
    {
        vector <pair<double,double> > coordenadas;
        int n;
        double x,y,xbomb,ybomb,radio;
        cin>>n;
        while(n--)
        {
            cin>>x>>y;
            coordenadas.push_back(make_pair(x,y));
        }
        cin>>xbomb>>ybomb>>radio;
        int sucess=0;
        for(int i=0;i<coordenadas.size();++i)
        {
            if(p_to_p(xbomb,ybomb,coordenadas[i].first,coordenadas[i].second)<=radio){sucess++;}
        }
        cout<<sucess<<endl;
 
    }
    return 0;
}
 
/**************************************************************
    Problem: 1098
    User: Vlada
    Language: C++
    Result: Accepted
    Time:8 ms
    Memory:1576 kb
****************************************************************/
