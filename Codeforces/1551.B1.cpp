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
#define test() int q;cin>>q;while(q--)
#define all(v) v.begin(),v.end()
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9,MAX = 3e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		string s;
		cin>>s;
		int k = 2;
		int n = s.length();
		vi A(n);
		for(int i=0;i<n;i++)
		{
			A[i] = s[i] - 'a';
		}
		vvi X(26);
		for(int i=0;i<n;i++)
		{
			X[A[i]].push_back(i);
		}
		vi Ans(n,-1);
		int curr = 0;
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<min(k,(int)X[i].size());j++)
			{
				Ans[X[i][j]] = curr;
				curr = (curr+1)%k;
			}
		}
		if(curr!=0)
		{
			set<int> S;
			for(int i=0;i<curr;i++) S.insert(i);

			for(int i=0;i<n;i++)
			{
				if(S.count(Ans[i]))
				{
					S.erase(Ans[i]);
					Ans[i] = -1;
				}
			}

		}
		int ans = 0;
		for(int i=0;i<n;i++)
		{
			if(Ans[i]==1) ans++;
		}
		cout<<ans<<endl;
		
	}
}	