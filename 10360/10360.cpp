#include<iostream>
using namespace std;

static int array[1025][1025];

int main(){
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        for(int size1=0;size1<1025;size1++)
            for(int size2=0;size2<1025;size2++)
                array[size1][size2]=0;
        int d, group;
        cin>>d>>group;
        for(int j=0;j<group;j++){
            int x,y,rat;
            cin>>x>>y>>rat;
            for(int l=x-d;l<=x+d;l++){
                for(int r=y-d;r<=y+d;r++){
                    if(l>=0 && l<1025 && r>=0 && r<1025){
                        array[l][r]+=rat;
                        //cout<<rat<<endl;
                    }
                }
            }
        }
        int max_x, max_y, max=0;
            for(int l=0;l<1025;l++){
                for(int r=0;r<1025;r++){
                    if(array[l][r]>max){
                        max=array[l][r];
                        max_x=l;
                        max_y=r;
                    }
                }
            }
            cout<<max_x<<" "<<max_y<<" "<<max<<endl;
    }
}