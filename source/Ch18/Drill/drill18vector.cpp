#include "std_lib_facilities.h"

vector<int> gv{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void f(vector<int> v)
{
	vector<int> lv(v.size());
	lv = gv;
	for (int x : lv)
		cout << x << endl;

	vector<int> lv2 = v;
	for (int x : lv2)
		cout << x << endl;

}

int main()
{
	f(gv);

	vector<int> vv {1, 2*1, 3*2*1, 4*3*2*1, 5*4*3*2*1, 6*5*4*3*2*1, 7*6*5*4*3*2*1, 8*7*6*5*4*3*2*1, 9*8*7*6*5*4*3*2*1, 10*9*8*7*6*5*4*3*2*1};
	f(vv);
}