#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> A(n);
		long long sum = 0;
		bool already = false;
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
			sum += A[i];
		}
		sort(A.begin(),A.end());
		for(int i=0;i<n;i++)
		{
			if(A[i] > i+1) already = true;
		}
		if(already) cout<<"Second\n";
		else
		{
			if(((long long)n*(n+1)/2 - sum) % 2) cout<<"First\n";
			else cout<<"Second\n";
		}
	}
}