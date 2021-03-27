#include<iostream>
#include<cmath>

bool isPrime(int i){
    for(int c=2;c<=sqrt(i);c++){
        if(i%c==0)
            return false;
    }
    return true;
}

int main(){
    int prime_number[100000];
    for(int i=2, count=0;count<100000;i++){
        if(isPrime(i)){
            prime_number[count] = i;
            count++;
        }
    }
    int input;
    while(std::cin>>input){
        if(input == 0)
            break;
        else if(input == 1299709){
            std::cout<<0<<std::endl;
            continue;
        }
        for(int i=0;i<100000;i++){
            if(input>=prime_number[i] && input<prime_number[i+1]){
                if(input==prime_number[i])
                    std::cout<<0<<std::endl;
                else{
                    std::cout<<(prime_number[i+1]-prime_number[i])<<std::endl;
                }
                break;
            }
        }
    }
}