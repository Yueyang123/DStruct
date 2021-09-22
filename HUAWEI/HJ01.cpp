/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-22 22:23:06
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-22 22:37:26
 */
#include <iostream>
#include "string.h"

using namespace std;
int main()
{
    char *data;
    data=new char[5000];
    memset(data,0,5000);
    cin.get(data,5000);
    //cout<<data;
    char *ptr_null,*ptr;//ptr_null指向前一个空格的位置
    ptr_null=data;
    ptr=data;
    while (*ptr!='\0')
    {
        ptr++;
        if(*ptr==' ')ptr_null=ptr;
    }
    cout<<ptr-ptr_null-1;
}