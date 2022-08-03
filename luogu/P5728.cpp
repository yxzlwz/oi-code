#include <bits/stdc++.h>
using namespace std;
int a[10001][3];

bool pd(int m[], int n[])
{
	int f[3];
	for (int i = 0; i < 3; i++)
	{
		f[i] = abs(m[i] - n[i]);
		if (f[i] > 5)
			return false;
	}
	if (f[0] + f[1] + f[2] > 10)
		return false;
	return true;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i][0] >> a[i][1] >> a[i][2];

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i == j)continue;
			if (pd(a[i], a[j]))
				cnt++;
		}
	}

	cout << cnt / 2;

	return 0;
}