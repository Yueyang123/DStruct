/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-24 11:12:59
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-24 11:18:53
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 基本思路，两遍最长递增子序列，并找和最大
int main(void)
{
	int n;
	while (cin >> n)
	{
		int tmp;
		vector<int> queue;
		vector<int> dp_1(n, 1);
		vector<int> dp_2(n, 1);
		
		for (int i = 0; i < n; ++i)
		{
			cin >> tmp;
			queue.push_back(tmp);
		}

		// 第一遍dp
		for (int i = 0; i < n; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (queue[i] > queue[j] && dp_1[i] < dp_1[j] + 1)
					dp_1[i] = dp_1[j] + 1;
			}
		}

		std::reverse(queue.begin(), queue.end());
		// 第二遍dp
		for (int i = 0; i < n; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (queue[i] > queue[j] && dp_2[i] < dp_2[j] + 1)
					dp_2[i] = dp_2[j] + 1;
			}
		}
		std::reverse(dp_2.begin(), dp_2.end());

		int max = -1;
		int sum;
		for (int i = 0; i < n; ++i)
		{
			sum = dp_1[i] + dp_2[i];
			if (sum > max)
			{
				max = sum;
			}
		}
		cout << n - max + 1 << endl;
	}
	return 0;
}