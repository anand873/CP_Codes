//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

int main()
{
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	vector<string> V;
	V.push_back(s);
	while(next_permutation(s.begin(),s.end()))
	{
		V.push_back(s);
	}
	cout<<V.size()<<endl;
	for(auto str:V) cout<<str<<endl;
}	