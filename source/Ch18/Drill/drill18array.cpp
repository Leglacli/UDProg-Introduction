#include "std_lib_facilities.h"

int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void f(int arr[], int n)
{
	int la[10];
	for (int i = 0; i < 10; i++)
	{
		la[i] = ga[i];
	}

	for (int j = 0; j < 10; j++)
		cout << la[j] << endl;

	int* p = new int[n];
	for (int k = 0; k < n; k++)
		p[k] = arr[k];

	for (int l = 0; l < n; l++)
		cout << p[l] << endl;

	delete[] p;
}

int main()
{
	f(ga, 10);
	
	int aa[10] = {1, 2*1, 3*2*1, 4*3*2*1, 5*4*3*2*1, 6*5*4*3*2*1, 7*6*5*4*3*2*1, 8*7*6*5*4*3*2*1, 9*8*7*6*5*4*3*2*1, 10*9*8*7*6*5*4*3*2*1};
	f(aa, 10);
}