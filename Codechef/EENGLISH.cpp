//Author: AnandRaj anand873
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
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
 
const ll MOD = 1e9+7,MAX = 1e5+5;
/////////////////FastExp///////////////////
ll powN(ll a,ll p,ll mod)
{
	if(p==0) return 1;
	ll z=powN(a,p/2,mod);
	z=(z*z)%mod;
	if(p%2) z=(z*a)%mod;
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
	fastio
	test(t)
	{
		int n;
		cin>>n;
		vector<string> V(n);
		int ting=0;
		int lastlen=0;
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			int l=s.length();
			ting+=l;
			V[i]="";
			for(int j=0;j<l;j++)
			{
				V[i]+=s[j];
				V[i]+=s[l-1-j];
			}
		}
		sort(all(V));
		if(ting>99990&&ting!=99999)
		{
			int where=0;
			int how=1;
			for(int i=1;i<n;i++)
			{
				//cout<<V[i-1]<<" "<<V[i]<<endl;
				int l1=(int)V[i].length();
				int l2=(int)V[i-1].length();
				ll ting=0;
				int j=0;
				while(V[i-1][j]==V[i][j]&&j<min(l1,l2)) {ting++;j++;}
				ting/=2;
				//cout<<ting<<endl;
				if(ting==0)
				{
					where=where+how;
					how=1;
					lastlen=0;
				}
				else if(ting>=lastlen) {lastlen=ting;how++;}
				else
				{
					int here=where+how;
					reverse(V.begin()+where,V.begin()+here);
					where=here-1;
					how=1;
					lastlen=0;
					i--;
				}
			}
			//for(auto v:V) cout<<v<<endl;
			vvl dp(n+1,vl(2));
			dp[0][0]=0;
			dp[0][1]=0;
			dp[1][0]=0;
			dp[1][1]=0;
			for(int i=2;i<=n;i++)
			{
				dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
				int l1=(int)V[i-1].length();
				int l2=(int)V[i-2].length();
				ll ting=0;
				int j=0;
				while(V[i-1][j]==V[i-2][j]&&j<min(l1,l2)) {ting++;j++;}
				ting=ting/2;
				//cout<<ting<<endl;
				dp[i][1]=dp[i-1][0]+ting*ting;
			}
			cout<<max(dp[n][0],dp[n][1])<<endl;
		}
		else
		{
			map<string,ll> M;
			for(int i=0;i<n;i++)
			{
				string tem="";
				for(int j=0;j<V[i].size();j++)
				{
					tem+=V[i][j];
					if(M.find(tem)==M.end()) M[tem]=1;
					else M[tem]++; 
				}
			}
			auto i=M.end();
			i--;
			ll ans=0;
			//for(auto x:M) cout<<x.first<<" "<<x.second<<endl;
			while(1)
			{
				//printf("YES\n");
				if((*i).second<=1)
				{
					if(i==M.begin()) break;
					i--;
					continue;
				}
				ll temp=(*i).second/2;
				temp*=2;
				if(temp!=0)
				{
					string p="";
					for(auto x:(*i).first)
					{
						p+=x;
						M[p]-=temp;
					}
				}
				ll inc = ((*i).first).size()/2;
				ans+=(temp/2)*inc*inc;
				if(i==M.begin()) break;
				i--;
			}
			cout<<ans<<endl;
		}	
	}
}