//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int kill(int mid,vector<int> &A)
{
	int n = A.size();
	int temp=0;
	int i=0,j=mid;
	while(i<mid&&j<n)
	{
		while(j+1<n&&A[j]<3*A[i]) j++;
		if(j+1<n&&A[j]>=3*A[i])
		{
			temp++;
			j+=2;
		}
		i++;
	}
	return temp;
}

int main()
{
	fastio
	int n;
	cin>>n;
	vector<int> A(3*n);
	for(auto &a:A) cin>>a;

	sort(A.begin(),A.end());
	int ans = 0;
	int low = 1,high=n;
	while(low<=high)
	{
		int mid = low+(high-low)/2;
		int val_mid = kill(mid,A);
		int val_bef = kill(mid-1,A);
		// cout<<mid<<": "<<val_mid<<" "<<mid-1<<": "<<val_bef<<endl;
		if(val_mid<val_bef)
		{
			ans = max(ans,val_bef);
			high = mid-1;
		}
		else
		{
			ans = max(ans,val_mid);
			low = mid+1;
		}
	}	
	cout<<ans<<'\n';
}	