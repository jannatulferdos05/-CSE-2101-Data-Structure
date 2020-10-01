#include<iostream>
using namespace std;

class Student{
public:
    int s_Id; //Student id
    float CGPA;
    void SetData(int id,float c1,float c2,float c3){
        s_Id = id;
        CGPA = (c1+c2+c3)/3;
    }
};

int main()
{
    cout<<"Number of Students: ";
    int S_n; //S_n=Student Number
    cin>>S_n;
    Student students[S_n];

    int id;
    float c1,c2,c3;
    for(int i=0;i<S_n;i++){
        cout<<"\nStudent Id: ";;
        cin>>id;
        cout<<"Course 1 GPA: ";
        cin>>c1;
        cout<<"Course 2 GPA: ";
        cin>>c2;
        cout<<"Course 3 GPA: ";
        cin>>c3;
        students[i].SetData(id,c1,c2,c3);
    }
    Student temp;
    for(int i=0;i<S_n;i++){
        for(int j=i+1;j<S_n;j++){
            if(students[i].CGPA<students[j].CGPA){
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    cout<<"\nEnter Student ID for result:";
    int ResultId;
    bool y=false;
    cin>>ResultId;
    for(int i=0;i<S_n;i++){
        if(students[i].s_Id == ResultId){
            cout<<"\n\nCGPA of Student ID "<<ResultId<<" is "<<students[i].CGPA<<endl;
            cout<<"Merit position: "<<i+1;
            y=true;
        }
    }
    if(y==false){
        cout<<"Invalid ID "<<ResultId<<"!";
    }

}
