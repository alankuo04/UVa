#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

vector<int> four;
vector<int> six;
vector<int> eight;

int main(){
    for(int i=10;i<100;i++){
        for(int j=i;j<100;j++){
            if(((i*j-i-j)%9!=0) || (i%2!=0 && j%2!=0) || (i%10==0 && j%10==0))
                continue;
            char sum[5], a[3], b[3];
            snprintf(sum, 5, "%4d", i*j);
            snprintf(a, 3, "%2d", i);
            snprintf(b, 3, "%2d", j);
            int count[10]={};
            bool check = true;
            for(int k=0;k<4;k++){
                count[(sum[k]-'0')] += 1;
            }
            for(int k=0;k<2;k++){
                if(count[a[k]-'0']==0){
                    check=false;
                    break;
                }
                count[a[k]-'0'] -= 1;
            }
            for(int k=0;k<2;k++){
                if(count[b[k]-'0']==0){
                    check=false;
                    break;
                }
                count[b[k]-'0'] -= 1;
            }
            if(check){
                four.push_back(i*j);
            }
        }
    }
    for(int i=100;i<1000;i++){
        for(int j=i;j<1000;j++){
            if(((i*j-i-j)%9!=0) || (i%2!=0 && j%2!=0) || (i%10==0 && j%10==0))
                continue;
            char sum[7], a[4], b[4];
            snprintf(sum, 7, "%6d", i*j);
            snprintf(a, 4, "%3d", i);
            snprintf(b, 4, "%3d", j);
            int count[10]={};
            bool check = true;
            for(int k=0;k<6;k++){
                count[(sum[k]-'0')] += 1;
            }
            for(int k=0;k<3;k++){
                if(count[a[k]-'0']==0){
                    check=false;
                    break;
                }
                count[a[k]-'0'] -= 1;
            }
            for(int k=0;k<3;k++){
                if(count[b[k]-'0']==0){
                    check=false;
                    break;
                }
                count[b[k]-'0'] -= 1;
            }
            if(check){
                six.push_back(i*j);
            }
        }
    }
    for(int i=1000;i<10000;i++){
        for(int j=i;j<10000;j++){
            if(((i*j-i-j)%9!=0) || (i%2!=0 && j%2!=0) || (i%10==0 && j%10==0))
                continue;
            char sum[9], a[5], b[5];
            snprintf(sum, 9, "%8d", i*j);
            snprintf(a, 5, "%4d", i);
            snprintf(b, 5, "%4d", j);
            int count[10]={};
            bool check = true;
            for(int k=0;k<8;k++){
                count[(sum[k]-'0')] += 1;
            }
            for(int k=0;k<4;k++){
                if(count[a[k]-'0']==0){
                    check=false;
                    break;
                }
                count[a[k]-'0'] -= 1;
            }
            for(int k=0;k<4;k++){
                if(count[b[k]-'0']==0){
                    check=false;
                    break;
                }
                count[b[k]-'0'] -= 1;
            }
            if(check){
                eight.push_back(i*j);
            }
        }
    }
    sort(four.begin(), four.end());
    sort(six.begin(), six.end());
    sort(eight.begin(), eight.end());
    int input;
    while(cin>>input){
        if(input == 4){
            for(long long unsigned int i=0;i<four.size();i++){
                cout<<four[i]<<endl;
            }
        }
        else if(input == 6){
            for(long long unsigned int i=0;i<six.size();i++){
                if(six[i]!=six[i-1])
                    cout<<six[i]<<endl;
            }
        }
        else if(input == 8){
            for(long long unsigned int i=0;i<eight.size();i++){
                if(eight[i]!=eight[i-1])
                    cout<<eight[i]<<endl;
            }
        }
        cout<<endl;
    }
}