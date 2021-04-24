#include <iostream>

int main() {

	int n, m, result, min_value;

	for (int i = 0; i < n; i++)
	{
		min_value = 10001;
		for (int j = 0; j < m; j++)
		{
			int x; 
			cin >> x;
			min_value = min(min_value, x);
		}

		result = max(min_value, result);
	}
	
	cout << result << endl;
	
	
	
	/* 
	처음 풀었던 방법(1)
	int n, m, card[100][100], LowNum[100], Min=2147000000;

	for (int i = 0; i < n; i++)
	{
		Min = 2147000000;
		for (int j = 0; j < m; j++)
		{
			cin >> card[i][j];
			if (card[i][j] < Min)
				Min = card[i][j];
		}
		LowNum[i] = Min;
	}
	int Max =-1;
	for (int i = 0; i < n; i++)
	{
		if (LowNum[i] > Max)
			Max = LowNump[i];
	}
	cout << Max << endl;


	두번째 풀었던 방법(2)
	int n, m, num, min_num;
	int a[100][100];

	int main() {

	cin >> n >> m;
	memset(a, 10000, sizeof(a));

	num = -1;
	for (int i = 0; i < n; i++) {
		min_num = 10000;
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (min_num > a[i][j]) {
				min_num = a[i][j];
			}
		}
		if (min_num > num) {
			num = min_num;
		}
	}

	cout << num;

	return 0;


}
	*/

	return 0;

}