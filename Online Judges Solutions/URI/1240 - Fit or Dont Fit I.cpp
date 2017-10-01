#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cases;
    cin>>cases;
    string a;
    string b;
    bool oc=false;
    while(cases--)
    {
        oc=false;
        cin>>a>>b;
        if(b.size()>a.size()) oc=true;

        if(oc==false)
        {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(int i=0;i<b.size(); ++i)
        {
            if(b[i]!=a[i]) oc=true;
        }
        }
      if(oc==true) cout<<"nao encaixa"<<endl;
      if(oc==false) cout<<"encaixa"<<endl;
    }

    return 0;
}
