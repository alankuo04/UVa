#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    bool prime[1000]={};
    vector<int> prime_number;
    for(int i=2;i<1000;i++){
        if(!prime[i]){
            for(int j=i+i;j<1000;j+=i){
                prime[j]=true;
            }
        }
    }
    for(int i=2;i<1000;i++){
        if(!prime[i])
            prime_number.push_back(i);
    }
    
    long long input;
    while(cin>>input){
        if(input < 2){
            cout<<"Not Exist!"<<endl;
            continue;
        }
        long long factors = 1;
        vector<int> factor_list;
        priority_queue<long long, vector<long long>, greater<long long>> queue;

        long long temp = input;
        for(int i=0;i<prime_number.size();i++){
            if(temp%prime_number[i]==0){
                factors *= prime_number[i];
                factor_list.push_back(prime_number[i]);
                while(1){
                    temp /= prime_number[i];
                    if(temp%prime_number[i]!=0)
                        break;
                }
            }
        }
        if(temp>1){
            factors *= temp;
            factor_list.push_back(temp);
        }
        queue.push(factors);

        while(1){
            temp = queue.top();
            if(temp<=input){
                queue.pop();
                for(int i=0;i<factor_list.size();i++){
                    //cout<<"f:"<<temp*factor_list[i]<<endl;
                    queue.push(temp*factor_list[i]);
                }
            }
            else{
                break;
            }
        }
        if(queue.top()<=2000000){
            cout<<queue.top()<<endl;
        }
        else{
            cout<<"Not Exist!"<<endl;
        }
    }
}