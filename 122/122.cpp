#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){return a.first < b.first;}

int main(){
    string s;
    vector<pair<int, int>> v;
    int complete=0;
    while(cin>>s){
        s = s.substr(1,s.size()-2);
        //cout<<s<<endl;
        if(s==""){
            for(auto i:v){
                for(auto j:v){
                    if(j.first==i.first/2 || i.first==1){
                        complete++;
                        break;
                    }
                }
            }
            if(complete==v.size()){
                sort(v.begin(), v.end(), cmp);
                for(auto i=v.begin();i<v.end();i++){
                    cout<<i->second;
                    if(i!=v.end()-1)
                        cout<<" ";
                }
                cout<<endl;
            }
            else{
                cout<<"not complete"<<endl;
            }
            v.clear();
            complete=0;
            continue;
        }
        string val = s.substr(0 ,s.find_first_of(","));
        string pos = s.substr(s.find_first_of(",")+1);
        int count = 1;
        for(int i=0;i<pos.size();i++){
            if(pos[i]=='R')
                count = count*2+1;
            else if(pos[i]=='L')
                count = count*2;
                
        }
        //cout<<stoi(val)<<" "<<count<<endl;
        bool check=true;
        for(auto i:v){
            if(i.first==count){
                check=false;
                break;
            }
        }
        if(check)
            v.push_back({count, stoi(val)});
        else
            complete++;
    }
}