#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int a;
    while(cin>>a && a!=0){
        vector<int> array;
        for(int i=0;i<a;i++){
            int temp;
            cin>>temp;
            array.push_back(temp);
        }
        sort(array.begin(), array.end());
        int max_d;
        bool flag=false;
        for(int i=a-1;!flag&&i>=0;i--){
            for(int j=0;!flag&&j<a;j++){
                if(j==i)
                    continue;
                for(int k=j+1;!flag&&k<a;k++){
                    if(k==i)
                        continue;
                    for(int l=k+1;!flag&&l<a;l++){
                        if(l==i)
                            continue;
                        if(array[i]==(array[j]+array[k]+array[l]) && array[i]!=array[j] && array[j]!=array[k] && array[k]!=array[l]){
                            max_d=array[i];
                            flag=true;
                        }
                    }
                }
            }
        }

        if(!flag)
            cout<<"no solution"<<endl;
        else
            cout<<max_d<<endl;
    }
}