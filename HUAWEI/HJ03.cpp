/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-22 23:15:10
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-23 09:34:59
 */


#include <iostream>
using namespace std;
int main() {
	int N, n;
	while (cin >> N) {
        int a[1001] = { 0 };
		while (N--) {
			cin >> n;
			a[n] = 1;
		}
		for (int i = 0; i < 1001; i++)
			if (a[i])
				cout << i << endl;
	}
	return 0;
}
