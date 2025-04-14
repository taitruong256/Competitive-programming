#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n+1];
    for (int i=0; i<n; i++) cin>>a[i];
    stack<int> st;

    for (int i=0; i<n; i++)
    {
        while (!st.empty() && a[st.top()]<=a[i])
            st.pop();
        int ans=-1;
        if (!st.empty()) ans=st.top();
        if (ans==-1) cout<<ans<<" "; else cout<<ans+1<<" ";
        st.push(i);
    }
    return 0;
}


