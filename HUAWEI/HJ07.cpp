/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-23 10:59:47
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-23 11:24:34
 */
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main()
{
    string str;
    char* res;
    cin>>str;
    int i=0;
    while(str[i]!='.'&&i<str.length()){
        i++;
    }
    if(i>=str.length()){
        cout<<atoi(str.c_str())<<endl;
    }else{
        res=new char[i+1];
        memset(res,0,i+1);
        memcpy(res,str.c_str(),i);
        if(str[i+1]>='5')
            cout<<atoi(res)+1<<endl;
        else
            cout<<atoi(res)<<endl;
    }
}