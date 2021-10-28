#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int m, n;
char map[510][510];
int dir[4] = { -1,0,1,0 }, dir[4] = { 0,-1,0,1 };
void dfs(int x, int y)
{
	if (x < 0 || x >= m || y < 0 || y >= n || map[x][y] == '*')
	{
		return;
	}
	map[x][y] = '*';
	for (int i = 0; i < 4; i++)
	{
		dfs(x + dir[i], y + dir[i]);
	}
}
int main()
{
	int ans = 0;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{

		cin >> map[i];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && map[i][j] == '0')
			{
				dfs(i, j);
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '0')
			{
				ans++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
