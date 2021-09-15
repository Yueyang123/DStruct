/*
 * @Descripttion: 队列
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-02 10:27:07
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-02 11:22:21
 */
#include "ds.h"
int DSQueue_Length(struct __DSQUEUE *queue)
{
    return (queue->rear-queue->front+DS_DSQUEUE_MAXSIZE)%DS_DSQUEUE_MAXSIZE;
}
/**
 * @name: DSQueue_GetHead
 * @msg: 获取队头元素
 * @param {__DSQUEUE} *queue
 * @return {*}
 */
DS_DSQUEUE_ELEMTYPE DSQueue_GetHead(struct __DSQUEUE *queue)
{
    DS_DSQUEUE_ELEMTYPE res;
    if(queue->isempty(queue)==ds_true){
        assert(!(queue->isempty(queue)==ds_true));
        return res;
    }
    res=queue->data[queue->front];
    return res;
}
/**
 * @name: DSQueue_Show
 * @msg: 显示队列
 * @param {__DSQUEUE} *queue
 * @return {*}
 */
ds_bool DSQueue_Show(struct __DSQUEUE *queue)
{
    int temp=queue->front;
    int length=0;
    printf("[");
    while (temp!=queue->rear)
    { 
        length++;
        DS_DSQUEUE_ELEM_SHOW(queue->data[temp]);
        temp=(temp+1)%DS_DSQUEUE_MAXSIZE;
    }
    printf("]\n");
    printf("length: %d\n",length);
    
}
/**
 * @name: DSQueue_DeQueue
 * @msg: 出队
 * @param {__DSQUEUE} *queue
 * @return {*}
 */
DS_DSQUEUE_ELEMTYPE DSQueue_DeQueue(struct __DSQUEUE *queue)
{
    DS_DSQUEUE_ELEMTYPE res;
    if(queue->isempty(queue)==ds_true){
        assert(!(queue->isempty(queue)==ds_true));
        return res;
    }
    res=queue->data[queue->front];
    queue->front=(queue->front+1)% DS_DSQUEUE_MAXSIZE;
    return res;
}

/**
 * @name: DSQueue_EnQueue
 * @msg: 入队
 * @param {__DSQUEUE} *queue
 * @param {DS_DSQUEUE_ELEMTYPE} element
 * @return {*}
 */
ds_bool DSQueue_EnQueue(struct __DSQUEUE *queue,DS_DSQUEUE_ELEMTYPE element)
{
    if(queue->isfull(queue)==ds_true){
        assert(!(queue->isfull(queue)==ds_true));
        return ds_false;
    }
    queue->data[queue->rear]=element;
    queue->rear=(queue->rear+1)%DS_DSQUEUE_MAXSIZE;
    return ds_true;
}

/**
 * @name: DSQueue_ISFull
 * @msg: 判断队满
 * @param {__DSQUEUE} *queue
 * @return {*}
 */
ds_bool DSQueue_ISFull(struct __DSQUEUE *queue)
{
    if((queue->rear+1)%DS_DSQUEUE_MAXSIZE==queue->front)return ds_true;
    else return ds_false;
}
/**
 * @name: DSQueue_ISEmpty
 * @msg: 判空
 * @param {__DSQUEUE} *queue
 * @return {*}
 */
ds_bool DSQueue_ISEmpty(struct __DSQUEUE *queue)
{
    if(queue->front==queue->rear)return ds_true;
    else return ds_false;
}

/**
 * @name: DS_InitQueue
 * @msg: 初始化队列
 * @param {*}
 * @return {*}
 */
DSQueue DS_InitQueue()
{
    DSQueue q;
    q.front=q.rear=0;
    q.show=DSQueue_Show;
    q.enqueue=DSQueue_EnQueue;
    q.dequeue=DSQueue_DeQueue;
    q.gethead=DSQueue_GetHead;
    q.isempty=DSQueue_ISEmpty;
    q.isfull=DSQueue_ISFull;
    q.length=DSQueue_Length;
    return q;
}

