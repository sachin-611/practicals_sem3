def partition(array,l,h):

    mid=(h+l)//2
    if(array[l]>array[mid]):
        array[mid],array[l]=array[l],array[mid]
    if(array[mid]>array[h]):
        array[mid],array[h]=array[h],array[mid]
    array[l],array[mid]=array[mid],array[l]

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


def updated_quick_sort(array,low,high):        #function to sort array using updated quick sort
    if(low<high):
        if(high-low>3):
            loc=partition(array,low,high)
            updated_quick_sort(array,low,loc-1)
            updated_quick_sort(array,loc+1,high)
        elif(high-low==3):
            if(array[low]>array[low+1]):
                array[low],array[low+1]=array[low+1],array[low]
            if(array[low+1]>array[high]):
                array[low+1],array[high]=array[high],array[low+1]
        elif(high-low==2):
            if(array[low]>array[high]):
                array[low],array[high]=array[high],array[low]

if __name__=="__main__":
    #input's
    n=int(input("Enter no of student : "))
    percentage=list(map(int,input("Enter percentage of students(space seperated) : ").split()))

    #calling funcstions to sort array
    print("\n\nSorting array using updated quick sort : ")
    updated_quick_sort(percentage,0,n-1)
    print("Array after sorting is : ",percentage)
