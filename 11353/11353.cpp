#include<iostream>
#include<algorithm>
using namespace std;

class Node{
public:
    Node():num(0),prime_count(1){}
    Node(int num, int prime):num(num),prime_count(prime){}
    int num;
    int prime_count;
};

bool compare(Node a, Node b){
    if(a.prime_count==b.prime_count)
        return a.num < b.num;
    else
        return a.prime_count < b.prime_count;
}

static Node list[2000001];

int main(){
    for(int i=1;i<2000001;i++){
        list[i].num = i;
    }
    for(int i=2;i<2000001;i++){
        for(int j=i;j<2000001;j+=i){
            if(list[j].num%i==0 && list[j].prime_count==1){
                list[j].prime_count=(list[j].num/i);
            }
        }
    }
    for(int i=1;i<2000001;i++){
        if(list[i].prime_count!=1)
            list[i].prime_count = list[list[i].prime_count].prime_count+1;
    }
    sort(list, list+2000001, compare);

    int in, count = 0;
    while (cin>>in && in!=0){
        cout<<"Case "<<++count<<": ";
        cout<<list[in].num<<endl;
    }
}