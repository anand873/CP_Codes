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

map<char,int> M;

bool cmp(string a, string b)
{
	int i=0;
	while(i<a.size()&&i<b.size()&&a[i]==b[i])
	{
		i++;
	}
	return (i==a.size()||(i<a.size()&&i<b.size()&&M[a[i]]<M[b[i]]));
}

int main()
{
	ll n,k;
	cin>>n>>k;
	vector<char> V;
	vector<vector<string>> D(n); 
	for(int i=0;i<n;i++)
	{
		int p;
		cin>>p;
		for(int j=0;j<k;j++)
		{
			string s;
			cin>>s;
			D[p].push_back(s);
		}
	} 
	map<char,vector<char>> M;
	for(int i=0;i<n;i++)
	{
		set<char> Done;
		vector<char> Temp;
		for(auto word:D[i])
		{
			for(auto c:word)
			{
				if(!Done.count(c))
				{
					Done.insert(c);
					Temp.push_back(c);
				}
			}
		}
		M[]
		for(int i=1;i<Temp.size())
	}
	for(int i=0;i<V.size();i++)
	{
		M[V[i]]=i;
	}

	vector<string> VV;
	VV = DD;
	sort(all(VV),cmp);
	prinv(VV);
	for(int i=0;i<DD.size();i++)
	{
		if(DD[i]!=VV[i])
		{
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
	}
	for(auto c:V) cout<<c;
	cout<<endl;

}	