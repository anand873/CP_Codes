//Author: AnandRaj uux
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
const int MOD = 1e9+7,MAX = 1e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int cnt = 0;
		for(int i=0;i+6<n;i++)
		{
			string sy = s.substr(i,7);
			if(sy=="abacaba") cnt++;
		}
		if(cnt==1)
		{
			cout<<"Yes"<<endl;
			for(int i=0;i<n;i++)
			{
				if(s[i]=='?') s[i]='d';
			}
			cout<<s<<endl;
		}
		else if(cnt==0)
		{
			bool done=false;
			for(int i=0;i+6<n;i++)
			{
				string temp = s;
				string sx = s.substr(i,7);
				string cmp = "abacaba";
				bool can = true;
				for(int j=0;j<7;j++)
				{
					if(cmp[j]==sx[j]) continue;
					else if(sx[j]=='?')
					{
						temp[i+j]=cmp[j];
					}
					else can=false;
				}
				if(!can) continue;
				else
				{
					int str = max(0,i-7);
					int len = min(21,n-str);
					string news = temp.substr(str,n);
					int cnt2=0;
					// cout<<temp<<endl;
					for(int j=0;j+6<news.length();j++)
					{
						string th = news.substr(j,7);
						if(th=="abacaba") cnt2++;
					}
					// cout<<cnt2<<endl;
					if(cnt2==1)
					{
						for(int j=0;j<n;j++)
						{
							if(temp[j]=='?') temp[j]='d';
						}
						done=true;
						cout<<"Yes"<<endl;
						cout<<temp<<endl;
						break;
					}
				}

			}
			if(!done) cout<<"No"<<endl;
		}
		else cout<<"No"<<endl;
	}
}	