#include <iostream>
#include <cmath>

using namespace std;

bool red(int a,int b)
{
    int aux;
    if(abs(a)<=abs(b)){aux=b; b=a; b=aux;}

    int i=1,divis=0;
    if(a)

    while(i<=b && divis<=1)
    {
        if(b%i==0 && a%i==0){divis++;}
        ++i;
    }
    if(divis==1){return false;} else return true;


}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(false);
    int cases;
    cin>>cases;
    while(cases--)
    {
        char SIGN,misc;
        long long N1,D1,N2,D2;
        cin>>N1>>misc>>D1>>SIGN>>N2>>misc>>D2;
        int NUM,DEN;
        if(SIGN=='+'){NUM=(D1 * D2) * N1 / D1 + (D1 * D2) * N2 / D2; DEN=(D1*D2);}
        if(SIGN=='-'){NUM=(D1 * D2) * N1 / D1 - (D1 * D2) * N2 / D2; DEN=(D1*D2);}
        if(SIGN=='*'){NUM=(N1*N2); DEN=(D2*D1);}
        if(SIGN=='/'){NUM=(N1*D2); DEN=(N2*D1);}

        int r,num_r,den_r,j;

        if (abs(NUM) < abs(DEN))
            r = abs(NUM);
        else
            r = abs(DEN);

        num_r = NUM;
        den_r = DEN;

        j = 2;
        while (j <= r / 2 + 1){
            if (num_r % j == 0 && den_r % j == 0){
                num_r = num_r / j;
                den_r = den_r / j;
            } else {
                j++;
            }
        }
      cout<<NUM<<"/"<<DEN<<" = "<<num_r<<"/"<<den_r<<endl;

    }
    return 0;
}
