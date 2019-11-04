#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <time.h>

using namespace std;

void DeleteFullMatr(int **mas, int n) {
	for (int i = 0; i < n; i++) {
		delete[] mas[i];
	}
	delete[] mas;
}

int** Fill_Matr_With_Zeros(int** M, const int col, const int row, const int n) {
	int **R = new int*[n];
	for (int i = 0; i < n; i++) {
		R[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			R[i][j] = 0;
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			R[i][j] = M[i][j];
	return R;
}

int** Simple_Way_To_Multiple(int** A, int** B, const int N) {
	int** C = new int*[N];
	for (int i = 0; i < N; i++) {
		C[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int wtf = i;
			C[i][j] = 0;
			for (int t = 0; t < N; t++) {
				C[i][j] += A[i][t] * B[t][j];
			}
		}
	}
	return C;
}

int** Simple_Way_To_Multiple_NonNN_For_Strassens(int** A, int** B, const int col1, const int row1, const int row2, const int n) {
	int **C = new int*[n];
	for (int i = 0; i < n; i++) {
		C[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = 0;
		}
	}

	for (int i = 0; i < col1; i++) {
		for (int j = 0; j < row2; j++) {
			for (int k = 0; k < row1; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	}

	return C;
}

int** Simple_Way_To_Multiple_NonNN(int** A, int** B, const int col1, const int row1, const int row2) {
	int **C = new int*[col1];
	for (int i = 0; i < col1; i++)
	{
		C[i] = new int[row2];
		for (int j = 0; j < row2; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < row1; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	}
	return C;
}

void Take_parts_from_array(int** full, int** part00, int** part01, int** part10, int** part11, const int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			part00[i][j] = full[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = n; j < 2 * n; j++) {
			part01[i][j - n] = full[i][j];
		}
	}
	for (int i = n; i < 2 * n; i++) {
		for (int j = 0; j < n; j++) {
			part10[i- n][j] = full[i][j];
		}
	}
	for (int i = n; i < 2 * n; i++) {
		for (int j = n; j < 2 * n; j++) {
			part11[i - n][j - n] = full[i][j];
		}
	}
}

int** Take_4matr_into_1(int** c1, int** c2, int** c3, int** c4, const int n) {
	int** res = new int*[2 * n];
	for (int i = 0; i < (2 * n); i++) {
		res[i] = new int[2 * n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res[i][j] = c1[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = n; j < 2 * n; j++) {
			res[i][j] = c2[i][j - n];
		}
	}
	for (int i = n; i < 2 * n; i++) {
		for (int j = 0; j < n; j++) {
			res[i][j] = c3[i - n][j];
		}
	}
	for (int i = n; i < 2 * n; i++) {
		for (int j = n; j < 2 * n; j++) {
			res[i][j] = c4[i - n][j - n];
		}
	}
	return res;
}

const int find_our_pow_of_2(int n) {
	int i = 0;
	while (n > pow(2, i)) {
		i++;
	}
	return pow(2, i);
}

int** Sum_Matr(int** A, int** B, int n) {
	int** C = new int*[n];
	for (int i = 0; i < n; i++) {
		C[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	return C;
}

int** Minus_Matr(int** A, int** B, int n) {
	int** C = new int*[n];
	for (int i = 0; i < n; i++) {
		C[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
	return C;
}


int** MM(int** A, int** B, int n) {
	const int N = n / 2;

	int** C = new int*[n];
	for (int i = 0; i < n; i++) {
		C[i] = new int[n];
	}

	if (n <=100) {
		C = Simple_Way_To_Multiple(A, B, n);

	} else {
		int** m1 = new int*[N];
		int** m2 = new int*[N];
		int** m3 = new int*[N];
		int** m4 = new int*[N];
		int** m5 = new int*[N];
		int** m6 = new int*[N];
		int** m7 = new int*[N];
		int** c1 = new int*[N];
		int** c2 = new int*[N];
		int** c3 = new int*[N];
		int** c4 = new int*[N];
		int** a00 = new int*[N];
		int** a01 = new int*[N];
		int** a10 = new int*[N];
		int** a11 = new int*[N];
		int** b00 = new int*[N];
		int** b01 = new int*[N];
		int** b10 = new int*[N];
		int** b11 = new int*[N];
		for (int i = 0; i < N; i++) {
			m1[i] = new int[N];
			m2[i] = new int[N];
			m3[i] = new int[N];
			m4[i] = new int[N];
			m5[i] = new int[N];
			m6[i] = new int[N];
			m7[i] = new int[N];
			c1[i] = new int[N];
			c2[i] = new int[N];
			c3[i] = new int[N];
			c4[i] = new int[N];
			a00[i] = new int[N];
			a01[i] = new int[N];
			a10[i] = new int[N];
			a11[i] = new int[N];
			b00[i] = new int[N];
			b01[i] = new int[N];
			b10[i] = new int[N];
			b11[i] = new int[N];
		}

		Take_parts_from_array(A, a00, a01, a10, a11, N);
		Take_parts_from_array(B, b00, b01, b10, b11, N);

		m1 = MM(Sum_Matr(a00, a11, N), Sum_Matr(b00, b11, N), N);
		m2 = MM(Sum_Matr(a10, a11, N), b00, N);
		m3 = MM(a00, Minus_Matr(b01, b11, N), N);
		m4 = MM(a11, Minus_Matr(b10, b00, N), N);
		m5 = MM(Sum_Matr(a00, a01, N), b11, N);
		m6 = MM(Minus_Matr(a10, a00, N), Sum_Matr(b00, b01, N), N);
		m7 = MM(Minus_Matr(a01, a11, N), Sum_Matr(b10, b11, N), N);

		c1 = Sum_Matr(m7, Minus_Matr(Sum_Matr(m1, m4, N), m5, N), N);
		c2 = Sum_Matr(m3, m5, N);
		c3 = Sum_Matr(m2, m4, N);
		c4 = Sum_Matr(m6, Sum_Matr(m3, Minus_Matr(m1, m2, N), N), N);

		C = Take_4matr_into_1(c1, c2, c3, c4, N);

		DeleteFullMatr(m1, N);
		DeleteFullMatr(m2, N);
		DeleteFullMatr(m3, N);
		DeleteFullMatr(m4, N);
		DeleteFullMatr(m5, N);
		DeleteFullMatr(m6, N);
		DeleteFullMatr(m7, N);
		DeleteFullMatr(c1, N);
		DeleteFullMatr(c2, N);
		DeleteFullMatr(c3, N);
		DeleteFullMatr(c4, N);
		DeleteFullMatr(a00, N);
		DeleteFullMatr(a01, N);
		DeleteFullMatr(a10, N);
		DeleteFullMatr(a11, N);
		DeleteFullMatr(b00, N);
		DeleteFullMatr(b10, N);
		DeleteFullMatr(b01, N);
		DeleteFullMatr(b11, N);
	}
	return C;
}

int** MM_NonNN(int** A, int** B, const int col1, const int row1, const int col2, const int row2) {
	if (row1 != col2) return 0;
	else {
		const int n = find_our_pow_of_2(row1);
		int** C = new int*[n];
		for (int i = 0; i < n; i++) {
			C[i] = new int[n];
		}

		int **New_A = Fill_Matr_With_Zeros(A, col1, row1, n);
		int **New_B = Fill_Matr_With_Zeros(B, col2, row2, n);

		if (n <= 100){
			C = Simple_Way_To_Multiple(New_A, New_B, n);
		}
		else {
			const int N = n / 2;
			int** m1 = new int*[N];
			int** m2 = new int*[N];
			int** m3 = new int*[N];
			int** m4 = new int*[N];
			int** m5 = new int*[N];
			int** m6 = new int*[N];
			int** m7 = new int*[N];
			int** c1 = new int*[N];
			int** c2 = new int*[N];
			int** c3 = new int*[N];
			int** c4 = new int*[N];
			int** a00 = new int*[N];
			int** a01 = new int*[N];
			int** a10 = new int*[N];
			int** a11 = new int*[N];
			int** b00 = new int*[N];
			int** b01 = new int*[N];
			int** b10 = new int*[N];
			int** b11 = new int*[N];
			for (int i = 0; i < N; i++) {
				m1[i] = new int[N];
				m2[i] = new int[N];
				m3[i] = new int[N];
				m4[i] = new int[N];
				m5[i] = new int[N];
				m6[i] = new int[N];
				m7[i] = new int[N];
				c1[i] = new int[N];
				c2[i] = new int[N];
				c3[i] = new int[N];
				c4[i] = new int[N];
				a00[i] = new int[N];
				a01[i] = new int[N];
				a10[i] = new int[N];
				a11[i] = new int[N];
				b00[i] = new int[N];
				b01[i] = new int[N];
				b10[i] = new int[N];
				b11[i] = new int[N];
			}

			Take_parts_from_array(A, a00, a01, a10, a11, N);
			Take_parts_from_array(B, b00, b01, b10, b11, N);

			m1 = MM(Sum_Matr(a00, a11, N), Sum_Matr(b00, b11, N), N);
			m2 = MM(Sum_Matr(a10, a11, N), b00, N);
			m3 = MM(a00, Minus_Matr(b01, b11, N), N);
			m4 = MM(a11, Minus_Matr(b10, b00, N), N);
			m5 = MM(Sum_Matr(a00, a01, N), b11, N);
			m6 = MM(Minus_Matr(a10, a00, N), Sum_Matr(b00, b01, N), N);
			m7 = MM(Minus_Matr(a01, a11, N), Sum_Matr(b10, b11, N), N);

			c1 = Sum_Matr(m7, Minus_Matr(Sum_Matr(m1, m4, N), m5, N), N);
			c2 = Sum_Matr(m3, m5, N);
			c3 = Sum_Matr(m2, m4, N);
			c4 = Sum_Matr(m6, Sum_Matr(m3, Minus_Matr(m1, m2, N), N), N);

			C = Take_4matr_into_1(c1, c2, c3, c4, N);
		}
		return C;
	}
}

int What_Is_The_Biggest_Of3(int f, int s, int t) {
	if (f >= s && f >= t) return f;
	else if (s >= f && s >= t) return s;
	else return t;
}

int main() {


	fstream in_a("A(mn).txt", ios::in);
	fstream in_b("B(mn).txt", ios::in);

	// matrix A - col1*row1, matrix B - col2*row2

	vector<int> test;

	int  col1 = 1025, row1 = 1020, col2 = 1020, row2 = 1026;



	/*const int n = 1024;*/

	/*if (in_a) {
		in_a >> col1 >> row1;
	}
	if (in_b) {
		in_b >> col2 >> row2;
	}*/

	int **A = new int*[col1];
	for (int i = 0; i < col1; i++) {
		A[i] = new int[row1];
	}

	int **B = new int*[col2];
	for (int i = 0; i < col2; i++) {
		B[i] = new int[row2];
	}

	/*if (in_a && in_b) {
		while (!in_a.eof()) {
			for (int i = 0; i < col1; i++) {
				for (int j = 0; j < row1; j++) {
					in_a >> A[i][j];
				}
			}
		}
		while (!in_b.eof()) {
			for (int i = 0; i < col2; i++) {
				for (int j = 0; j < row2; j++) {
					in_b >> B[i][j];
				}
			}
		}
	}*/

	for (int i = 0; i < col1; i++) {
		for (int j = 0; j < row1; j++) {
			A[i][j] = j * (i + 1);
		}
	}
	for (int i = 0; i < col2; i++) {
		for (int j = 0; j < row2; j++) {
			B[i][j] = j * (i + 1);
		}
	}


	cout << endl;
	
	clock_t begin1 = clock();
	int **QT = Simple_Way_To_Multiple_NonNN(A, B, col1, row1, row2);
	clock_t end1 = clock();

	cout << endl;

	int n = find_our_pow_of_2(What_Is_The_Biggest_Of3(col1, row1, row2));
	int **New_A = Fill_Matr_With_Zeros(A, col1, row1, n);
	int **New_B = Fill_Matr_With_Zeros(B, col2, row2, n);
	clock_t begin2 = clock();
	int **Q = MM(New_A, New_B, n);
	clock_t end2 = clock();

	double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
	double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;

	cout << "The time of n^3: " << time_spent1 << " s" << endl;

	cout << "The time of Strassen: " << time_spent2 << " s" << endl;

	system("pause>nul");
	return 0;
}