//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> A(n+5),B(m+5);
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	for(int i=0;i<m;i++)
		cin>>B[i];

	vector<long long> iB(m+5),iA(n+5);
	int i=0;
	while(i<m)
	{
		int siz=0;
		while(B[i]==1&&i<m)
		{
			i++;
			siz++;
			iB[siz]++;
		}
		i++;
	}
	i=0;
	while(i<n)
	{
		int siz=0;
		while(A[i]==1&&i<n)
		{
			i++;
			siz++;
			iA[siz]++;
		}
		i++;
	}
	
	for(int i=n+1;i>0;i--)
	{
		iA[i]+=iA[i+1];
	}
	for(int i=m+1;i>0;i--)
	{
		iB[i]+=iB[i+1];
	}

	long long sum=0;
	for(int i=1;i<n+5;i++)
	{
		if(k%i==0)
		{
			if(k/i>m) continue;
			sum+=iA[i]*iB[k/i];
		}
	}
	cout<<sum<<endl;


}		