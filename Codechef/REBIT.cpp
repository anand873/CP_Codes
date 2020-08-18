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

vl XorMul(string str1,string str2)
{
	if(str1.size()==1&&str2.size()==1)
	{
		return {4,4,4,4};
	}
	else if(str1.size()==1)
	{
		int op=1;
		int len=0;
		for(int i=1;i<str2.size();i++)
		{
			if(str2[i]=='(') op++;
			else if(str2[i]==')') op--;

			len++;
			if(op==0) break;
		}
		string s1=str2.substr(1,len);
		string s2=str2.substr(2+len,str2.size()-2-len);
		vl RH;
		if(str2[len+1]=='|') RH=OrMul(s1,s2);
		else if(str2[len+1]=='&') RH=AndMul(s1,s2);
		else RH=XorMul(s1,s2);

		ll x=0;
		for(auto rh:RH) x=(x+rh)%MOD;
		return {x,x,x,x};
	}
	else if(str2.size()==1)
	{
		int op=1;
		int len=0;
		for(int i=1;i<str1.size();i++)
		{
			if(str1[i]=='(') op++;
			else if(str1[i]==')') op--;

			len++;
			if(op==0) break;
		}
		string s1=str1.substr(1,len);
		string s2=str1.substr(2+len,str1.size()-2-len);
		vl RH;
		if(str1[len+1]=='|') RH=OrMul(s1,s2);
		else if(str1[len+1]=='&') RH=AndMul(s1,s2);
		else RH=XorMul(s1,s2);

		ll x=0;
		for(auto rh:RH) x=(x+rh)%MOD;
		return {x,x,x,x};
	}
	else
	{
		int op=1;
		int len=0;
		for(int i=1;i<str1.size();i++)
		{
			if(str1[i]=='(') op++;
			else if(str1[i]==')') op--;

			len++;
			if(op==0) break;
		}
		string s1=str1.substr(1,len);
		string s2=str1.substr(2+len,str1.size()-2-len);
		vl RH;
		if(str1[len+1]=='|') RH=OrMul(s1,s2);
		else if(str1[len+1]=='&') RH=AndMul(s1,s2);
		else RH=XorMul(s1,s2);

		op=1;
		len=0;
		for(int i=1;i<str2.size();i++)
		{
			if(str2[i]=='(') op++;
			else if(str2[i]==')') op--;

			len++;
			if(op==0) break;
		}
		s1=str2.substr(1,len);
		s2=str2.substr(2+len,str2.size()-2-len);
		vl LH;
		if(str2[len+1]=='|') LH=OrMul(s1,s2);
		else if(str2[len+1]=='&') LH=AndMul(s1,s2);
		else LH=XorMul(s1,s2);

		vvl M(4,vl(4));
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				M[i][j]=LH[i]*RH[j];
			}
		}
	}
}

int main()
{
	test()
	{
		string s;
	}
}		