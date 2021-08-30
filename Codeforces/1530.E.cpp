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
const int MOD = 1e9+7,MAX = 2e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		string s;
		cin>>s;
		int n = s.length();
		sort(all(s));
		
		map<char,int> M;
		for(auto c:s) M[c]++;

		vector<char> C;
		C.push_back(s[0]);
		for(int i=1;i<n;i++)
		{
			if(s[i]!=s[i-1]) C.push_back(s[i]);
		}

		int dis = C.size();

		int howsmall = M.begin()->second;
		int extra = n - howsmall;
		bool oneone = false;
		char chargood;

		for(int i=0;i<dis;i++)
		{
			if(M[C[i]]==1)
			{
				oneone = true;
				chargood = C[i];
				break;
			}
		}

		if(oneone)
		{
			string ss;
			ss += chargood;
			for(int i=0;i<n;i++)
			{
				if(s[i]!=chargood) ss.push_back(s[i]);
			}
			cout<<ss<<endl;
		}
		else if(dis==1)
		{
			cout<<s<<endl;
		}
		else if(dis==2)
		{
			if(extra >= (howsmall - 2))
			{
				string ss;
				ss.push_back(s[0]);
				ss.push_back(s[1]);
				int kittaleft = howsmall-2;
				for(int i=howsmall;i<n;i++)
				{
					ss += s[i];
					for(int j=0;j<min(kittaleft,1);j++)
					{
						ss += s[0];
					}
					kittaleft = max(0,kittaleft - 1);
				}
				cout<<ss<<endl;
			}
			else
			{
				string ss;
				for(int i=howsmall-1;i<n;i++) ss+=s[i];
				for(int i=0;i<howsmall-1;i++) ss+=s[i];

				cout<<ss<<endl;
			}
		}
		else
		{
			if(extra >= (howsmall - 2))
			{
				string ss;
				ss.push_back(s[0]);
				ss.push_back(s[1]);
				int kittaleft = howsmall-2;
				for(int i=howsmall;i<n;i++)
				{
					ss += s[i];
					for(int j=0;j<min(kittaleft,1);j++)
					{
						ss += s[0];
					}
					kittaleft = max(0,kittaleft - 1);
				}
				cout<<ss<<endl;
			}
			else
			{

				string ss;
				ss.push_back(C[0]);
				M[C[0]]--;
				ss.push_back(C[1]);
				M[C[1]]--;

				for(int i=0;i<M[C[0]];i++)
				{
					ss.push_back(C[0]);
				}
				M[C[0]] = 0;
				ss.push_back(C[2]);
				M[C[2]]--;

				for(auto m:M)
				{
					for(int i=0;i<m.second;i++)
					{
						ss.push_back(m.first);
					}
				}
				cout<<ss<<endl;
			}
		}

	}
}	