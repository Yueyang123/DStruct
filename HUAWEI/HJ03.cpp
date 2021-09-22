/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-22 23:15:10
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-23 00:17:13
 */
#include <iostream>
#include <assert.h>
#include <vector>
#include <string.h>
#include<algorithm>
using namespace std;
int cmp(int a,int b){
    return a<b;
}//升序排列
class group{
    private:
        int length;//就是N
        vector<int> data;
    public:

        group(int length){
            if(!(length>=0&&length<=1000))return;
            int temp;
            this->length=length;
            for(int i=0;i<length;i++){
                cin>>temp;
                assert(temp>=1&&temp<=1000);
                this->data.push_back(temp);
            }
           	vector<int>::iterator it; 
            for(it = data.begin();it != data.end();it++)
		        cout<<*it<<" ";
        }
        void delete_repeat()
        {

        }
        void data_sort()
        {
            sort(this->data.begin(),this->data.end(),cmp);
        }
};

int main()
{
    vector<group> task;
    char data[5];
    int data_in=1;
    memset(data,0,5);
    cin.getline(data,5);
    data_in=atoi(data);
    assert(data_in>=1&& data_in<=1000);
    while (data[0]=='\n')
    {
        group temp=group(data_in);
        task.push_back(temp);
        memset(data,0,5);
        cin.getline(data,5);
        data_in=atoi(data);
        cout<<data_in;
    }
    cout<<"over";


}