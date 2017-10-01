#include <iostream>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int kadane(int *a, int n)
{
	int max_ending_here = a[0], max_so_far = a[0];
	for(int i = 1; i < n; i++)
	{
		max_ending_here = max(a[i], max_ending_here + a[i]);
		max_so_far = max(max_so_far, max_ending_here);
	}
	return max_so_far;

}

int main()
{
	///freopen("out.txt","w",stdout);
    IOS
    int n;
    while(cin>>n)
    {
        int v[n],cost;
        cin>>cost;
        for(int i=0;i<n;++i)
        {
            cin>>v[i];
            v[i]-=cost;
        }
        int answer = kadane(v,n);
        cout<<((answer<=0)?0:answer)<<endl;
    }
}
/// Out of the Blue
