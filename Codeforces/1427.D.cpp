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
	int n;
	cin>>n;
	vi C(n);
	take(C,0,n);
	int curr=2;
	vvi Ans;
	for(int times=0;times<n;times++)
	{
		bool sorted=true;
		for(int i=0;i<n;i++)
		{
			if(C[i]!=i+1) sorted=false;
		}
		if(sorted) break;
		for(int i=1;i<=n;i++)
		{
			// cout<<i<<endl;
			int currpos,onepos;
			for(int j=0;j<n;j++)
			{
				if(C[j]==i) onepos=j;
			}
			int j=onepos;
			while(j<n&&C[j]==j-onepos+i)
			{
				j++;
			}
			int curr = C[j-1]+1;
			for(int j=0;j<n;j++)
			{
				if(C[j]==curr) currpos=j;
			}
			if(currpos>onepos) continue;
			else
			{
				vi X;
				if(currpos!=0)
				{
					X.push_back(currpos);
				}
				X.push_back(onepos-currpos);
				X.push_back(curr-i);
				if(onepos+curr-i!=n) X.push_back(n-(onepos+curr-i));
				vi Y(n);
				int idx=0,idx2=n;
				for(int j=X.size()-1;j>=0;j--)
				{
					idx2-=X[j];
					for(int k=0;k<X[j];k++)
					{
						Y[idx+k] = C[idx2+k];
					}
					idx+=X[j];
				}
				Ans.push_back(X);
				C = Y;
				// prinv(C);
				break;
			}
		}
	}

	cout<<Ans.size()<<endl;
	for(auto a:Ans)
	{
		cout<<a.size()<<" ";
		prinv(a);
	}

}	