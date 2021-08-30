//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vpll; 

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int t;cin>>t;while(t--)
#define all(v) v.begin(),v.end()
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9+7,MAX = 1e6+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		set<int> Sa;

		for(int i=0;i<n;i++)
		{
			int len = 4;
			if(str[i]<='b')
			{
				len = 5;
			}
			int ss = 0;

			for(int j=i;j<min(n,i+len);j++)
			{
				ss = ss*26 + (str[j]-'a'+1);
				Sa.insert(ss);
			}
		}
		for(int i=1;i<=1000000;i++)
		{
			if(Sa.count(i)==0)
			{
				string ans;
				int curr = i;
				while(curr)
				{
					ans += ('a'+(curr-1)%26);
					curr /= 26;
				}
				reverse(all(ans));
				cout<<ans<<endl;
				break;
			}
		}

	}
}	