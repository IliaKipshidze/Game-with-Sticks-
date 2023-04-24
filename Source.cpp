#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void binary(int a, vector <int>& v);
void insertZeros(vector <int>& b, vector <int>& n, vector <int>& m);
void makeOnesEven(vector <int>& r, vector <int>& t, vector <int>& p);
void backToDecimal(vector <int> a, vector <int> b, vector <int> c, int& d, int& f, int& g);

int main() {
	vector <int> V, M, N, z, x, s;
	int a, b, c, j, l, k;
	cout << "Enter three (starting) numbers:  \n";
	cin >> j >> l >> k;
	a = j; b = l; c = k;
	binary(j, z);
	binary(l, x);
	binary(k, s);
	insertZeros(z, x, s);
	makeOnesEven(z, x, s);
	backToDecimal(z, x, s, j, l, k);
	if (a == j && b == l && c == k) {
		cout << "YOU START\n";
		while (true) {
			cout << "\nit is your turn!  - please enter three numbers (remember you can change only one number):  ";
			cin >> a >> b >> c;
			V.clear(); M.clear(); N.clear();
			binary(a, V);
			binary(b, M);
			binary(c, N);
			insertZeros(V, M, N);
			makeOnesEven(V, M, N);
			backToDecimal(V, M, N, a, b, c);
			cout << "\nit is computer's turn!   " << a << "\t" << b << "\t" << c;
			if (a == 0 && b == 0 && c == 0) {
				cout << "\nCOMPUTER WON!!!" << "\nIt is your turn and you have not left any move!"
					<< "\nPrepare better and try again!" << "\nGOOD LUCK!!!";
				cout << endl << endl << endl;
				break;
			}
		}
	}
	else {
		cout << "COMPUTER STARTS\n";
		while (true) {
			binary(a, V);
			binary(b, M);
			binary(c, N);
			insertZeros(V, M, N);
			makeOnesEven(V, M, N);
			backToDecimal(V, M, N, a, b, c);
			cout << "\nit is computer's turn!   " << a << "\t" << b << "\t" << c;
			if (a == 0 && b == 0 && c == 0) {
				cout << "\nCOMPUTER WON!!!" << "\nIt is your turn and you have not left any move!"
					<< "\nPrepare better and try again!" << "\nGOOD LUCK!!!";
				cout << endl << endl << endl;
				break;
			}
			cout << "\nit is your turn!  - please enter three numbers (remember you can change only one number):  ";
			cin >> a >> b >> c;
			V.clear(); M.clear(); N.clear();
		}
	}
}
void binary(int a, vector <int>& v) {
	int t, k = 0;
	if (a == 0) v.insert(v.begin(), 0);
	while (a > 0) {
		t = a % 2;
		a /= 2;
		v.insert(v.begin(), t);
	}
}
void insertZeros(vector <int>& b, vector <int>& n, vector <int>& m) {
	int MAX = b.size();
	if (m.size() > MAX) MAX = m.size();
	if (n.size() > MAX) MAX = n.size();

	int j = MAX - b.size(), k = MAX - n.size(), l = MAX - m.size();
	for (int i = 0; i < j; i++) b.insert(b.begin(), 0);
	for (int i = 0; i < k; i++) n.insert(n.begin(), 0);
	for (int i = 0; i < l; i++) m.insert(m.begin(), 0);
}
void makeOnesEven(vector <int>& r, vector <int>& t, vector <int>& p) {
	int a, b;
	for (a = 0; a < r.size(); a++) {
		int countOnes = 0;
		if (r[a] == 1)countOnes++;
		if (t[a] == 1)countOnes++;
		if (p[a] == 1)countOnes++;
		if (countOnes % 2 != 0) {
			if (r[a] == 1) {
				r[a] = 0;
				for (int k = a + 1; k < r.size(); k++) {
					int localCounter = 0;
					if (r[k] == 1)localCounter++;
					if (t[k] == 1)localCounter++;
					if (p[k] == 1)localCounter++;
					if (localCounter % 2 != 0) {
						if (r[k] == 0) {
							r[k] = 1;
							continue;
						}
						if (r[k] == 1) r[k] = 0;
					}
				}
			}
			else if (t[a] == 1) {
				t[a] = 0;
				for (int k = a + 1; k < t.size(); k++) {
					int localCounter = 0;
					if (r[k] == 1)localCounter++;
					if (t[k] == 1)localCounter++;
					if (p[k] == 1)localCounter++;
					if (localCounter % 2 != 0) {
						if (t[k] == 0) {
							t[k] = 1;
							continue;
						}
						if (t[k] == 1) t[k] = 0;
					}
				}
			}
			else if (p[a] == 1) {
				p[a] = 0;
				for (int k = a + 1; k < p.size(); k++) {
					int localCounter = 0;
					if (r[k] == 1)localCounter++;
					if (t[k] == 1)localCounter++;
					if (p[k] == 1)localCounter++;
					if (localCounter % 2 != 0) {
						if (p[k] == 0) {
							p[k] = 1;
							continue;
						}
						if (p[k] == 1) p[k] = 0;
					}
				}
			}
			break;
		}
	}
}
void backToDecimal(vector <int> a, vector <int> b, vector <int> c, int& d, int& f, int& g) {
	d = 0; f = 0; g = 0;
	int k = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		d += a[i] * pow(2, k);
		f += b[i] * pow(2, k);
		g += c[i] * pow(2, k);
		k++;
	}
}



