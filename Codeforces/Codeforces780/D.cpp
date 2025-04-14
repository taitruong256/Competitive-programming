#include<bits/stdc++.h>
using namespace std;
int main(){
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<int> a(n+2);
        vector<int> b; a[0] = 0; a[n+1] = 0;
        b.push_back(0);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] == 0){
                b.push_back(i);
            }
        }
        b.push_back(n+1);
        int cmax = 0; pair<int,int> ans;
        for(int i = 0; i < b.size() - 1; i++){
            int l1 = b[i], r1 = b[i+1], cnt = 0; bool check = false;
            for(int j = b[i] + 1; j <= b[i+1]-1;j++){
                if(a[j] < 0){
                    cnt++;
                    r1 = j;
                    if(check == false){
                        check = true;
                        l1 = j;
                    }
                }
            }
            if(cnt%2 == 0){
                int tempMax = 0;
                for(int j = b[i] + 1; j <= b[i+1]-1;j++){
                    if(a[j] == -2 || a[j] == 2){
                        tempMax++;
                    }
                }
                if(cmax < tempMax){
                    cmax = tempMax;
                    ans.first = b[i] + 1;
                    ans.second = b[i+1] - 1;
                }
            }
            else{
                int tempMax = 0;
                for(int j = l1 + 1; j <= b[i+1]-1;j++){
                    if(a[j] == -2 || a[j] == 2){
                        tempMax++;
                    }
                }
                if(cmax < tempMax){
                    cmax = tempMax;
                    ans.first = l1 + 1;
                    ans.second = b[i+1] - 1;
                }
                tempMax = 0;
                for(int j = b[i] + 1; j <= r1 - 1;j++){
                    if(a[j] == -2 || a[j] == 2){
                        tempMax++;
                    }
                }
                if(cmax < tempMax){
                    cmax = tempMax;
                    ans.first = b[i] + 1;
                    ans.second = r1 - 1;
                }
            }
        }
        if(cmax == 0){
            cout <<n<<" 0\n";
        }
        else{
            cout << ans.first - 1 <<" "<< n - ans.second<<"\n";
        }
    }
}