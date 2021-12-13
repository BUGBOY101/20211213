#define	_CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
int main() {
	cout << "zhuyongqianghaohaonuliba!" << endl;
}

//dfs-全排列

//#include<iostream>
//using namespace std;
//int n, a[10], book[10];
//void dfs(int step) {
//	int i;
//	if (step == n+1) {
//		for (i = 1; i <= n; i++)
//			cout << a[i] << " ";
//		cout << endl;
//		return;
//	}
//	for (i = 1; i <= n; i++) {
//		if (book[i] == 0) {
//			a[step] = i;
//			book[i] = 1;
//			dfs(step + 1);
//			book[i] = 0;
//		}
//	}
//	return;
//}
//int main() {
//	cout << "请输入箱子个数：";
//	cin >> n;
//	a[1] = 1;
//	dfs(1);
//}

//#include<iostream>
//using namespace std;
//int f() {
//	static int a = 1;
//	return ++a;
//}
//int main() {
//	f();
//	cout << f() << endl;
//}