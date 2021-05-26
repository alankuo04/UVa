#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    static long long dp_board[1001][1001];    
    while(cin>>n>>m && (n!=0 || m!=0)){
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                dp_board[i][j]=0;
            }
        }
        int input[n];
        for(int i=0;i<n;i++){
            dp_board[i][0]=1;
            cin>>input[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j<=i){
                    dp_board[i][j] = ((dp_board[i-1][j-1]*input[i-1])%m+(dp_board[i-1][j])%m)%m;
                }
            }
        }
        
        long long max_group=0;
        for(int i=1;i<=n;i++){
            //cout<<dp_board[n][i]<<" ";
            if(dp_board[n][i]>max_group){
                max_group = dp_board[n][i];
            }
        }
        cout<<max_group<<endl;
    }
}