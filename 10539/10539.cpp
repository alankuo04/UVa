#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000000000000
using namespace std;

int main(){
    bool prime[1000000]={};
    vector<int> prime_number;
    vector<long long> almost_prime;
    for(int i=2;i<1000000;i++){
        if(!prime[i]){
            for(int j=i+i;j<1000000;j+=i){
                prime[j]=true;
            }
        }
    }
    for(int i=2;i<1000000;i++){
        if(!prime[i])
            prime_number.push_back(i);
    }
    for(int i=0;i<prime_number.size();i++){
        long long temp = prime_number[i];
        for(;temp<MAX;){
            temp *= prime_number[i];
            almost_prime.push_back(temp);
        }
    }
    sort(almost_prime.begin(), almost_prime.end());
    int c;
    cin>>c;
    for(int i=0;i<c;i++){
        long long low, high;
        int low_index=-1, high_index=-1;
        cin>>low>>high;
        for(int i=0;i<almost_prime.size();i++){
            if(almost_prime[i]>=low && low_index == -1)
                low_index = i;
            if(almost_prime[i]<=high)
                high_index = i;
            if(almost_prime[i]>=high)
                break;
        }
        cout<<high_index-low_index+1<<endl;
    }
}