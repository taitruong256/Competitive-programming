#include <bits/stdc++.h>
using namespace std;
vector<int> giatri;
vector<char> pheptinh;

int uutien(char phep)
{
    if (phep=='+' || phep=='-') return 1;
    else return 2;
}

void xuli(vector<int>& giatri, char phep)
{
    int r=giatri.back(); giatri.pop_back();
    int l=giatri.back(); giatri.pop_back();
    switch(phep)
    {
    case '+': giatri.push_back(l + r); break;
    case '-': giatri.push_back(l - r); break;
    case '*': giatri.push_back(l * r); break;
    case '/': giatri.push_back(l / r); break;
    }
}
int tinh(string s)
{
    for (int i=0; i<s.size();i++)
    {
        if (s[i]>='0' && s[i]<='9')
        {
            int number=0;
            while (i<s.size() && s[i]>='0' && s[i]<='9')
            {
                number=number*10+s[i]-'0';
                ++i;
            }
            giatri.push_back(number);
            --i;
        }
        else
        {
            char phep_ht=s[i];
            while (!pheptinh.empty() && uutien(pheptinh.back()>=uutien(phep_ht)))
            {
                xuli(giatri, pheptinh.back());
                pheptinh.pop_back();
            }
            pheptinh.push_back(phep_ht);
        }
    }
    while (!pheptinh.empty())
    {
        xuli(giatri, pheptinh.back());
        pheptinh.pop_back();
    }
    return giatri.back();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    cout<<tinh(s);
    return 0;
}


