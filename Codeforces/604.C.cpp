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
#define forn(i,a,b) for(int i=a;i<b;i++)
#define rforn(i,b,a) for(int i=b-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl;
#define what(x) cerr<<#x<<" is "<<x<<endl

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
	int n;
	cin>>n;
	string s;
	cin>>s;
	int i=0;
	vi Z;
	while(i<n)
	{
		if(s[i]=='0')
		{
			int j=i;
			int ting=0;
			while(s[j]=='0'&&j<n)
			{
				ting++;
				j++;
			}
			Z.push_back(ting);
			i=j;
		}
		else
		{
			int j=i;
			int ting=0;
			while(s[j]=='1'&&j<n)
			{
				ting++;
				j++;
			}
			Z.push_back(ting);
			i=j;
		}
	}
	//prin(Z);
	int tt=0,ttt=0;

	int l=Z.size();
	for(int i=0;i<l;i++)
	{
		if(Z[i]>2) ttt++;
		if(Z[i]==2) tt++;
	}
	if(tt==0&&ttt==0) cout<<l<<endl;
	else if(tt==1&&ttt==0) cout<<l+1<<endl;
	else cout<<l+2<<endl;
}