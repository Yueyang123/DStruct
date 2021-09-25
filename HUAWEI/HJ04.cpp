/*
 * @Descripttion: 字符分割
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-23 09:39:57
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-23 10:12:22
 */
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    string s,res;
    int i=0,index=0;
    while(cin>>s){
        while (s[i]!='\0')
        {
            if(i/8!=index){
                index++;
                cout<<res<<endl;
                res.clear();
            }
            res.push_back(s[i]);
            i++;
        }
        if(!res.empty()){
            int zero_length=8-res.length();
            while(zero_length--)
            {
                res.push_back('0');
            }
            cout<<res<<endl;
        }
        index=0;
        i=0;
        res.clear();
    }
}