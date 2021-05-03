#include<iostream>
#include<vector>
#define N 2000001
using namespace std;

static int phi[N]={};
static int depth[N]={};

int main(){
    for(int i=2;i<N;i++){
        phi[i] = i;
    }
    for(int i=2;i<N;i++){
        if(phi[i]==i){
            for(int j=i;j<N;j+=i){
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
    for(int i=2;i<N;i++){
        int temp=i;
        int count=0;
        while(temp!=0){
            temp=phi[temp];
            count++;
        }
        depth[i]=count-1;
    }
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int m,n;
        cin>>m>>n;
        int sum=0;
        for(int j=m;j<=n;j++){
            sum+=depth[j];
        }
        cout<<sum<<endl;
    }
}