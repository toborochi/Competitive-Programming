#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

vector<int> arr;

void totop(int n,int i)
{
    int tmp=i,l=i*2+1,r=i*2+2;
    if(l<n && arr[l]>arr[tmp])tmp=l;
    if(r<n && arr[r]>arr[tmp])tmp=r;
    if(tmp!=i)
    {
        swap(arr[i],arr[tmp]);
        totop(n,tmp);
    }
}

void heap(int n)
{
    for(int i=n/2 -1;i>=0;--i)
    {
        totop(n,i);
    }
}

void add(int val,int pos)
{
    if(pos==arr.size())arr.push_back(val);
    int parent;
    if(pos%2==0)parent=pos/2 -1; else parent=pos/2;
    if(arr[pos]>arr[parent])
    {
        swap(arr[pos],arr[parent]);
        add(arr[parent],parent);
    }
    else return;
}


void poptop()
{
    int pos=arr.size()-1;
    swap(arr[0],arr[pos]);
    arr.pop_back();
    totop(arr.size(),0);
}

bool find(int val)
{
    int l,r;
    int n=arr.size();
    for(int i=0;i<=n/2 -1;++i)
    {
        l=2*i+1;
        r=2*i+2;
        if(arr[i]==val)return 1;
        if(l<n&&arr[l]==val)return 1;
        if(r<n&&arr[r]==val)return 1;
    }
    return 0;
}

int main()
{
    IOS
    ///freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    arr.assign(n,int());
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }

    heap(n); /// Iniciar el heap

    add(5,arr.size()); ///Insertar valor (valor, tamano)
    add(1,arr.size()); /// Insertar valor (valor, tamano)
    poptop(); /// Borrar el tope
    int maxi=arr[0]; /// Ver el mas grande
    cout<<find(98)<<endl; /// Ver si un elemento existe (nodo, elemento)

    for(int i=0;i<arr.size();++i)
    {
        cout<<arr[i]<<" ";
    }
}
/// This code is less virgin than me
