#include <iostream>
#include <sstream>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int centenas;
int decenas,milesimas,unidades;
string nm[10];
string nc[10];
string nd[10];
string nu[10];


int value(char roman)
{
   switch(roman)
   {
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
   }
}

int getdec(string input)
{
  int sum=0; char prev='%';
  for(int i=(input.length()-1); i>=0; i--)
  {
    if(value(input[i])<sum && (input[i]!=prev))
    {       sum -= value(input[i]);
            prev = input[i];
    }
    else
    {
            sum += value(input[i]);
            prev = input[i];
    }
  }
  return sum;
}

void toroman(int numero)
{
    if (numero==1000) {
            cout<<"M"<<endl;
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
            cout<<nm[milesimas]<<nc[centenas]<<nd[decenas]<<nu[unidades]<<endl;
        }
}

int main() {

    IOS
    cin.tie(0);
    cout.tie(0);
    ///freopen("out.txt","w",stdout);
    string ss;
    while(cin>>ss)
    {
        if(isalpha(ss[0]))
        {
            cout<<getdec(ss)<<endl;
        }
        else
        {
            stringstream temp;
            temp<<ss;
            int derp;
            temp>>derp;
            ///cout<<derp<<endl;
            toroman(derp);
        }

    }
}

/// This code is less virgin than me
