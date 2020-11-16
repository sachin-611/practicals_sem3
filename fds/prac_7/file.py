import math


def prefix_sum(array):
    for i in range(1,len(array)):
        array[i]=array[i]+array[i-1]
    return array

def shift(array):
    for i in range (len(array)-1,0,-1):
        array[i]=array[i-1]
    array[0]=0
    return array

def counting_sort(array,pwr):
    c=[0,0,0,0,0,0,0,0,0,0]
    for i in range(len(array)):
        dig=(array[i]%pow(10,pwr))//pow(10,pwr-1)
        c[dig]+=1
    c=prefix_sum(c)
    c=shift(c)
    temp=array.copy()
    for i in range(len(array)):
        dig=(array[i]%pow(10,pwr))//pow(10,pwr-1)
        temp[c[dig]]=array[i]
        c[dig]+=1
    return temp

def radix_sort_using_counting_sort(array):    #function to sort array using radix sort (counting sort method)
    maxo=array[0]
    for i in range(1,len(array)):
        if(maxo<array[i]):
            maxo=array[i]
    maxo=math.ceil(math.log10(maxo))
    for i in range(1,maxo+1):
        array=counting_sort(array,i)
        print("Array after",i,"th pass is : ",array)

    print("Array after sorting is : ",array)

def calculation(array,val):
    bucket=[[],[],[],[],[],[],[],[],[],[]]
    place=pow(10,val)
    less_place=pow(10,val-1)
    for i in range(len(array)):
        digit=array[i]%place//less_place
        bucket[digit].append(array[i])
    temp=[]
    for j in range(0,10):
        if(len(bucket[j])!=0):
            for i in range (len(bucket[j])):
                temp.append(bucket[j][i])
    return temp

def radix_sort(array):                         #function to sort array using radix sort (bucket method)
    maxo=array[0]
    for i in range(1,len(array)):
        if(maxo<array[i]):
            maxo=array[i]
    maxo=math.ceil(math.log10(maxo))

    for i in range(1,maxo+1):
        array=calculation(array,i)
        print("Array after",i,"th pass is : ",array)

    print("Array after sorting is : ",array)

def partition(array,l,h):
    if l>=h:
        return
    pivot=array[l]
    start=l
    end=h
    while(start<end):
        while(pivot>=array[start] and start<h):
            start+=1
        while(pivot<array[end] and end>l):
            end-=1
        if(start<end):
            array[start],array[end]=array[end],array[start]
    array[l],array[end]=array[end],array[l]
    print("Array in ith pass is : ",array[l:h+1])
    return end


def quick_sort(array,low,high):        #function to sort array using quick sort
    if(low<high):
        loc=partition(array,low,high)
        quick_sort(array,low,loc-1)
        quick_sort(array,loc+1,high)

if __name__=="__main__":   
    #input's
    n=int(input("Enter no of student : "))
    percentage=list(map(int,input("Enter percentage of students(space seperated) : ").split()))

    #calling funcstions to sort array
    print("Sort array using radix sort (counting sort method) : ")
    radix_sort_using_counting_sort(percentage)
    print("\n\nSorting array using radix sort (bucket method) : ")
    radix_sort(percentage)
    print("\n\nSorting array using quick sort : ")
    quick_sort(percentage,0,n-1)
    print("Array after sorting is : ",percentage)
