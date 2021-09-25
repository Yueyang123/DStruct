/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-24 11:00:17
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-24 11:06:29
 */
/*
递归问题
3个瓶子换1瓶水+1个空瓶子，两个瓶子换1瓶水+0个空瓶子，1个瓶子换0瓶水。
f(1) = 0
f(2) = 1
f(3) = 1
f(4) = f(2)+1    //4个瓶子，其中3个可以换1瓶水+1个空瓶，所以是f(2)+1
f(5) = f(3)+1    //3个瓶子换1瓶水+1个空瓶，所以是f(3)+1
...
f(n) = f(n-2)+1 */
#include <iostream>
 
using namespace std;
 
int f(int n)
{
    if(n==1) return 0;
    if(n==2) return 1;
    return f(n-2)+1;
}
 
int main()
{
    int n;
    while(cin >> n){
        if(n==0)
            break;
        cout<<f(n)<<endl;
    }
    return 0;
}