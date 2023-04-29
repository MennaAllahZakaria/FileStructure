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

f.open( path_student,ios::in);
if ( f.is_open()){
    student s;
    string name;
    cout<<"Enter the name you want to search "<<nl;
    cin>>name;
while ( !f.eof()){
 f.read((char *)&s,sizeof (s));

 if ( s.name==name) return void ( cout<<"Found"<<nl);
}
cout<<"name is not exist"<<nl;

}

else {

cout<<"sorry the file is not found";
}

f.close();


}


int main(){
update_student();
  return 0;
}
