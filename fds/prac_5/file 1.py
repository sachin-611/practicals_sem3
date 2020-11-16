def linear_search(array,value):         #function for searching (using linear search) rollnumber of atttendee to check whether he/she was present or not in the training program
    for i in range(len(array)):
        if(array==value):
            return i
    return -1

def sentinal_search(array,value):       #function for searching (using sentinal search) rollnumber of attendee to check wheather he/she was present or not in the training program
    n=len(array)
    array.append(value)
    i=0
    while(array[i]!=value):
        i+=1
    array.pop()
    if(i!=n):
        return i
    return -1

def binary_search(array,value):         #function for searching (using binary search) rollnumber of attendee to check wheather he/she was present or not in the training program
    left=0
    right=len(array)-1
    while(left<=right):
        mid=int((left + right )/2)
        if(array[mid]==value):
            return mid
        if(array[mid]>value):
            right=mid-1
        else:
            left=mid+1
    return -1

def fibonacci_search(array,value):      #function for searching (using fibonacci search) rollnumber of attendee to check wheather he/she was present or not in the training program
    m2=0
    m1=1
    m=m1+m2
    while(m<len(array)):
        m2=m1
        m1=m
        m=m1+m2
    
    offset=0

    while(m2>0):
        i=min(offset+m2,len(array)-1)    
        if(array[i]==value):
            return i
        if(array[i]<value):
            offset+=m2
            m=m1
            m1=m2
            m2=m-m1
        if(array[i]>value):
            m=m2
            m1=m1-m
            m2=m-m1
    return -1

def input_array():                       #function for taking input of attendees of the training program
    attended=[]
    number_of_attendee=int(input("Enter number of attendee : "))
    for i in range(number_of_attendee):
        tep=int(input("Enter roll number of attendee:"))
        attended.append(tep)
    return attended
if __name__=="__main__":

    
    #input of attendees of training program
    attende=input_array()
        
    
    #search roll number using linear search
    rollnumber=int(input("Enter Roll number to be searched in attendance list(uses Linear search):"))
    answer=linear_search(attende,rollnumber)
    if(answer==-1):
        print(rollnumber,"did not attended training program")
    else:
        print(rollnumber,"attended the training program")
    
    
    #search roll number using sentinal search
    rollnumber2=int(input("Enter Roll number to be searched in attendance list(uses Sentinal search):"))
    answer1=sentinal_search(attende,rollnumber2)
    if(answer1==-1):
        print(rollnumber2,"did not attended training program")
    else:
        print(rollnumber2,"attended the training program")
    

    #search roll number using binary search
    attende.sort()
    rollnumber3=int(input("Enter Roll number to be searched in attendance list(uses Binary search):"))
    answer2=binary_search(attende,rollnumber3)
    if(answer2==-1):
        print(rollnumber3,"did not attended training program")
    else:
        print(rollnumber3,"attended training program")

    #search roll number using fibonacci search
    rollnumber4=int(input("Enter Roll number to be searched in attendance list(uses Fibonacci search):"))
    answer3=fibonacci_search(attende,rollnumber4)
    if(answer3==-1):
        print(rollnumber3,"did not attended training program")
    else:
        print(rollnumber3,"attended training program")
