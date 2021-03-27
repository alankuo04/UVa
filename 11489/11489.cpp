#include<iostream>
#include<string>
using namespace std;

bool check(string s){
    int sum=0;
    for(int i=0;i<s.size();i++){
        sum+=s[i]-'0';
    }
    if(sum%3==0)
        return true;
    else
        return false;
}

int main(){
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        string s;
        cin>>s;
        int count = 0;
        for(int j=0;j<s.size();j++){
            for(int k=0;k<s.size();k++){
                //cout<<check(s)<<endl;
                if(s[k]!='0'){
                    string temp = s;
                    temp[k]='0';
                    if(check(temp)){
                        count++;
                        s[k]='0';
                        break;
                    }
                }
            }
        }
        //cout<<count<<endl;
        if(count%2==0)
            cout<<"Case "<<i+1<<": T"<<endl;
        else
            cout<<"Case "<<i+1<<": S"<<endl;
    }
}