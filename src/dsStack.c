/*
 * @Descripttion: 栈
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-01 22:27:02
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-01 22:53:49
 */
#include "dsStack.h"

/**
 * @name: DSStack_GetElem
 * @msg: 获取栈顶元素
 * @param {__DSStack*} stack
 * @return {*}
 */
DS_STACK_ELEMTYPE DSStack_GetTop(struct __DSStack* stack)
{
    DS_STACK_ELEMTYPE res;
    if(stack->top==-1){
        assert(!((stack->top==-1)));
        return res;
    }
    res=stack->data[stack->top];
    return res;
}

/**
 * @name: DSStack_Show
 * @msg: 打印栈元素
 * @param {__DSStack*} stack
 * @return {*}
 */
ds_bool DSStack_Show(struct __DSStack* stack)
{
    int i=0;
    printf("[ ");
    for(i=0;i<=stack->top;i++)
    {
        DS_STACK_ELEM_SHOW(stack->data[i]);
    }
    printf("]");
    return ds_true;
}
/**
 * @name: DSStack_Push
 * @msg: 入栈
 * @param {__DSStack*} stack
 * @param {DS_STACK_ELEMTYPE} element
 * @return {*}
 */
ds_bool DSStack_Push(struct __DSStack* stack,DS_STACK_ELEMTYPE element)
{
    if(stack->top>=DS_STACK_MAXSIZE){
        assert(!(stack->top>=DS_STACK_MAXSIZE));
        return ds_false;
    }
    stack->top++;
    stack->data[stack->top]=element;
    return ds_true;
}
/**
 * @name: DSStack_Pop
 * @msg: 出栈
 * @param {__DSStack*} stack
 * @return {*}
 */
DS_STACK_ELEMTYPE DSStack_Pop(struct __DSStack* stack)
{
    DS_STACK_ELEMTYPE res;
    if(stack->top==-1){
        assert(!(stack->top==-1));
        return res;
    }
    res= stack->data[stack->top];
    stack->top--;
    return res;
}

/**
 * @name: DSInit_Stack
 * @msg: 初始化一个栈
 * @param {*}
 * @return {*}
 */
DSStack DS_InitStack()
{
    DSStack s;
    s.top=-1;
    s.pop=DSStack_Pop;
    s.push=DSStack_Push;
    s.show=DSStack_Show;
    s.gettop=DSStack_GetTop;
    return s;
}