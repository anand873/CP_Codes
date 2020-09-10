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
const int MOD = 998244353,MAX = 2e5+5;
const ll INF = 1e18+5;


int main()
{
	fastio
	int n;
	cin>>n;
	vi A(n);
	take(A,0,n);
	map<int,int> M;
	vvi In(n);
	for(int i=0;i<n;i++) 
	{
		In[A[i]].push_back(i+1);
		M[A[i]]++;
	}
	int curr=0;
	vi X;
	bool can=true;
	vi Ans;
	for(int i=0;i<n;i++)
	{
		if(M[curr]!=0)
		{
			Ans.push_back(In[curr].back());
			In[curr].pop_back();
			M[curr]--;
			curr++;
		}
		else
		{
			bool thiscan=false;
			for(int j=curr-3;j>=0;j-=3)
			{
				if(M[j]!=0) 
				{
					Ans.push_back(In[j].back());
					In[j].pop_back();
					M[j]--;
					thiscan=true;
					curr=j+1;
					break;
				}
			}
			if(thiscan) continue;
			else {can=false;break;}
		}
	}
	if(can)
	{
		cout<<"Possible"<<endl;
		prinv(Ans);
	}
	else cout<<"Impossible"<<endl;
	
}
