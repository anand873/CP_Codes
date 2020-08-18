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

const int MOD = 998244353,MAX = 1e6+5;
/////////////////FastExp///////////////////
ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
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
		int n,k;
		cin>>n>>k;
		vvi S(k);
		for(int i=0;i<k;i++)
		{
			int c;
			cin>>c;
			for(int j=0;j<c;j++)
			{
				int x;
				cin>>x;
				S[i].push_back(x);
			}
		}

		vi K(k);
		int hap = 0;
		int l=0,r=k-1;
		if(k==1)
		{
			set<int> D;
			for(int i=1;i<=n;i++) D.insert(i);
			for(auto x:S[0]) D.erase(x);

			cout<<"? "<<D.size()<<" ";
			prin(D);

			int x;
			cin>>x;
			cout<<"! "<<x<<endl;
			string s;
			cin>>s;
			continue;
		}
		while(l<r)
		{
			int tot=0;
			vi V;
			int mid=l+(r-l)/2;
			for(int s=l;s<=mid;s++)
			{
				tot+=S[s].size();
				for(auto x:S[s]) V.push_back(x);
			}
			cout<<"? "<<tot<<" ";
			prin(V);
			int ma1,ma2;
			cin>>ma1;

			tot=0;
			V.clear();
			V.resize(0);
			for(int s=mid+1;s<=r;s++)
			{
				tot+=S[s].size();
				for(auto x:S[s]) V.push_back(x);
			}
			cout<<"? "<<tot<<" ";
			prin(V);

			cin>>ma2;

			if(ma1>ma2)
			{
				for(int i=mid+1;i<=r;i++) K[i]=max(hap,ma1);
				hap=max(hap,ma2);

				r=mid;
			}
			else
			{
				for(int i=l;i<=mid;i++) K[i]=max(hap,ma2);
				hap = max(hap,ma1);
				l=mid+1;
			}
			if(l==r) K[l]=hap;
		}
		cout<<"! ";
		prin(K);
		string s;
		cin>>s;
		if(s!="Correct") return 0;
	}
}		