#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(false);

   int cases;
   cin>>cases;
   while(cases--)
   {
        int n,val,total=0;
        cin>>n;
        int students[n];
        for(int i=0;i<n;++i)
        {
            cin>>students[i];
            total+=students[i];
        }
        double p = total/n,cant=0;

        for(int i=0;i<n;++i)
        {
            if(students[i]>p){++cant;}
        }
        cout<<fixed<<setprecision(3);
        cout<< (100.00*cant)/n <<"%"<<endl;

   }


    return 0;
}
