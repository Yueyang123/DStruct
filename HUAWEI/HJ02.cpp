/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-22 22:23:06
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-22 23:00:06
 */
#include <iostream>
#include "string.h"

using namespace std;
int main()
{
    char *data,target;
    int counts=0;
    data=new char[500];
    memset(data,0,500);
    cin.get(data,500);
    cin>>target;
    //cout<<data;
    char *ptr;//ptr_null指向前一个空格的位置
    ptr=data;
    while (*ptr!='\0')
    {
        //非字母
        if(!(target>'A'&&target<'Z')||(target>'a'&&target<'z'))
            if(*ptr==target)counts++;
        else{//字母
            if(target>='A'&&target<='Z'){
                if(*ptr==target|| *ptr==(target+'a'-'A'))counts++;
            }
            else if(target>='a'&&target<='z'){
                if(*ptr==target || *ptr==(target+'A'-'a')){
                    counts++;
                }
            }
        }
        ptr++;
    }
    cout<<counts;
}