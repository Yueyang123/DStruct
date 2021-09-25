#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(char &a,char &b){
    return a>b;
}

bool ch(string t){
    int l=0,r;
    bool flag=false;
    int num[4];
    int k=0;
    for(int i=0;i<t.size();i++){
        if(t[i]=='.'){
            r=i;
            num[k++]=stoi(t.substr(l,r-l));
            l=i+1;
        }
    }
    num[3]=stoi(t.substr(l,t.size()-l));
    if(num[0]>127 && num[0]>=num[1] && num[1]>=num[2] && num[2]>=num[3]){
        if(num[1]==0 && num[2]==0 && num[3]==0){
            string d="",dd;
            while(num[0]!=0){
                d=to_string(num[0]%2)+d;
                num[0]/=2;
            }
            dd=d;
            sort(dd.begin(),dd.end(),cmp);
            if(d==dd){
                flag=true;
            }
        }else if(num[0]==255 && num[1]>127 && num[2]==0 && num[3]==0){
            string d1="",dd1;
            while(num[1]!=0){
                d1=to_string(num[1]%2)+d1;
                num[1]/=2;
            }
            dd1=d1;
            sort(dd1.begin(),dd1.end(),cmp);
            if(dd1==d1){
                flag=true;
            }
        }else if(num[0]==255 && num[1]==255 && num[2]>127 && num[3]==0){
            string d1="",dd1;
            while(num[2]!=0){
                d1=to_string(num[2]%2)+d1;
                num[2]/=2;
            }
            dd1=d1;
            sort(dd1.begin(),dd1.end(),cmp);
            if(dd1==d1){
                flag=true;
            }
        }else if(num[0]==255 && num[1]==255 && num[2]==255 && num[3]>127){
            string d1="",dd1;
            while(num[3]!=0){
                d1=to_string(num[3]%2)+d1;
                num[3]/=2;
            }
            dd1=d1;
            sort(dd1.begin(),dd1.end(),cmp);
            if(dd1==d1 && d1.find('0')!=d1.npos){
                flag=true;
            }
        }
    }
    return flag;
}

int cate(string t){
    int m=0;
    int loc[3]={0,0,0};
    for(int i=0;i<t.size();i++){
        if(t[i]=='.'){
            loc[m++]=i;
        }
    }
    m=7;
    if(loc[0]!=0 && loc[2]!=t.size()-1 && loc[1]-loc[0]!=1 && loc[2]-loc[1]!=1){
        int n=stoi(t.substr(0,loc[0]));
        
        if(n>0 && n<127){
            m=1;
        }else if (n>127 && n<192){
            m=2;
        }else if (n>191 && n<224){
            m=3;
            
        }else if (n>223 && n<240){
            m=4;
        }else if (n>239 && n<256){
            m=5;
        }else if (n==127){
            m=7;
        }
    }
    else{
        m=6;
    }
    return m;
}

int main(){
    string s;
    int res[7]={0,0,0,0,0,0,0};
    int diu=0;
    while(cin>>s){
        string:: size_type pos;
        pos=s.find('~');
        //cout<<ch(s.substr(pos+1,s.size()-pos-1))<<endl;
        if(s.find('~')==s.npos){
            res[5]++;
        }else{
            if(ch(s.substr(pos+1,s.size()-pos-1))){
                int k=cate(s.substr(0,pos));
                //cout<<k<<endl;
                string c=s.substr(0,pos);
                if(k==1){
                    for(int i=0;i<c.size();i++){
                        if(c[i]=='.'){
                            if(stoi(c.substr(0,i))==10){
                                diu++;
                            }
                            break;
                        }
                    }
                }
                else if(k==2){
                    int u=0;
                    int l=0;
                    for(int i=0;i<c.size();i++){
                        if(c[i]=='.' && u==0){
                            if(stoi(c.substr(l,i))==172){
                                u++;
                                l=i+1;
                            }else{
                                break;
                            }
                        }else if(c[i]=='.' && u==1){
                            if(stoi(c.substr(l,i-l))>15 && stoi(c.substr(l,i-l))<32){
                                diu++;
                                break;
                            }
                        }
                    }
                }
                else if(k==3){
                    int u=0;
                    int l=0;
                    for(int i=0;i<c.size();i++){
                        if(c[i]=='.' && u==0){
                            if(stoi(c.substr(l,i))==192){
                                u++;
                                l=i+1;
                            }else{
                                break;
                            }
                        }else if(c[i]=='.' && u==1){
                            if(stoi(c.substr(l,i-l))==168){
                                diu++;
                                break;
                            }
                        }
                    }
                }
                if(k<7){
                    res[k-1]++;
                }
            }else{
                res[5]++;
            }
        }
    }
    res[6]=diu;
    for(int i=0;i<7;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}