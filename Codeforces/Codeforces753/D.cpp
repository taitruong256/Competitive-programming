#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
char color[200005];


int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for (ll i=0; i<n; i++) cin>>a[i];
        for (ll i=0; i<n; i++) cin>>color[i];

        vector<int> red, blue;
        for (ll i=0; i<n; i++)
            if (color[i]=='B') blue.push_back(a[i]);
            else red.push_back(a[i]);
        sort(red.begin(), red.end());
        sort(blue.begin(), blue.end());
        reverse(blue.begin(), blue.end());

        for (ll i=0; i<red.size(); i++) cout<<red[i]<<" ";
        for (ll i=0; i<blue.size(); i++) cout<<blue[i]<<" ";


        bool check=true;
        for (ll i=0; i<red.size(); i++) if (blue[i]<i+1) check=false;
        for (ll i=0; i<blue.size(); i++) if (red[i]>n-i) check=false;

        if (check==true) cout<<"YES\n"; else cout<<"NO\n";
    }
    return 0;
}
