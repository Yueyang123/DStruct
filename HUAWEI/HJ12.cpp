/*
 * @Descripttion: 字符串反转
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-23 13:00:40
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-23 13:06:22
 */
#include <iostream>
#include <string.h>
using namespace std;

void swap(int &a ,int& b){
    int temp=a;
    a=b;
    b=temp;
}
int main()
{
    char str[1000];
    memset(str,0,1000);
    int i;
    cin>>str;
    while (i<strlen(str)/2)
    {
        swap(str[i],str[strlen(str)-1-i]);
        i++;
    }
    for(i=0;i<strlen(str);i++)
    cout<<str[i];
    
}

