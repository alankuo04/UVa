#include<iostream>
#include<iomanip>
using namespace std;

class Node{
public:
    unsigned int value;
    unsigned int feast;
    Node():value(-1),feast(-1){}
    int sum(){
        return value+feast;
    }
};

static int city[80];
static Node dp_board[1000][1000];

void print(int C){
    cout<<"    ";
    for(int i=0;i<C;i++)
        cout<<i+1<<"     ";
    cout<<endl;
    for(int i=0;i<C;i++){
        cout<<i+1<<" ";
        for(int j=0;j<C;j++){
            if(dp_board[i][j].value!=-1 && dp_board[i][j].feast!=-1)
                cout<<setw(3)<<dp_board[i][j].value<<setw(3)<<dp_board[i][j].feast;
            else if(dp_board[i][j].feast!=-1)
                cout<<setw(3)<<0<<setw(3)<<dp_board[i][j].feast;
            else
                cout<<"  0  0";
        }
        cout<<endl;
    }
}

int main(){
    int C,R,Q, count=0;
    while(cin>>C>>R>>Q && (C!=0 || R!=0 || Q!=0)){
        if(count!=0)
            cout<<endl;
        
        for(int i=0;i<C;i++){
            cin>>city[i];
            dp_board[i][i].feast = city[i];
        }
            
        //print(C);
        for(int i=0;i<R;i++){
            int j,k,cost;
            cin>>j>>k>>cost;
            dp_board[j-1][k-1].value = cost;
            dp_board[k-1][j-1].value = cost;
            dp_board[j-1][k-1].feast = city[j-1]>city[k-1]?city[j-1]:city[k-1];
            dp_board[k-1][j-1].feast = city[j-1]>city[k-1]?city[j-1]:city[k-1];
        }
        //print(C);
        for(int c=0;c<2;c++){
            for(int k=0;k<C;k++){
                for(int i=0;i<C;i++){
                    for(int j=0;j<C;j++){
                        if(dp_board[i][k].value!=-1 && dp_board[k][j].value!=-1 && dp_board[i][k].feast!=-1 && dp_board[k][j].feast!=-1)
                            if(dp_board[i][j].sum() > dp_board[i][k].value+dp_board[k][j].value+max(dp_board[i][k].feast, dp_board[k][j].feast)){
                                dp_board[i][j].value = dp_board[i][k].value+dp_board[k][j].value;
                                dp_board[i][j].feast = max(dp_board[i][k].feast, dp_board[k][j].feast);
                            }
                    }
                }
            }
        }
        //print(C);
        cout<<"Case #"<<++count<<endl;
        for(int i=0;i<Q;i++){
            int start, end;
            cin>>start>>end;
            if(start<end){
                if(dp_board[start-1][end-1].sum()!=-2)
                    cout<<dp_board[start-1][end-1].sum()<<endl;
                else
                    cout<<-1<<endl;
            }
            else{
                if(dp_board[end-1][start-1].sum()!=-2)
                    cout<<dp_board[end-1][start-1].sum()<<endl;
                else
                    cout<<-1<<endl;
            }
        }
        //print(C);
    }
}