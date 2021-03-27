#include<iostream>
#include<cmath>
using namespace std;

int main(){
    unsigned int array[33];
    for(int i=0;i<=32;i++)
        array[i] = int(pow(2,i));
    unsigned int input;
    while(cin>>input){
        for(int i=0;i<=32;i++){
            if(input>array[i] && input<=array[i+1]){
                cout<<input-1+(i)<<endl;
                break;
            }
        }
    }
}