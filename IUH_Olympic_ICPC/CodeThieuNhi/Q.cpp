#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    if (x1==x2)
    {
        cout<<min(x1, x2)+abs(y1-y2)<<" "<<y1<<" "<<min(x1, x2)+abs(y1-y2)<<" "<<y2;
    }
    else if (y1==y2)
    {
        cout<<x1<<" "<<min(y1, y2)+abs(x1-x2)<<" "<<x2<<" "<<min(y1, y2)+abs(x1-x2);
    }
    else if (abs(x1-x2)==abs(y1-y2))
    {
        cout<<x2<<" "<<y1<<" "<<x1<<" "<<y2;
    }
    else 
        cout<<-1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}