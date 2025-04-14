#include<bits/stdc++.h>
#define MAX_N 100005
#define INF 987654321
using namespace std;
typedef long long lld;
bool visited[100005];
 
struct Point
{
    int X, Y, index;
    Point(){ this->X = this->Y = this->index = 0; }
    Point(int x, int y, int id){ this->X = x; this->Y = y; this->index = id;}
};
 
int n;
Point P[MAX_N];
Point R;

 
inline bool cmp(Point A, Point B)
{
    return atan2(A.Y-R.Y,A.X-R.X) < atan2(B.Y-R.Y,B.X-R.X);
}
 
inline double CCW(Point a, Point b, Point c)
{
    return ((b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X));
}
 
inline int GrahamScan(vector<Point> &cH)
{
    int min_id = 0;
    for (int i=1;i<=n;i++) if (visited[i]==false)
        if (P[i].Y < P[min_id].Y || (P[i].Y == P[min_id].Y && P[i].X < P[min_id].X))
            min_id = i;
    if (min_id==0) return 0;

    swap(P[1], P[min_id]);
    R = P[1];
    sort(P+2, P+n+1, cmp);
    
    P[0] = P[n];
    int HullSize = 1;
    
    for (int i=2;i<=n;i++) if (visited[i]==false)
    {
        
        while (CCW(P[HullSize-1], P[HullSize], P[i]) <= 0)
        {
            if (HullSize > 1) HullSize--;
            else if (i == n) break;
            else i++;
        }
        swap(P[++HullSize], P[i]);
    }
    
    for (int i=1;i<=HullSize;i++) cH.push_back(P[i]);
    int m=0;
    for (int i=1; i<=n; i++) visited[i]=false;
    for (int i=1; i<=n; i++) visited[cH[i].index]=true;
    for (int i=1; i<=n; i++) if (visited[i]==false) P[++m]=P[i];
    n=m;        cout<<n<<endl;
    return HullSize;
}
 
void solve()
{
    cin>>n;
    P[0]=Point(1e9, 1e9, 0);
    for (int i=1; i<=n; i++)
    {
        int x, y; cin>>x>>y;  
        P[i]=Point(x, y, i);
    }
    
    vector<Point> cH;
    int ans=0;
    int m;
    while (true) 
    {
        cH.clear();
        m=GrahamScan(cH);
        if (m==0) break;
        ++ans;
        cout<<m<<endl;
        for (int i=0; i<m; i++) cout<<cH[i].index<<" "; cout<<endl;
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}