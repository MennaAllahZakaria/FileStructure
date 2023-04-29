
def delete_student():
        import os
        id=input("Enter the ID of the record you want to delete\n")

        file= open(path,"r")  
        temp=open("tempfile.txt",'w')
        flag=False
        for line in file:
            st=line.split("\t")

            if st[0]==id:
                flag= True
            else:
                temp.write(line)
        
        file.close()
        temp.close()
        os.remove(path)
        os.rename("tempfile.txt",path)
        if not flag:
          print("SORRY No such element")     
        else :
            print("DELETED")  
            
delete_student()
