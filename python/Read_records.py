def view_all_students():
        with open(path,"r") as file:
            for line in file:
                print ("student  : ")
                print (line)

view_all_students()
