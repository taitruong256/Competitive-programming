#include<bits/stdc++.h>
using namespace std;

bool nt(int n)
{
    if (n<2)return false;
    for (int i=2; i<=sqrt(n); i++) if (n%i==0) return false;
    return true;
}

int main()
{
    int n; cin>>n;
    queue<int> q;
    for (int i=2; i<=9; i++) if (nt(i)==true) q.push(i);
    while (!q.empty())
    {
        for (int i=1; i<=9; i++) 
        {
            int x=q.front()*10+i;
            if (x<=n && nt(x)==true) q.push(q.front()*10+i);
        }
            
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}