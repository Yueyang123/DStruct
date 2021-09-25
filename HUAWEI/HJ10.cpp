/*
 * @Descripttion: 字符个数统计
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-23 12:34:15
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-23 12:50:23
 */
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int count=0;
    char buf[2000];
    int dic[127]={0};//对应于10个数的字典，1表示出现过了
    cin>>buf;
    int i=strlen(buf);
    for(;i>0;i--){
        if(dic[buf[i-1]]==0)count++;
        dic[buf[i-1]]=1;//相应数字已经出现过了
    }
    cout<<count<<endl;
}