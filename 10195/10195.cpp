#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    double a,b,c;
    while(cin>>a>>b>>c){
        double s = (a+b+c)/2;
        double tri = sqrt(s*(s-a)*(s-b)*(s-c));
        cout<<"The radius of the round table is: ";
        if(a==0 && b==0 && c==0)
            cout<<"0.000"<<endl;
        else
            cout<<fixed<<setprecision(3)<<tri/s<<endl;
    }
}