 //         اللهم لا سهل الا ما جعلته سهلا و انت تجعل الصعب ان شئت سهل        
 #include <bits/stdc++.h> 
  #define ll                            long long 
  #define nl                            "\n"

 using namespace std;

class student{
    public:
    int id,age;
    char name[10];
};
string path="D:\\data.txt";
void add_student(){
fstream f;
student s;

f.open(path,ios::out);
char ch ='y';
while ( ch!='n'){
cout<<"Enter id"<<nl;
cin >>s.id;
cout<<"Enter name"<<nl;
cin>>s.name;
cout<<"Enter age of the student"<<nl;
cin >> s.age;
 f.write((char *)&s,sizeof(s));

cout<<"Do you want to conuinue .. y/n";
cin >>ch;

}

f.close();

}

int main(){
add_student();
  return 0;
}








