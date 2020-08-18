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
#define test(t) int t;cin>>t;while(t--)
#define forn(i,f,n) for(int i=f;i<f+n;i++)
#define rforn(i,l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
#define what(x) cerr<<#x<<" = "<<x<<endl

const int MOD = 1e9+7,MAX = 1e5+5;
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
vector<bool> is_prime(MAX+1, true);
void Sieve()
{
	is_prime[0] = is_prime[1] = false;
	int i,j;
	for (i = 2; i*i <= MAX; i++) 
	{
    	if (is_prime[i]) 
    	{
        	for (j = i * i; j <= MAX; j += i)
            	is_prime[j] = false;
    	}
	}
}
//////////////////Sieve////////////////////

int main()
{
	set<ll> SS;
	vl S;
	for(int i=0;i<18;i++)
	{
		for(int j=i+1;j<18;j++)
		{
			for(int k=j+1;k<18;k++)
			{
				for(int fi=0;fi<=9;fi++)
				{
					for(int se=0;se<=9;se++)
					{
						for(int thi=0;thi<=9;thi++)
						{
							ll num=0;
							num+=fi*(ll)(pow(10,17-i)+0.5);
							num+=se*(ll)(pow(10,17-j)+0.5);
							num+=thi*(ll)(pow(10,17-k)+0.5);
							SS.insert(num);
						}
					}
				}
			}
		}
	}
	for(auto ss:SS) S.push_back(ss);
	S.push_back(1000000000000000000);
	int n=S.size();
	//for(int i=0;i<50;i++) cout<<S[i]<<endl;
	test(t)
	{
		ll l,r;
		cin>>l>>r;
		int low=0,high=n-1;
		int ansl,ansr;
		while(low<=high)
		{
			int mid=low+(high-low)/2;
			if(S[mid]<l) low=mid+1;
			else {ansl=mid;high=mid-1;}
			//what(ansl);
		}
		low=0;
		high=n-1;
		while(low<=high)
		{
			int mid=low+(high-low)/2;
			if(S[mid]<=r) {ansr=mid;low=mid+1;}
			else high=mid-1;
			//what(ansr);
		}
		cout<<ansr-ansl+1<<endl;
	}
}