#include<iostream>
#include<string>
using namespace std;

int main(){
    int N, n, num;
    cin>>N;
    for(int i=0;i<N;i++){
        string M;
        cin>>M;
        int count = 0;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>num;
            int temp = int(M[0])-int('0');
            if(int(M.length())==1 && temp%num==0){
                count++;
            }
            else{
                for(int k=1;k<int(M.length());k++){
                    temp = (temp%num)*10+int(M[k])-int('0');

                    if(temp%num==0 && k==int(M.length())-1){
                        count++;
                        break;
                    }
                    //cout<<temp<<endl;
                }
            }
        }
        //cout<<count<<" "<<n<<endl;
        if(M=="0")
            cout<<M<<" - "<<"Wonderful."<<endl;
        else
            cout<<M<<" - "<<(count!=n?"Simple.":"Wonderful.")<<endl;
    }
}