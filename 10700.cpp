#include<iostream>
#include<stack>
using namespace std;

int main(){
    int N, num;
    char temp;
    cin>>N;
    for(int i=0;i<N;i++){
        stack<long long> max, min;
        cin>>num;
        max.push(num);
        min.push(num);
        while(true){
            cin.get(temp);
            if(temp=='\n')
                break;
            cin>>num;
            if(temp=='+'){
                long long t = max.top();
                max.pop();
                max.push(num+t);
                min.push(num);
            }
            else if(temp=='*'){
                long long t = min.top();
                min.pop();
                min.push(num*t);
                max.push(num);
            }
        }
        long long max_sum = 1, min_sum = 0;
        for(;!max.empty();){
            max_sum *= max.top();
            max.pop();
        }
        for(;!min.empty();){
            min_sum += min.top();
            min.pop();
        }
        cout<<"The maximum and minimum are "<<max_sum<<" and "<<min_sum<<"."<<endl;
    }
}