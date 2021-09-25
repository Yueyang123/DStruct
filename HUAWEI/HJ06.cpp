/*
 * @Descripttion: 寻找质因子
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-23 10:34:53
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-23 10:54:36
 */
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long data;
    long fact=2,res;
    cin>>data;
    res=data;
    while(fact<sqrt(res)){
        while(res%fact!=0){
            fact++;
        }
        
        res/=fact;
        cout<<fact<<' ';
    }
    if(res!=1)
    cout<<res<<endl;
}


