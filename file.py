def writestudent():
    with open("students.txt","r") as file:
 
        ids = [line.split()[0] for line in file]
 
    with open("students.txt","a") as file:
        c = 'y'
        while c == 'y':
            id = input("enter student's id : ")
 
            while id in ids:
                print("ID already exists. Please enter a different ID.")
                id = input("enter student's id : ")
            name = input("enter student's name : ")
            age = input("enter student's age : ")
            grade = input("enter student's grade : ")
            file.write(id + '\t' + name + '\t' + age + '\t' + grade + '\n')
            ids.append(id) 
            c = input("add another student ? (y/n)")
        print("record added successfully.")
#-------------------------------------------------------------
 
def writeteacher():
    with open("teachers.txt","r") as file:
 
        ids = [line.split()[0] for line in file]
 
    with open("teachers.txt","a") as file:
        c = 'y'
        while c == 'y':
            id = input("enter teachar id : ")
 
            while id in ids:
                print("ID already exists. Please enter a different ID.")
                id = input("enter teachar's id : ")
            name = input("enter teachar's name : ")
            age = input("enter teachar's age : ")
            subject = input("enter teachar's subject : ")
            file.write(id + '\t' + name + '\t' + age + '\t' + subject + '\n')
            ids.append(id) 
            c = input("add another teacher ? (y/n)")
        print("record added successfully.")

#-------------------------------------------------------------

def readstudent():
    with open("students.txt","r") as file:
        print("ID" + "\t" + "NAME" + "\t" + "AGE" + "\t" + "GRADE")
        print("---------------------------------------------------")
        for line in file:
            print(line, end='')

#-------------------------------------------------------------

def readteacher():
    with open("teachers.txt","r") as file:
        print("ID" + "\t" + "NAME" + "\t" + "AGE" + "\t" + "SUBJECT")
        print("---------------------------------------------------")
        for line in file:
            print(line, end='')

#-------------------------------------------------------------

def searchstudent():
    with open('students.txt', 'r') as file :
        id = input('Enter the id of the student to search for : ')
        flag = False
        for line in file:
            std = line.split('\t')
            if std [0] == id:
                flag = True
                print("ID" + "\t" + "NAME" + "\t" + "AGE" + "\t" + "GRADE")
                print('------------------------------------------------')
                print(line)
        if not flag:
            print('there is no student found with id : ' + id)

#-------------------------------------------------------------

def searchteacher():
    with open("teachers.txt","r") as file:
        id = input('Enter the id of the teacher to search for : ')
        flag = False
        for line in file:
            tch = line.split('\t')
            if tch [0] == id:
                flag = True
                print("ID" + "\t" + "NAME" + "\t" + "AGE" + "\t" + "SUBJECT")
                print('------------------------------------------------')
                print(line)
        if not flag:
            print('there is no teacher found with id : ' + id)

#-------------------------------------------------------------

def deletestudent():
    import os
    id = input ("Enter the id of student you want to delete: ")
    file = open ("students.txt", "r")
    tempFile = open ("tempstudents.txt", "w")
    flag = False
    for line in file:
        st = line.split ("\t")
        if st[0] == id:
            flag = True
        else:
            tempFile.write (line)
    file.close()
    tempFile.close()
    os.remove("students.txt")                                        
    os.rename("tempstudents.txt", "students.txt")    
    if flag:
        print ("student successfully deleted")
    else:
        print ("No students are found with id : " + id)

#-------------------------------------------------------------

def deleteteacher():
    import os
    id = input ("Enter the id of teacher you want to delete: ")
    file = open ("teachers.txt", "r")
    tempFile = open ("tempteachers.txt", "w")
    flag = False
    for line in file:
        st = line.split ("\t")
        if st[0] == id:
            flag = True
        else:
            tempFile.write (line)
    file.close()
    tempFile.close()
    os.remove("teachers.txt")                                        
    os.rename("tempteachers.txt", "teachers.txt")    
    if flag:
        print ("teacher successfully deleted")
    else:
        print ("No teachers are found with id : " + id)
#-------------------------------------------------------------
def updatestudent () :
    #readstudent()
    import os
    id = input ("Enter the id of the student you want to update : ")
    file= open ("students.txt", "r")
    tempFile = open ("tempstudents.txt", "w")
    flag= False
    for line in file:
        st = line.split ("\t")
        if st[0] == id:
            flag = True
            print("1 -> Update student's id.")
            print("2 -> Update student's name.")
            print("3 -> Update student's age.")
            print("4 -> Update student's grade.")
            print("5 -> Update all student's record.")
            op = input("")
            if op == '1':
                id = input ('Enter the new id for the student : ')
                line = id + '\t' + st[1] + '\t' + st [2] + '\t' + st [3]
            elif op == '2':
                name = input ('Enter the new name for the student : ')
                line = st[0] + '\t' + name + '\t' + st [2] + '\t' + st [3]
            elif op == '3':
                age = input ('Enter the new age for the student : ')
                line = st[0] + '\t' + st[1] + '\t' + age + '\t' + st [3]
            elif op == '4':
                grade = input ('Enter the new grade for the student : ')
                line = st[0] + '\t' + st[1] + '\t' + st [2] + '\t' + grade + '\n'    
            elif op == '5':
                id = input ('Enter the new id for the student : ')
                name = input ('Enter the new name for the student : ')
                age = input ('Enter the new age for the student : ')
                grade = input ('Enter the new grade for the student : ')
                line = id + '\t' + name + '\t' + age + '\t' + grade + '\n'    
        tempFile.write (line)
    file.close ()
    tempFile.close ()
    os. remove ("students.txt")          # delete original file
    os. rename ("tempstudents.txt", "students.txt")       # rename temp file
    if flag:
        print ("student successfully updated")
        readstudent()
    else:
        print ("No students are found with id : " + id)
#-------------------------------------------------------------

def updateteacher():
    #readteacher()
    import os
    id = input ("Enter the id of the teacher you want to update : ")
    file= open ("teachers.txt", "r")
    tempFile = open ("tempteachers.txt", "w")
    flag= False
    for line in file:
        tch = line.split ("\t")
        if tch[0] == id:
            flag = True
            print("1 -> Update teacher's id.")
            print("2 -> Update teacher's name.")
            print("3 -> Update teacher's age.")
            print("4 -> Update teacher's subject.")
            print("5 -> Update all teachers's record.")
            op = input("")
            if op == '1':
                id = input ('Enter the new id for the teacher : ')
                line = id + '\t' + tch[1] + '\t' + tch[2] + '\t' + tch[3]
            elif op == '2':
                name = input ('Enter the new name for the teacher : ')
                line = tch[0] + '\t' + name + '\t' + tch[2] + '\t' + tch[3]
            elif op == '3':
                age = input ('Enter the new age for the teacher : ')
                line = tch[0] + '\t' + tch[1] + '\t' + age + '\t' + tch[3]
            elif op == '4':
                subject = input ('Enter the new subject for the teacher : ')
                line = tch[0] + '\t' + tch[1] + '\t' + tch[2] + '\t' + subject + '\n'    
            elif op == '5':
                id = input ('Enter the new id for the teacher : ')
                name = input ('Enter the new name for the teacher : ')
                age = input ('Enter the new age for the teacher : ')
                subject = input ('Enter the new subject for the teacher : ')
                line = id + '\t' + name + '\t' + age + '\t' + subject + '\n'    
        tempFile.write (line)
    file.close ()
    tempFile.close ()
    os. remove ("teachers.txt")          # delete original file
    os. rename ("tempteachers.txt", "teachers.txt")       # rename temp file
    if flag:
        print ("teacher successfully updated")
        readteacher()
    else:
        print ("No teachers are found with id : " + id)
#-------------------------------------------------------------

def main():
    c = 'y'
    while c == 'y':
        print("1 -> To add data")
        print("2 -> To read data")
        print("3 -> To search data")
        print("4 -> To delete data")
        print("5 -> To update data")
        op = input("enter : ")
        if op == '1':
            print("1 -> To write student")
            print("2 -> To write teacher")
            op2 = input("")
            if op2 == '1':
                writestudent()
            elif op2 == '2':
                writeteacher()
            else:
                print("invalid input")
        elif op == '2':
            print("1 -> To read student")
            print("2 -> To read teacher")
            op2 = input("")
            if op2 == '1':
                readstudent()
            elif op2 == '2':
                readteacher()
            else:
                print("invalid input")
        elif op == '3':
            print("1 -> To search for student")
            print("2 -> To search for teacher")
            op2 = input("")
            if op2 == '1':
                searchstudent()
            elif op2 == '2':
                searchteacher()
            else:
                print("invalid input")
        elif op == '4':
            print("1 -> To delete student")
            print("2 -> To delete teacher")
            op2 = input("")
            if op2 == '1':
                deletestudent()
            elif op2 == '2':
                deleteteacher()
            else:
                print("invalid input")
        elif op == '5':
            print("1 -> To update student")
            print("2 -> To update teacher")
            op2 = input("")
            if op2 == '1':
                updatestudent()
            elif op2 == '2':
                updateteacher()
            else:
                print("invalid input")
        c = input("perform another operation ? (y/n)")
    print("bye bye :)")

main()
