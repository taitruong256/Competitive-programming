#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, k; cin>>n;
    int a[n+1];
    bool dau[1001];
    for (int i=0; i<1001; i++) dau[i]=false;
    for (int i=1; i<=n; i++) cin>>a[i];
    cin>>k;
    queue<int> q;
    for (int i=1; i<=n; i++) if (dau[a[i]]==false)
    {
        if (q.size()<k)
        {
            q.push(a[i]);
            dau[a[i]]=true;
        }
        else 
        {
            q.push(a[i]);
            dau[q.front()]=false;
            dau[a[i]]=true;
            q.pop();
        }
    }
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}