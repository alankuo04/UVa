#include <iostream>

unsigned long long fact(int num){
    unsigned long long factorial = 1;
    for(int i=1;i<=num;i++){
        factorial *= i;
    }
    return factorial;
}

int main(){
    int factorial;
    unsigned long long num;
    int lower_bound = 0, upper_bound = 0;
    for(int i=0;;i++){
        num = 1;
        for(int j=1;j<=i;j++){
            num *= j;
        }
        if(num < 10000)
            lower_bound = i;
        if(num > 6227020800){
            upper_bound = i;
            break;
        }
    }
    while(std::cin>>factorial){
        if(factorial>=0){
            if(factorial >= upper_bound)
                std::cout<<"Overflow!"<<std::endl;
            else if (factorial <= lower_bound)
                std::cout<<"Underflow!"<<std::endl;
            else
                std::cout<<fact(factorial)<<std::endl;
        }
        else{
            factorial = -factorial;
            if(factorial%2==0)
                std::cout<<"Underflow!"<<std::endl;
            else
                std::cout<<"Overflow!"<<std::endl;
        }
    }
}