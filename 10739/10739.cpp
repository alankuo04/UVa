#include<iostream>
#define MAX 10000;
using namespace std;

int main(){
    int a;
    cin>>a;
    static int dp_board[1001][1001] = {};
    for(int i=0;i<a;i++){
        string temp;
        cin>>temp;
        for(int i=0;i<=temp.size();i++){
            for(int j=0;j<=temp.size();j++){
                dp_board[i][j]=MAX;
                if(i==j){
                    dp_board[i][j]=0;
                }
            }
        }

        for(int i=temp.size();i>=1;i--){
            for(int j=i;j<=temp.size();j++){
                if(i!=j){
                    if(temp[i-1]==temp[j-1]){
                        if(dp_board[i+1][j-1] == 10000)
                            dp_board[i][j] = 0;
                        else
                            dp_board[i][j] = dp_board[i+1][j-1];
                    }
                    else{
                        dp_board[i][j] = min(dp_board[i+1][j], min(dp_board[i][j-1], dp_board[i+1][j-1]))+1;
                    }
                }
            }
        }
        /*cout<<"  ";
        for(int i=0;i<temp.size();i++)
            cout<<temp[i]<<" ";
        cout<<endl;
        for(int i=1;i<=temp.size();i++){
            cout<<temp[i-1]<<" ";
            for(int j=1;j<=temp.size();j++){
                if(dp_board[i][j]<10000)
                    cout<<dp_board[i][j]<<" ";
                else{
                    cout<<"- ";
                }
            }
            cout<<endl;
        }*/


        cout<<"Case "<<i+1<<": "<<dp_board[1][temp.size()]<<endl;
    }
}