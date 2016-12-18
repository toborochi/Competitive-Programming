#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int centenas;
int decenas,milesimas,unidades;
string nm[10];
string nc[10];
string nd[10];
string nu[10];

string toroman(int numero)
{
    if (numero==1000) {
            return "M";
        } else {
            nu[0]="";
            nu[1]="I";
            nu[2]="II";
            nu[3]="III";
            nu[4]="IV";
            nu[5]="V";
            nu[6]="VI";
            nu[7]="VII";
            nu[8]="VIII";
            nu[9]="IX";

            nd[0]="";
            nd[1]="X";
            nd[2]="XX";
            nd[3]="XXX";
            nd[4]="XL";
            nd[5]="L";
            nd[6]="LX";
            nd[7]="LXX";
            nd[8]="LXXX";
            nd[9]="XC";

            nc[0]="";
            nc[1]="C";
            nc[2]="CC";
            nc[3]="CCC";
            nc[4]="CD";
            nc[5]="D";
            nc[6]="DC";
            nc[7]="DCC";
            nc[8]="DCCC";
            nc[9]="CM";

            nm[0]="";
            nm[1]="M";
            nm[2]="MM";
            nm[3]="MMM";

            milesimas=(numero/1000)%100;
            centenas=(numero/100)%10;
            decenas=(numero/10)%10;
            unidades=numero%10;
            string answer = nm[milesimas]+nc[centenas]+nd[decenas]+nu[unidades];
            return answer;
        }
}

int main() {

    IOS
    cin.tie(0);
    cout.tie(0);
    ///freopen("out.txt","w",stdout);
    int n;
    while(cin>>n)
    {
        ///cout<<n<<endl;

        string temp = toroman(n);
        int total=0;
        for(int i=0;i<temp.size();++i)
        {
            if(temp[i]=='I')total++;
            if(temp[i]=='V'||temp[i]=='X'||temp[i]=='L'||temp[i]=='C')total+=2;
            if(temp[i]=='D')total+=3;
            if(temp[i]=='M')total+=4;
        }
        cout<<total<<endl;
        ++n;
    }
}

/// This code is less virgin than me
