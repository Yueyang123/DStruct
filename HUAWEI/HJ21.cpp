/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-24 10:55:27
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-24 11:00:01
 */
#include<iostream>
#include<string>
using namespace std;
const string dict1="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const string dict2="bcdefghijklmnopqrstuvwxyza22233344455566677778889999";

char Char_Change(char a){
    for(int i=0;i<dict1.size();i++)
        if(dict1[i]==a) return dict2[i];
    return a;
}

int main(){
    //string data="YUANzhi1987";
    string data;
    while(getline(cin,data)){
    	for(int i=0;i<data.size();i++)
        	data[i] = Char_Change(data[i]);
    	cout<<data<<endl;
    }
    return 0;
}
