#include<iostream>
#include<vector>
using namespace std;

int main(){
    int input;
    vector<bool> prime_table(31624, true);
    vector<int> prime_number;
    for(int i=2;i<31624;i++){
        if(!prime_table[i])
            continue;
        for(int j=i+i;j<31624;j+=i){
            prime_table[j]=false;
        }
    }
    for(int i=2;i<31624;i++){
        if(prime_table[i])
            prime_number.push_back(i);
    }
    while (cin>>input && input!=0){
        int temp=input;
        int i;
        for(i=0;i<prime_number.size();i++){
            if(input%prime_number[i]==0){
                temp = temp - temp/prime_number[i];
                while(input%prime_number[i]==0){
                    input/=prime_number[i];
                }
                //cout<<prime_number[i]<<" "<<input<<" "<<temp<<endl;
            }
        }
        if(input>1){
            temp = temp - temp/input;
        }
        cout<<temp<<endl;
    }
}