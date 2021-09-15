/*
 * @Descripttion: 队列
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-02 10:26:56
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-02 11:19:07
 */
#ifndef  DSQUEUE_H
#define DSQUEUE_H

#include "ds.h"

typedef struct  __DSQUEUE{
    DS_DSQUEUE_ELEMTYPE data[DS_DSQUEUE_MAXSIZE];
    int front,rear;
    DS_DSQUEUE_ELEMTYPE     (*gethead)(struct __DSQUEUE*queue);
    DS_DSQUEUE_ELEMTYPE     (*dequeue)(struct __DSQUEUE*queue);
    ds_bool                 (*show)(struct __DSQUEUE* queue);
    ds_bool                 (*isempty)(struct __DSQUEUE* queue);
    ds_bool                 (*isfull)(struct __DSQUEUE* queue);
    ds_bool                 (*enqueue)(struct __DSQUEUE* queue,DS_DSQUEUE_ELEMTYPE element);
    int                     (*length)(struct __DSQUEUE*queue);

}DSQueue;
DSQueue DS_InitQueue();



#endif // ! DSQUEUE_H
