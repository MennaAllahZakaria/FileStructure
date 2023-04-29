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


void view_one_student(){
fstream f;
student s;

f.open(pass_student,ios::in);

    cout<<"Please enter name "<<nl;
   char name[20];
    cin >> name;
    while ( !f.eof()){
 f.read((char *)&s,sizeof (s));

 if ( strcmp(s.name,name)==0) {
    cout<<"ID             -> "<<s.id<<nl;
    cout<<"Name           -> "<<s.name<<nl;
    cout<<"Age            -> "<<s.age<<nl;
    return void( f.close());
 }
    }

    cout<<"Sorry this name is not found"<<nl;
    f.close();

}


void view_all_students(){
fstream f,o;
student s;

f.open(pass_student,ios::in);
   
   int i=0;
    while (  f.read((char *)&s,sizeof (s)) ){
    
     i++;
    cout<<"STUDENT       "<<i<<nl<<nl;
    cout<<"ID             -> "<<s.id<<nl;
    cout<<"Name        -> "<<s.name<<nl;
   
    cout<<"-------------------------------------------------------"<<nl;
    }

     f.close();
 
}






int main(){
view_one_student();
view_all_students();
  return 0;
}

