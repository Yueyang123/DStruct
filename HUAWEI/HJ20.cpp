/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-24 10:47:06
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-24 10:53:43
 */
#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    while(cin >> str){
        int flag[4] = {0};
        if(str.size() <= 8) goto NG;
        for(int i = 0; i < str.size(); ++i)
            if(str[i] >= 'a' && str[i] <= 'z') flag[0] = 1;
            else if(str[i] >= 'A' && str[i] <= 'Z') flag[1] = 1;
            else if(str[i] >= '0' && str[i] <= '9') flag[2] = 1;
            else flag[3] = 1;
        if(flag[0] + flag[1] + flag[2] + flag[3] < 3) goto NG;
        for(int i = 0; i <= str.size()-6; i++)
            for(int j = i+3;j < str.size();j++)
                if(str[i] == str[j] && str[i+1] == str[j+1] &&str[i+2] == str[j+2]) goto NG;
        OK:
        cout << "OK" << endl;continue;
        NG:
        cout << "NG" << endl;
    }
    return 0;
}
