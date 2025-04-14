#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fi first
#define se second
#define po pop
#define pu push
#define ety empty
#define tp top
#define ft front
#define bk back
#define ll long long
#define int ll
const ll MOD = 1e18;

ll yo[200005]={};
pair <string,ll> tmp_x[200005]={};
pair <string,ll> tmp_y[200005]={};
pair <ll,ll> x[200005]={};
pair <ll,ll> y[200005]={};
ll sum[1600005]={};
ll key[1600005]={};
int ic=1;

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
//    	cout<<id<<" "<<val<<" "<<key[id]<<"->";
    	key[id]+= val;
//    	cout<<key[id]<<" "<<min(r+1,ic)<<":"<<yo[min(r+1,ic)]-1<<" "<<l<<":"<<yo[l]<<endl;
        sum[id]= (yo[min(r+1,ic)]-1 - yo[l] +1) * (key[id]>0?1:0);
        if (key[id]==0) sum[id] = (sum[id*2] + sum[id*2 + 1]);
		return;
    }

    int mid = (l + r) / 2;
    update(id*2    , l    , mid, u, v, val);
    update(id*2 + 1, mid+1, r  , u, v, val);
//    cout<<id<<" "<<key[id]<<" "<<sum[id]<<" "<<sum[id*2]<<" "<<sum[id*2 + 1]<<endl;
	if (key[id]==0) sum[id] = (sum[id*2] + sum[id*2 + 1]);
}

int get() {
    return sum[1];
}

bool cmp (pair <string,ll> a,pair <string,ll> b){
	if (a.fi[0]=='-'&&b.fi[0]!='-') return true; 
	if (a.fi[0]!='-'&&b.fi[0]=='-') return false; 
	if (a.fi[0]=='-'&&b.fi[0]=='-') return ( (a.fi.size()>b.fi.size()) || (a.fi.size()==b.fi.size() && a.fi.compare(b.fi)>0) || (a.fi.size()==b.fi.size() && a.fi.compare(b.fi)==0 && a.se>b.se));
	return ((a.fi.size()<b.fi.size()) || (a.fi.size()==b.fi.size() && a.fi.compare(b.fi)<0) || (a.fi.size()==b.fi.size() && a.fi.compare(b.fi)==0 && a.se>b.se));
}

ll DIVM(string x){
	ll key=0;
	if (x[0]=='-') key++;
	ll tmp=0;
	ll len=x.length();
	for (ll i=0+key;i<len;i++)
		tmp = (tmp*10 + x[i] - '0');
	if (key) return-tmp; return tmp;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
	ll n,k,ans=0,tmp;
    ll xx=0, yy=0;
	string x1,y1,x2,y2;
	cin>>k>>n;   
    n+=1;
	for (ll i=0;i<n;i++) {
        if (i==0)
        {
            x1=to_string(0);
            y1=to_string(0);
            x2=to_string(k-1);
            y2=to_string(k-1);  
            tmp_x[i*2]=mp(x1,(i+1));
            tmp_x[i*2+1]=mp(x2,-(i+1));
            tmp_y[i*2]=mp(y1,(i+1));
            tmp_y[i*2+1]=mp(y2,-(i+1));
            continue;
        }
        char c;
        ll d; 
        cin>>c>>d;
        if (c=='N') 
        {
            x1=to_string(xx);
            y1=to_string(yy);
            x2=to_string(xx+k-1);
            y2=to_string(yy+d+k-1);
            yy+=d;
        }
        else if (c=='S')
        {
            x1=to_string(xx);
            y1=to_string(yy-d);
            x2=to_string(xx+k-1);
            y2=to_string(yy+k-1);
            yy-=d;
        }
        else if (c=='W')
        {
            x1=to_string(xx-d);
            y1=to_string(yy);
            x2=to_string(xx+k-1);
            y2=to_string(yy+k-1);
            xx-=d;
        }
        else
        {
            x1=to_string(xx);
            y1=to_string(yy);
            x2=to_string(xx+d+k-1);
            y2=to_string(yy+k-1);
            xx+=d;
        }
		tmp_x[i*2]=mp(x1,(i+1));
		tmp_x[i*2+1]=mp(x2,-(i+1));
		tmp_y[i*2]=mp(y1,(i+1));
		tmp_y[i*2+1]=mp(y2,-(i+1));
	}
	sort(tmp_x,tmp_x+n*2,cmp);
	sort(tmp_y,tmp_y+n*2,cmp);

	
	yo[1]=DIVM(tmp_y[0].fi);
	y[0].fi=abs(tmp_y[0].se)-1;
	y[0].se=1;
	for (ll i=1;i<2*n;i++){
		tmp=DIVM(tmp_y[i].fi);
		if (tmp_y[i].se<0) tmp = (tmp + 1);
		if (yo[ic]!=tmp) {
			ic++;
			yo[ic]=tmp;
		};
		y[i].fi=abs(tmp_y[i].se)-1;
		y[i].se=ic;
	}
	sort(y,y+n*2);
	
	for (ll i=0;i<2*n;i++){
		x[i].fi=DIVM(tmp_x[i].fi);
		x[i].se=tmp_x[i].se;
		if (x[i].se<0) x[i].fi = (x[i].fi +1); 
	}

	
	for (ll i=0;i<2*n-1;i++){
		update(1,1,n*2,y[(abs(x[i].se)-1)*2].se,y[(abs(x[i].se)-1)*2+1].se-1,(x[i].se<0?-1:1));
		ans = (ans + (( x[i+1].fi - x[i].fi)* get()) );
	}
	cout<<ans;
}
