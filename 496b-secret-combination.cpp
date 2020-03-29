#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define vec(x) vector< x >
#define pb push_back
#define all(x) x.begin(), x.end()
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef long long ll;
typedef long double f80;
void convert(string &s, vector <int> &v)
{    for (int i = 0; i<s.size() ;i++)
          v[i] = s[i] - '0';
}
void addition(vector <int> &v)
{    int a = 9-v[0]+1;
     for(int i = 0; i<v.size() ; i++)
     {
          v[i] = (v[i]+a)%10;    
     }
}
bool check(vector <int> &v1,vector <int> &v2)
{
     for(int i = 0; i<v1.size() ; i++)
     {    if(v1[i]<v2[i])     return true;
          if(v1[i]>v2[i])     return false;
     }
     return false;
}
int main() {
     ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
     int n; string s; cin>>n>>s;
     vector <int> v(s.size()),vo(s.size()),vmin(s.size());
     convert(s,v);
     vo = v;
     addition(v);
     vmin = v;
     int i = 0;
     while(i<n)
     {    rotate(v.begin(), v.begin()+v.size()-1, v.end());
          addition(v);
          if(check(v,vmin))
               vmin = v;
          i++;
     }
     for(int x: vmin)
          cout<<x;
     return 0;
}

