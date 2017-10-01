#include<bits/stdc++.h>

using namespace std;

int ite=0;

long fibonacci( long n )
{
   ite++;
   if ( n == 0 || n == 1 ) {
      return n;   }
   else {
      return fibonacci( n - 1 ) + fibonacci( n - 2 );
   }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(false);

    long cases,number;
    cin>>cases;
    while(cases--)
    {
     cin>>number;
     ite=0;
     cout<<"fib("<<number<<") = "<<ite-1<<" calls = "<<fibonacci(number)<<endl;
    }

    return 0;
}
