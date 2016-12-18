#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

bool isPal(string ss)
{
    string tmp,tmp2;
    for(int i=0;i<ss.size();++i)
    {
        if((ss[i]>='a' && ss[i]<='z') || (ss[i]>='A' && ss[i]<='Z'))
        {
            tmp+=tolower(ss[i]);
        }
    }
    tmp2=tmp;
    reverse(tmp2.begin(),tmp2.end());
    return tmp==tmp2;
}

int main()
{
   IOS
   freopen("out.txt","w",stdout);
   string ss;
   while(true)
   {
       getline(cin,ss);
       if(ss=="DONE")break;
       cout<< ((isPal(ss))?"You won't be eaten!":"Uh oh..") <<endl;
   }
}
