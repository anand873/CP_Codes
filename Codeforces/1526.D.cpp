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

vi find_inv(ll &ans, vi A, vi B)
{
	if(A.size()+B.size() == 0) return {0,{}};
	vi V(A.size()+B.size());
	int ai = 0, bi = 0;

	while(ai<A.size() && bi<B.size())
	{
		if(A[ai]<=B[bi])
		{
			V[ai+bi] = A[ai];
			ai++;
		}
		else
		{
			V[ai+bi] = B[bi];
			bi++;
			ans += ((int)A.size()-ai);
		}
	}
	while(ai<A.size())
	{
		V[ai+bi] = A[ai];
		ai++;
	}
	while(bi<B.size())
	{
		V[ai+bi] = B[bi];
		bi++;
	}

	return V;
}

ll find(string s, vi P)
{
	vector<char> C = {'A','N','T','O'};

	vvi V4(4);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==C[P[0]])
		{
			V4[0].push_back(i);
		}
		else if(s[i]==C[P[1]])
		{
			V4[1].push_back(i);
		}
		else if(s[i]==C[P[2]])
		{
			V4[2].push_back(i);
		}
		else V4[3].push_back(i);
	}

	ll ans = 0;
	vi A;

	A = find_inv(ans,V4[0],V4[1]);
	A = find_inv(ans,A,V4[2]);
	A = find_inv(ans,A,V4[3]);

	return ans;
}

int main()
{
	fastio
	test()
	{
		string s;
		cin>>s;
		
		string sa,sn,st,so;
		unordered_map<char,int> M;
		for(auto c:s) M[c]++;

		for(int i=0;i<M['A'];i++) sa+='A';
		for(int i=0;i<M['N'];i++) sn+='N';
		for(int i=0;i<M['T'];i++) st+='T';
		for(int i=0;i<M['O'];i++) so+='O';

		vector<string> S = {sa,sn,st,so};
		vi P = {0,1,2,3};

		ll ans = 0;
		string anss;
		do
		{	
			ll temp = find(s,P);

			if(temp >= ans)
			{
				ans = temp;

				string news;
				for(int i=0;i<4;i++)
				{
					news += S[P[i]];
				}
				anss = news;
			}
		}
		while(next_permutation(all(P)));

		cout<<anss<<'\n';
	}
}	