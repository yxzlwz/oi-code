#include <cstdio>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	int in[100001];
	for (int i = 0; i < n; i++)
		cin >> in[i];
	int t[100001], count = -1;
	for (int i = 0; i < n; i++)
	{
		bool had = 0;
		for (int j = 0; j <= count; j++)
		{
			if (in[i] == t[j])
			{
				had = 1;
				break;
			}
		}
		if (!had)
		{
			t[++count] = in[i];
		}
	}
	sort(t, t + count + 1);

	if (k - 1 <= count)
		cout << t[k - 1];
	else
		cout << "NO RESULT";

	return 0;
}
