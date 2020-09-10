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
	fastio
	int n;
	cin>>n;
	vector<string> V(n);
	take(V,0,n);
	map<string,vi> M;
	for(int i=0;i<n;i++)
	{
		reverse(all(V[i]));
		M[V[i]].push_back(i+1);
	}
	int q;
	cin>>q;

	string X;
	string Ans;
	for(int i=0;i<q;i++)
	{
		char c;
		cin>>c;
		X.push_back(c);
		int curr = X.size()-1;
		string temp = "";
		vector<int> V;
		for(int i=curr;i>=max(0,curr-100);i--)
		{
			temp+=X[i];
			if(M.find(temp)!=M.end())
			{
				for(auto v:M[temp])
				{
					V.push_back(v);
				}
			}
		}
		for(auto s:V) Ans.push_back('1'-s%2);
	}
	cout<<Ans<<"\n";



}	