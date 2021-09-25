/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-23 12:34:15
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-23 12:47:34
 */
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int data;
    char buf[20];
    int dic[10]={0};//对应于10个数的字典，1表示出现过了
    cin>>buf;
    //itoa(data,buf,10);
    int i=strlen(buf);
    for(;i>0;i--){
        if(dic[buf[i-1]-48]==0)cout<<buf[i-1];
        dic[buf[i-1]-48]=1;//相应数字已经出现过了
    }

}