/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-03 21:02:25
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-04 13:40:26
 */
#ifndef  DSBINTREE
#define  DSBINTREE

#include "ds.h"

typedef struct DSBINTREENODE
{
    DS_DSBINTREE_ELEMTYPE data;
    struct DSBINTREENODE* lchild,*rchild;
}dsBinTreeNode;

enum DSBINTREE_VISIT_TYPE{
    PREORDER,
    MIDORDER,
    POSTORDER
};
typedef struct __DSBINTREE
{
    dsBinTreeNode* root;

}DSBinTree;
DSBinTree DS_InitBinTree();

#endif // ! DSBINTREE
