/*
 * @Descripttion: 
 * @Version: V1.0
 * @Author: YURI
 * @Email: 1700695611@qq.com
 * @Website: www.heredifferent.com.cn
 * @Date: 2021-09-24 10:41:13
 * @LastEditors: YURI
 * @LastEditTime: 2021-09-24 10:41:13
 */
#include<iostream>
#include<vector>
#include<map>

using namespace std;

string decomp(string filepath){
    int end_pos = filepath.size()-1;
    for(; end_pos >= 0; end_pos--){
        if(filepath[end_pos] == '\\') break;
    }
    string file = filepath.substr(end_pos + 1, filepath.size() - end_pos - 1);
    if(file.size() > 16) file = file.substr(file.size()-16, 16);
    return file;
}
int main(){
    string filepath, length;
    map<string, int> m;
    int start_index = 0;
    vector<string> record(8,"");
    while(cin >> filepath >> length){
        string file = decomp(filepath);
        string key = file + " " + length;
        if(m.find(key) == m.end()){
            m[key] = 1;
            record[start_index] = key;
            start_index = (start_index + 1) % 8;
        }else{
            m[key] += 1;
        }
    }
    for(int i = 0; i < 8; i++){
        if(record[start_index] != ""){
            cout << record[start_index] << " " << m[record[start_index]] <<endl;
        }
        start_index = (start_index + 1) % 8;
    }
    return 0;
}