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
	int n;
	cin>>n;
	set<string> S;
	for(int i=0;i<10000;i++)
	{
		vector<int> F(10);
		int j=i;
		int x=4;
		while(x)
		{
			F[j%10]++;
			j/=10;
			x--;
		}
		int f=1;
		for(int j=0;j<10;j++)
		{
			if(F[j]>1) f=0; 
		}
		if(f)
		{
			stringstream ss;
			ss<<i;
			string s;
			ss>>s;
			if(s.length()==3)
			{
				reverse(all(s));
				s+='0';
				reverse(all(s));
			}
			S.insert(s);
		}
	}
	vector<pair<string,pii>> Q(n);
	for(int i=0;i<n;i++)
	{
		cin>>Q[i].first>>Q[i].second.first>>Q[i].second.second;
	}
	set<string> TR;
	for(auto s:S)
	{
		for(int i=0;i<n;i++)
		{
			string check=Q[i].first;
			int x=Q[i].second.first;
			int y=Q[i].second.second;
			int ding=0,dong=0;
			set<int> di;
			for(int i=0;i<4;i++)
			{
				di.insert(check[i]-'0');
				if(check[i]==s[i]) ding++;
			}
			for(int i=0;i<4;i++)
			{
				if(di.count(s[i]-'0')) dong++;
			}
			dong-=ding;
			if(ding!=x||dong!=y) TR.insert(s);
		}
	}
	for(auto tr:TR) S.erase(tr);
	if(S.size()==0) cout<<"Incorrect data\n";
	else if(S.size()==1) cout<<*S.begin()<<endl;
	else cout<<"Need more data"<<endl;
}