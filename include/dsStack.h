/*
 * @Descripttion: 栈
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-01 22:24:23
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-01 22:54:41
 */
#ifndef DSSTACK_H
#define DSSTACK_H

#include "ds.h"

typedef struct __DSStack
{
    DS_STACK_ELEMTYPE data[DS_STACK_MAXSIZE];
    int top;
    DS_STACK_ELEMTYPE   (*gettop)(struct __DSStack*s);
    DS_STACK_ELEMTYPE   (*pop)(struct __DSStack*s);
    ds_bool             (*show)(struct __DSStack* stack);
    ds_bool             (*push)(struct __DSStack* stack,DS_STACK_ELEMTYPE element);
}DSStack;
DSStack DS_InitStack();

#endif
