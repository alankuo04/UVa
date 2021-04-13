#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>> board, int n){
    for(int i=0;i<n;i++){
        cout<<i+1<<": ";
        for(int j=0;j<board[i].size();j++)
            cout<<board[i][j]+1<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void get_route(vector<vector<int>> board, int p1, int p2, int n){
    vector<int> route;
    bool already[n] = {};
    route.push_back(p1-1);
    already[p1-1]=true;
    while(route[route.size()-1]!=p2-1){
        for(int i=0;i<board[route.back()].size();i++){
            if(!already[board[route.back()][i]]){
                //cout<<"now:"<<board[route.back()][i]<<endl;
                already[board[route.back()][i]]=true;
                route.push_back(board[route.back()][i]);
                break;
            }
            else if(i==board[route.back()].size()-1){
                int no_move = route.back();
                route.pop_back();
                for(int j=0;j<board[route.back()].size();j++){
                    if(board[route.back()][j]==no_move){
                        i = j;
                        break;
                    }
                }
            }
        }
    }
    /*for(int i=0;i<route.size();i++){
        cout<<route[i]<<" ";
    }
    cout<<endl;*/
    if(route.size()%2==0){
        int a = route[route.size()/2-1]+1;
        int b = route[route.size()/2]+1;
        cout<<"The fleas jump forever between "<<min(a,b)<<" and "<<max(a,b)<<"."<<endl;
    }
    else{
        cout<<"The fleas meet at "<<route[route.size()/2]+1<<"."<<endl;
    }
}

int main(){
    int n,l;
    while(cin>>n && n!=0){
        vector<vector<int>> link_board(n);
        int p1, p2;
        for(int i=0;i<n-1;i++){
            cin>>p1>>p2;
            link_board[p1-1].push_back(p2-1);
            link_board[p2-1].push_back(p1-1);
        }
        //print(link_board, n);
        cin>>l;
        for(int i=0;i<l;i++){
            cin>>p1>>p2;
            get_route(link_board, p1, p2, n);
        }
    }
}