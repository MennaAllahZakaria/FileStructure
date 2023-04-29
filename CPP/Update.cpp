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
string path_student="D:\\data.txt";


void update_student(){
fstream f;
student s;
f.open(path_student,ios::in|ios::out);

 char name[10];
cout<<"Please enter name to update"<<nl;
cin >> name;
if ( f.is_open()){
while ( f.read((char *)&s,sizeof(s))){

if ( strcmp(name,s.name)==0){
    cout<<"Please enter the new age "<<nl;
    cin >> s.age;
   f.write((char *)&s,sizeof(s));
    f.close();
    return ;

}

}

}else {
    cout<<"This file is not found "<<nl;
}



}



int main(){
update_student();
  return 0;
}
