/*
 * @Descripttion: 进制转换
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-23 10:14:08
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-23 10:35:08
 */
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    string str;
    int length=0,i=2,sum=0;//16进制位数
    while(cin>>str)
    {
        length=0;
        i=2;
        sum=0;
        if(str[0]!='0'||str[1]!='x')//不是16进制形式
            continue;
        while(str[i++]!='\0'){
            length++;
        }
        
        i=2;
        while(str[i]!='\0'){
            int res;
            if(str[i]>='0'&&str[i]<='9'){
                res=str[i]-48;
                sum+=res*(int)pow(16,length-i+1);
            }else if(str[i]>='A'&&str[i]<='Z'){
                res=str[i]-55;
                sum+=res*(int)pow(16,length-i+1);
            }else if(str[i]>='a'&&str[i]<='z'){
                res=str[i]-87;
                sum+=res*(int)pow(16,length-i+1);
            }
            i++;
        }
        cout<<sum<<endl;
    }
    return 0;
}