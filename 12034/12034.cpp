#include<iostream>
#include<iomanip>
#define T 1000
using namespace std;

int main(){
    static int dp_board[T][T] = {};
    dp_board[0][0]=1;
    for(int i=1;i<T;i++){
        dp_board[i][0]=1;
        for(int j=1;j<=i;j++){
            dp_board[i][j] = (dp_board[i-1][j-1] * (j+1) + dp_board[i-1][j] * (j+1)) % 10056;
        }
    }
    /*
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<setw(4)<<dp_board[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    
    int c;
    cin>>c;
    for(int i=1;i<=c;i++){
        int horse, sum = 0;
        cin>>horse;
        for(int j=0;j<horse;j++){
            sum += dp_board[horse-1][j];
            sum %= 10056;
        }
        cout<<"Case "<<i<<": "<<sum<<endl;
    }
}