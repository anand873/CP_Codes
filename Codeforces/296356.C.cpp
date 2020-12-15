//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cost(map<int,int> &M,int x)
{
	int price = 0;
	for(auto m:M)
	{
		price += abs(x-m.second)*(m.first+1);
	}
	return price;
}

int main()
{
	string s;
	cin>>s;
	int n = s.length();
	map<int,int> M;
	for(auto c:s) M[c-'A']++;

	int low = 1,high = n;
	int ans; 
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		int price_mid = cost(M,mid);
		int price_bef = cost(M,mid-1);
		if(price_bef<price_mid)
		{
			ans = price_bef;
			high = mid-1;
		}
		else
		{
			ans = price_mid;
			low = mid+1;
		}
	}
	cout<<ans<<endl;
}	