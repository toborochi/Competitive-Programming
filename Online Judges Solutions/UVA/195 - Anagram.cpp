#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

bool comparator(char a, char b){
	if(tolower(a) == tolower(b)){
		return a<b;
	}
	return tolower(a) < tolower(b);
}

int main()
{
    IOS
    int cases;
    string ss;
    cin>>cases;
    cin.ignore();
    while(cases--)
    {
        cin>>ss;
        sort(ss.begin(),ss.end(),comparator);

        do
        {
            cout <<ss<< endl;
        }
        while(next_permutation(ss.begin(),ss.end(),comparator));

    }
}
