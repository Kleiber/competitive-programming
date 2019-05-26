#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k, l, r, sall, sk;

	cin >> n >> k >> l >> r >> sall >> sk;

	sall -= sk;
	n -= k;

	while (k > 0)
	{
		cout << sk / k << " ";
		sk -= sk / k;
		k--;
	}

	while (n > 0)
	{
		cout << sall / n << " ";
		sall -= sall / n;
		n--;
	}

	cout << endl;

	return 0;
}