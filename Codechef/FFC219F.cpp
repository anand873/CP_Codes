#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,p;
		cin>>n>>p;
		int i;
		int A[n];
		for(i=0;i<n;i++)
		{
			cin>>A[i];
		}
		sort(A,A+n);
		i=0;
		int cnt=0;
		while(A[i]<=p&&i<n)
		{
			cnt++;
			p-=A[i];
			i++;

		}
		cout<<cnt<<endl;
	}
}