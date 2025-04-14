/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll x1,y1,x2,y2,x3,y3;
    double a,b;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (x1==0 && x2==0) {
        if (x3==0) {
            cout << "TOUCH" << endl;
            return;
        }
        else if (x3>0) {
            cout << "RIGHT" << endl;
            return;
        }
        else {
            cout << "LEFT" << endl;
            return;
        }
    }
    if (y1==0 && y2==0) {
        if (y3==0) {
            cout << "TOUCH" << endl;
            return;
        }
        else if (y3<0) {
            cout << "RIGHT" << endl;
            return;
        }
        else {
            cout << "LEFT" << endl;
            return;
        }
    }
    a = double((y1-y2))/double((x1-x2));
    b = y1 - double(a*x1);
    if (abs(a*x1-y1-a*x3+y3)<1e-6) {
        cout << "TOUCH" << endl;
    }
    else {
        double y4 = double(y1*x3)/double(x1);
        if (y4 > y3) {
            cout << "RIGHT" << endl;
            return;
        }
        else {
            cout << "LEFT" << endl;
            return;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}