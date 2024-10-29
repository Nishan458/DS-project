#include <iostream>
#include <string>
using namespace std;
struct Student{
    string name;
    string id;
    string address;
    float cgpa;
    Student* next;
};
Student*createStudent(string name,string id,string address,float cgpa){
    Student*newStudent = new Student();
    newStudent->name=name;
    newStudent->id=id;
    newStudent->address=address;
    newStudent->cgpa=cgpa;
    newStudent->next=nullptr;
    return newStudent;
}
void addStudent(Student*&head,string name,string id,string address,float cgpa){
    Student*newStudent=createStudent(name,id,address,cgpa);
    if (head==nullptr){
        head=newStudent;
    }else{
        Student*temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newStudent;
    }
}
void sortStudentsByID(Student*& head){
    if (head==nullptr)return;
    for (Student*current=head;current!=nullptr;current=current->next){
        Student* minStudent=current;
        for (Student* next=current->next; next!=nullptr; next=next->next){
            if (next->id < minStudent->id){
                minStudent=next;
            }
        }
        if (minStudent!=current){
            swap(current->name,minStudent->name);
            swap(current->id,minStudent->id);
            swap(current->address,minStudent->address);
            swap(current->cgpa,minStudent->cgpa);
        }
    }
}
Student*searchByID(Student*head,string id){
    Student*temp=head;
    while (temp!=nullptr){
        if (temp->id==id){
            return temp;
        }
        temp=temp->next;
    }
    return nullptr;
}
void displayStudentInfo(Student*student) {
    if(student!=nullptr){
        cout<<"Student Name: "<< student->name<<endl;
        cout<<"Student ID: "<< student->id<<endl;
        cout<<"Address: "<<student->address<<endl;
        cout<<"CGPA: "<<student->cgpa<<endl;
    } else {
        cout<<"Student not found!"<<endl;
    }
}
void displayAllStudents(Student* head) {
    if (head==nullptr) {
        cout<<"No students in the list."<<endl;
        return;
    }
    Student*temp=head;
    while(temp!=nullptr){
        displayStudentInfo(temp);
        cout<<" "<<endl;
        temp=temp->next;
    }
}
void displayMenu(){
    cout<<"\n1.Search by ID"<<endl;
    cout<<"2.Add student information"<<endl;
    cout<<"3.Display all student's data (sorted by ID)"<< endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter your choice: ";
}
void deleteStudentList(Student*& head){
    Student*temp;
    while (head != nullptr){
        temp=head;
        head=head->next;
        delete temp;
    }
}
int main(){
    cout<<"Welcome to STUDENT INFO BOOK"<<endl;
    Student*head=nullptr;
    addStudent(head, "Md Nishan Kha", "458", "Jashore.", 3.5);
    addStudent(head, "Tanjib Ahmed", "223", "Demra.", 3.0);
    addStudent(head, "MD Nayeem Islam", "362", "Tejgaon.", 3.37);
    addStudent(head, "Irfan Ahmed", "234", "Nawabganj.", 3.01);
    addStudent(head, "Md Mehedi Hasan", "360", "Sonirakhra.", 3.26);
    addStudent(head, "MD Sajedul Islam", "372", "Mohammadpur.", 3.33);

    int choice=0;
    while (choice!=4) {
        displayMenu();
        cin>>choice;
        switch(choice) {
            case 1:{
                string searchID;
                cout << "Enter your ID to search: ";
                cin >> searchID;
                Student*foundStudent=searchByID(head,searchID);
                displayStudentInfo(foundStudent);
                break;
            }
            case 2:{
                string name,id,address;
                float cgpa;
                cout<<"Enter student name: ";
                cin.ignore();
                getline(cin,name);
                cout<<"Enter student ID: ";
                cin>>id;
                cout<<"Enter address: ";
                cin.ignore();
                getline(cin, address);
                cout<<"Enter CGPA: ";
                cin>>cgpa;
                addStudent(head, name, id, address, cgpa);
                cout << "Student information added successfully!" << endl;
                break;
            }
            case 3:{
                sortStudentsByID(head);
                displayAllStudents(head);
                break;
            }
            case 4:{
                deleteStudentList(head);
                cout<<"Exiting the program. Goodbye!"<<endl;
                break;
            }
            default:
                cout<<"Invalid choice! Please try again."<<endl;
        }
    }
    return 0;
}
