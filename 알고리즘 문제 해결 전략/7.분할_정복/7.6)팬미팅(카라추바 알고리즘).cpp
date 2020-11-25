#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

vector<int>multiply(vector<int>& A, vector<int>& B)
{
	vector<int> C(A.size() + B.size() + 1, 0);

	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
		{
			C[i + j] += A[i] * B[j];
		}
	}
	return C;
}
void add(vector<int>& A, vector<int>& B, int k)
{
	A.resize(max(A.size(), B.size()) + k);
	for (int i = 0; i < B.size(); i++)
		A[i + k] += B[i];

}
void substract(vector<int>& A, vector<int>& B)
{
	A.resize(max(A.size(), B.size()) + 1);
	for (int i = 0; i < B.size(); i++)
		A[i] -= B[i];
}

/*카라츠바 알고리즘
 a = a0+a1
 b = b0+b1
 a0, a1은 a를 앞뒤 절반으로 나눈 것

 a*b = (a0*b0) + (a0*b1+b0*a1) + (a1*b1)

   ∴ z0 + ( z1 * 10^half ) + ( z2 * 10^(half*2) )
	   z0 = a0 * b0
	   z2 = a1 * b1
	   z1 = (a0 + b1) * (b0 + b1) - z0 - z2
  */
vector<int>karatsuba(vector<int>& A, vector<int>& B)
{
	if (A.size() > B.size())
	{
		return karatsuba(B, A);
	}
	if (A.size() == 0 || B.size() == 0)
	{
		return vector<int>();
	}
	if (A.size() <= 50)
	{
		return multiply(A, B);
	}
	int half = A.size() / 2;
	vector<int> a0(A.begin(), A.begin() + half);
	vector<int> a1(A.begin() + half, A.end());
	vector<int> b0(B.begin(), B.begin() + min<int>(B.size(), half));
	vector<int> b1(B.begin() + min<int>(B.size(), half), B.end());

	vector <int> z0 = karatsuba(a0, b0);
	vector <int> z2 = karatsuba(a1, b1);

	add(a0, a1, 0);
	add(b0, b1, 0);

	vector<int> z1 = karatsuba(a0, b0);
	substract(z1, z0);
	substract(z1, z2);

	vector<int>res;
	add(res, z0, 0);
	add(res, z1, half);
	add(res, z2, half * 2);

	return res;
}
int hugs(string& m, string& f)
{
	int N = m.size(), M = f.size();
	vector<int>A(N), B(M);
	for (int i = 0; i < N; i++) {
		if (m[i] == 'M')
		{
			A[i] = 1;
		}
	}
	for (int i = 0; i < M; i++)
	{
		if (f[i] == 'M')
		{
			B[M - i - 1] = 1;
		}
	}
	vector<int> C = karatsuba(A, B);
	int allHugs = 0;
	for (int i = N - 1; i < M; ++i)
	{
		if (C[i] == 0)
			++allHugs;
	}
	return allHugs;
}

int main()
{
	int c;
	string m, f;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> m >> f;
		cout << hugs(m, f);
	}

	return 0;
}