/*
 * @Descripttion: 带头结点的单链表数据结构
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-08-31 21:27:02
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-01 13:03:18
 */
#include "ds.h"
#include <stdlib.h>


/**
 * @name: DSSingleLink_Min DSSingleLink_Max
 * @msg: 寻找最大最小值
 * @param {__SINGLELINK} *list
 * @return {*}
 */
DSSingleLinkNode* DSSingleLink_Min(struct __SINGLELINK *list)
{
    DSSingleLinkNode* p=list->head->next;
    DSSingleLinkNode*r=p;
    DS_SINGLELINK_ELEMTYPE min=p->data;
    while (p!=NULL)
    {
        if(DS_SINGLELINK_ELEM_GREATER(min,p->data))//最小值大于当前值
        {
            min=p->data;
            r=p;
        }   
        p=p->next;
    }
    return r;
}

DSSingleLinkNode* DSSingleLink_Max(struct __SINGLELINK *list)
{
    DSSingleLinkNode* p=list->head->next;
    DSSingleLinkNode*r=p;
    DS_SINGLELINK_ELEMTYPE max=p->data;
    while (p!=NULL)
    {
        if(DS_SINGLELINK_ELEM_GREATER(p->data,max))//当前值大于最大值
        {
            max=p->data;
            r=p;
        }   
        p=p->next;
    }
    return r;
}
/**
 * @name: DSSingleLink_Reverse
 * @msg: 倒置单链表
 * @param {__SINGLELINK} *list
 * @return {*}
 */
ds_bool DSSingleLink_Reverse(struct __SINGLELINK *list)
{
    DSSingleLinkNode* p,*t;//在指向当前操作节点
    p=list->head->next;
    DSSingleLinkNode* newhead=(DSSingleLinkNode*)ds_malloc(sizeof(DSSingleLinkNode));//新的头结点
    newhead->next=NULL;
    while (p!=NULL)
    {
        t=p->next;
        p->next=newhead->next;
        newhead->next=p;
        p=t;
    }
    list->head=newhead;
    return ds_true;
}

/**
 * @name: DSSingleLink_Locate
 * @msg: 按值查找
 * @param {__SINGLELINK} *list
 * @param {DS_SINGLELINK_ELEMTYPE} element
 * @return {*}
 */
DSSingleLinkNode* DSSingleLink_Locate(struct __SINGLELINK *list,DS_SINGLELINK_ELEMTYPE element)
{
    DSSingleLinkNode* p=list->head->next;
    while (p!=NULL&& !(DS_SINGLELINK_ELEM_ISEQUAL(p->data,element))){

        p=p->next;
    }
    assert(p!=NULL);
    return p;
}

/**
 * @name: DSSingleLink_GetElem
 * @msg: 按位查找
 * @param {__SINGLELINK} *list
 * @param {int} index
 * @return {*}
 */
DSSingleLinkNode* DSSingleLink_GetElem(struct __SINGLELINK *list,int index)
{
    int j=0;
    DSSingleLinkNode* p=list->head;
    if(index<0){
        assert(!(index<0));
        return NULL;
    }
    while (p!=NULL&&j<index)//直接指向要寻找的位置
    {
        p=p->next;
        j++;
    }
    if(p==NULL){
        assert(p!=NULL);
        return NULL;
    }
    return p;
}

/**
 * @name: DSSingleLink_Show
 * @msg: 单链表打印
 * @param {__SINGLELINK} *list
 * @return {*}
 */
ds_bool DSSingleLink_Show(struct __SINGLELINK *list)
{
    DSSingleLinkNode* p;
    p=list->head;
    printf("singlelink length: %d\n",list->length);
    printf("[");
    while (p->next!=NULL)
    {
        p=p->next;
        DS_SINGLELINK_ELEM_SHOW(p->data);
    }
    printf("]\n");
    return ds_true;
}
/**
 * @name: DSSingleLink_Insert
 * @msg: 单链表插入
 * @param {__SINGLELINK} *list
 * @param {int} index
 * @param {DS_SINGLELINK_ELEMTYPE} element
 * @return {*}
 */
ds_bool DSSingleLink_Insert(struct __SINGLELINK *list, int index,DS_SINGLELINK_ELEMTYPE element)
{
    DSSingleLinkNode* p,*node;//扫描位置使用的指针
    if(index<1){
        assert(!(index<1));
        return ds_false;
    }
    p=list->at(list,index-1);
    if(p==NULL)//应该不会发生,除非超过链表长度
    {
        assert(p!=NULL);
        return ds_false;
    }
    node=(DSSingleLinkNode*)ds_malloc(sizeof(DSSingleLinkNode));
    node->data=element;
    //先将node指向p的下一个元素
    node->next=p->next;
    //再将P指向node
    p->next=node;
    list->length++;
    return ds_true;
}
/**
 * @name: DSSingleLink_Delete
 * @msg: 删除节点
 * @param {__SINGLELINK} *list
 * @param {int} index
 * @return {*}
 */
ds_bool DSSingleLink_Delete(struct __SINGLELINK *list, int index)
{
    DSSingleLinkNode*p=list->head,*t;
    p=list->at(list,index-1);
    if(p==NULL){
        assert(!(p==NULL));
        return ds_false;
    }
    t=p->next;
    p->next=t->next;
    ds_free(t);
    list->length--;
    return ds_true;
}
/**
 * @name: DS_InitSingleLink
 * @msg: 初始化一个单链表
 * @param {*}
 * @return {*}
 */
DSSingleLink DS_InitSingleLink()
{
    DSSingleLink Link;
    Link.head=(DSSingleLinkNode*)ds_malloc(sizeof(DSSingleLinkNode));
    assert(Link.head!=NULL);
    Link.head->next=NULL;
    Link.length=0;
    Link.insert=DSSingleLink_Insert;
    Link.show=DSSingleLink_Show;
    Link.delete=DSSingleLink_Delete;
    Link.at=DSSingleLink_GetElem;
    Link.locate=DSSingleLink_Locate;
    Link.reverse=DSSingleLink_Reverse;
    Link.min=DSSingleLink_Min;
    Link.max=DSSingleLink_Max;
    return Link;
}