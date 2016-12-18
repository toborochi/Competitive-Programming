#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int max_gcd(string ss)
{
    int ans=1;
    vector<int> v;
    for(int i=0;i<ss.size();++i)
    {
        if(ss[i]!=' ')
        {
            string tmp="";
            int j;
            for(j=i;ss[j]!=' '&&j<ss.size();++j)
            {
                tmp+=ss[j];
            }
            if(tmp!=""&&tmp!="0"){
            cout<<tmp<<endl;
            int aux;
            stringstream p;
            p << tmp;
            p >> aux;
            v.push_back(aux);
            ///cout<<aux<<endl;
            }
            i=j;
            --i;
        }
    }
    for(int i=0;i<v.size()-1;++i)
    {
        for(int j=i+1;j<v.size();++j)
        {
            ans=max(ans,__gcd(v[i],v[j]));
        }
    }

    return ans;
}

int main()
{
    IOS
    int cases;
    string numbers;
    cin>>cases;
    cin.ignore();
    while(cases--)
    {
        getline(cin,numbers);
        cout<<max_gcd(numbers)<<endl;
    }
}
/// Ghost Dancers Slay Together

