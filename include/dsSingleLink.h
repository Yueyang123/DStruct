/*
 * @Descripttion: 单链表数据结构
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-08-31 21:25:22
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-01 12:52:18
 */
#ifndef  DSSINGLELIST_H
#define  DSSINGLELIST_H

#include "ds.h"

typedef struct __DSSingleLinkNode
{
   DS_SINGLELINK_ELEMTYPE data;
   struct __DSSingleLinkNode*next;
}DSSingleLinkNode;


typedef struct __SINGLELINK{

    DSSingleLinkNode *head;
    int length;
    ds_bool             (*show)(struct __SINGLELINK *list);
    ds_bool             (*insert)(struct __SINGLELINK *list, int index,DS_SINGLELINK_ELEMTYPE element);
    ds_bool             (*delete)(struct __SINGLELINK *list, int index);
    ds_bool             (*isempty)(struct __SINGLELINK *list);
    DSSingleLinkNode*   (*locate)(struct __SINGLELINK *list,DS_SINGLELINK_ELEMTYPE element);
    DSSingleLinkNode*   (*at)(struct __SINGLELINK *list,int index);

    ds_bool             (*reverse)(struct __SINGLELINK *list);
    DSSingleLinkNode*   (*min)(struct __SINGLELINK *list);
    DSSingleLinkNode*   (*max)(struct __SINGLELINK *list);

}DSSingleLink;
DSSingleLink DS_InitSingleLink();


#endif // DEBUG


