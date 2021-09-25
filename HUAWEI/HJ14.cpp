/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-23 13:57:22
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-23 14:00:40
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int cmp(string a ,string b){
    return a<b;
}
int main()
{
    int N;
    cin>>N;
    vector<string> table;
    while(N--){
        string str;
        cin>>str;
        table.push_back(str);
    }
    sort(table.begin(),table.end(),cmp);
    for(int i=0;i<table.size();i++)
        cout<<table[i]<<endl;

    return 0;
}
