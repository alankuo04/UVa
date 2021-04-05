#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    int a;
    double PI = acos(-1);
    cin>>a;
    for(int i=0;i<a;i++){
        double L, W, theta;
        cin>>L>>W>>theta;
        theta = (theta/180.0)*PI;
        double A = L/cos(theta);
        double temp_W = tan(theta)*L;
        int count = int(temp_W/W);
        temp_W =  temp_W-W*count;
        //cout<<temp_W<<endl;
        double B;
        if(count%2==0)
            B = sqrt(pow(temp_W,2)+pow(L,2));
        else
            B = sqrt(pow(W-temp_W,2)+pow(L,2));
        //cout<<A<<" "<<B<<" ";
        printf("%.3f\n", A/B);
    }
}