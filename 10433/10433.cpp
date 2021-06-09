#include<iostream>
#include<string>
using namespace std;

int main(){
    string a;
    while(cin>>a){
        bool check = true;
        if(a[a.size()-1]=='5' || a[a.size()-1]=='6'){
            int size = int(a.size());
            int b[2001] = {}, c[4001] = {};
            for(int i=0;i<size;i++){
                b[i] = a[i]-'0';
            }
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    //cout<<b[i]<<" "<<b[j]<<endl;;
                    c[j+i] += b[i]*b[j];
                }
            }
            for(int i=size*2;i>=0;i--){
                if(c[i]>=10){
                    c[i-1] += c[i]/10;
                    c[i] = c[i]%10;
                }
            }
            for(int i=size*2-1-size,j=0;j<size;i++,j++){
                //cout<<b[j]<<" "<<c[i]<<endl;
                if(b[j] != c[i]){
                    check = false;
                    break;
                }
            }
            if(check)
                cout<<"Automorphic number of "<<size<<"-digit."<<endl;
            else
                cout<<"Not an Automorphic number."<<endl;
        }
        else
            cout<<"Not an Automorphic number."<<endl;
    }
}