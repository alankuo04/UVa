#include<iostream>
#include<fstream>
#include<unordered_map>
using namespace std;

int main(){
    string s;
    unordered_map<string, string> star_list;
    fstream file;
    file.open("./star.txt", ios::in|ios::binary);
    char c = file.get();
    star_list["100"] = "1";
    while(file>>s){
        /*cout<<s.substr(0, s.find(","))<<endl;
        cout<<s.substr(s.find(",")+1, s.size())<<endl;*/
        star_list[s.substr(0, s.find(","))] = s.substr(s.find(",")+1, s.size());
    }
    file.close();
    file.open("./README.md",ios::out);
    file<<"# UVa題目練習\n高等程式設計課程練習紀錄，以上題目皆為OnlineJudge上AC通過\n|難度|題號|完成日期|\n|---|----|--------|\n";
    while(cin>>s){
        if(star_list.find(s)==star_list.end())
            cout<<"Unknown problem number."<<endl;
        else{
            string stars[6] = {"☆☆☆☆☆","★☆☆☆☆","★★☆☆☆","★★★☆☆","★★★★☆","★★★★"};
            file<<"|"<<stars[stoi(star_list[s])]<<"|["<<s<<"](https://github.com/alankuo04/UVa/tree/main/"<<s<<")|"<<endl;
        }
    }
    file.close();
    return 0;
}

// ls -n [0-9]*