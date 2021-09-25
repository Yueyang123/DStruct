/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-23 13:08:05
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-23 13:55:26
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <string.h>
using namespace std;

int main()
{
    char sen[2000];
    char temp[20];
    stack<string> stk;
    cin.getline(sen,2000);
    int i=0,j=-1;//j指向前一个空格位置
    for(i=0;sen[i]!='\0';i++){
        if(sen[i]==' '){
            memset(temp,0,20);
            memcpy(temp,sen+j+1,i-j-1);
            string str=string(temp);
            //cout<<j+1<<" "<<i<<" "<<str<<endl;
            stk.push(str);
            j=i;
        }
    }
    memset(temp,0,20);
    memcpy(temp,sen+j+1,i-j);
    string str=string(temp);
    //cout<<j+1<<" "<<i<<" "<<str<<endl;
    stk.push(str);
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
}