#include <iostream>
#include <string>
using namespace std;

class course
{
    string name;
    int units;
    public:
        void setCourseName(){
            cin>>name;
        }
        void setUnits(){
            cin>>units;
        }
        void getCourseName(){
            cout<<name;
        }
        void getUnits(){
            cout<<units;
        }
};
class student
{
    string name;
    float gpa;
    int number_of_courses;
    course *courses_array;
    public:
        student(){
            name="XYZ";
            gpa=0.0;
            number_of_courses=0;
        }
        void setCourseTaken(){
            cout<<"\nEnter number of courses taken:";
            cin>>number_of_courses;
            courses_array=new course[number_of_courses];
            for(int i=0;i<number_of_courses;i++){
                cout<<"\nEnter name of "<<i+1<<"th course:";
                courses_array[i].setCourseName();
                cout<<"\nEnter number of units in "<<i+1<<"th course:";
                courses_array[i].setUnits();
            }
        }
        void setData(){
            cout<<"Enter name of student:";
            cin>>name;
            cout<<"Enter gpa:";
            cin>>gpa;
            setCourseTaken();
        }
        void display()
        {
            cout<<"\n\n---------------------------------------------------\n\n";
            cout<<"Name of Student :"<<name;
            cout<<"\nGPA of "<<name<<" is :"<<gpa;
            cout<<"\nStudent opted for :\n";
            for(int i=0;i<number_of_courses;i++){
                cout<<"\ncourse "<<i+1<<" :\n";
                cout<<"Course Name:";courses_array[i].getCourseName();
                cout<<"\nNumber of units:";courses_array[i].getUnits();
                cout<<"\n";
            }
        }
    ~student(){
        delete courses_array;
    }
};
int main()
{
    student s1;
    s1.setData();
    s1.display();
    return 0;
}