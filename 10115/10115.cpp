#include<iostream>
#include<string>
using namespace std;

int main(){
    int rules;
    while(cin>>rules && rules!=0){
        cin.get();
        string find[rules], replace[rules];
        for(int i=0;i<rules;i++){
            getline(cin, find[i]);
            getline(cin, replace[i]);
        }
        string origin;
        getline(cin, origin);
        for(int i=0;i<rules;i++){
            while(int(origin.find(find[i]))!=-1)
                origin.replace(origin.find(find[i]), find[i].length(), replace[i]);
        }
        cout<<origin<<endl;
    }
}