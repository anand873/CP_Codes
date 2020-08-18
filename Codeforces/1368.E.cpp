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
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 1e6+5;
/////////////////FastExp///////////////////
ll powN(ll a,ll p,ll mod)
{
	if(p==0) return 1;
	ll z=powN(a,p/2,mod);
	z=(z*z)%mod;
	if(p%2) z=(z*a)%mod;
	return z;
}
/////////////////FastExp///////////////////
//////////////////Sieve////////////////////
vector<bool> is_prime(MAX, true);
vector<int> MinDiv(MAX);
void Sieve()
{
	is_prime[0] = is_prime[1] = false;
	int i,j;
	for (i = 2; i*i <= MAX; i++) 
	{
    	if (is_prime[i]) 
    	{
    		MinDiv[i]=i;
        	for (j = i * i; j <= MAX; j += i)
            {
				is_prime[j] = false;
				MinDiv[j]=i;
    		}
    	}
	}
	for(int i=2;i<=MAX;i++) if(is_prime[i]) MinDiv[i]=i;
}
//////////////////Sieve////////////////////

int main()
{
	test()
	{
		int n,m;
		cin>>n>>m;
		vvi A(n+1);
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			A[x].push_back(y);
		}

		queue<pii> Q;
		vector<bool> vis(n+1);
		set<int> S;
		for(int i=0;i<n;i++) S.insert(i+1);
		vi MC;
		while(S.size())
		{
			vector<int> C,UC;
			int upar = *(S.begin());
			vis[upar]=true;
			Q.push({upar,1});
			while(!Q.empty())
			{
				int curr = Q.front().first;
				int level = Q.front().second;
				S.erase(curr);
				Q.pop();
				if(level%2)
				{
					C.push_back(curr);
				}
				else UC.push_back(curr);

				for(auto v:A[curr])
				{
					if(!vis[v])
					{
						vis[v]=true;
						Q.push({v,level+1});
					}
				}
			}
			if(C.size()<UC.size())
			{
				for(auto c:C) MC.push_back(c);
			}
			else
			{
				for(auto c:UC) MC.push_back(c);
			}
		}

		cout<<MC.size()<<endl;
		prin(MC);
			
	}
}		