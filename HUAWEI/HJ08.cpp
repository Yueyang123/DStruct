/*
 * @Descripttion: 合并表记录 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-23 11:25:28
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-23 12:30:22
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Recode{
    public:
        int index;
        int value;
        void print()
        {
            cout<<index<<" "<<value<<endl;
        }
        Recode(int index,int value){
            this->index=index;
            this->value=value;
        }
};
int cmp(Recode a,Recode b){
    return a.index <b.index;
}
int main()
{
    int N;
    vector<Recode>  table;
    cin>>N;
    while (N--)
    {
        int index,value;
        scanf("%d %d",&index,&value);
        Recode r(index,value);
        table.push_back(r);
    }
    sort(table.begin(),table.end(),cmp);

    vector<Recode>::iterator it,it_tail;
    for(it=table.begin();it!=table.end()-1;it++){
        it_tail=it+1;
        int temp=(*it).value;
        if((*it_tail).index==(*it).index){
            (*it).index=-1;
            (*it_tail).value+=temp;
        }
    }
    for(int i=0;i<table.size();i++)
        if(table[i].index!=-1)
            table[i].print();
}