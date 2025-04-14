#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k, x;

ll tinh(ll n)
{
    if (n<=k) return k*(k+1)/2;
    else
    {
        if (n>2*k) n=2*k-1;
        return k*(k+1)/2+k*k-(n-k)*(n-k+1)/2;
    }
}

void solve()
{

    cin>>k>>x;
    if (x>=k*(k+1)-k)
    {            cout<<"-----1---------"<<endl;
        cout<<2*k-1<<endl;
        return;
    }
    else if (k*(k+1)/2==x)
    {                   cout<<"-----2---------"<<endl;
        cout<<k<<endl;
        return;
    }
    else if (x<k*(k+1)/2)
    {                     cout<<"-----3---------"<<endl;
        ll l=1, r=2*k;
        while (l<r)
        {         cout<<l<<" "<<r<<endl;
            ll mid=(l+r)/2;
            if (x<mid*(mid+1)/2) r=mid-1;
            else if (x>mid*(mid+1)/2) l=mid+1;
            else break;

        }
        cout<<l<<endl;
        return;
    }
    else
    {                 cout<<"-----4---------"<<endl;
        ll l=1, r=2*k;
        while (l<r)
        {         cout<<l<<" "<<r<<endl;
            ll mid=(l+r)/2;
            ll t=k*k-(mid-k)*(mid-k+1)/2;
            if (x<t) r=mid-1;
            else if (x>t) l=mid+1;
            else break;

        }
        cout<<l<<endl;
        return;
    }
}

int main()
{
    ll t;
    t=1; cin>>t;
    while (t--)
    {
        //solve();
        cin>>k>>x;
        cout<<tinh(2*k)<<endl;
    }
    return 0;
}
