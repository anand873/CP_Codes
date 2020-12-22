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

vector<bool> is_prime(MAX, true);
vi MinDiv(MAX);
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

int main()
{
	int n;
	cin>>n;
	vi A(n);
	take(A,0,n);
	set<int> D;
	Sieve();
	int last = A[n-1];
	
	while(last>1)
	{
		int x = MinDiv[last];
		D.insert(x);
		while(last%x==0)
		{
			last/=x;
		}
	}
	bool can=true;
	for(int i=n-2;i>=0;i--)
	{
		vi P;
		int num = A[i];
		while(num>1)
		{
			int x = MinDiv[num];
			P.push_back(x);
			while(num%x==0)
			{
				num/=x;
			}
		}
		for(auto p:P)
		{
			if(D.count(p)) can=false;

			D.insert(p);
		}
		if(!can) break;
	}
	if(can) cout<<"pairwise coprime"<<endl;
	else
	{
		int g = A[0];
		for(int i=1;i<n;i++) g = __gcd(g,A[i]);

		if(g==1) cout<<"setwise coprime"<<endl;
		else cout<<"not coprime"<<endl;
	}

}	