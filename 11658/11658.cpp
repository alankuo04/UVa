#include<iostream>
#include<iomanip>
#define N 101

using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b && a!=0 && b!=0){
        bool list[10001] = {};
        int stock[a];
        for(int i=0;i<a;i++){
            string temp;
            cin>>temp;
            stock[i] = stoi(temp.substr(0,temp.find_first_of(".")))*100+stoi(temp.substr(temp.find_first_of(".")+1));
            //cout<<temp.substr(0,2)<<" "<<temp.substr(3)<<endl;
        }
        list[stock[b-1]]=true;
        if(stock[b-1]>5000){
            cout<<"100.00"<<endl;
            continue;
        }
        for(int i=0;i<a;i++){
            if(i==b-1)
                continue;
            for(int j=10000-stock[b-1];j>=0;j--){
                if(list[j]){
                    //cout<<j<<" "<<stock[i]<<" "<<j+stock[i]<<endl;
                    list[j+stock[i]]=true;
                }
            }
        }
        /*for(int i=0;i<10001;i++){
            if(list[i])
                cout<<"i:"<<i<<endl;
        }*/
        for(int i=5001;i<10001;i++){
            if(list[i]){
                //cout<<stock[b-1]<<" "<<i<<endl;
                cout<<fixed<<setprecision(2)<<(float(stock[b-1])/float(i))*100<<endl;
                break;
            }
        }
    }
}