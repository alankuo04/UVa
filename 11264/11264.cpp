#include<iostream>
using namespace std;

int main(){
    int i,j;
    cin>>i;
    for(int temp_i=0;temp_i<i;temp_i++){
        cin>>j;
        int array[j];
        for(int temp_j=0;temp_j<j;temp_j++){
            cin>>array[temp_j];
        }
        unsigned long long sum=array[0], count=1;
        for(int k=1;k<j;k++){
            if(sum<array[k]){
                sum+=array[k];
                count++;
            }
            else{
                sum-=array[k-1];
                sum+=array[k];
            }
        }
        cout<<count<<endl;
    }
}