#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

bool iswrd(string ss)
{
    for(int i=0;i<ss.size();++i)
    {
        if((ss[i]>='a'&&ss[i]<='z')||(ss[i]>='A'&&ss[i]<='Z')) return true;
    }
    return false;
}

bool isletter(char c)
{
    if(c>='a'&&c<='z') return 1;
    if(c>='A'&&c<='Z') return 1;
    else return 0;
}

int wrdamount(string ss)
{
    int total=0;
    for(int i=0;i<ss.size();++i)
    {
        if(ss[i]!=' ')
        {
            int j=i;
            string tmp;
            for(;j<ss.size()&&ss[j]!=' ';++j)
            {
                if(!isletter(ss[j])){++j;break;}
                tmp+=ss[j];
            }
            ///getchar();
            ///cout<<tmp<<endl;
            if(tmp!="")
            {
            total+=iswrd(tmp);
            }
            i=j;
            --i;
        }
    }
    return total;
}

int main()
{
    IOS
    string ss;
    while(getline(cin,ss))
    {
        cout<<wrdamount(ss)<<endl;
    }
}
/// Ghost Dancers Slay Together
