#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int v[1000];

int findSwaps( int n, int a[] )
{
    int count = 0, i, j, temp, b[100000];
    for( i = 0; i < n; i++ )
    {
        b[i] = a[i];
    }
    for( i = 0; i < n; i++ )
    {
        for( j = 0; j < n - 1; j++ )
        {
            if( b[j] > b[j+1] )
            {
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    IOS
    ///freopen("out.txt","w",stdout);
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;++i)cin>>v[i];
        cout<<"Minimum exchange operations : "<<findSwaps(n,v)<<endl;
    }
}
