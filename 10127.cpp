#include<iostream>
using namespace std;

int main(){
    int input;
    while(cin>>input){
        int temp=1;
        for(int i=0;;i++){
            temp = temp % input;
            if(temp == 0){
                cout<<i+1<<endl;
                break;
            }
            temp = temp*10+1;
        }
    }
}
