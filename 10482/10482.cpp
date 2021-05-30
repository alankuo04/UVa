#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int candyNum, totalWeight=0;
        cin>>candyNum;
        int candy[candyNum];
        for(int j=0;j<candyNum;j++){
            cin>>candy[j];
            totalWeight += candy[j];
        }
        sort(candy, candy+candyNum);

        vector<vector<int>> dp_board(641, vector<int>(641, -1));

        dp_board[0][0] = totalWeight;
        for(int j=0;j<candyNum;j++){
            for(int k=totalWeight;k>=0;k--){
                for(int l=totalWeight;l>=0;l--){
                    if(dp_board[k][l]!=-1 && totalWeight-k-l>=0){
                        dp_board[candy[j]+k][l]=totalWeight-(candy[j]+k)-l;
                        dp_board[k][candy[j]+l]=totalWeight-k-(candy[j]+l);
                    }
                }
            }
        }
        int min_badness=100000;
        for(int j=0;j<=totalWeight;j++){
            for(int k=0;k<=totalWeight;k++){
                //cout<<dp_board[j][k]<<" ";
                if(dp_board[j][k]!=-1){
                    int badness = max(dp_board[j][k], max(j, k)) - min(dp_board[j][k], min(j, k));
                    if(badness < min_badness)
                        min_badness = badness;
                }
            }
            //cout<<endl;
        }
        cout<<"Case "<<i+1<<": "<<min_badness<<endl;
    }
}