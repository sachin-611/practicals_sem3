def average(marks,student,num):
    avg=0
    for mark in marks:
        if(mark!=num):
            avg+=mark
        else:
            student-=1
    avg/=student
    return avg

def highest(marks):
    max_num=marks[0]
    for mark in marks:
        if max_num<mark:
            max_num=mark
    return max_num

def count_absent(marks,student,n):
    absent=0
    for mark in marks:
        if mark==n:
            absent+=1;
    return absent

def highest_frequency(marks,student):
    dup=[0]*101
    for mark in marks:
        if (mark>=0):
            dup[mark]+=1
    max_freq=0
    mark_with_freq=0
    for freq in range(0,101):
        if freq>max_freq:
            max_freq=freq
            marks_with_freq=dup[freq]
    return marks_with_freq

def result_of_subject(marks,student,pass_mark):
    result=0
    for mark in marks:
        if mark>pass_mark:
            result+=1
    result/=student
    result*=100
    return result

student=int(input("Enter Total No of Student:")) #input of total students
marks=[] #array containing all marks
max_marks=100 #total marks
num=40 #passing marks
print("Enter marks of student use -1 for absent student:")
for i in range(1,student+1):     #input of marks
    temp=int(input("Enter marks of Student:"))
    marks.append(temp)
print("highest marks of class is :",highest(marks))                         #printing highest marks
print("Average marks of class is :",average(marks,student,-1))                      #printing average marks
print("Total number of students absent :",count_absent(marks,student,-1))           #printing total no of absent student
print("marks with hightest frequency :",highest_frequency(marks,student)) #printing highest frequency marks
print("Result of class is :",result_of_subject(marks,student,num),"%")                  #printing average marks
