/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-23 12:51:07
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-23 12:59:47
 */
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int data;
    char buf[50];
    cin>>data;
    sprintf(buf,"%d",data);
    int i=strlen(buf);
    for(;i>0;i--){
        cout<<buf[i-1];
    }
    return 0;
}