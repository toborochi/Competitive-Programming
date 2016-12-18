#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

map<string,pair<int,string> > tmp;

string minimize(string ss)
{
    for(int i=0;i<ss.size();++i){if(ss[i]>='A' && ss[i]<='Z')ss[i]+=32;}
    sort(ss.begin(),ss.end());
    return ss;
}

void f(string ss)
{
    string aux;
    int j;
    for(int i=0;i<ss.size();++i)
    {
        if(ss[i]!=' ')
        {
            aux="";
            for(j=i;ss[j]!=' '&&j<ss.size();++j){aux+=ss[j];}
            i=j;
            ///cout<<minimize(aux)<<endl;
            tmp[minimize(aux)].first+=1;
            tmp[minimize(aux)].second=aux;
        }
    }
}

int main()
{
    IOS
    freopen("out.txt","w",stdout);
    string ss;
    while(getline(cin,ss))
    {
        if(ss=="#")break;
        f(ss);
    }
    vector<string> ans;
    map<string,pair<int,string> >::iterator it;
    for(it=tmp.begin();it!=tmp.end();++it)
    {
            if((it->second).first==1) {ans.push_back(((it->second).second)); /*cout<< ((it->second).second) <<endl;*/}
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();++i){cout<<ans[i]<<endl;}
}
