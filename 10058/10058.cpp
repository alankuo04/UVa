#include<iostream>
#include<string>
#include<sstream>
#include<deque>
#include<vector>
using namespace std;

const string ARTICLE[2] = {"a", "the"};
const string NOUN[8] = {"tom", "jerry", "goofy", "mickey", "jimmy", "dog", "cat", "mouse"};
const string VERB[8] = {"hate", "love", "know", "like", "hates", "loves", "knows", "likes"};

int check_type(string s){
    for(int i=0;i<2;i++)
        if(s==ARTICLE[i])
            return 5;
    for(int i=0;i<8;i++)
        if(s==NOUN[i])
            return 6;
    for(int i=0;i<8;i++)
        if(s==VERB[i])
            return 7;
    if(s=="and")
        return 8;
    if(s==",")
        return 9;
    return -1;
}

int main(){
    string s;
    vector<int> ds;
    while(getline(cin, s)){
        ds.clear();
        stringstream ss(s);
        string temp;
        ds.push_back(0);
        while(ss>>temp){
            //cout<<temp<<endl;
            if(temp.back()==',' && temp.size()>1){
                string t = temp;
                t.pop_back();
                ds.push_back(check_type(t));
                ds.push_back(check_type(string()+temp.back()));
            }
            else
                ds.push_back(check_type(temp));
        }
        //cout<<endl;
        
        for(auto iter=ds.begin(); iter!=ds.end();iter++){
            if(*iter==5){
                if(*(iter+1)==6){
                    *iter = 4;
                    ds.erase(iter+1);
                }
            }
        }
        for(auto iter=ds.begin(); iter!=ds.end();iter++){
            if(*iter==6){
                *iter = 4;
            }
        }
        for(auto iter=ds.begin(); iter!=ds.end();iter++){
            if(*iter==4){
                *iter = 3;
            }
        }
        for(auto iter=ds.begin(); iter!=ds.end();iter++){
            if(*iter==3){
                if(ds.size()>2 && iter!=ds.end()-2 && *(iter+1)==8 && *(iter+2)==3){
                    *iter = 3;
                    ds.erase(iter+1);
                    ds.erase(iter+1);
                    iter = iter-1;
                }
            }
        }
        for(auto iter=ds.begin(); iter!=ds.end();iter++){
            if(*iter==3){
                if(ds.size()>2 && iter!=ds.end()-2 && *(iter+1)==7 && *(iter+2)==3){
                    //cout<<"CHANGE"<<endl;
                    *iter = 2;
                    ds.erase(iter+1);
                    ds.erase(iter+1);
                    iter = iter-1;
                }
            }
        }
        for(auto iter=ds.begin(); iter!=ds.end();iter++){
            if(*iter==2){
                *iter=1;
            }
        }
        for(auto iter=ds.begin(); iter!=ds.end();iter++){
            if(*iter==1){
                if(ds.size()>2 && iter!=ds.end()-2 && *(iter+1)==9 && *(iter+2)==1){
                    *iter = 1;
                    ds.erase(iter+1);
                    ds.erase(iter+1);
                    iter = iter-1;
                }
            }
        }
        /*cout<<"test: ";
        for(int i: ds){
            cout<<i<<" ";
        }
        cout<<endl;*/

        
        if(ds.size()==2 && ds.at(1)==1)
            cout<<"YES I WILL"<<endl;
        else
            cout<<"NO I WON'T"<<endl;
    }
}