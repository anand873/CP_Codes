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

ll fun(vector<string> V,int n)
{
	//cout<<"YO"<<endl;
	if(V[0].length()==0) return 0;
	int zero=0;
	
	for(int i=0;i<n;i++)
	{
		if(V[i].back()=='0') zero++;
	}
	//what(zero);
	if(zero==n||zero==0)
	{
		for(int i=0;i<n;i++) V[i].pop_back();
		//cout<<"DIDNOTHING"<<endl;
		return fun(V,n);
	} 
	else
	{
		vector<string> V0,V1;
		for(int i=0;i<n;i++)
		{
			if(V[i].back()=='0') 
			{
				V[i].pop_back();
				V0.push_back(V[i]);
			}
			else 
			{
				V[i].pop_back();
				V1.push_back(V[i]);
			}
		}
		//for(auto x:V0) cout<<x<<endl;
		int l=V0[0].length();
		return (1ll<<l)+min(fun(V0,V0.size()),fun(V1,V1.size()));
	}
}


int main()
{	
	int n;
	cin>>n;
	vi A(n);
	take(A,0,n);
	vector<string> V(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<30;j++)
		{
			if(A[i]&(1<<j)) V[i]+='1';
			else V[i]+='0';
		}
	}
	ll ans = fun(V,n);
	// for(int i=0;i<n;i++) cout<<V[i]<<endl;
	// ll sum=0;
	// int k=0;
	// for(int i=29;i>=0;i--)
	// {
	// 	if(V[i]==n||V[i]==0) continue;
	// 	else
	// 	{
	// 		//cout<<i<<" "<<V[i]<<endl;
	// 		if(k%2==0) {sum+=1<<i;k++;}
	// 	}
	// }
	// // ll ans=0;
	// cout<<sum<<endl;
	// // for(int i=0;i<n;i++)
	// // {
	// // 	ans=max(ans,sum^A[i]);
	// // }
	cout<<ans<<endl;
}