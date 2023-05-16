 #        اللهم لا سهل الا ما جعلته سهلا و انت تجعل الصعب ان شئت سهل        

# write your passes 
pass_student="D:\\student_python.txt"
pass_teacher="D:\\teacher_python.txt"
pass_temp="D:\\temp.txt"
grade=["General","Bioinformatics","Software Engineering" ,"Computer science","Information System"]

# To transfer data between two files 
def trans( pass1 , pass2):
    file=open(pass1,'r')
    file2=open(pass2,'w')
    
    for line in file:
        file2.write(line)
        
    file.close()
    file2.close()
        
         


def print_grades():
     print('----------------------Departments----------------------')
     for i in range(len(grade)):
         print(str(i+1)+"  "+grade[i])
     print("--------------------------------------------------------")

   #------------------------------------------------------------------------------------              
   # To add new student record
def addStudent():
    with open(pass_student, 'a') as file:
        c='y'
        while c=='y':
            name = input('Enter The student name: ')
            password = input('Enter The student password: ')
            phone = input('Enter The student phone: ')
            age = input('Enter The student age: ')
            year = input('Enter The student year: ')
            
            i=-1
            while i==-1:
                 print_grades()
                 i=  int(input('please entre the choice of departments\n'))
                 if i<0 or i>5 :
                  print('Your Choice is not Available Try again  \n')
                  i=-1
          
            file.write(name + '\t' + password + '\t' + phone + '\t' + age + '\t' + year+'\t' +grade[i-1] +'\n')
            c=input('Enter records again (y//n)? \n')
        print('All Records were Added\n')
        
  #------------------------------------------------------------------------------------                      
# To delete student from data            
def deletestudent():
    import os
    name=input("Please enter the name to delete this student    \n ")
    pas=input ("Please enter the password to this student       \n ")
    file=open(pass_student,'r')
    file2=open(pass_temp,'w')   
    flag=False
    for line in file:
        s=line.split('\t')
        if name==s[0] and pas==s[1]:
           flag= True
        else:
           file2.write(line)
        
    file.close()
    file2.close()
    trans(pass_temp,pass_student)
    if flag:
       print("DELETED\n")  
    else:
       print("THIS STUDENT IS NOT VALID \n") 
       
                 
  #------------------------------------------------------------------------------------                
  # to checks if the student is in our data or not             
def vaildstudent():
    file=open(pass_student,"r")
    name=input("Enter the name    \n")
    pas=input ("Enter the password  \n   ")
    for line in file:
        s=line.split('\t')
        if name==s[0] and pas==s[1]: 
            file.close()  
            return True
    print("NOT VALID \n")
    return False
   # to view the infotmation of one student    
def view_one_student():
    file=open(pass_student,"r")
    name=input("Enter the name       \n")
    pas=input ("Enter the password   \n  ")
    for line in file:
        s=line.split('\t')
        if name==s[0] and pas==s[1]:
            print("Name     ->"+s[0])
            print("Phone    ->"+s[2])
            print("Age      ->"+s[3])
            print("Year     ->"+s[4])
            print("Grade    ->"+s[5])
            return
    print("That student is not found\n")
  
    #------------------------------------------------------------------------------------                
   # to view the infotmation of all students               
def view_all_students():
    file=open(pass_student,"r")
    i=1
    for line in file:
        s=line.split('\t')
        print("====================student   "+str(i)+"      ====================")
        print("Name     ->"+s[0])
        print("Phone    ->"+s[2])
        print("Age      ->"+s[3])
        print("Year     ->"+s[4])
        print("Grade    ->"+s[5])
        print("===================================================================")
        i=i+1
        
     #------------------------------------------------------------------------------------                   
   # to update the information of student        
def update_student():
        import os
        name_search=input("Enter the name of the record\n")
        pas=input("Enter the password of the record\n")
        file= open(pass_student,"r")  
        temp=open("tempfile.txt",'w')
        flag=False
        for line in file:
            st=line.split("\t")

            if st[0]==name_search and st[1]==pas:
                flag=True
                print("1 - Update name  ")
                print("2 - Update phone ")
                print("3 - Update age   ")
                print("4 - Update year  ")
                print("5 - Update grade ")
                i=int(input("please Enter your choise"))
                if i==1:
                    name=input("Please enter the new name \n")
                    line =name+'\t'+st[1]+'\t'+st[2]+'\t'+st[3]+'\t'+st[4]+'\t'+st[5]
                elif i==2:   
                    phone=input("please enter the new phone \n")
                    line =st[0]+'\t'+st[1]+'\t'+phone+'\t'+st[3]+'\t'+st[4]+'\t'+st[5]
                elif i==3:     
                    age =input("please enter the new age \n")
                    line =st[0]+'\t'+st[1]+'\t'+st[2]+'\t'+age+'\t'+st[4]+'\t'+st[5]
                elif i==4:
                    year=input("please enter the new year \n")
                    line =st[0]+'\t'+st[1]+'\t'+st[2]+'\t'+st[3]+'\t'+year+'\t'+st[5]
                elif i==5:
                    print_grades()
                    gr=int(input("Please enter the grade\n"))
                    line =st[0]+'\t'+st[1]+'\t'+st[2]+'\t'+st[3]+'\t'+st[4]+'\t'+grade[gr-1]
            temp.write(line)        
                
          
        file.close()
        temp.close()
        os.remove(pass_student)
        os.rename("tempfile.txt",pass_student)
        if not flag:
          print("No such element\n")     
        else :
            print("UPDATED\n")  
   
     #------------------------------------------------------------------------------------              
    # to update the password of student              
            
def update_student_password():
        import os
        name_search=input("Enter the name of the record\n")
        pas=input("Enter the password of the record\n")
        file= open(pass_student,"r")  
        temp=open("tempfile.txt",'w')
        flag=False
        for line in file:
            st=line.split("\t")

            if st[0]==name_search and st[1]==pas:
                flag=True
                password=input("pleas enter new password\n")              
                line =st[0]+'\t'+password+'\t'+st[2]+'\t'+st[3]+'\t'+st[4]+'\t'+st[5]
            temp.write(line)        
                
          
        file.close()
        temp.close()
        os.remove(pass_student)
        os.rename("tempfile.txt",pass_student)
        if not flag:
          print("No such element\n")     
        else :
            print("UPDATED\n")  
  
    #------------------------------------------------------------------------------------               
          # to search student an know he/she in which record  
def search_student():
        import os
        name_search=input("Enter the name of the record\n")
        file= open(pass_student,"r")  
        i=1
        for line in file:
            st=line.split("\t")
            if name_search==st[0]:
                print("Student found at line "+str(i)+'\n')
                file.close()
                return
            i+=1
   
   
  #------------------------------------------------------------------------------------              
  # these functions only the student can access          
            
def do_student():
    c='y'
    while c=='y':
         print("1- Add new student")
         print("2- update student password")
         print("3- search student")
         print("4- view one student")
         

         i=int(input("Please enter your choice\n"))
         if i==1:
             addStudent()
         elif i==2:
             update_student_password()  
         elif i==3:
             search_student()    
         elif i==4:
             view_one_student()            
            
         c=input("Do you to countinue ......  (y // n)")        
            
            
            
 # ===================================TEACHER============================================    
 
 # To add new teacher record        
def addTeacher():
    with open(pass_teacher, 'a') as file:
        c='y'
        while c=='y':
            name = input('Enter The Teacher name:    ->')
            password = input('Enter The Teacher password:   -> ')
            phone = input('Enter The Teacher phone: ->')
            age = input('Enter The Teacher age: ->')
            

            i=-1
            while i==-1:
                 print_grades()
                 i=  int(input('please entre the choice of departments\n'))
                 if i<0 or i>5 :
                  print('Your Choice is not Available Try again  \n')
                  i=-1
            
            file.write(name + '\t' + password + '\t' + phone + '\t' + age + '\t'+grade[i-1] +'\n')
            c=input('Enter records again (y//n)? \n')
            print(' Record  Added \n ')
  
 #------------------------------------------------------------------------------------                  
 # To delete teacher from data            
def deleteteacher():
    import os
    name=input("Please enter the name to delete this teacher     ->")
    pas=input ("Please enter the password to this teacher        ->")
    file=open(pass_teacher,'r')
    file2=open(pass_temp,'w')   
    flag=False
    for line in file:
        s=line.split('\t')
        if name==s[0] and pas==s[1]:
           flag= True
        else:
           file2.write(line)
        
    file.close()
    file2.close()
    trans(pass_temp,pass_teacher)
    if flag:
       print("DELETED\n")  
    else:
       print("THIS TEACHER IS NOT VALID \n")           
  
 #------------------------------------------------------------------------------------                        
  # to checks if the teacher is in our data or not              
def vaildteacher():
    file=open(pass_teacher,"r")
    name=input("Enter the name       \n ")
    pas=input(" Enter the password   \n  ")
    for line in file:
        s=line.split('\t')
        if name==s[0] and pas==s[1]: 
            file.close()  
            return True
    print("NOT VALID \n")
    return False


  #------------------------------------------------------------------------------------              
    # to view the infotmation of one teacher 
         
                
def view_one_teacher():
    file=open(pass_teacher,"r")
    name=input("Enter the name         \n")
    pas=input ("Enter the password     \n")
    for line in file:
        s=line.split('\t')
        if name==s[0] and pas==s[1]:
            print("_____________________________________________")
            print("Name     ->"+s[0])
            print("Phone    ->"+s[2])
            print("Age      ->"+s[3])
            print("Grade    ->"+s[4])
            print("_____________________________________________")

            return
    print("That teacher is not found\n")
    
    
    #------------------------------------------------------------------------------------                
    # to view the infotmation of all teachers   
               
def view_all_teacher():
    file=open(pass_teacher,"r")
    i=1
    for line in file:
        s=line.split('\t')
        print("============Teacher"+str(i)+"  ============")
        print("Name     ->"+s[0])
        print("Phone    ->"+s[2])
        print("Age      ->"+s[3])
        print("Grade    ->"+s[4])
        print("_____________________________________________")
        i=i+1
 #------------------------------------------------------------------------------------                       
     # to update the information of teacher
 
           
def update_teacher():
        import os
        name_search=input("Enter the name of the record\n")
        pas=input("Enter the password of the record\n")
        file= open(pass_teacher,"r")  
        temp=open("tempfile.txt",'w')
        flag=False
        for line in file:
            st=line.split("\t")

            if st[0]==name_search and st[1]==pas:
                flag=True
                print("1 - Update name  ")
                print("2 - Update phone ")
                print("3 - Update age   ")
                print("4 - Update grade ")
                i=int(input("please Enter your choise\n"))
                if i==1:
                    name=input("Please enter the new name \n")
                    line =name+'\t'+st[1]+'\t'+st[2]+'\t'+st[3]+'\t'+st[4]+'\t'+'\n'
                elif i==2:   
                    phone=input("please enter the new phone \n")
                    line =st[0]+'\t'+st[1]+'\t'+phone+'\t'+st[3]+'\t'+st[4]+'\n'
                elif i==3:     
                    age =input("please enter the new age \n")
                    line =st[0]+'\t'+st[1]+'\t'+st[2]+'\t'+age+'\t'+st[4]+'\n'
            
                elif i==4:
                    print_grades()
                    gr=int(input("Please enter the grade\n"))
                    line =st[0]+'\t'+st[1]+'\t'+st[2]+'\t'+st[3]+'\t'+grade[gr-1]+'\n'
            temp.write(line)        
                
          
        file.close()
        temp.close()
        os.remove(pass_teacher)
        os.rename("tempfile.txt",pass_teacher)
        if not flag:
          print("No such element\n")     
        else :
            print("UPDATED\n") 
            
            
             
    #------------------------------------------------------------------------------------              
      # to update the password of teacher              
           
            
def update_teacher_password():
        import os
        name_search=input("Enter the name of the record\n")
        pas=input("Enter the password of the record\n")
        file= open(pass_teacher,"r")  
        temp=open("tempfile.txt",'w')
        flag=False
        for line in file:
            st=line.split("\t")

            if st[0]==name_search and st[1]==pas:
                flag=True
                password=input("pleas enter new password\n")              
                line =st[0]+'\t'+password+'\t'+st[2]+'\t'+st[3]+'\t'+st[4]
            temp.write(line)        
                
          
        file.close()
        temp.close()
        os.remove(pass_teacher)
        os.rename("tempfile.txt",pass_teacher)
        if not flag:
          print("No such element\n")     
        else :
            print("UPDATED\n")  
  
    #------------------------------------------------------------------------------------              
     # to search teacher an know he/she in which record               
   
         
def search_teacher():
        import os
        name_search=input("Enter the name of the record\n")
        file= open(pass_teacher,"r")  
        i=1
        for line in file:
            st=line.split("\t")
            if name_search==st[0]:
                print("Teacher found at line "+str(i)+'\n')
                file.close()
                return
            i+=1
     
   #------------------------------------------------------------------------------------                   
   # these functions only the teacher can access            
def do_teacher():
    c='y'
    while c=='y':
         print("1- Add new teacher")
         print("2- update teacher info")
         print("3- update teacher password")
         print("4- search teacher")
         print("5- view one teacher")
         print("6- view all teacher")
         print("7- delete teacher")
         print("8- update student info")
         print("9- view one student")
         print("10- view all students")
         print("11- delete student")



         i=int(input("Please enter your choice\n"))
         if i==1:
             addTeacher()
         elif i==2:
             update_teacher() 
         elif i==3:
             update_teacher_password()   
         elif i==4:
             search_teacher()            
         elif i==5:
             view_one_teacher()
         elif i==6:
             view_all_teacher()
         elif i==7:
             deleteteacher() 
         elif i==8:
             update_student()           
         elif i==9:
             view_one_student()
         elif i==10:
             view_all_students()
         elif i==11:
             deletestudent()                                    
         c=input("Do you to countinue ...... y//n \n")        
            
 

def main():

  c='y'
  print("----------------------------HELLO IN OUR PROGRAME------------------------")
  while  c=='y':

    print("TEACHER        enter  1 ")
    print("STUDENT        enter  2 \n")
    ch=int(input())

    if  ch==1:
        print("SIGN UP     1 ")
        print("SIGN IN     2 \n")
        i=int(input())
        
        if i==2:
              if vaildteacher() :
                 do_teacher()
              else :
               print("your name or password is not valid   --------    please try again")   

        else:
            addTeacher()
    
  


    else :
        print("SIGN UP     1 \n")
        print("SIGN IN     2 \n")
        i=int(input())
        
        if i==2:
              if vaildstudent() :
                 do_student()
              else :
               print("your name or password is not valid   --------    please try again\n")   

        else:
            addStudent()
    


    c=input("Do you want to continue   y/n \n")


    print("-----------------------------------GOOD BAY-----------------------------------\n")

main()
