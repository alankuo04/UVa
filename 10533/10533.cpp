#include<iostream>
#include<vector>
using namespace std;

int main(){
    bool prime[1000000]={};
    bool digital_prime[1000000]={};
    for(int i=2;i<1000000;i++){
        if(!prime[i]){
            for(int j=i+i;j<1000000;j+=i){
                prime[j]=true;
            }
        }
    }
    vector<int> prime_number;
    for(int i=2;i<1000000;i++){
        if(!prime[i])
            prime_number.push_back(i);
    }
    vector<int> digital;
    for(int i=0;i<prime_number.size();i++){
        int temp = prime_number[i];
        int sum = 0;
        while(temp!=0){
            sum += temp%10;
            temp/=10;
        }
        //cout<<sum<<endl;
        if(!prime[sum]){
            digital.push_back(prime_number[i]);
            digital_prime[prime_number[i]]=true;
        }
    }
    static int digital_count[1000000]={};
    int count = 0, digit_i = 0;
    for(int i=0;i<1000000;i++){
        if(i==digital[digit_i]){
            count++;
            digit_i++;
        }
        digital_count[i]=count;
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t1,t2, c=0;
        cin>>t1>>t2;
        if(digital_prime[t1])
            c=1;
        cout<<digital_count[t2]-digital_count[t1]+c<<endl;
    }
}