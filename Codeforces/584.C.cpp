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
	int n,t;
	cin>>n>>t;
	string s1,s2;
	cin>>s1>>s2;
	set<int> S;
	for(int i=0;i<n;i++)
	{
		if(s1[i]==s2[i]) S.insert(i);
	}
	if(S.size()<n-t)
	{
		int x=(n-S.size()+1)/2;
		if(x>t) cout<<-1<<endl;
		else
		{
			string s3;
			int ganda=2*t-n+S.size();
			int done1=0,done2=0;
			for(int i=0;i<n;i++)
			{
				if(S.count(i)) s3.push_back(s1[i]);
				else
				{
					if(ganda)
					{
						for(int j=0;j<26;j++)
						{
							if(s1[i]!='a'+j&&s2[i]!='a'+j) {s3.push_back('a'+j);done1++;done2++;ganda--;break;}
						}
					}
					else if(done1<done2) {s3.push_back(s2[i]);done1++;}
					else {s3.push_back(s1[i]);done2++;}
				}
			}
			if(done1==t) cout<<s3<<endl;
			else
			{
				int i=0;
				while(done1<t&&i<n)
				{
					if(s1[i]==s2[i]) {s3[i]=(s1[i]-'a'+1)%26+'a';done1++;}
					i++;
				}
				if(done1==t) cout<<s3<<endl;
				else cout<<-1<<endl;
			}
		}
	}
	else
	{
		int done=0;
		string s3;
		for(int i=0;i<n;i++)
		{
			if(S.count(i)) s3.push_back(s1[i]);
			else
			{
				for(int j=0;j<26;j++)
				{
					if(s1[i]!='a'+j&&s2[i]!='a'+j) {s3.push_back('a'+j);done++;break;}
				}
			}
		}
		if(done==t) cout<<s3<<endl;
		else
		{
			int i=0;
			while(done<t&&i<n)
			{
				if(s1[i]==s2[i]) {s3[i]=(s1[i]-'a'+1)%26+'a';done++;}
				i++;
			}
			if(done==t) cout<<s3<<endl;
			else cout<<-1<<endl;
		}
	}
}