#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> ke[1005];
string ten[1005];
int sodinh, cha[1005];
bool danhdau[1005];

void dfs(int u)
{
    danhdau[u]=true;
    for (auto [v, w]: ke[u]) if (danhdau[v]==false) 
    {
        dfs(v);
        cha[v]=u;
    }
}

void solve()
{
    cin>>sodinh; 
    for (int i=0; i<sodinh; i++) danhdau[i]=false;
    for (int i=0; i<sodinh; i++) cha[i]=-1;
    for (int i=0; i<sodinh; i++)
    {
        int dinhke; cin>>dinhke; 
        for (int j=0; j<dinhke; j++)
        {
            int k, trongso; cin>>k>>trongso;
            ke[i].push_back({k, trongso});  
        }
        cin>>ten[i];
    }
    dfs(0);
    if(danhdau[sodinh-1]==false)
    {
        cout<<"Khong co duong di tu dinh dau den dinh cuoi";
    }
    else 
    {
        int v=sodinh-1;
        vector<string> duongdi;
        while (v!=-1)
        {
            duongdi.push_back(ten[v]);
            v=cha[v];
        }
        reverse(duongdi.begin(), duongdi.end());
        for (int i=0; i<duongdi.size(); i++) cout<<duongdi[i]<<" ";
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
    return 0;
}