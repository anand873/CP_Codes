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
	test()
	{
		int n;
		cin>>n;
		vl A(n);
		take(A,0,n);

		ll prod = -INF;
		vl P,N;
		for(int i=0;i<n;i++)
		{
			if(A[i]>0) P.push_back(A[i]);
			else if(A[i]<0) N.push_back(A[i]); 
		}
		if(P.size()+N.size()<5) cout<<0<<endl;
		else
		{
			sort(all(P));
			reverse(all(P));
			sort(all(N));
			for(int i=max(5-(int)N.size(),0);i<=min((int)P.size(),5);i++)
			{
				ll temp = 1;
				if(i%2)
				{
					for(int j=0;j<i;j++)
					{
						temp*= P[j];
					}
					for(int j=0;j<5-i;j++)
					{
						temp*=N[j];
					}
					// cerr<<i<<" "<<temp<<endl;
					prod = max(prod,temp);
				}
				else
				{
					for(int j=0;j<i;j++)
					{
						temp*= P[P.size()-1-j];
					}
					for(int j=0;j<5-i;j++)
					{
						temp*=N[N.size()-1-j];
					}
					// cerr<<i<<" "<<temp<<endl;
					prod = max(prod,temp);
				}
			}
			if(P.size()+N.size()<n) prod = max(prod,0ll);
			cout<<prod<<endl;
		}

	}
}	