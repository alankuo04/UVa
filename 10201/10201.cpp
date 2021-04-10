#include<iostream>
#include<sstream>
#include<vector>
#define MAX_VAL 200000000
using namespace std;

int main(){
    int a;
    cin>>a;
    for(int c=0;c<a;c++){
        int road, station, price;
        string t;
        vector<vector<int>> dp_board(101, vector<int>(201, MAX_VAL));
        vector<pair<int, int>> station_list;
        cin>>road;
        //cout<<c<<" "<<road<<endl;
        cin.get();
        while(1){
            getline(cin, t);
            //cout<<"T:"<<t<<endl;
            if(int(t[0])==0)
                break;
            stringstream ss(t);
            ss>>station>>price;
            //cout<<station<<" "<<price<<endl;
            if(station<=road)
                station_list.push_back({station, price});
        }

        if(station_list.size()==0)
            cout<<"Impossible"<<endl;
        else if(100-station_list[0].first < 0)
            cout<<"Impossible"<<endl;
        else{
            dp_board[0][100-station_list[0].first] = 0;
            for(int i=0;i<station_list.size()-1;i++){
                int distance = station_list[i+1].first-station_list[i].first;
                if(distance > 200)
                    break;
                for(int j=0;j<201;j++){
                    for(int k=0;(k+j)<201;k++){
                        if(k+j >= distance)
                            dp_board[i+1][j+k-distance] = min(dp_board[i+1][j+k-distance], dp_board[i][j]+station_list[i].second*k);
                    }
                }
            }
            int minimum = MAX_VAL;
            for(int j=0;j<201;j++){
                //cout<<dp_board[station_list.size()-1][j]<<" ";
                int last = road-station_list[station_list.size()-1].first+100-j;
                if(last<0)
                    last = 0;
                int cost = dp_board[station_list.size()-1][j]+station_list[station_list.size()-1].second*last;
                if(cost<minimum && road-station_list[station_list.size()-1].first <= 100){
                    //cout<<dp_board[station_list.size()-1][j]<<" "<<road-station_list[station_list.size()-1].first<<endl;
                    minimum = cost;
                }
            }
            if(minimum == MAX_VAL)
                cout<<"Impossible"<<endl;
            else
                cout<<minimum<<endl;
        }
        if(c!=a-1)
            cout<<endl;
    }
}