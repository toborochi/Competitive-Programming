#include <iostream>
using namespace std;

bool isPrime(long long n)
{
    if(n<=3) return n>1; else
    if(n%2==0 or n%3==0) return false;
    else
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(false);

    long long NUMBER,cases;
    cin>>cases;
    while(cases--)
    {
    cin>>NUMBER;
    if(isPrime(NUMBER)) cout<<"Prime"<<endl; else cout<<"Not Prime"<<endl;
    }
    return 0;
}
