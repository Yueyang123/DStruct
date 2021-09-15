/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-09 09:56:17
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-09 22:12:26
 */
#ifndef DSMGRAPH
#define DSMGRAPH

#include "ds.h"

enum MGRAPH_IFCONNECTED{MGRAPH_DISCONNECTED,MGRAPH_CONNECTED};

typedef struct __DSMGRAPH
{
    DS_DSMGRAPH_ELEMTYPE Vex[DS_DSMGRAPH_MAXSIZE];
    enum MGRAPH_IFCONNECTED Edge;
    int vexnum,arcnum;
}DSMGpaph;


#endif // !DSMGRAPH
