def search_student():
    id=input("Enter the ID of the record you wait to search about it\n")
    with open(path,"r") as file:
        flag=False
        for line in file:
            st=line.split("\t")

            if st[0]==id:
                flag= True
                print("ID:",st[0])
                print("AGE:",st[1])
                print("NAME:",st[2])
                
    if not flag:
        print("SORRY No such element : (")
        
        
 search_student()
