#include<iostream>

int main(){
    int square[100000];
    for(int i=0;i<100000;i++)
        square[i] = 0;
    for(int i=0;;i++){
        if(i*i<100000){
            square[i*i] = 1;
        }
        else
            break;
    }
    int a,b;
    while(std::cin>>a>>b){
        if(a==0&&b==0)
            break;
        else{
            int count=0;
            for(int i=a;i<=b;i++){
                if(square[i]==1)
                    count++;
            }
            std::cout<<count<<std::endl;
        }
    }
}