//Author: AnandRaj uux
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
#define forn(i,f,n) for(int i=f;i<f+n;i++)
#define rforn(i,l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

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
            {
				is_prime[j] = false;
    		}
    	}
	}
}
//////////////////Sieve////////////////////

int main()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int l=0;
	int ansmin=0;
	//int ansmax=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='L')
		{
			ansmin=max(ansmin,i-l);
			l++;
		}
	}
	//what(ansmin);
	if(k!=ansmin)
	{
		cout<<-1<<endl;
	}
	else
	{
		//vvi WW;
		for(int mov=0;mov<ansmin;mov++)
		{
			vi WHO;
			for(int i=0;i<n-1;i++)
			{
				if(s[i]=='R'&&s[i+1]=='L')
				{
					swap(s[i],s[i+1]);
					i++;
					WHO.push_back(i);
				}
			}
			cout<<WHO.size()<<" ";
			prin(WHO);
			//WW.push_back(WHO);
		}
		// int here;
		// for(int i=0;i<n-1;i++)
		// {
		// 	if(s[i]!=s[i+1])
		// 	{
		// 		here=i+1;
		// 		break;
		// 	}
		// }
		// for(int i=ansmin;i<k;i++)
		// {
		// 	cout<<1<<" "<<here-(ansmin-i)%2+1<<endl;
		// }
	}

}		