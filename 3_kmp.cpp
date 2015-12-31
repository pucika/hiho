#include <iostream>
#include <string>
#include <vector>

/*
	next数组计算的差距还是影响很大，按照july的写法超时。代码需要优化。
*/

using namespace std;

class KMP
{
public:
	static void calNext(const string& par);
	static int match(const string& par, const string& ori);
	static vector<int> next;
};

vector<int> KMP::next(10000, 0);

void KMP::calNext(const string& par)
{
	/**
	* 构造next数组
	*/
	for (int i = 1; i < par.size(); i++){
		int j = i;
		while (j > 0){
			j = next[j];
			if (par[j] == par[i]){
				next[i + 1] = j + 1;
				break;
			}
		}
	}
}

int KMP::match(const string& par, const string& ori)
{
	int ans = 0;
	int m = ori.size();
	for (int i = 0, j = 0; i<m; i++){
		if (j < par.size() && ori[i] == par[j])  j++;
		else{
			while (j > 0){
				j = next[j];
				if (ori[i] == par[j]){
					j++;
					break;
				}
			}
		}
		if (j == par.size()) 	ans++;
	}
	return ans;
}

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