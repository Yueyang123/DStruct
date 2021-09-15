/*
 * @Descripttion: 排序算法
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-15 21:19:06
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-15 21:33:04
 */

typedef int DSSortElemType;
enum DSSORTWAY{
    QUICK,  //默认的排序模式快速排序
    INSERT, //插入排序
    SHELL,  //希尔排序
    BUBBLE, //冒泡排序
    SELECT  //选择排序
};
typedef struct __SORTBUNDLE
{
    enum DSSORTWAY sortway;
    void (*run)(DSSortElemType[] target);
    void (*init)(enum DSSORTWAY way);
}Sortbundle;


