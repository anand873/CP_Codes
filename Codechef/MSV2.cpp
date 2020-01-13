#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int F[1000001]={0};
		int i;
		int A[n];
		for(i=0;i<n;i++)
		{
			cin>>A[i];
		}
		int V[1000001]={0};
		for(i=n-2;i>=0;i--)
		{
			V[A[i+1]]=1;
			int j;
			for(j=1;j<=sqrt(A[i]);j++)
			{
				if(A[i]%j==0)
				{
					if(V[j]==1) F[j]++;
					if(V[A[i]/j]==1&&A[i]/j!=j) F[A[i]/j]++;
				}
			}
		}
		int ma=0;
		for(i=n-1;i>=0;i--)
		{
			ma=max(ma,F[A[i]]);
			//cout<<"A[i]="<<A[i]<<" "<<"ma="<<ma<<" F[A[i]]="<<F[A[i]]<<endl;
		}
		cout<<ma<<endl;
	}
}