#include <iostream>
#include <string>

using namespace std;



int main()
{
	int nu;
	string ori;
	string par;
	cin >> nu;
	while (nu-- != 0)
	{
		cin >> par >> ori;
		KMP::calNext(par);
		cout << KMP::match(par, ori) << endl;
	}
	system("pause");
	return 0;
}