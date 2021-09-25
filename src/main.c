/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-08-30 20:42:49
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-25 10:07:21
 */
#include <stdio.h>
#include "ds.h"
int main()
{
    int a[]={5,4,3,2,1};
    Sortbundle sort=DSSort_Init(SHELL);
    sort.show(a,sizeof(a)/sizeof(int));
    sort.run(a,sizeof(a)/sizeof(int));
    sort.show(a,sizeof(a)/sizeof(int));
}

