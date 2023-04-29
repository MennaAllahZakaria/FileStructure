 //         اللهم لا سهل الا ما جعلته سهلا و انت تجعل الصعب ان شئت سهل        
 #include <bits/stdc++.h> 
 
 #define ll                            long long 
 
 #define nl                            "\n"
 
 using namespace std;
 

class teacher{
    public:

  char name[20],password [20],phone[11];
int age,department;
};



class student{
    public:
        char name[20],password [20],phone[11];


int age,year,department;
bool subject[7];
};

vector<string> grade={"General","Bioinformatics","Software Engineering" ,"Computer science","Information System"};

string pass_student="D:\\student.txt";
string pass_teacher="D:\\teacher.txt";


//=============================================functions of student==================================================//


void add_student(){
    fstream f;
student s;

f.open(pass_student,ios::app);


    cout<<"please enter student name"<<nl;
  cin >> s.name;
  cout<<"please enter student password"<<nl;
  cin >> s.password;
   cout<<"please enter student phone"<<nl;
  cin >> s.phone;

   cout<<"please enter student age"<<nl;
  cin >> s.age;

   cout<<"please enter student year"<<nl;
  cin >>s.year;
  
  
  int i=0;
 do{
  cout<<"------------GRADES------------"<<nl;

  cout<<"1 - General"<<nl;
  cout<<"2 - Bioinformatics"<<nl;
  cout<<"3 - Software Engineering" <<nl;
  cout<<"4 - Computer science"<<nl;
  cout<<"5 - Information System"<<nl;
  cout<<"please enter the choice of Departments"<<nl;

cin >> i;
if ( i<1 || i>5) cout<<"Your choice is not avilable please try again"<<nl ;


 }while ( i<1 || i>5);

s.department=i;

 

f.write((char *)&s,sizeof (s));

f.close();
}


void search_student(){
fstream f;
student s;

f.open(pass_student,ios::in);
  cout<<"Please enter name to search"<<nl;
 char name[20];
 
  cin >> name;
int i=1;
while ( !f.eof()){
 f.read((char *)&s,sizeof (s));

 if ( strcmp(name,s.name)==0) return void ( cout<<"Found at line  "<<i<<nl);
 i++;
}
cout<<"Sorry the student is not found"<<nl;
f.close();
}

bool valid_student(){
    fstream f;
    student s;
    char name [20],pass[20];
    f.open(pass_student,ios::in);
cout<<"Enter the name "<<nl;
cin >> name;
cout<<"Enter the password "<<nl;
cin >>pass;
while (  f.read((char *)&s,sizeof (s))){
if ( strcmp(name,s.name)==0 && strcmp(pass,s.password)==0) return 1;
}

return 0;

}

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
    cout<<"Name           -> "<<s.name<<nl;
   // cout<<"pass           ->"<<s.password<<nl;
    cout<<"Age            -> "<<s.age<<nl;
    cout<<"Phone          -> "<<s.phone<<nl;
    cout<<"year           -> "<<s.year<<nl;
    cout<<"Department     -> "<<grade[s.department-1]<<nl;
   
    return void( f.close());
 }
    }

    cout<<"Sorry this name is not found"<<nl;
   return void( f.close());

}


void view_all_students(){
fstream f,o;
student s;

f.open(pass_student,ios::in);
   
   int i=0;
    while (  f.read((char *)&s,sizeof (s)) ){
    
     i++;
    cout<<"STUDENT       "<<i<<nl<<nl;
    cout<<"Name        -> "<<s.name<<nl;
    //cout<<"pass        -> "<<s.password<<nl;
    cout<<"Age         -> "<<s.age<<nl;
    cout<<"Phone       -> "<<s.phone<<nl;
    cout<<"Grade       -> "<<s.year<<nl;
    cout<<"Department  -> "<<grade[s.department-1]<<nl;
    cout<<"-------------------------------------------------------"<<nl;

   
 
    }

     return void( f.close());
 
}



void update_student_info(){
fstream f;
student s;
int idx;
f.open(pass_student,ios::in| ios::out);

    cout<<"Please enter name ";
   char name[20],password[20];
    cin >> name;
    cout<<"please enter the password";
    cin>>password;
   


while (  f.read((char *)&s,sizeof (s))){

if (strcmp(name,s.name)==0&& strcmp(password,s.password)==0){
     cout<<"1 - Update the name"<<nl;
    cout<<"2 - Update the age"<<nl;
    cout<<"3 - Update the phone"<<nl;
    cout<<"4 - Update the grade"<<nl;
    cout<<"5 - Update the department"<<nl;

    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
       cout<<"Please enter the new name"<<nl;
       cin >> s.name;
  
        break;

    case 2:
       cout<<"Please enter the new age"<<nl;
       cin >> s.age;
   
        break;
    
        case 3:
       cout<<"Please enter the new phone number"<<nl;
       cin >> s.phone;
    
        break;
    
        case 4:
       cout<<"Please enter the new grade"<<nl;
       cin >> s.year;
      
        break;
    
        case 5:
       cout<<"Please enter the new department"<<nl;
      
  cout<<"------------GRADES------------"<<nl;

  cout<<"1 - General"<<nl;
  cout<<"2 - Bioinformatics"<<nl;
  cout<<"3 - Software Engineering" <<nl;
  cout<<"4 - Computer science"<<nl;
  cout<<"5 - Information System"<<nl;
  cout<<"please enter the choice of Departments"<<nl;

      cin >> idx;

              s.department=idx;
              
        break;
    
    default:
       cout<<"your choice is not avilable"<<nl;
        break;
    }
    // to overwrite the data in the student
          int poss = f.tellg(),size=sizeof(s);
        f.seekp(poss-size,ios::beg);
        f.write((char *)&s,sizeof (s));
         f.seekg(poss-size,ios::beg);
        f.read((char *)&s,sizeof (s));
    cout<<"Name        -> "<<s.name<<nl;
    cout<<"Age         -> "<<s.age<<nl;
    cout<<"Phone       -> "<<s.phone<<nl;
    cout<<"Grade       -> "<<s.year<<nl;
    cout<<"Department  -> "<<grade[s.department-1]<<nl;
    f.close();
    return;
}
 
}
cout<<"Sorry the student is not found"<<nl;
f.close();
}


void update_student_password(){
fstream f;
student s;
int idx;
f.open(pass_student,ios::in| ios::out);

    cout<<"Please enter name "<<nl;
   char name[20],password[20];
    cin >> name;
    cout<<"please enter the password"<<nl;
    cin>>password;
    while (  f.read((char *)&s,sizeof (s))){

if (strcmp(name,s.name)==0&& strcmp(password,s.password)==0){
    cout<<"please enter the new password"<<nl;
    cin >> s.password;
       int poss = f.tellg(),size=sizeof(s);
        f.seekp(poss-size,ios::beg);
        f.write((char *)&s,sizeof (s));
         f.seekg(poss-size,ios::beg);
        f.read((char *)&s,sizeof (s));
    cout<<"Name             -> "<<s.name<<nl;
    cout<<"password         -> "<<s.password<<nl;
 
    f.close();
    return;
    
}

    }
    cout<<"Sorry the student is not found"<<nl;
f.close();
}

void copy_data(string pass1,string pass2){

fstream f,o;
student s;
f.open(pass1,ios::in);
o.open(pass2,ios::out);
while (  f.read((char *)&s,sizeof (s))){
  
     o.write((char *)&s,sizeof (s));

}
f.clear();
f.close();
o.close();

}

void delete_student(){

fstream in,out;
student s;
bool is=0;
in.open(pass_student,ios::in);
out.open("temp.txt",ios::out);

char name[20],pass[20];
cout<<"Please enter the name to delete this student"<<nl;
cin >> name;
cout<<"Please enter the password to this student"<<nl;
cin >> pass;



while (  in.read((char *)&s,sizeof (s))){
  if ((strcmp(name,s.name)==0&& strcmp(pass,s.password)==0)){
    is=1;
    continue;
  }
  out.write((char *)&s,sizeof (s));

}

cout<<(is?"DELETED  ":"THIS TEACHER IS NOT VALID")<<nl;

in.close();
out.close();
if (is)copy_data("temp.txt",pass_student);


}

void add_values(){
    fstream f;
    f.open(pass_student,ios::in|ios::out);
char name[20];
student s;
cout<<"please enter the student name"<<nl;

cin >> name;

while (  f.read((char *)&s,sizeof (s))){
    if ( strcmp(s.name,name)==0){

       for ( int i=0;i<7;i++){
int j;
cout<<"if the student pass the subject "<<i+1<<" enter 1 otherwise enter 0"<<nl;
cin>>j;
s.subject[i]=(j==1?true:false);


       }
  int poss = f.tellg(),size=sizeof(s);
        f.seekp(poss-size,ios::beg);
        f.write((char *)&s,sizeof (s));
         f.seekg(poss-size,ios::beg);
        return;
    }
}




}
void read_values(){


   fstream f;
    f.open(pass_student,ios::in);
char name[20];
student s;
cout<<"please enter the student name"<<nl;

cin >> name;

while (  f.read((char *)&s,sizeof (s))){
    if ( strcmp(s.name,name)==0){

       for ( int i=0;i<7;i++){
          cout<< " subject    "<<i+1<<" =  "<<(s.subject[i]?"  PASS":"  FAIL")<<nl;   
       }


    }
    }

}


void student_do(){

char c='y';
while (c=='y')
{
    cout<<"1- Add new student"<<nl;
    cout<<"2- update student password"<<nl;
    cout<<"3- search student"<<nl;
    cout<<"4- view one student"<<nl;
    cout<<"5- view values of student"<<nl<<nl;

    cout<<"Please enter your choice"<<nl;
    int ch;
    cin >> ch;

  switch (ch)
  {
    case 1:
    add_student();
    break;
    case 2:
    update_student_password();
    break;
    case 3:
    search_student();
    break;
    case 4:
    view_one_student();
    break;
    case 5:
    read_values();
    break;

    default:
    cout<<"Your choise is not valid"<<nl;
    break;
  }


cout<<"If you want to continue y/n"<<nl;
cin>>c;

}





}


//============================================functions of teachar=============================================//



void add_teacher(){
    fstream f;
teacher t;

f.open(pass_teacher,ios::app);


    cout<<"please enter teacher name"<<nl;
  cin >> t.name;
  cout<<"please enter teacher password"<<nl;
  cin >> t.password;
   cout<<"please enter teacher phone"<<nl;
  cin >> t.phone;

   cout<<"please enter teacher age"<<nl;
  cin >> t.age;

   
  
  int i=0;
 do{
  cout<<"------------DEPATRMENTS------------"<<nl;

  cout<<"1 - General"<<nl;
  cout<<"2 - Bioinformatics"<<nl;
  cout<<"3 - Software Engineering" <<nl;
  cout<<"4 - Computer science"<<nl;
  cout<<"5 - Information System"<<nl;
  cout<<"please enter the choice of Departments"<<nl;

cin >> i;
if ( i<1 || i>5) cout<<"Your choice is not avilable please try again"<<nl ;

 }while ( i<1 || i>5);

t.department=i;

 

f.write((char *)&t,sizeof (t));

f.close();
}


void search_teacher(){
fstream f;
teacher t;

f.open(pass_teacher,ios::in);
  cout<<"Please enter name to search"<<nl;
 char name[20];
 
  cin >> name;
int i=1;
while ( !f.eof()){
 f.read((char *)&t,sizeof (t));

 if ( strcmp(name,t.name)==0) return void ( cout<<"Found at line  "<<i<<nl);
 i++;
}
cout<<"Sorry the teacher is not found"<<nl;
f.close();
}

bool valid_teacher(){
    fstream f;
    teacher t;;
    char name [20],pass[20];
    f.open(pass_teacher,ios::in);
cout<<"Enter the name "<<nl;
cin >> name;
cout<<"Enter the password "<<nl;
cin >>pass;
while (  f.read((char *)&t,sizeof (t))){
if ( strcmp(name,t.name)==0 && strcmp(pass,t.password)==0) return 1;
}

return 0;

}


void view_one_teacher(){
fstream f;
teacher t;

f.open(pass_teacher,ios::in);

    cout<<"Please enter name "<<nl;
   char name[20];
    cin >> name;
    while ( !f.eof()){
 f.read((char *)&t,sizeof (t));

 if ( strcmp(t.name,name)==0) {
    cout<<"Name           -> "<<t.name<<nl;
   // cout<<"pass           ->"<<s.password<<nl;
    cout<<"Age            -> "<<t.age<<nl;
    cout<<"Phone          -> "<<t.phone<<nl;
    cout<<"Department     -> "<<grade[t.department-1]<<nl;
   
    return void( f.close());
 }
    }

    cout<<"Sorry this name is not found"<<nl;
   return void( f.close());

}






void view_all_teachers(){
fstream f;
teacher t;

f.open(pass_teacher,ios::in);
   
   int i=0;
    while (  f.read((char *)&t,sizeof (t)) ){
    
     i++;
    cout<<"Teacher       "<<i<<nl<<nl;
    cout<<"Name        -> "<<t.name<<nl;
    cout<<"Age         -> "<<t.age<<nl;
    cout<<"Phone       -> "<<t.phone<<nl;
  
    cout<<"Department  -> "<<grade[t.department-1]<<nl;
   
   cout<<"-------------------------------------------------------"<<nl;
 
    }

     return void( f.close());
 
}




void update_teacher_info(){
fstream f;
teacher t;
int idx;
f.open(pass_teacher,ios::in| ios::out);

    cout<<"Please enter name ";
   char name[20],password[20];
    cin >> name;
    cout<<"please enter the password";
    cin>>password;
   


while (  f.read((char *)&t,sizeof (t))){

if (strcmp(name,t.name)==0&& strcmp(password,t.password)==0){
    cout<<"1 - Update the name"<<nl;
    cout<<"2 - Update the age"<<nl;
    cout<<"3 - Update the phone"<<nl;
    cout<<"4 - Update the department"<<nl;

    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
       cout<<"Please enter the new name"<<nl;
       cin >> t.name;
  
        break;

    case 2:
       cout<<"Please enter the new age"<<nl;
       cin >> t.age;
   
        break;
    
        case 3:
       cout<<"Please enter the new phone number"<<nl;
       cin >> t.phone;
    
        break;
    
    
    
        case 4:
       cout<<"Please enter the new department"<<nl;
      
  cout<<"------------GRADES------------"<<nl;

  cout<<"1 - General"<<nl;
  cout<<"2 - Bioinformatics"<<nl;
  cout<<"3 - Software Engineering" <<nl;
  cout<<"4 - Computer science"<<nl;
  cout<<"5 - Information System"<<nl;
  cout<<"please enter the choice of Departments"<<nl;

      cin >> idx;

              t.department=idx;
              
        break;
    
    default:
       cout<<"your choice is not avilable"<<nl;
        break;
    }
    // to overwrite the data in the student
          int poss = f.tellg(),size=sizeof(t);
        f.seekp(poss-size,ios::beg);
        f.write((char *)&t,sizeof (t));
         f.seekg(poss-size,ios::beg);
        f.read((char *)&t,sizeof (t));
    cout<<"Name        -> "<<t.name<<nl;
    cout<<"Age         -> "<<t.age<<nl;
    cout<<"Phone       -> "<<t.phone<<nl;
    cout<<"Department  -> "<<grade[t.department-1]<<nl;
    f.close();
    return;
}
 
}
cout<<"Sorry the teacher is not found"<<nl;
f.close();
}



void update_teacher_password(){
fstream f;
teacher t;
int idx;
f.open(pass_teacher,ios::in| ios::out);

    cout<<"Please enter name "<<nl;
   char name[20],password[20];
    cin >> name;
    cout<<"please enter the password"<<nl;
    cin>>password;
    while (  f.read((char *)&t,sizeof (t))){

if (strcmp(name,t.name)==0&& strcmp(password,t.password)==0){
    cout<<"please enter the new password"<<nl;
    cin >> t.password;
       int poss = f.tellg(),size=sizeof(t);
        f.seekp(poss-size,ios::beg);
        f.write((char *)&t,sizeof (t));
         f.seekg(poss-size,ios::beg);
        f.read((char *)&t,sizeof (t));
    cout<<"Name             -> "<<t.name<<nl;
    cout<<"password         -> "<<t.password<<nl;
 
    f.close();
    return;
    
}

    }
    cout<<"Sorry the student is not found"<<nl;
f.close();
}


void copy_data_teacher(string pass1,string pass2){

fstream f,o;
teacher t;
f.open(pass1,ios::in);
o.open(pass2,ios::out);
while (  f.read((char *)&t,sizeof (t))){
  
     o.write((char *)&t,sizeof (t));

}

f.close();
o.close();

}

void delete_teacher(){


fstream in,out;
teacher t;
bool is=0;
in.open(pass_teacher,ios::in);
out.open("temp2.txt",ios::out);

char name[20],pass[20];
cout<<"Please enter the name to delete this teacher"<<nl;
cin >> name;
cout<<"Please enter the password to this teacher"<<nl;
cin >> pass;



while (  in.read((char *)&t,sizeof (t))){
  if ((strcmp(name,t.name)==0&& strcmp(pass,t.password)==0)) {
    is=1;
    continue;
  }
     out.write((char *)&t,sizeof (t));

}

cout<<(is?"DELETED  ":"THIS TEACHER IS NOT VALID")<<nl;
in.close();
out.close();
if (is)copy_data_teacher("temp2.txt",pass_teacher);




}


void teacher_do(){

char c='y';
while (c=='y')
{
    cout<<"1- Add new teacher"<<nl;
    cout<<"2- update teacher info"<<nl;
    cout<<"3- update teacher password"<<nl;
    cout<<"4- search teacher"<<nl;
    cout<<"5- view one teacher"<<nl;
    cout<<"6- view all teacher"<<nl;
    cout<<"7- delete teacher"<<nl;
    cout<<"8- update student info"<<nl;
    cout<<"9- view one student"<<nl;
    cout<<"10- view all students"<<nl;
    cout<<"11- delete student"<<nl;
    cout<<"12- add values to student"<<nl<<nl;

    cout<<"Please enter your choice"<<nl;
    int ch;
    cin >> ch;

  switch (ch)
  {
    case 1:
    add_teacher();
    break;
    case 2:
    update_teacher_info();
    break;
    case 3:
    update_teacher_password();
    break;
    case 4:
    search_teacher();
    break;
    case 5:
    view_one_teacher();
    break;
    case 6:
    view_all_teachers();
    break;
    case 7:
    delete_teacher();
    break;
    case 8:
    update_student_info();
    break;
    case 9:
    view_one_student();
    break;
    case 10:
    view_all_students();
    break;
    case 11:
    delete_student();
    break;
    case 12:
    add_values();
    break;
    default:
    cout<<"Your choise is not valid"<<nl;
    break;
  }


cout<<"If you want to continue y/n"<<nl;
cin>>c;

}




}

int main(){

char c='y';
cout<<"----------------------------HELLO IN OUR PROGRAME------------------------"<<nl;
while ( c=='y'){
int ch;
cout<<"TEACHER        enter  1 "<<nl;
cout<<"STUDENT        enter  2 "<<nl;
cin >>ch;
if ( ch==1){
  cout<<"SIGN UP     1 "<<nl;
  cout<<"SIGN IN     2 "<<nl;
  int i=1;
  cin >>i;
  if (i==2){
  if (valid_teacher()) 
        teacher_do();
     else 
        cout<<"your name or password is not valid   --------    please try again"<<nl;   

  }else{
    add_teacher();
  }

}
else {
  cout<<"SIGN UP     1 "<<nl;
  cout<<"SIGN IN     2 "<<nl;
  int i=1;
  cin >>i;
  if ( i==2){
 if (valid_student()) 
       student_do();
     else 
        cout<<"your name or password is not valid   --------    please try again"<<nl;   
  }else{
    add_student();
  }
    

}
cout<<"Do you want to continue   y/n"<<nl;
cin >>c;
}

cout<<"-----------------------------------GOOD BAY-------------------------------"<<nl;

    return 0;

}

