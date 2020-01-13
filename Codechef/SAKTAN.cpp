#include <bits/stdc++.h>
using namespace std;
#define N 1000000007

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,q;
		cin>>n>>m>>q;
		int M=max(n,m);
		int R[M],C[M];
		int i;
		for(i=0;i<=M;i++)
		{
			R[i]=0;
			C[i]=0;
		}
		for(i=0;i<q;i++)
		{
			int x,y;
			cin>>x>>y;
			R[x]++;
			C[y]++;
		}
		int Ro=0,Co=0;
		for(i=1;i<=M;i++)
		{
			if(R[i]%2&&i<=n) Ro++;
			if(C[i]%2&&i<=m) Co++;
		}
		//cout<<Ro<<" "<<Co<<endl;
		long long int ans;
		ans=(long long int)Ro*(m-Co)+(long long int)(n-Ro)*Co;
		cout<<ans<<endl;
	}
}