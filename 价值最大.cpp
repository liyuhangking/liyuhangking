
#include<iostream>

using namespace std;

int v[25], p[25], dp[60000];

int main()
{
	int m, n;
	cin >> m>> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i] >> p[i];
		p[i] *= v[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j >= 0; j--)
		{
			if (j >= v[i])
				dp[j] = max(dp[j], dp[j - v[i]] + p[i]);
		}
	}
	printf("%d\n", dp[m]);
	return 0;
}
