//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	vector<int> V;
	int curr=0;
	for(int i=0;i<n;i++)
	{
		if(A[i]==1)
		{
			V.push_back(curr);
			curr=0;
		}
		else
		{
			curr++;
		}
	}
	V.push_back(curr);
	V.push_back(0);
	sort(V.begin(),V.end());
	reverse(V.begin(),V.end());

	bool first=false;
	if(V[0]>2*V[1]&&V[0]%2) first = true;
	
	if(first) cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;
}	