#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

int adminView();
int studentView();
int studentLogin();
int checkStudentCredentials(string userName, string password);
int getAllStudentsbyRollNo();
int deleteAllStudents();
int deleteStudentbyRollno();
int checkListOfStudentsRegistered();
int checkPresenseCountbyRollno();
int getListOfStudentsWithTheirPresenseCount();
int registerStudent();
int adminLogin();
int markMyAttendance(string username);
int countMyAttendance(string username);
int delay();

int delay()
{
    for(int i = 0; i < 3; i++)
    {
        cout << "\n Saving Records ...";
        for(int ii = 0; ii < 20000; ii++)
        {
            for(int iii = 0; iii < 20000; iii++)
            {
                // Simulate delay
            }
        }
    }

    cout << "\n Exiting Now ...";
    for(int i = 0; i < 3; i++)
    {
        for(int ii = 0; ii < 20000; ii++)
        {
            for(int iii = 0; iii < 20000; iii++)
            {
                // Simulate delay
            }
        }
    }
    return 0;
}

int adminView()
{
    int goBack = 0;
    while(1)
    {
        system("cls");
        cout << "\n 1 Register a Student";
        cout << "\n 2 Delete All students name registered";
        cout << "\n 3 Delete student by rollno";
        cout << "\n 4 Check List of Student registered by username";
        cout << "\n 5 Check presence count of any student by Roll No";
        cout << "\n 6 Get List of student with their attendance count";
        cout << "\n 0. Go Back <- \n";
        int choice;
        cout << "\n Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: registerStudent(); break;
            case 2: deleteAllStudents(); break;
            case 3: deleteStudentbyRollno(); break;
            case 4: checkListOfStudentsRegistered(); break;
            case 5: checkPresenseCountbyRollno(); break;
            case 6: getListOfStudentsWithTheirPresenseCount(); break;
            case 0: goBack = 1; break;
            default:
                cout << "\n Invalid choice. Enter again ";
                cin.ignore();
        }
        if(goBack == 1)
        {
            break;
        }
    }
    return 0;
}

int studentLogin()
{
    system("cls");
    cout << "\n -------- Student Login ---------";
    studentView();
    delay();
    return 0;
}

int adminLogin()
{
    system("cls");
    cout << "\n --------- Admin Login --------";
    string username;
    string password;
    cout << "\n Enter username : ";
    cin >> username;
    cout << "\n Enter password : ";
    cin >> password;
    if(username == "admin" && password == "admin@2")
    {
        adminView();
        cin.ignore();
        delay();
    }
    else
    {
        cout << "\n Error ! Invalid Credentials..";
        cout << "\n Press any key for main menu ";
        cin.ignore();
        cin.get();
    }
    return 0;
}

int checkStudentCredentials(string username, string password)
{
    // read file line by line & check if username-password.dat exist?
    // if it exists return 1 else 0
    ifstream read;
    read.open("db.dat");
    if (read)
    {
        int recordFound = 0;
        string line;
        string temp = username + "-" + password + ".dat";
        cout << "\n file name is : " << temp;
        while(getline(read, line))
        {
            if(line == temp)
            {
                recordFound = 1;
                break;
            }
        }
        read.close();
        if(recordFound == 0)
            return 0;
        else
            return 1;
    }
    else
    {
        return 0;
    }
}

int getAllStudentsbyName()
{
    cout << "\n List of All Students by their Name \n";
    cout << "\n Press any key to continue..";
    cin.ignore();
    cin.get();
    return 0;
}

int getAllStudentsbyRollNo()
{
    cout << "\n List of All Students by their Roll No \n";
    cout << "\n Press any key to continue..";
    cin.ignore();
    cin.get();
    return 0;
}

int deleteStudentbyRollno()
{
    cout << "\n Delete any Student by their Roll No \n";
    cout << "\n Press any key to continue..";
    cin.ignore();
    cin.get();
    return 0;
}

int checkPresenseCountbyRollno()
{
    cout << "\n Check presence count of any Student by Roll No \n";
    cout << "\n Press any key to continue..";
    cin.ignore();
    cin.get();
    return 0;
}

int checkAllPresenseCountbyRollno()
{
    cout << "\n Check presence count of All Students by Roll No & Name \n";
    cout << "\n Press any key to continue..";
    cin.ignore();
    cin.get();
    return 0;
}

int studentView()
{
    cout << "\n ------- Student Login-------- \n";
    string username, password;
    cout << "\n Enter username : ";
    cin >> username;
    cout << "\n Enter password : ";
    cin >> password;
    int res = checkStudentCredentials(username, password);
    if(res == 0)
    {
        cout << "\n Invalid Credentials !!";
        cout << "\n Press any key for Main Menu..";
        cin.ignore();
        cin.get();
        return 0;
    }
    int goBack = 0;
    while(1)
    {
        system("cls");
        cout << "\n 1 Mark Attendance for Today ";
        cout << "\n 2 Count my Attendance";
        cout << "\n 0. Go Back <- \n";
        int choice;
        cout << "\n Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: markMyAttendance(username); break;
            case 2: countMyAttendance(username); break;
            case 0: goBack = 1; break;
            default:
                cout << "\n Invalid choice. Enter again ";
                cin.ignore();
        }
        if(goBack == 1)
        {
            break;
        }
    }
    return 0;
}

int markMyAttendance(string username)
{
    cout << "\n Mark Attendance for today !!";
    cout << "\n Press any key to continue..";
    cin.ignore();
    cin.get();
    return 0;
}
int countMyAttendance(string username)
{
    cout << "\n Count my attendance for today !!";
    cout << "\n Press any key to continue..";
    cin.ignore();
    cin.get();
    return 0;
}

int deleteAllStudents()
{
    cout << "\n In delete all students !!";
    cout << "\n Press any key to continue..";
    cin.ignore();
    cin.get();
    return 0;
}

int checkListOfStudentsRegistered()
{
    cout << "\n - Check List of Student Registered by Username-- ";
    ifstream read;
    read.open("db.dat");
    if(read)
    {
        string line;
        while(getline(read, line))
        {
            string onlyname = line.substr(0, line.length() - 4); // Removes .dat extension
            cout << "\n " << onlyname;
        }
        read.close();
    }
    else
    {
        cout << "\n No Record found :(";
    }
    cout << "\n Press any key to continue..";
    cin.ignore();
    cin.get();
    return 0;
}

int getListOfStudentsWithTheirPresenseCount()
{
    cout << "\n All Students with their Presence count !!";
    cout << "\n Press any key to continue..";
    cin.ignore();
    cin.get();
    return 0;
}

int registerStudent()
{
    cout << "\n ----- Form to Register Student ---- \n";
    string name, username, password, rollno, address, father, mother;
    cout << "\n Enter Name : ";       cin >> name;
    cout << "\n Enter Username : ";   cin >> username;
    cout << "\n Enter password : ";   cin >> password;
    cout << "\n Enter rollno : ";     cin >> rollno;
    cin.ignore();
    char add[100];
    cout << "\n Enter address : ";    cin.getline(add, 100);
    cout << "\n Enter father : ";     cin >> father;
    cout << "\n Enter mother : ";     cin >> mother;

    // Check if record already exist..
    ifstream read;
    read.open("db.dat");
    if(read)
    {
        int recordFound = 0;
        string line;
        while(getline(read, line))
        {
            if(line == username + ".dat")
            {
                recordFound = 1;
                break;
            }
        }
        read.close();
        if(recordFound == 1)
        {
            cout << "\n Username already Register. Please choose another username ";
            cin.ignore();
            cin.get();
            delay();
            return 0;
        }
    }
    ofstream out;
    out.open("db.dat", ios::app);
    out << username + ".dat" << "\n";
    out.close();

    ofstream out1;
    string temp = username + ".dat";
    out1.open(temp.c_str());
    out1 << name << "\n";
    out1 << username << "\n";
    out1 << password << "\n";
    out1 << rollno << "\n";
    out1 << add << "\n";
    out1 << father << "\n";
    out1 << mother << "\n";
    out1.close();

    cout << "\n Student Registered Successfully !!";
    cout << "\n Press any key to continue..";
    cin.ignore();
    cin.get();
    return 0;
}

int main(int argc, char** argv)
{
    while(1)
    {
        system("cls");
        cout << "\t\t\t\t\t Attendance Management System \n";
        cout << "-------------------------------------\n\n";
        cout << "1. Student Login\n";
        cout << "2. Admin Login\n";
        cout << "0. Exit\n";
        int choice;
        cout << "\n Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: studentLogin(); break;
            case 2: adminLogin(); break;
            case 0:
                while(1)
                {
                    system("cls");
                    cout << "\n Are you sure, you want to exit? y | n \n";
                    char ex;
                    cin >> ex;
                    if(ex == 'y' || ex == 'Y')
                        exit(0);
                    else if(ex == 'n' || ex == 'N')
                    {
                        break;
                    }
                    else
                    {
                        cout << "\n Invalid choice !!!";
                        cin.ignore();
                    }
                }
                break;
            default:
                cout << "\n Invalid choice. Enter again ";
                cin.ignore();
        }
    }
    return 0;
}
