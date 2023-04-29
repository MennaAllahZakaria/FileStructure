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

void delete_student(){
fstream f;

f.open(path_student,ios::in|ios::out);
if ( f.is_open()){
    student s;
char name[10];
    bool found=0;
    cout<<"Enter the name you want to delete "<<nl;
    cin>>name;
while (  f.read((char *)&s,sizeof (s))){
 if ( strcmp(s.name,name)==0) {
    found=1;
    int n=f.tellg(),m=sizeof(s);
    f.seekp(n-m,ios::beg);
    f.write((char *)&s,sizeof(s));
    break;
 }
}
if(!found)cout<<"name is not exist"<<nl;

}

else {

cout<<"sorry the file is not found";
}

f.close();

}


int main(){
 delete_student()
  return 0;
}
