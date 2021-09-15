/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-08-31 09:42:24
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-09 09:59:23
 */
#ifndef DS_H
#define DS_H
//#define NDEBUG
#include <stdio.h>
#include <assert.h>
#include <string.h>
//使用线性表
#define USE_DSTLIST         1
//使用单链表
#define USE_DSSINGLELINK    1
//使用栈
#define USE_DSSTACK         1
//使用栈
#define USE_DSQUEUE         1
//使用树
#define USE_DSBINTREE       1
//使用邻接矩阵图
#define USE_DSMGRAPH       1

enum DS_BOOL{
    ds_false=0,
    ds_true=1,
};
typedef unsigned char ds_bool ;
#define ds_malloc(s)   malloc(s)  
#define ds_free(p)     free(p)  


#if USE_DSTLIST
    //用户定义的元素
    typedef int                 DS_LIST_ELEMTYPE;
    //判同
    #define DS_LIST_ELEM_ISEQUAL(A,B) (A==B)
    //A是否大于B
    #define DS_LIST_ELEM_GREATER(A,B) (A>B)
    //输出
    #define DS_LIST_ELEM_SHOW(A) printf("%d\t",A)
    #define DS_LIST_MAXSIZE    100
    #include "dsList.h"
#endif

#if USE_DSSINGLELINK 

    typedef int DS_SINGLELINK_ELEMTYPE;
    #define DS_SINGLELINK_ELEM_ISEQUAL(A,B) (A==B)
    //A是否大于B
    #define DS_SINGLELINK_ELEM_GREATER(A,B) (A>B)
    //输出
    #define DS_SINGLELINK_ELEM_SHOW(A) printf("%d ->",A)
    #include "dsSingleLink.h"

#endif


#if USE_DSSTACK

    typedef int DS_STACK_ELEMTYPE;
    #define DS_STACK_ELEM_ISEQUAL(A,B) (A==B)
    //A是否大于B
    #define DS_STACK_ELEM_GREATER(A,B) (A>B)
    //输出
    #define DS_STACK_ELEM_SHOW(A) printf("%d ",A)
    #define DS_STACK_MAXSIZE    100
    #include "dsStack.h"

#endif


#if USE_DSQUEUE

    typedef int DS_DSQUEUE_ELEMTYPE;
    #define DS_DSQUEUE_ELEM_ISEQUAL(A,B) (A==B)
    //A是否大于B
    #define DS_DSQUEUE_ELEM_GREATER(A,B) (A>B)
    //输出
    #define DS_DSQUEUE_ELEM_SHOW(A) printf("%d ",A)
    #define DS_DSQUEUE_MAXSIZE    100
    #include "dsQueue.h"
#endif

#if USE_DSBINTREE

    typedef int DS_DSBINTREE_ELEMTYPE;
    #define DS_DSBINTREE_ELEM_ISEQUAL(A,B) (A==B)
    //A是否大于B
    #define DS_DSBINTREE_ELEM_GREATER(A,B) (A>B)
    //输出
    #define DS_DSBINTREE_ELEM_SHOW(A) printf("%d ",A)
    #include "dsBinTree.h"
#endif

#if USE_DSMGRAPH
    typedef int DS_DSMGRAPH_ELEMTYPE;
    #define DS_DSMGRAPH_ELEM_ISEQUAL(A,B) (A==B)
    //A是否大于B
    #define DS_DSMGRAPH_ELEM_GREATER(A,B) (A>B)
    //输出
    #define DS_DSMGRAPH_ELEM_SHOW(A) printf("%d ",A)
    #define DS_DSMGRAPH_MAXSIZE    100
    #include "dsMGraph.h"
#endif

#endif