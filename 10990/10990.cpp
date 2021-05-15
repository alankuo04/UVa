#include<iostream>
#include<vector>
#define N 2000001
using namespace std;

static int phi[N]={};
static int depth[N]={};

int main(){
    vector<bool> prime(N, true);
	for(int i=2;i<N;i++){
        if(prime[i]){
			for(int j=i+i;j<N;j+=i){
				prime[j]=false;
			}
		}
    }
    vector<int> prime_number;
    for(int i=2;(i*i)<N;i++){
        if(prime[i])
            prime_number.push_back(i);
    }

    for(int i=2;i<N;i++){
		int temp = i;
		int answer = i;
		for(int j=0;j<prime_number.size();j++){
            if(temp%prime_number[j]==0){
                answer = answer/prime_number[j]*(prime_number[j]-1);
                while(temp%prime_number[j]==0)
                    temp/=prime_number[j];
            }
        }
        if(temp>1){
            answer = answer/temp*(temp-1);
        }
        phi[i] = answer;
    }
    depth[1]=0;
    for(int i=2;i<N;i++){
        depth[i]=depth[phi[i]]+1;
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