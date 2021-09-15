/*
 * @Descripttion: 顺序表数据结构
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-08-31 12:04:24
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-01 22:20:53
 */
#ifndef  DSLIST_H
#define  DSLIST_H

#include "ds.h"


typedef struct __DSLIST{
    DS_LIST_ELEMTYPE data[DS_LIST_MAXSIZE];
    unsigned int length;
    unsigned int maxlength;
    ds_bool             (*show)(struct __DSLIST *list);
    ds_bool             (*insert)(struct __DSLIST *list, int index,DS_LIST_ELEMTYPE element);
    ds_bool             (*delete)(struct __DSLIST *list, int index);
    ds_bool             (*isempty)(struct __DSLIST *list);
    int                 (*locate)(struct __DSLIST *list,DS_LIST_ELEMTYPE element);
    DS_LIST_ELEMTYPE    (*at)(struct __DSLIST *list,int index);
    
    ds_bool             (*reverse)(struct __DSLIST *list,int start,int end);
    DS_LIST_ELEMTYPE    (*min)(struct __DSLIST *list);
    DS_LIST_ELEMTYPE    (*max)(struct __DSLIST *list);

}DSList;
DSList DS_InitList();


#endif // DEBUG