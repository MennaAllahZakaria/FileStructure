          
def update_student():
        import os
        id=input("Enter the ID of the record\n")

        file= open(path,"r")  
        temp=open("tempfile.txt",'w')
        flag=False
        for line in file:
            st=line.split("\t")

            if st[0]==id:
                flag=True
                name=input("Please enter the new name \n")
                age =input("please enter the new age \n")
                line =id+'\t'+name+'\t'+age+'\n'
        temp.write(line)
        
        file.close()
        temp.close()
        os.remove(path)
        os.rename("tempfile.txt",path)
        if not flag:
          print("No such element")     
        else :
            print("UPDATED")  
                
update_student()
