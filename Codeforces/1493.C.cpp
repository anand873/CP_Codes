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
const int MOD = 1e9+7,MAX = 1e6+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		if(n%k) cout<<-1<<endl;
		else
		{
			vector<int> H(26);
			for(int i=0;i<n;i++)
			{
				H[s[i] - 'a']++;
			}
			bool div = true;
			for(int j=0;j<26;j++) if(H[j]%k) div = false;

			if(div)
			{
				cout<<s<<endl;
				continue;
			}
			string ans;
			for(int i=n-1;i>=0;i--)
			{
				if(s[i]=='z') continue;
				for(int j=s[i]-'a'+1;j<26;j++)
				{
					vector<int> BH = H;
					BH[s[i]-'a']--;
					BH[j]++;
					int sum = 0;
					for(int v=0;v<26;v++)
					{
						BH[v]%=k;
						BH[v] = k-BH[v];
						BH[v]%=k;
						sum += BH[v];
					}
					if(sum > n-i-1)
					{
						continue;
					}
					else
					{
						string ta;
						for(int v=0;v<26;v++)
						{
							for(int u=0;u<BH[v];u++) ta += ('a'+v);
						}
						while(ta.length()!=n-i-1) ta += 'a';
						sort(all(ta));
						string ts = s;
						ts[i] = 'a' + j;
						for(int v=i+1;v<n;v++) ts[v] = ta[v-i-1];
						// cout<<ts<<endl;
						ans = (ans=="")?ts:min(ans,ts);
					}
				}
				H[s[i] - 'a']--;
			}
			cout<<ans<<endl;
		}
	}
}	