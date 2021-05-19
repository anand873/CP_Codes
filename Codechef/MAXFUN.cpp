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
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		}
		sort(A.begin(),A.end());
		cout<<(long long)2*(A[n-1]-A[0])<<endl;
	}
}