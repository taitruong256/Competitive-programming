int T; cin >> T;
    while(T--){
        string s; cin >> s; int l = 0;
        int cnt = 0;
        while(l < s.size()){
            map<char,int> temp;
            int k;
            for(k = l; k < s.size();k++){
                if(temp[s[k]] == 0){
                    cnt++;
                    temp[s[k]]++;
                }
                else{
                    cnt--;
                    break;
                }
            }
            l = k + 1;

        }
        cout << cnt<< endl;
    }
