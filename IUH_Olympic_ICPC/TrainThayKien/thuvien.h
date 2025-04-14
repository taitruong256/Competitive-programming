
string trai(string s)
{
    string t; s=" "+s;
    t.push_back(s[4]); 
    t.push_back(s[1]); 
    t.push_back(s[3]); 
    t.push_back(s[5]); 
    t.push_back(s[2]); 
    t.push_back(s[6]); 
    return t;
}

string phai(string s)
{
    string t; s=" "+s;
    t.push_back(s[1]); 
    t.push_back(s[5]); 
    t.push_back(s[2]); 
    t.push_back(s[4]); 
    t.push_back(s[6]); 
    t.push_back(s[3]); 
    return t;
}