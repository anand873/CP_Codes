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
		vector<int> H(n);
		for(int i=0;i<n;i++)
		{
			cin>>H[i];
		}
		int low = 1, high = n-1;
		while(low<=high)
		{
			int mid = low + (high-low)/2;
			multiset<int> S;
			for(int i=1;i<mid-1;i++)
			{
				
			}
		}
	}
}