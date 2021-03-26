#include<iostream>
using namespace std;

int main(){
    static long long array[20000001]={0};
    for(int i=2;i<20000001;i++){
        for(int j=i;j<20000001;j+=i){
            array[j] += i;
        }
        array[i]++;
    }
    for(int i=0;i<20000000;i++)
        array[i+1] += array[i];
        
    int c;
    while(cin>>c && c!=0){
        cout<<array[c]<<endl;
    }
}