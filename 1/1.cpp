#include <iostream>
using namespace std;
const int N = 3, M = 301;
struct tov { int m; float c; };
int main()
{
	setlocale(LC_ALL, "Russian");
	int i, j, B[2][M] = { 0 }, pr[M] = { 0 }, w = 0, C[N] = { 0 };
	float f[M] = { 0 };
	tov A[N] = {
		3, 3,
		5, 20,
		92, 1000,
	};
	cout << " Товары:\n";
	for (i = 0; i < N; i++)
		cout << " m" << i << " = " << A[i].m << " c" << i << " = " << A[i].c << endl;

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i - A[j].m < 0)
				continue;
			if (f[i] < f[i - A[j].m] + A[j].c)
			{
				f[i] = f[i - A[j].m] + A[j].c;
				B[0][i] = i - A[j].m;
				B[1][i] = j;
			}
		}
		cout << "\tf(" << i << ") = " << f[i];
		if ((i + 1) % 4 == 0)
			cout << endl;
	}

	/*for (i = 0; i < 2; i++)
	{
		for (j = 0; j < M; j++)
			cout << " " << B[i][j];
		cout << endl;
	}*/
	cout << "\n Общая цена: " << f[M - 1] << "\n Общий вес: ";
	for (i = M - 1, j = 0; (i > 0) && (w + A[pr[j]].m <= M); i = B[0][i], j++)
	{
		pr[j] = B[1][i];
		w += A[pr[j]].m;
	}
	cout << w << "\n Сколько места осталось: " << M - 1 - w << "\n Взятые товары:\n";
	for (i = 0; i < j; i++)
	{
		C[pr[i]]++;
		//cout << " m" << pr[i] << " = " << A[pr[i]].m << " c" << pr[i] << " = " << A[pr[i]].c << endl;
	}
	for (i = 0; i < N; i++)
		cout << " " << C[i] << " m" << i << " = " << A[i].m << " c" << i << " = " << A[i].c << endl;
	return 0;
}