#include <bits/stdc++.h>
using namespace std;
#define N 1000000007

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		long long int k;
		cin>>n>>k;
		int i;
		vector<int> V;
		for(i=0;i<n;i++)
		{
			int x;
			cin>>x;
			V.push_back(x);
		}
		long long int p = k%(3*n);
		for(i=0;i<p;i++)
		{
			V[i%n]^=V[n-1-i%n];
		}
		if(n%2&&k>n/2) V[n/2]=0;
		cout<<V[0];
		for(i=1;i<n;i++) cout<<" "<<V[i];
		cout<<endl;
	}
}