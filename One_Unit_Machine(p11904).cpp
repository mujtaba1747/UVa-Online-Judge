// Author : Syed Mujtaba
// Seek knowledge from the Cradle to the Grave !!
// https://www.linkedin.com/in/syed-mujtaba-064a5016a  

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3055
#include <bits/stdc++.h>
using namespace std;
#define int             long long
#define mod             1000000007 // 1e9 + 7

int fact[1000007]={0};
int xyp(int x,int y)
{
	int res=1;
	while(y>0)
	{
		if(y%2==1)
			res=(res*x)%mod;
		x=(x*x)%mod;y/=2;
	}
	return res%mod;
}
void init()
{
	fact[0]=1;
	fact[1]=1;
	for(int i=2;i<1000007;i++)
		fact[i]=(fact[i-1]*i)%mod;
}
int ncr(int n,int r)
{
	int res=1; 
	res=fact[n]; 
	res=(res*(xyp(fact[r],mod-2)))%mod; 
	res=(res*(xyp(fact[n-r],mod-2)))%mod; 
	return res;
}
int add(int a, int b)
{
	return (a%mod + b%mod)%mod;
}
int sub(int a, int b)
{
	return (a%mod - b%mod + mod)%mod;
}
int mul(int a, int b)
{
	return ((a%mod)*(b%mod))%mod;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	int t;
	cin >> t;
	for(int q = 0; q < t; q++)
	{
		int n;
		cin >> n;
		vector < int > k(n);
		for(auto &z : k)
			cin >> z;
		vector < int > ps(n + 1, 0);
		ps[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			ps[i] = ps[i - 1] + k[i - 1];
		}
		int ans = 1; 
		for(int i = 1; i < n; i++)
		{
			int ss = ps[i];
			int el = k[i];
			ans = mul(ans, sub(ncr(ss + el, el), ncr(ss + el - 1, el)));
		}
		cout << "Case " << q+1 << ": " << ans << endl;
	}
}
