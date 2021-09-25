/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-23 14:03:37
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-23 14:21:22
 */
#include <iostream>
#include <string.h>
#include <string>
#include <stack>
using namespace std;
//不会自己申请内存
int dec_to_bin(int dec,stack<char> &bin)
{
    int count=0;
    int res=dec;
    while(res>1)
    {
        if(res%2){
            bin.push('1');
            count++;
        }
        else bin.push('0');
        res/=2;
    }
    bin.push('1');
    count++;
    return count;
}

int main() {

    int data;
    cin>> data;
    stack<char> bin;
    cout<<dec_to_bin(data,bin)<<endl;
    while (!bin.empty())
    {
       //cout<<bin.top();
       bin.pop();
    }
    
    return 0;
}