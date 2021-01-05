#include <iostream>


int main() {
	int n, k,cnt;
	cin >> n >> k;

	while (1)
	{
		int target = (n / k) * k;
		cnt += (n - target);
		n = target;
		if (n < k) break;
		cnt += 1;
		n /= k;
	}
	cnt += (n - 1);
	cout << cnt << endl;


	/*贸澜俊 沁带 规过
	while (n >= k)
	{
		while (n % k != 0)
		{
			n -= 1;
			cnt++;
		}
		n /= k;
		cnt++;		
	}

	while (n > 1)
	{
		n--;
		cnt++;
	}
	cout << cnt << endl;
	*/

	return 0;
}