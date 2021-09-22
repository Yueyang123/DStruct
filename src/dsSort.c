/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-15 21:18:47
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-16 12:48:06
 */
#include "dsSort.h"



ds_bool DSSortShow(DSSortElemType target[],int length)
{
    int i=0; 
    printf("[");
    for(i=0;i<length;i++)DS_DSSORT_ELEM_SHOW(target[i]);
    printf("] \n");
}
static inline void dssortswap(DSSortElemType* A,DSSortElemType*B)
{
    DSSortElemType temp=*A;
    *A=*B;
    *B=temp;
}
/**
 * @name: DSInsertSort
 * @msg: 插入排序
 * @param {DSSortElemType} target
 * @param {int} length
 * @return {*}
 */
DSSortElemType* DSInsertSort(DSSortElemType target[],int length)
{
    DSSortElemType temp;
    int i=0,j=0;
    if(target==NULL||length<1){
        assert(!(target==NULL||length<1));
        return NULL;
    }
    for(i=1;i<length;i++)
    {
        if(target[i]<target[i-1]){
            temp=target[i];
            for(j=i-1;j>=0&&DS_DSSORT_ELEM_GREATER(target[j],temp);--j)
                target[j+1]=target[j];
            target[j+1]=temp;       
        }
    } 
    return target;   
}

/**
 * @name: DSBubbleSort
 * @msg: 冒泡 排序算法
 * @param {DSSortElemType} target
 * @return {*}
 */
DSSortElemType* DSBubbleSort(DSSortElemType target[],int length)
{
    int i=0;
    int j=length-1;
    unsigned char swapflag=ds_false;
    if(target==NULL||length<1){
        assert(!(target==NULL||length<1));
        return NULL;
    }
    for(i=0;i<length-1;i++){
        swapflag=ds_false;
        for(j=length-1;j>i;j--)
        {
            if(DS_DSSORT_ELEM_GREATER(target[j-1],target[j]))//target[j]<target[j-1]
            {
                dssortswap(&target[j-1],&target[j]);
                swapflag=ds_true;
            }
        }
        if(swapflag==ds_false)//没有发生转换
            break;
    }
    return target;
}
/**
 * @name: DSSort_Init
 * @msg: 初始化一个排序器
 * @param {enum DSSORTWAY} sortway
 * @return {*}
 */
Sortbundle DSSort_Init(enum DSSORTWAY sortway)
{
    Sortbundle sort;
    sort.sortway=sortway;
    sort.show=DSSortShow;
    switch (sortway)
    {
    case BUBBLE:
        sort.run=DSBubbleSort;
        break;
    case INSERT:
        sort.run=DSInsertSort;
        break;    
    default:
        sort.run=DSBubbleSort;
        break;
    }
    
    return sort;
}
