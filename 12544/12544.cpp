#include<iostream>
#include<queue>
#include<unordered_map>
#include<ctime>
#define N 501
#define MAX_VAL 100000000
using namespace std;


vector<int> path_list[N];

int main(){
    clock_t tStart = clock();
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        int n,m;
        cin>>n>>m;
        for(int j=0;j<N;j++)
            path_list[j].clear();
        
        for(int j=0;j<m;j++){
            int a,b;
            cin>>a>>b;
            path_list[a].push_back(b);
            path_list[b].push_back(a);
        }

        int min_circle = MAX_VAL;
        for(int j=0;j<n;j++){
            // initialize
            vector<int> alreadyGo(n, -1);
            vector<int> parent_list(n,-1);
            queue<int> bfs_queue;

            // startpoint
            alreadyGo[j] = 0;
            bfs_queue.push(j);
            while(bfs_queue.size()!=0){
                int now = bfs_queue.front();
                bfs_queue.pop();
                //cout<<"now:"<<now<<endl;
                for(int k=0;k<path_list[now].size();k++){
                    int find_point = path_list[now][k];
                    if(alreadyGo[find_point] == -1){
                        parent_list[find_point] = now;
                        alreadyGo[find_point] = alreadyGo[now]+1;
                        bfs_queue.push(find_point);
                        //cout<<path_list[now][k]<<" "<<alreadyGo[now]+1<<endl;
                    }
                    else{
                        if(find_point!=j && parent_list[find_point]!=now && parent_list[now]!=find_point){
                            //cout<<"already:";
                            //cout<<now<<"->"<<path_list[now][k]<<endl;
                            int route = alreadyGo[now]+alreadyGo[find_point]+1;
                            if(route < min_circle){
                                min_circle = route;
                            }
                        }
                    }
                }
            }
            //cout<<endl;
        }
        

        cout<<"Case "<<i+1<<": ";
        if(min_circle == MAX_VAL)
            cout<<"impossible"<<endl;
        else
            cout<<min_circle<<endl;
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    
}