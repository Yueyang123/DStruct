/*
 * @Descrmid_expresstion: 四则运算
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-23 08:00:54
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-23 09:29:03
 */
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
#include <assert.h>
#include <vector>
using namespace std;

class expression{
    public:
        string mid_express,last_express;
        expression(string mid_express){
            this->mid_express=mid_express;
        }
        int cal_last()
        {
                stack<int>stk_cache;
                for (int i = 0; i < last_express.size(); i++) {
                if (last_express[i] >= '0' && last_express[i] <= '9') {
                    int temp=0;
                    while (last_express[i]!=',')
                    {
                        temp *= 10;
                        temp+=last_express[i] - '0';
                        i++;
                    }
                    stk_cache.push(temp);
                }
                if (last_express[i] == '+' || last_express[i] == '-' || last_express[i] == '*' || last_express[i] == '/' ) {
                    int s1, s2,temp;
                    s2 = stk_cache.top();
                    stk_cache.pop();
                    s1 = stk_cache.top();
                    stk_cache.pop();
                    if (last_express[i] == '+') {
                        temp = s1 + s2;
                    }
                    if (last_express[i] == '-') {
                        temp = s1 - s2;
                    }
                    if (last_express[i] == '*') {
                        temp = s1 * s2;
                    }
                    if (last_express[i] == '/') {
                        temp = s1 / s2;
                    }
                    stk_cache.push(temp);
                }
            }
            //cout << stk_cache.top() << endl;
            return stk_cache.top();
        }
        void mid_to_last()//中缀转后缀
        {
            stack<int>stk_cache;
            string reversePoland;
                for (int i = 0; i < mid_express.size(); i++) {
                //如果当前位置是数字
                if ('0' <= mid_express[i]&& mid_express[i] <= '9') {
                    int temp;
                    //继续检查该操作数的其他位,取完整的一个整数
                    while ('0' <= mid_express[i] && mid_express[i] <= '9') {
                        reversePoland += mid_express[i];
                        i++;
                    }
                    reversePoland += ',';//每个数字之间用逗号隔开
                    i--;//while循环最后i多+了一次
                }
                if (mid_express[i] == '+' || mid_express[i] == '-') {
                    //判断负数
                    if (mid_express[i] == '-') {
                        if (i == 0 || mid_express[i-1]=='(' || mid_express[i - 1] == '[' || mid_express[i - 1] == '{') {
                            mid_express.insert(mid_express.begin() + i,'0');
                            i--; continue;
                        }
                    }
                    //如果栈内为空或栈顶是括号，加减运算符直接入栈
                    if (stk_cache.empty()|| stk_cache.top()=='(' || stk_cache.top() == '[' || stk_cache.top() == '{') {
                        stk_cache.push(mid_express[i]);
                    }
                    //其他情况都要出栈，直到找到左括号或栈空
                    else if (stk_cache.top() == '*' || stk_cache.top() == '/' || stk_cache.top() == '+' || stk_cache.top() == '-') {
                        while (!(stk_cache.empty() || stk_cache.top() == '(' || stk_cache.top() == '[' || stk_cache.top() == '{'))
                        {
                            reversePoland += stk_cache.top();
                            reversePoland += ',';
                            stk_cache.pop();
                        }
                        stk_cache.push(mid_express[i]);
                    }
                }
                if (mid_express[i] == '*' || mid_express[i] == '/') {
                    if (stk_cache.empty()||stk_cache.top()=='+' || stk_cache.top() == '-'|| stk_cache.top() == '(' || stk_cache.top() == '[' || stk_cache.top() == '{') {
                        stk_cache.push(mid_express[i]);
                    }
                    else if (stk_cache.top() == '*' || stk_cache.top() == '/') {
                        while (stk_cache.top() == '*' || stk_cache.top() == '/') {
                            reversePoland += stk_cache.top();
                            reversePoland += ',';
                            stk_cache.pop();
                        }
                        //reversePoland += mid_express[i];
                        //reversePoland += ',';
                        stk_cache.push(mid_express[i]);
                    }
                }
                if (mid_express[i] == '(' || mid_express[i] == '[' || mid_express[i] == '{') {
                    stk_cache.push(mid_express[i]);
                }
                if (mid_express[i] == ')') {
                    while (stk_cache.top() != '(') {
                        reversePoland += stk_cache.top();
                        reversePoland += ',';
                        stk_cache.pop();
                    }
                    stk_cache.pop();
                }
                if (mid_express[i] == ']') {
                    while (stk_cache.top() != '[') {
                        //出栈
                        reversePoland += stk_cache.top();
                        reversePoland += ','; //每多一个元素就加一个逗号
                        stk_cache.pop();
                    }
                    stk_cache.pop();// [出栈
                }
                if (mid_express[i] == '}') {
                    while (stk_cache.top() != '{') {
                        reversePoland += stk_cache.top();
                        reversePoland += ',';
                        stk_cache.pop();
                    }
                    stk_cache.pop();
                }
            }
            while(!stk_cache.empty()){
                reversePoland += stk_cache.top();
                reversePoland += ',';
                stk_cache.pop();
            }
            this->last_express=reversePoland;
            //cout<<reversePoland;
        }

};

int main()
{
    string str;
    cin>>str;
    expression express=expression(str);
    express.mid_to_last();
    cout<< express.cal_last();
}

