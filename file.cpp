#include <bits/stdc++.h>
using namespace std;
 
class Student
{
public:
    int sID, sAge;
    char sName[10], sGrade[10];
};
 
class Tracher
{
public:
    int tID, tAge;
    char tName[10], tSubject[10];
};
int ar[1000]{};
int arr[1000]{};
void write_Student()
{
    fstream outFile("Student.txt", ios::out | ios::app);
 
    Student s1;
    char c = 'y';
    while (c == 'y')
    {
        cout << "Enter Student Name : ";
        cin >> s1.sName;
 
        cout << "Enter Student ID : ";
        cin >> s1.sID;
        arr[s1.sID]++;
        while(arr[s1.sID] != 1){
            cout << "this id is valid, input another id";
            cin >> s1.sID;
            arr[s1.sID]++;
            }

        cout << "Enter Student Age : ";
        cin >> s1.sAge;
 
        cout << "Enter Student Grade : ";
        cin >> s1.sGrade;
 
        outFile.write((char *)&s1, sizeof(s1));
        cout << "Enter records again? (y/n) ";
        cin >> c;
    }
    outFile.close();
}
 
 
void write_Teacher()
{
    fstream outFile("Teacher.txt", ios::out | ios::app);
    Tracher t1;
    char c = 'y';
    while (c == 'y')
    {
        cout << "Enter Teacher Name : ";
        cin >> t1.tName;
 
        cout << "Enter Teacher ID : ";
        cin >> t1.tID;
        arr[t1.tID]++;
        while(arr[t1.tID] != 1){
            cout << "this id is valid, input another id";
            cin >> t1.tID;
            arr[t1.tID]++;
            }
 
        cout << "Enter Teacher Age : ";
        cin >> t1.tAge;
 
        cout << "Enter Teacher Subject : ";
        cin >> t1.tSubject;
 
        outFile.write((char *)&t1, sizeof(t1));
        cout << "Enter records again? (y/n) ";
        cin >> c;
    }
    outFile.close();
}
 
void read_Student()
{
    Student s1;
    ifstream in;
    in.open("Student.txt", ios::in);
    if (in.is_open())
    {
        cout << "ID\tName\tAge\tGrade" << endl;
        while (true)
        {
            in.read((char *)&s1, sizeof(s1));
            if (in.eof())
             break;
            cout << s1.sID << "\t" << s1.sName << "\t" << s1.sAge << "\t" << s1.sGrade << endl;
        }
    }
    else
        cout << "This File is not Valid \n";
    in.close();
}
 
void read_Teacher()
{
    Tracher t1;
    ifstream in;
    in.open("Teacher.txt", ios::in);
    if (in.is_open())
    {
        cout << "ID\tName\tAge\tSubject" << endl;
        while (true)
        {
            in.read((char *)&t1, sizeof(t1));
            if (in.eof())
                break;
 
            cout << t1.tID << "\t" << t1.tName << "\t" << t1.tAge << "\t" << t1.tSubject << endl;
        }
    }
    else
        cout << "This File is not Valid \n";
    in.close();
}
 
 
 
void Search_Student(int id)
{
    bool found;
    Student s1;
    ifstream in;
    in.open("Student.txt", ios::in);
    if (in.is_open())
    {
        in.read((char *)&s1, sizeof(s1));
        while (!in.eof())
        {
            if (s1.sID == id)
            {
                cout << "ID\tName\tAge\tGrade" << endl;
                cout << s1.sID << "\t" << s1.sName << "\t" << s1.sAge << "\t" << s1.sGrade << endl;
                found = true;
                break;
            }
            in.read((char *)&s1, sizeof(s1));
        }
        if (!found)
            cout << "ID Not Found" << endl;
 
        in.close();
    }
    else
    {
        cout << "File not found" << endl;
    }
}
 
 
 
void Search_Teacher(int id)
{
    bool found;
    Tracher t1;
    ifstream in;
    in.open("Teacher.txt", ios::in);
    if (in.is_open())
    {
        in.read((char *)&t1, sizeof(t1));
        while (!in.eof())
        {
            if (t1.tID == id)
            {
                cout << "ID\tName\tAge\tSubject" << endl;
                cout << t1.tID << "\t" << t1.tName << "\t" << t1.tAge << "\t" << t1.tSubject << endl;
                found = true;
                break;
            }
            in.read((char *)&t1, sizeof(t1));
        }
        if (!found)
            cout << "ID Not Found" << endl;
 
        in.close();
    }
    else
    {
        cout << "File Not Found" << endl;
    }
}
 
 
 
 
void update_teacher(){
    read_Teacher();
    char str[10];
    cout << "Enter the name of the teacher whose data you want to update :"<<endl;
    cin >> str;
    bool found=false;
    Tracher t;
    fstream f;
    f.open("Teacher.txt",ios::in | ios::out);
    if(f.is_open()){
 
        f.read((char*)&t,sizeof(t));
        while(!f.eof()){
            if(strcmp(str,t.tName)==0){
                cout<<"id"<<"\t"<<"Name"<<"\t"<<"Age"<<"\t"<<"Subject"<<endl;
                cout<<t.tID<<"\t"<<t.tName<<"\t"<<t.tAge<<"\t"<<t.tSubject<<endl;
 
                cout << " 1-> Update teacher's name.\n";
                cout << " 2-> Update teacher's age.\n";
                cout << " 3-> Update teacher's id.\n";
                cout << " 4-> Update teacher's subject.\n";
                int operation;
                cin >> operation;
                switch (operation)
                {
                    case 1:                     
                        cout << "enter the new name for the teacher "<<str<< " \n";
                        cin >> t.tName;
 
                        break;
                    case 2:
 
                        cout << "enter the new age for the teacher "<<str<< " \n";
                        cin >> t.tAge;
 
                        break;
                    case 3:                     
                        cout << "enter the new id for the teacher "<<str<< " \n";
                        cin >> t.tID;
                        break;
                    case 4:                     
                        cout << "enter the new subject for the teacher "<<str<< " \n";
                        cin >> t.tSubject;
                        break;
                }
                int curPos =f.tellg();
                int stuSize=sizeof(t);
                f.seekp(curPos-stuSize,ios::beg);
                f.write((char*)&t,sizeof(t));
                f.seekp(curPos-stuSize,ios::beg);
                f.read((char*)&t,sizeof(t));
                cout<<t.tID<<"\t"<<t.tName<<"\t"<<t.tAge<<"\t"<<t.tSubject<<endl;
                found = true;
                break;
            }
            f.read((char*)&t,sizeof(t));
        }if(!found){
            cout<<"name not found";
        }
 
    f.close();
    }
}
 
 
void update_student(){
    read_Student();
    char str[10];
    cout<<"Enter the name of the student whose data you want to update  "<<endl;
    cin>>str;
    bool found=false;
    Student s;
    fstream f;
    f.open("Student.txt",ios::in | ios::out);
    if(f.is_open()){
 
        f.read((char*)&s,sizeof(s));
        while(!f.eof()){
        /*ask youssef about it*/    if(strcmp(str,s.sName)==0){
                cout<<"id"<<"\t"<<"Name"<<"\t"<<"Age"<<"\t"<<"Grade"<<endl;
                cout<<s.sID<<"\t"<<s.sName<<"\t"<<s.sAge<<"\t"<<s.sGrade<<endl;
 
                cout << " 1-> Update student's name.\n";
                cout << " 2-> Update student's age.\n";
                cout << " 3-> Update student's id.\n";
                cout << " 4-> Update student's grade.\n";
                int operation;
                cin >> operation;
                switch (operation)
                {
                    case 1:                     
                        cout << "enter the new name for the student "<<str<< " \n";
                        cin >> s.sName;
 
                        break;
                    case 2:
 
                        cout << "enter the new age for the student "<<str<< " \n";
                        cin >> s.sAge;
 
                        break;
                    case 3:                     
                        cout << "enter the new id for the student "<<str<< " \n";
                        cin >> s.sID;
                        break;
                    case 4:                     
                        cout << "enter the new grade for the student "<<str<< " \n";
                        cin >> s.sGrade;
                        break;
                }
                int curPos =f.tellg();
                int stuSize=sizeof(s);
                f.seekp(curPos-stuSize,ios::beg);
                f.write((char*)&s,sizeof(s));
                f.seekp(curPos-stuSize,ios::beg);
                f.read((char*)&s,sizeof(s));
                cout<<s.sID<<"\t"<<s.sName<<"\t"<<s.sAge<<"\t"<<s.sGrade<<endl;
                found = true;
                break;
            }
            f.read((char*)&s,sizeof(s));
        }if(!found){
            cout<<"name not found";
        }
 
    f.close();
    }
}
 
void delete_Teacher(){
    int id ;
 
cin>>id;
    bool found;
    Tracher t1;
    ifstream in;
    ofstream Temp("temp.txt",ios::out);
    in.open("Teacher.txt",ios::in);
    if(in.is_open())
    {
        in.read((char*)&t1,sizeof(t1));
        while(!in.eof())
        {
            if( t1.tID != id)
            {
               Temp.write((char*)&t1,sizeof(t1));
                found = true;
            }
            in.read((char*)&t1,sizeof(t1));           
        }
        if(!found)
            cout<<"ID not found";
 
        in.close();
        Temp.close();
        remove("Teacher.txt");
        rename("temp.txt","Teacher.txt");
    }
    else 
       cout<<"ID not found";
    
}
 
 
void delete_student(){
    int id ;
cin>>id;
    bool found;
    Student s1;
    ifstream in;
    ofstream Temp("temp.txt",ios::out);
    in.open("Student.txt" , ios::in);
    if(in.is_open())
    {
        in.read((char*)&s1,sizeof(s1));
        while(!in.eof())
        {
            if(s1.sID != id)
            {
             
          Temp.write((char*)&s1,sizeof(s1));
                found = true;
            }
            in.read((char*)&s1,sizeof(s1));           
        }
        if(!found)
            cout<<"ID not found";
 
        in.close();
        Temp.close();
        remove("Student.txt");
        rename("temp.txt","Student.txt");
    }
    else 
       cout<<"ID not found";
    
}
 
int main()
{
    char c;
    int id = 0;
    int id2 = 0 ;
    while (true)
    {
        // --------------------------Menu--------------------------------------
 
        cout << " 1-> Write data.\n";
        cout << " 2-> Read data.\n";
        cout << " 3-> Search for data.\n";
        cout << " 4-> update for data.\n";
        cout << " 5-> delete for data.\n";
 
 
 
 
        // ---------------------------Select Operation-------------------------------------
 
        int op;
        cin >> op;
 
        switch (op)
        {
            int n;
 
        case 1:
            cout << " 1-> Write Student.\n";
            cout << " 2-> Write Teacher.\n";
            cin >> n;
            switch (n)
            {
            case 1:
                write_Student();
                break;
            case 2:
                write_Teacher();
                break;
            }
            break;
        case 2:
            cout << " 1-> Read Student.\n";
            cout << " 2-> Read Teacher.\n";
            cin >> n;
            switch (n)
            {
            case 1:
                read_Student();
                break;
            case 2:
                read_Teacher();
                break;
            }
            break;
        case 3:
            cout << " 1-> Search For Student.\n";
            cout << " 2-> Search For Teacher.\n";
            cin >> n;
            switch (n)
            {
            case 1:
                cout << "Enter Student ID to Search for : " << endl;
                cin >> id;
                Search_Student(id);
                break;
            case 2:
                cout << "Enter Teacher ID to Search for : " << endl;
                cin >> id;
                Search_Teacher(id);
                break;
            }
            break;
 
            case 4 : 
            cout << " 1-> update For Student.\n";
            cout << " 2-> update For Teacher.\n";
            cin >> n;
            switch (n)
            {
            case 1:
                cout << "Enter Student ID to update for : " << endl;
                update_student();
                break;
            case 2:
                cout << "Enter Teacher ID to update for : " << endl;
                update_teacher();
                break;
            }
            break;
 
            case 5 : 
            cout << " 1-> delete For Student.\n";
            cout << " 2-> delete For Teacher.\n";
            cin >> n;
            switch (n)
            {
            case 1:
                cout << "Enter Student ID to delete for : " << endl;
                delete_student();
                break;
            case 2:
                cout << "Enter Teacher ID to delete for : " << endl;
                delete_Teacher();
                break;
            }
            break;
        }

        cout << "Do you want to do another Operation ? [y/n] -> ";
        cin >> c;
        if (c != 'y')
            break;
    }
}
