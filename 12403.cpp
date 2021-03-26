#include<iostream>
#include<string>

int main(){
    int sum = 0, count, money;
    std::string mode;
    std::cin>>count;
    for(int i=0;i<count;i++){
        std::cin>>mode;
        if(mode=="donate"){
            std::cin>>money;
            sum += money;
        }
        else if(mode=="report"){
            std::cout<<sum<<std::endl;
        }
    }
}