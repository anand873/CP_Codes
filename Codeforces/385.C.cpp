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
const int MOD = 1e9+7,MAX = 1e7+5;
const ll INF = 1e18+5;

vector<bool> is_prime(MAX, true);
vi MinDiv(MAX);
void Sieve()
{
	is_prime[0] = is_prime[1] = false;
	int i,j;
	for (i = 2; i*i < MAX; i++) 
	{
    	if (is_prime[i]) 
    	{
    		MinDiv[i]=i;
        	for (j = i * i; j < MAX; j += i)
            {
            	if(is_prime[j]) MinDiv[j]=i;
				is_prime[j] = false;
    		}
    	}
	}
	MinDiv[1]=1;
	for(int i=2;i<MAX;i++) if(is_prime[i]) MinDiv[i] = i;
}



int main()
{
	fastio
	int n;
	cin>>n;
	vi A(n);
	take(A,0,n);
	Sieve();
	vector<int> M(MAX);
	for(int i=0;i<n;i++)
	{
		while(A[i]>1)
		{
			set<int> S;
			while(A[i]>1)
			{
				S.insert(MinDiv[A[i]]);
				A[i]/=MinDiv[A[i]];
			}
			for(auto s:S) M[s]++;
		}
	}
	for(int i=1;i<MAX;i++) M[i] += M[i-1];
	int m;
	cin>>m;
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		r = min(r,MAX-1);
		l = min(l,MAX);
		cout<<M[r]-M[l-1]<<'\n';
	}


}	