#include<iostream>
using namespace std;

int main(){
    int i, a, b, c;
    cin>>a;
    for(i=0;i<a;i++){
        int max = 0;
        cin>>b;
        for(int j=0;j<b;j++){
            cin>>c;
            if(c>max)
                max = c;
        }
        cout<<"Case "<<i+1<<": "<<max<<endl;
    }
}