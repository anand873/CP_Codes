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

vi A;
vi P;

void dfs(int u)
{
	if(P[A[u]]==0)
	{
		P[A[u]] = u;
		dfs(A[u]);
	}
}

int main()
{
	test()
	{
		int n;
		cin>>n;
		A.resize(n+1);
		P.resize(n+1);
		take(A,1,n);

		for(int i=1;i<=n;i++)
		{
			dfs(i);
		}

		vi B(n+1);
		vi V;
		vi I;
		int k = 0;
		set<int> S;

		for(int i=1;i<=n;i++)
		{
			S.insert(i);
		}
		// prinv(P);
		for(int i=1;i<=n;i++)
		{
			if(P[i]==0)
			{
				V.push_back(i);
				k++;
			}
			else
			{
				S.erase(P[i]);
				B[P[i]] = i;
			}
		}
		for(auto s:S) I.push_back(s);
		// prinv(B);
		// prinv(I);
		// prinv(V);
		if(V.size()==1 && V[0]==I[0])
		{
			B[V[0]] = A[V[0]];
			B[P[A[V[0]]]] = V[0];
		}
		else
		{
			set<int> VV;
			for(auto v:V) VV.insert(v);

			for(auto v:VV)
			{
				if(v!=I[0])
				{
					B[I[0]] = v;
					VV.erase(v);
					break;
				}
			}

			for(int i=1;i<k;i++)
			{
				if(*VV.begin() == I[i])
				{
					B[I[i]] = B[I[0]];
					B[I[0]] = *VV.begin();
				}
				else
				{
					B[I[i]] = *VV.begin();
				}

				VV.erase(*VV.begin());
			}
		}
		int ans = 0;
		for(int i=1;i<=n;i++)
		{
			if(A[i]==B[i]) ans++;
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		{
			cout<<B[i]<<" ";
		}
		cout<<endl;
		A.clear();
		P.clear();

	}
}	