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

bool fun(vector<string> &A, vector<string> &B)
{
	int n = A.size();
	if(n==0) return true;
	bool can = false;

	vector<string> XB(n-1),XA(n-1);
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			XB[i-1].push_back(B[i][j]);
			XA[i-1].push_back(A[i][j]);
		}
	}

	if(A[0][0]==B[0][0])
	{
		
		vector<string> XXB = XB;
		vector<string> XXA = XA;
		for(int i=1;i<n;i++)
		{
			if(A[0][i]!=B[0][i])
			{
				for(int j=1;j<n;j++)
				{
					XXA[j-1][i-1] = '0' + (1-(XXA[j-1][i-1]-'0'));
				}
			}
			if(A[i][0]!=B[i][0])
			{
				for(int j=1;j<n;j++)
				{
					XXA[i-1][j-1] = '0' + (1-(XXA[i-1][j-1]-'0'));
				}
			}
		}
		can = (XXA == XXB);
		// cerr<<can<<" ";
		XXA = XA;
		XXB = XB;
		for(int i=1;i<n;i++)
		{
			if(A[0][i]==B[0][i])
			{
				for(int j=1;j<n;j++)
				{
					XXA[j-1][i-1] = '0' + (1-(XXA[j-1][i-1]-'0'));
				}
			}
			if(A[i][0]==B[i][0])
			{
				for(int j=1;j<n;j++)
				{
					XXA[i-1][j-1] = '0' + (1-(XXA[i-1][j-1]-'0'));
				}
			}
		}
		can = (XXA == XXB);
		// cerr<<can<<" ";
	}
	else
	{
		vector<string> XXB = XB;
		vector<string> XXA = XA;
		for(int i=1;i<n;i++)
		{
			if(A[0][i]==B[0][i])
			{
				for(int j=1;j<n;j++)
				{
					XXA[j-1][i-1] = '0' + (1-(XXA[j-1][i-1]-'0'));
				}
			}
			if(A[i][0]!=B[i][0])
			{
				for(int j=1;j<n;j++)
				{
					XXA[i-1][j-1] = '0' + (1-(XXA[i-1][j-1]-'0'));
				}
			}
		}
		can = can = (XXA == XXB);
		// cerr<<can<<" ";
		XXA = XA;
		XXB = XB;
		for(int i=1;i<n;i++)
		{
			if(A[0][i]!=B[0][i])
			{
				for(int j=1;j<n;j++)
				{
					XXA[j-1][i-1] = '0' + (1-(XXA[j-1][i-1]-'0'));
				}
			}
			if(A[i][0]==B[i][0])
			{
				for(int j=1;j<n;j++)
				{
					XXA[i-1][j-1] = '0' + (1-(XXA[i-1][j-1]-'0'));
				}
			}
		}

		can = can = (XXA == XXB);
		// cerr<<can<<" ";
	}
	// cout<<endl;
	return can;
}

int main()
{
	test()
	{
		int n;
		cin>>n;
		vector<string> A(n),B(n);
		take(A,0,n);
		take(B,0,n);
		bool can = fun(A,B);
		if(can) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}	