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

const int MOD = 1e9+7,MAX = 2e6+5;
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

vector<string> S={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
vector<int> BN;

int main()
{
	set<int> C;
	for(auto s:S)
	{
		int ans=0;
		int x=64;
		for(int i=0;i<7;i++)
		{
			if(s[i]=='1') ans+=x;
			x/=2;
		}
		BN.push_back(ans);
		C.insert(ans);
	}
	int n,k;
	cin>>n>>k;
	vector<int> V(n);
	
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		int ans=0;
		int x=64;
		for(int i=0;i<7;i++)
		{
			if(s[i]=='1') ans+=x;
			x/=2;
		}
		V[i]=ans;
	}
	int have=k;
	prin(BN);
	// prin(V);
	bool can=true;
	vector<int> Mcost(n);
	for(int i=0;i<n;i++)
	{
		if(C.count(V[i])) continue;
		vi Good;
		for(auto bn:BN)
		{
			int wha=(bn|(~V[i]));
			//cout<<wha<<endl;
			if(((wha+1)&wha)==0) Good.push_back(bn);
		}
		int mincost=10;
		for(auto good:Good)
		{
			mincost=min(mincost,__builtin_popcount(good^V[i]));
		}
		Mcost[i]=mincost;
		have-=mincost;
		if(have<0) can=false;
	}
	if(!can) cout<<-1<<endl;
	else
	{
		vi Ans(n);
		for(int i=0;i<n;i++)
		{
			int from=V[i];
			//what(from);
			if(C.count(V[i]))
			{
				//cout<<"Already"<<endl;
				for(int ban=9;ban>=0;ban--)
				{
					if(BN[ban]==from)
					{
						Ans[i]=ban;
						break;
					}
					int wha=(BN[ban]|(~from));
					//cout<<wha<<endl;
					if(((wha+1)&wha)==0)
					{
						//what(ban);
						if(have>=__builtin_popcount(BN[ban]^from))
						{
							Ans[i]=ban;
							have-=__builtin_popcount(BN[ban]^from);
							break;
						}
					}
				}
			}
			else
			{
				//cout<<"Not Available"<<endl;
				have+=Mcost[i];
				for(int ban=9;ban>=0;ban--)
				{
					int wha=(BN[ban]|(~from));
					if(((wha+1)&wha)==0)
					{
						//what(ban);
						if(have>=__builtin_popcount(BN[ban]^from))
						{
							Ans[i]=ban;
							have-=__builtin_popcount(BN[ban]^from);
							break;
						}
					}
				}
			}
		}
		//prin(Ans);
		//cout<<have<<endl;
		for(int i=0;i<n;i++)
		{
			if(have>0&&Ans[i]==3) {Ans[i]=9;have--;}
		}
		for(int i=0;i<n;i++)
		{
			if(have>0&&Ans[i]==4) {Ans[i]=9;have--;}
		}
		for(int i=0;i<n;i++)
		{
			if(have>0&&Ans[i]==5) {Ans[i]=9;have--;}
		}
		for(int i=0;i<n;i++)
		{
			if(have>1&&Ans[i]==7) {Ans[i]=9;have--;}
		}
		for(int i=0;i<n;i++)
		{
			if(have>0&&Ans[i]==0) {Ans[i]=8;have--;}
		}
		for(int i=0;i<n;i++)
		{
			if(have>1&&Ans[i]==2) {Ans[i]=8;have--;}
		}
		for(int i=0;i<n;i++)
		{
			if(have>0&&Ans[i]==6) {Ans[i]=8;have--;}
		}
		for(int i=n-1;i>=0;i--)
		{
			//cout<<"Yo"<<endl;
			if(have>0&&Ans[i]==9) {Ans[i]=8;have--;}
		}
		if(have>0) cout<<-1<<endl;
		else
		{
			for(int i=0;i<n;i++) cout<<Ans[i];
			cout<<endl;
		}
	}


}		