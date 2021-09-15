/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-08-30 20:42:49
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-02 11:22:00
 */
#include <stdio.h>
#include "ds.h"
int main()
{
    DSQueue q= DS_InitQueue();
    for(int i=0;i<99;i++)q.enqueue(&q,i);
    q.show(&q);

    for(int i=0;i<10;i++)printf("%d \n", q.dequeue(&q));

    q.show(&q);

    printf("length :%d \n",q.length(&q));
}

