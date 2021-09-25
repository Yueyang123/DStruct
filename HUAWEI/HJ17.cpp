/*
 * @Descripttion: 坐标移动
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-24 09:17:49
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-24 10:33:56
 */
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
enum direction{
        LEFT,//A
        RIGHT,//D
        UP,//W
        DOWN//S
};
class Move
{
private:

public:
    enum direction dir;
    int distance;
    int x,y;
    Move()
    {
        x=0;
        y=0;
    }
    Move(enum direction dir,int distance){
        x=0;
        y=0;
        this->dir=dir;
        this->distance=distance;
        switch (dir)
        {
        case LEFT:
            this->x-=distance;
            break;
        case RIGHT:
            this->x+=distance;
            break;
        case UP:
            this->y+=distance;
            break;
        case DOWN:
            this->y-=distance;
            break;        
        default:
            break;
        }
    }
    void show(){
        cout<<x<<","<<y<<endl;
    }
    Move operator+(const Move A)const
    {
        Move m(*this);
        m.x=this->x+A.x;
        m.y=this->y+A.y;
        return m;
    }
};

Move* check(char str[])
{
    enum direction dir;
    int dis;
    char data[3];
    if(strlen(str)!=3&&strlen(str)!=2)return NULL;
    if(str[0]!='A'&&str[0]!='S'&&str[0]!='W'&&str[0]!='D')return NULL;
    if(!(str[1]<='9'&&str[1]>='0'))return NULL;
    if(str[2]<='9'&&str[2]>='0'||str[2]==0){
        memset(data,0,3);
        memcpy(data,&str[1],2);
        dis=atoi(data);
        //cout<<dis<<endl;
        switch (str[0])
        {
        case 'A':
            dir=LEFT;
            break;
        case 'D':
            dir=RIGHT;
            break;
        case 'S':
            dir=DOWN;
            break;
        case 'W':
            dir=UP;
            break;   
        default:
            break;
        }
        Move*m =new Move(dir,dis);
        return m;
    }else return NULL;
}

int main(){
    vector<Move> all_move;
    string discribe;
    while (cin>>discribe)
    {
        const char *p,* str=discribe.c_str();
        char buf[5];
        p=str;
        while (*p!='\0')
        {
            if(*p==';'){
                memset(buf,0,5);
                memcpy(buf,str,p-str);
                Move *temp= check(buf);
                if(temp!=NULL)
                    all_move.push_back(*temp);
                while (*p==';')
                {
                    p++;//一直移动到下一个字母出现的地方
                    str=p;
                }
            }
            else
                p++;
        }
        Move sum;
        for(int i=0;i<all_move.size();i++){
            sum=sum+all_move[i];
        }
        sum.show();
    
    }


    return 0;
}
