#include "MXORLIB.h"
#define ll int

main(){
    ll n = get_n();
    assert(n<=17);
    vector<pair<ll, ll>> ans;
    set<ll> stI, stJ;
    for (ll i=1; i<=n; i++) stJ.insert(i);

    for (ll i=1; i<=n; i++)
    {
        stI.insert(i);
        stJ.erase(i);
        vector<ll> I, J;
        for (ll x: stI) I.push_back(x);
        for (ll x: stJ) J.push_back(x);
        ll res=max_xor(I, J);
        ans.push_back({res, -i});
        stI.erase(i);
        stJ.insert(i);
    }
    sort(ans.begin(), ans.end(), greater<pair<ll, ll>>());
    ll x=-ans[0].second;
    ll y=-ans[1].second;
    answer(x, y);
}
