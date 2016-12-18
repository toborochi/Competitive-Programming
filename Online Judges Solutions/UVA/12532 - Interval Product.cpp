#include <iostream>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int v[100001];
int tree[(sizeof v)*4];

void maketree(int node,int a,int b)
{
     if(a==b)
    {
        tree[node] = v[a];
        return;
    }
    maketree(2*node+1,a,(a+b)>>1);
    maketree(2*node+2,((a+b)>>1)+1,b);

    tree[node]= tree[2*node+1] * tree[2*node+2];
}

int query(int node,int a,int b,int p,int q)
{
    if(q<a || b<p)return 1;
    if(p<=a&&b<=q)return tree[node];
    return query(2*node+1,a,(a+b)>>1,p,q) * query(2*node+2,((a+b)>>1)+1,b,p,q);
}

void update(int node,int a,int b,int p,int v)
{
  if(p<a || b<p)return;
    if(a==b)
    {
        tree[node] = v;
        return;
    }
    update(2*node+1,a,(a+b)>>1,p,v);
    update(2*node+2,((a+b)>>1)+1,b,p,v);
    tree[node] =  tree[2*node+1] * tree[2*node+2];
}

int main()
{
    IOS
    cin.tie(NULL); cout.tie(NULL);
    int n,q,val,a,b;
    char act;

    while(cin>>n>>q)
    {
        string answer;
        for(int i=0;i<n;++i)
        {
            cin>>val;
            v[i] = ((val>0)?1:((val<0)?-1:0));
        }

        maketree(0,0,n-1);

        while(q--)
        {
            cin>>act>>a>>b;
            if(act=='P'){
            a--; b--;
            int aux = query(0,0,n-1,a,b);

            ///cout<<aux<<endl;
            answer += ((aux>0)?"+":((aux<0)?"-":"0"));}
            else
            {
                a--;
                b = ((b>0)?1:((b<0)?-1:0));
                update(0,0,n-1,a,b);
            }
        }
        cout<<answer<<endl;
    }
}
