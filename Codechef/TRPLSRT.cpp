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
#define test() int t;cin>>t;while(t--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
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

struct Trip
{
	int a,b,c;
};

int main()
{
	// vi X(6);
	// for(int i=1;i<=5;i++) X[i]=i;
	test()
	{
		// vi P=X;
		// prin(P);
		int n;
		ll k;
		cin>>n>>k;
		vi P(n+1);
		take(P,1,n);
		vi In(n+1);
		for(int i=1;i<=n;i++)
			In[P[i]]=i;
		set<int> S;
		int par=0;
		for(int i=1;i<=n;i++)
		{
			if(!S.count(i))
			{
				int x=2;
				int j=P[i];
				S.insert(j);
				while(!S.count(P[j]))
				{
					S.insert(P[j]);
					j=P[j];
					x++;
				}
				par^=(x%2);
			}
		}
		//cout<<par<<endl;
		if(par) cout<<-1<<endl;
		else
		{
			vector<Trip> Ans;
			set<int> CorrPos;
			for(int i=1;i<=n;i++)
			{
				CorrPos.insert(i);
				if(In[i]==i) CorrPos.erase(i);
			}

			for(int i=1;i<=n;i++)
			{
				if(In[i]==i) continue;
				else
				{
					int a=i,b,c;
					if(In[i]!=P[i])
					{
						b=P[i];
						c=In[i];	
						CorrPos.erase(i);
						CorrPos.erase(P[i]);
						In[P[a]]=c;
						In[P[c]]=a;
						swap(P[a],P[c]);
						In[P[b]]=c;
						In[P[c]]=b;
						swap(P[b],P[c]);
						Trip X;
						X.a=a;
						X.b=b;
						X.c=c;
						Ans.push_back(X);
						if(P[c]==c) S.erase(c);
					}
					else
					{
						b=P[i];	
						for(auto in:CorrPos)
						{
							if(in!=b&&in!=a)
								{c=in;break;}
						}	
						CorrPos.erase(c);
						In[P[a]]=b;
						In[P[b]]=a;
						swap(P[a],P[b]);
						In[P[c]]=b;
						In[P[b]]=c;
						swap(P[c],P[b]);
						Trip X;
						X.a=a;
						X.b=c;
						X.c=b;
						Ans.push_back(X);
						if(P[c]==c) S.erase(c);

					}
				}
			}
			cout<<Ans.size()<<endl;
			for(int i=0;i<Ans.size();i++)
			{
				cout<<Ans[i].a<<" "<<Ans[i].b<<" "<<Ans[i].c<<endl;
			}
		}
		// next_permutation(all(X));
		// cout<<endl;
	}
}		