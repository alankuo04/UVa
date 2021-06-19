#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
    int start;
    int end;
};

bool compare(struct Node a, struct Node b){
    if(a.end == b.end)
        return a.start > b.start;
    return a.end < b.end;
}

int main(){
    int c;
    cin>>c;
    for(int i=0;i<c;i++){
        if(i!=0)
            cout<<endl;
        int ad, person;
        vector<struct Node> l;
        bool flag[20002]={};

        cin>>ad>>person;
        for(int j=0;j<person;j++){
            struct Node temp;
            int a,b;
            cin>>a>>b;
            if(a>b){
                temp.start = b+10000;
                temp.end = a+10000;
            }
            else{
                temp.start = a+10000;
                temp.end = b+10000;
            }
            l.push_back(temp);
        }
        sort(l.begin(), l.end(), compare);

        /*for(int j=0;j<person;j++){
            cout<<l[j].start<<" "<<l[j].end<<endl;
        }*/

        for(int j=0;j<person;j++){
            int already = 0;
            for(int k=l[j].start;k<=l[j].end;k++){
                if(flag[k])
                    already++;
            }
            //cout<<already<<endl;
            for(int k=l[j].end;k>=l[j].start;k--){
                if(already>=ad)
                    break;
                else if(!flag[k]){
                    //cout<<k<<endl;
                    flag[k]=true;
                    already++;
                }
            }
        }
        vector<int> p;
        for(int j=0;j<20002;j++){
            if(flag[j]){
                p.push_back(j-10000);
            }
        }
        
        cout<<p.size()<<endl;
        for(int j=0;j<p.size();j++){
            cout<<p[j]<<endl;
        }
    }
}