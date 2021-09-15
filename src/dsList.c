/*
 * @Descripttion:  顺序表数据结构
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-08-30 21:54:20
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-01 22:06:21
 */
#include "ds.h"


/**
 * @name: DSList_Max DSList_Min
 * @msg: 寻找最大最小值
 * @param {__DSLIST} *list
 * @return {*}
 */
DS_LIST_ELEMTYPE DSList_Max(struct __DSLIST *list)
{
    int i=0;
    DS_LIST_ELEMTYPE max=list->data[0];
    int maxindex=0;
    for(i=0;i<list->length;i++)
    {
        if(DS_LIST_ELEM_GREATER( list->data[i],max)){//如果现有最大值小于于index所在元素
            max=list->data[i];
            maxindex=i;
        }
    }
    return maxindex+1;
}
DS_LIST_ELEMTYPE DSList_Min(struct __DSLIST *list)
{
    int i=0;
    DS_LIST_ELEMTYPE min=list->data[0];
    int minindex=0;
    for(i=0;i<list->length;i++)
    {
        if(DS_LIST_ELEM_GREATER(min, list->data[i])){//如果现有最小值大于index所在元素
            min=list->data[i];
            minindex=i;
        }
    }
    return minindex+1;
}
/**
 * @name: DSList_Reverse
 * @msg: 调换从start到end的元素
 * @param {__DSLIST} *list
 * @param {int} start
 * @param {int} end
 * @return {*}
 */
ds_bool  DSList_Reverse(struct __DSLIST *list,int start,int end)
{
    DS_LIST_ELEMTYPE temp;
    int i=start-1,j=end-1;
    if(start>end){
        assert(!(start>end));
        return ds_false;
    }
    if(start<1||end>list->length){
        assert(!(start<1||end>list->length));
        return ds_false;
    }
    for(i=start-1,j=end-1; i<=(start-1+end-1)/2;i++,j--){
        temp=list->data[j];
        list->data[j]=list->data[i];
        list->data[i]=temp;
    }
    return ds_true;
}
/**
 * @name: DSList_GetElem
 * @msg: 确定元素
 * @param {__DSLIST} *list
 * @param {int} index
 * @return {*}
 */
DS_LIST_ELEMTYPE    DSList_GetElem(struct __DSLIST *list,int index)
{
    DS_LIST_ELEMTYPE fail;
    if(index<1||index>list->length){
        assert(!(index<1||index>list->length));
        return fail;
    }
    return list->data[index-1];
}

/**
 * @name: DS_LocateElem
 * @msg: 定位元素位置
 * @param {__DSLIST} *list
 * @param {DS_LIST_ELEMTYPE} element
 * @return {*}
 */
int DSList_LocateElem(struct __DSLIST *list,DS_LIST_ELEMTYPE element)
{
    int i=0;
    for(i=0;i<list->length;i++)
        if(DS_LIST_ELEM_ISEQUAL(list->data[i],element))return i+1;
    return ds_false;//没找到
}

/**
 * @name: isEmpty
 * @msg: 判空操作 true 空 false 非空
 * @param {__DSLIST} *list
 * @return {*}
 */
ds_bool DSList_ISEmpty(struct __DSLIST *list)
{
    if(list->length==0)return ds_true;
    else return ds_false;
}
/**
 * @name: DS_Insert
 * @msg: 在位序i处插入一个元素，i从1开始 最坏平均时间复杂度 O(n)
 *       从后向前将所有元素向后挪一个
 * @param {__DSLIST} list 
 * @param {int} index
 * @param {DS_LIST_ELEMTYPE} element
 * @return {*}
 */
ds_bool DSList_Insert(struct __DSLIST *list, int index,DS_LIST_ELEMTYPE element)
{
    int j=0;
    if(index<1||index>list->length+1||list->length>=list->maxlength){
        assert(!(index<1||index>list->length+1||list->length>=list->maxlength));
        return ds_false;
    }
    for(j=list->length;j>=index;j--)
        list->data[j]=list->data[j-1];
    list->data[index-1]=element;
    list->length++;
    return ds_true;
}
/**
 * @name: DS_Delete
 * @msg: 在位序i处删除一个元素，i从1开始 最坏平均时间复杂度 O(n)
 *       从前向后，将所有元素向前挪一个
 * @param {__DSLIST} *list
 * @param {int} index
 * @return {*}
 */
ds_bool DSList_Delete(struct __DSLIST *list, int index)
{
    int i=0;
    if(index<1||index>list->length){
        assert(!(index<1||index>list->length));
        return ds_false;
    } 
    for(i=index;i<list->length;i++)
        list->data[i-1]=list->data[i];
    list->length--;
    return ds_true;
}

/**
 * @name: DS_Show
 * @msg: 线性表打印
 * @param {__DSLIST} *list
 * @return {*}
 */
ds_bool DSList_Show(struct __DSLIST *list)
{
    int i=0;
    printf("length :%d \n",list->length);
    printf("[ ");
    for(i=0;i<list->length;i++)
        DS_LIST_ELEM_SHOW(list->data[i]);
    printf("] \n");
    return ds_true;
}
/**
 * @name: DS_InitList
 * @msg: 初始化一个线性表
 * @param {*}
 * @return {DSList}
 */
DSList DS_InitList()
{
    int i;
    DSList List;
    List.length=0;
    List.maxlength=100;
    List.insert=DSList_Insert;
    List.show=DSList_Show;
    List.delete=DSList_Delete;
    List.isempty=DSList_ISEmpty;
    List.locate=DSList_LocateElem;
    List.at =DSList_GetElem;
    List.reverse=DSList_Reverse;
    List.max=DSList_Max;
    List.min=DSList_Min;
    return List;
}

