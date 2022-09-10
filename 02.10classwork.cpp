#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
#define MIN_N 0
#define MAX_N 100
#define MAX(X, Y) (((X)>(Y))?(X):(Y))
#define MIN(X, Y) (((X)<(Y))?(X):(Y))

int* changeArraySize(int *oldar, int oldsize, int newsize) {
	int *newar = new int[newsize] { };
	int minsize { MIN(oldsize, newsize) };
	for (int i = 0; i < minsize; i++) {
		newar[i] = oldar[i];
	}
	delete[] oldar;
	return newar;
}

void swap(int &a, int &b) {
	int t { };
	t = a;
	a = b;
	b = t;
}

template<typename T>
void fillArray(T *ar, int size) {
	for (int i = 0; i < size; i++) {
		double m { (double) rand() / RAND_MAX };
		*(ar + i) = (MAX_N - MIN_N) * m;
	}
}

template<typename T>
void printArray(T *ar, int size) {
	for (int i = 0; i < size; i++) {
		cout << *(ar + i) << " ";
	}
	cout << endl;
}

int* findKey(int *ar, int size, int key) {
	int *ptr = ar;
	for (int i = 0; i < size; i++) {
		if (*ptr == key) {
			*ptr = 0;
			return ptr;
		}
		ptr++;
	}
	return ar;
}

void ch(int &a, int &b, int &c) {
	int m = MAX(a, MAX(b, c));
	a = m;
	b = m;
	c = m;
}

int* evenArray(int *ar1, int *ar2, int size1, int size2) {
	int *r = new int[size1 + size2] { };
	int *ptr = r;
	int truesize { 1 };
	ptr++;
	for (int i = 0; i < size1; i++) {
		if (!(ar1[i] % 2)) {
			*ptr = ar1[i];
			ptr++;
			truesize++;
		}
	}
	for (int i = 0; i < size2; i++) {
		if (!(ar2[i] % 2)) {
			*ptr = ar2[i];
			ptr++;
			truesize++;
		}
	}
	r[0] = truesize;
	r = changeArraySize(r, size1 + size2, truesize);
	return r;
}

int* deleteElement(int *ar, int size, int index) {
	for (int i = index; i < size - 1; i++) {
		ar[i] = ar[i + 1];
	}
	int *newar = new int[size - 1];
	newar = changeArraySize(ar, size, size - 1);
	return newar;
}

int main() {
	srand(time(NULL));
	int *ar1 = new int[5];
	int *ar2 = new int[6];
	int *ar3, *ar4;
	fillArray(ar1, 5);
	printArray(ar1, 5);
	fillArray(ar2, 6);
	printArray(ar2, 6);
	ar3 = evenArray(ar1, ar2, 5, 6);
	printArray(ar3, ar3[0]);
	int n = ar3[0] - 1;
	ar4 = deleteElement(ar3, ar3[0], 0);
	printArray(ar4, n);
	/*int a { 10 }, b { 20 }, c { 30 };
	 cout << "a " << a << " b " << b << " c " << c << endl;
	 ch(a, b, c);
	 cout << "a " << a << " b " << b << " c " << c << endl;*/

	/*int *ar = new int[10];
	 fillArray(ar, 10);
	 printArray(ar, 10);
	 int key { };
	 cout << "Enter key: ";
	 cin >> key;
	 int *addr { };
	 addr = findKey(ar, 10, key);
	 printArray(ar, 10);
	 cout << addr << endl;*/

	/*int a { 10 }, b { 20 };
	 cout << "a " << a << " b " << b << endl;
	 swap(a, b);
	 cout << "a " << a << " b " << b << endl;*/
	/*int var { 25 };
	 int *ptrvar { &var };
	 int *&rptrvar { *&ptrvar };
	 int &rvar { var };
	 cout << "var=" << var << endl;
	 cout << "rvar=" << rvar << endl;
	 cout << "&rvar=" << &rvar << endl;
	 cout << "ptrvar=" << ptrvar << endl;
	 cout << "*ptrvar=" << *ptrvar << endl;
	 cout << "rptrvar=" << rptrvar << endl;
	 cout << "&rptrvar=" << &rptrvar << endl;
	 cout << "*&rptrvar=" << *&rptrvar << endl;
	 cout << "*rptrvar=" << *rptrvar << endl;*/

	return 0;
}
