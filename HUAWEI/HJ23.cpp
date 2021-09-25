/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-24 11:08:01
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-24 11:09:38
 */
#include<iostream>
using namespace std;
#include<string>
#include<unordered_map>
int main()
{
    unordered_map<char, int> record;
    string Input;
    while (cin >> Input)
    {
        record.clear();
        
        string Output;
        for (int i = 0; i < Input.size(); ++i)
        {
            if (record[Input[i]] != 0)
            {
                record[Input[i]]++;
            }
            else
            {
                record[Input[i]] = 1;
            }
        }
        int Min = record[Input[0]];
        for (int j = 0; j < Input.size(); ++j)
        {
            Min = min(Min, record[Input[j]]);
        }
        for (int k = 0; k < Input.size(); ++k)
        {
            if (record[Input[k]] != Min)
            {
                Output += Input[k];
            }
        }
        cout << Output << endl;
    }
    return 0;
}