/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-03 21:02:16
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-09 09:55:35
 */
#include "ds.h"
#include <stdlib.h>
DSBinTree DS_InitBinTree(){
    DSBinTree b;
    b.root=(dsBinTreeNode*)ds_malloc(sizeof(dsBinTreeNode));
    b.root->data=0;
    b.root->lchild=NULL;
    b.root->rchild=NULL;
}

ds_bool DSBinTree_VisitAll(dsBinTreeNode * t ,int index)
{
    if(index==PREORDER)//先序，根左右
    {
        if(t!=NULL){
            DS_DSBINTREE_ELEM_SHOW(t->data);
            DSBinTree_VisitAll(t->lchild,index);
            DSBinTree_VisitAll(t->rchild,index);
        }
    }else if (index==MIDORDER)
    {
            if(t!=NULL){
            DSBinTree_VisitAll(t->lchild,index);
            DS_DSBINTREE_ELEM_SHOW(t->data);
            DSBinTree_VisitAll(t->rchild,index);
        }
    }else if (index==POSTORDER)
    {
            if(t!=NULL){
            DSBinTree_VisitAll(t->lchild,index);
            DSBinTree_VisitAll(t->rchild,index);
            DS_DSBINTREE_ELEM_SHOW(t->data);
        }
    }
}
