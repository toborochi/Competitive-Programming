#include <iostream>
#include <stack>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int tab[10][10];

long long sum(int ini,int fin)
{
    int total=0;
    for(int i=ini;i<fin;++i)
    {
        for(int j=ini;j<fin;++j)
        {
            total+=tab[i][j];
        }
    }
        return total;
}

int main()
{
    IOS
    ///freopen("out.txt","w",stdout);
    int n,c=1;
    while(cin>>n)
    {
        if(!n)break;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                cin>>tab[i][j];
            }
        }
        stack<int> answer;
        int tmp=n/2,carry=0;
        while(tmp>=0)
        {
            if(answer.empty()){answer.push(sum(tmp,n-tmp));}
            else{answer.push(sum(tmp,n-tmp)-carry);}
            carry+=answer.top();
            tmp--;
        }



        cout<<"Case "<<c<<":";
        while(!answer.empty())
        {
            if(answer.top()!=0){cout<<" "<<answer.top();}
            answer.pop();
        }cout<<endl;
        ++c;
    }
}
/// This code is less virgin than me
