#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int main()
{
string frase,aux;
    vector<string> answer;
     bool first=1;
    while(getline(cin,frase)&&frase!="")
    {
    aux="";
    for(int i=0;i<frase.size();++i)
    {
        if(frase[i]==34 && first)
        {
            aux+='`';
            aux+='`';
            first=0;
        }
        else if (frase[i]==34 && !first)
        {
            aux+=39;
            aux+=39;
            first=1;
        }
        else
        {
            aux+=frase[i];
        }
    }
    answer.push_back(aux);
    ///cout<<aux<<endl;
    }
    for(int i=0;i<answer.size();++i)
    {
        cout<<answer[i]<<endl;
    }
}
