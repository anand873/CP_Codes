#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	set<int> S;
	vector<int> P(n);
	for(int i=0;i<n;i++)
	{
		cin>>P[i];
		S.insert(P[i]);
	}
	bool can=true;
	set<int> A,B;
	while(S.size())
	{
		int x=*(S.begin());
		if(S.count(a-x)&&S.count(b-x))
		{
			if(a==2*x)
			{
				S.erase(x);
				S.erase(b-x);
				B.insert(x);
				B.insert(b-x);
			}
			else if(b==2*x)
			{
				S.erase(x);
				S.erase(a-x);
				A.insert(x);
				A.insert(a-x);
			}
			else {can=false;break;}
		}
		else if(S.count(a-x)&&!S.count(b-x))
		{
			A.insert(x);
			A.insert(a-x);
			S.erase(x);
			S.erase(a-x);
		}
		else if(S.count(b-x)&&!S.count(a-x))
		{
			B.insert(x);
			B.insert(b-x);
			S.erase(x);
			S.erase(b-x);
		}
		else {can=false;break;}
	}
	if(can)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		{
			if(A.count(P[i])) cout<<"0 ";
			else cout<<"1 ";
		}
		cout<<endl;
	}
	else cout<<"NO"<<endl;

}