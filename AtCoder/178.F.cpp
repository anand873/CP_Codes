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
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9+7,MAX = 1e6+5;
const ll INF = 1e18+5;

bool check(vi A,vi B)
{
	for(int i=0;i<(int)A.size();i++)
	{
		if(A[i]==B[i]) return false;
	}
	return true;
}

int main()
{
	int n;
	cin>>n;
	vi A(n),B(n);
	take(A,0,n);
	take(B,0,n);
	reverse(all(B));
	int matchs = -1,matche=-1;
	for(int i=0;i<n;i++)
	{
		if(A[i]==B[i])
		{
			matchs=i;
			matche=i;
			while(matche<n&&B[matche]==B[i])
			{
				matche++;
			}
			matche--;
			break;
		}
	}
	vi X;
	if(matchs==-1&&matche==-1)
	{
		cout<<"Yes"<<endl;
		prinv(B);
	}
	else if(matchs==0&&matche==n-1) cout<<"No"<<endl;
	else
	{
		if(matchs==0)
		{
			for(int i=matche+1;i<n;i++) X.push_back(B[i]);
			for(int i=0;i<matche+1;i++) X.push_back(B[i]);

			if(check(A,X))
			{
				cout<<"Yes"<<endl;
				prinv(X);
			}
			else cout<<"No"<<endl;
		}
		else if(matche==n-1)
		{
			while(matchs>=0&&B[matchs]==B[matche])
			{
				matchs--;
			}
			matchs++;
			for(int i=matchs;i<=matche;i++) X.push_back(B[i]);
			for(int i=0;i<matchs;i++) X.push_back(B[i]);

			if(check(A,X))
			{
				cout<<"Yes"<<endl;
				prinv(X);
			}
			else cout<<"No"<<endl;

		}
		else
		{
			for(int i=0;i<matchs;i++) X.push_back(B[i]);
			for(int i=matche+1;i<n;i++) X.push_back(B[i]);
			for(int i=matchs;i<matche+1;i++) X.push_back(B[i]);

			if(check(A,X))
			{
				cout<<"Yes"<<endl;
				prinv(X);
			}
			else
			{
				X.clear();
				while(matchs>=0&&B[matchs]==B[matche])
				{
					matchs--;
				}
				matchs++;
				for(int i=matchs;i<=matche;i++) X.push_back(B[i]);
				for(int i=0;i<matchs;i++) X.push_back(B[i]);

				if(check(A,X))
				{
					cout<<"Yes"<<endl;
					prinv(X);
				}
				else cout<<"No"<<endl;
			}
		}
	}
	
}