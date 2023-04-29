#for example we write a stuent info [id / name / age] in the file 

path="data.txt"
def add_student():
        with open(path,"a") as file:
            c='y'
            while c=='y':
                id=input("Please enter the id\n")
                name= input("please enter the name \n")
                age =input("please enter the age\n")
                file.write(id+'\t'+name+'\t'+age+'\n')
                c=input("If you want to countinue ... (y/n) \n")
            print ( " all recordes were ADDED ")
 
 
 add_student()
