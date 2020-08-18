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

const int MOD = 1e9+7,MAX = 2e5+5;
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
}
//////////////////Sieve////////////////////

bool cmp(pii a,pii b)
{
	if(a.second-a.first==b.second-b.first)
	{
		return a.first<b.first;
	}
	return a.second-a.first>b.second-b.first;
}

int main()
{
	fastio
	test()
	{
		int n;
		cin>>n;
		vi A;
		int i=1;
		set<pii,decltype(cmp)*> S(cmp);
		S.insert({1,n});
		while(!S.empty())
		{
			pii Curr=*(S.begin());S.erase(*S.begin());
			int mid=(Curr.first+Curr.second)/2;
			A.push_back(mid);
			if(Curr.first<=mid-1)
				S.insert({Curr.first,mid-1});
			if(Curr.second>=mid+1)
				S.insert({mid+1,Curr.second});
		}
		vi Ans(n);
		for(int i=0;i<n;i++)
		{
			Ans[A[i]-1]=i+1;
		}
		prin(Ans);
	}
}		