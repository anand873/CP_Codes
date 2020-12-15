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

vector<bool> is_prime(MAX+1, true);
vi MinDiv(MAX+1);
void Sieve()
{
	MinDiv[1]=1;
	is_prime[0] = is_prime[1] = false;
	int i,j;
	for (i = 2; i*i <= MAX; i++) 
	{
    	if (is_prime[i]) 
    	{
    		MinDiv[i]=i;
        	for (j = i * i; j <= MAX; j += i)
            {
            	if(is_prime[j]) MinDiv[j] = i;
				is_prime[j] = false;
    		}
    	}
	}
	for(int i=2;i<=MAX;i++) if(is_prime[i]) MinDiv[i] = i;
}

int main()
{
	Sieve();
	test()
	{
		// prinv(MinDiv);
		int n;
		cin>>n;
		set<int> D;
		set<int> P;
		for(int i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				D.insert(i);
				D.insert(n/i);
			}
		}
		D.insert(n);
		int prime = 0;
		for(int i=2;i*i<=n;i++)
		{
			if(is_prime[i])
			{
				if(n%i==0) P.insert(i);
				{
					while(n%i==0) {prime++;n/=i;}
				}
			}
		}
		if(n>1) {P.insert(n);prime++;}
		if(P.size()==1)
		{
			prinv(D);
			cout<<0<<endl;
		}
		else if(prime==2)
		{
			prinv(D);
			cout<<1<<endl;
		}
		else
		{
			set<int> Boun;
			vi Boundary;
			vi Prime;
			for(auto p:P) Prime.push_back(p);
			for(int i=0;i<Prime.size();i++)
			{
				Boundary.push_back(Prime[i]*Prime[(i+1)%Prime.size()]);
				Boun.insert(Boundary[i]);
			}

			vi X;
			for(int i=0;i<Prime.size();i++)
			{
				vi TE;
				X.push_back(Prime[i]);
				D.erase(Prime[i]);
				for(auto d:D)
				{
					if(d%Prime[i]==0&&Boun.count(d)==0)
					{
						X.push_back(d);
						TE.push_back(d);
					}
				}
				for(auto te:TE) D.erase(te);
				X.push_back(Boundary[i]);
				D.erase(Boundary[i]);
			}
			if(P.size()==2)
			{
				X.pop_back();
				for(int i=0;i<X.size();i++)
				{
					if(__gcd(X[i],X.back())!=1)
					{
						swap(X[0],X[i]);
						break;
					}
				}
			}
			prinv(X);
			cout<<0<<endl;
		}
	}
}	