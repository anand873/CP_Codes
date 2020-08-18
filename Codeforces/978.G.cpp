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
#define test() int t;cin>>t;while(t--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 998244353,MAX = 1e6+5;
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
	for(int i=2;i<=MAX;i++) if(is_prime[i]) MinDiv[i]=i;
}
//////////////////Sieve////////////////////

int main()
{
	int n,m;
	cin>>n>>m;

	vector<int> C,En;	//Days and End
	set<pii> St;		//Start

	for(int i=0;i<m;i++)
	{
		int s,d,c;
		cin>>s>>d>>c;
		C.push_back(c);
		St.insert({s,i});
		En.push_back(d);
	}

	vector<int> Today(n+1);
	for(int i=0;i<m;i++) Today[En[i]]=m+1;	//If Exam Day

	vector<int> How(m+1);
	set<pii> Close;
	bool can=true;
	for(int i=1;i<=n;i++)
	{
		//All the papers open today, Add them to Close
		while(St.size()&&(*(St.begin())).first==i)
		{
			auto Next = St.begin();
			if(i == (*Next).first)
			{
				Close.insert({En[(*Next).second],(*Next).second+1});
				St.erase(*Next);
			}
		}

		//If Not Exam Day
		if(Today[i]!=m+1)
		{
			if(Close.size())		
			{						
				//If There are exams to study for, study for the closest one.
				auto Next = Close.begin();
				Today[i] = (*Next).second;

				//Curr Date is over the exam date, Wrong assignment
				if(i>=En[Today[i]-1]) can=false;
				
				//How may days for this paper
				How[Today[i]]++;	

				//If done enough, remove from Close
				if(How[Today[i]]==C[Today[i]-1])	
				{
					Close.erase(*Next);
				}
			}
			else Today[i]=0;				//Else don't do anything
		}
	}
	for(int i=0;i<m;i++)
	{
		if(How[i+1]!=C[i]) can=false;		//If study days mismatch, Wrong assignment
	}
	if(can)
	{
		for(int i=1;i<=n;i++) cout<<Today[i]<<" ";
		cout<<endl;
	}
	else cout<<-1<<endl;

	
}		