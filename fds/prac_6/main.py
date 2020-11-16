def bubble_sort(array):        #function to sort array using bubble sort
    swaps=0
    comparison=0
    for i in range(0,len(array)):
        for j in range(1,len(array)):
            if(array[j-1]>array[j]):
                swaps+=1
                temp=array[j]
                array[j]=array[j-1]
                array[j-1]=temp
            comparison+=1
        print("Array after ",i,"th pass is : ",array)
    print("Array after sorting is : ",array)
    print(swaps," number of swaps and",comparison," comparisons")

def selection_sort(array):       #function to sort using selection sort
    swaps=0
    comparison=0
    for i in range(len(array)):
        mini=-1
        for j in range(i,len(array)):
            if(mini==-1 or array[j]<array[mini]):
                mini=j
            comparison+=1
        swaps+=1
        temp=array[i]
        array[i]=array[mini]
        array[mini]=temp
        print("Array after ",i+1,"th pass is : ",array)
    print("Array after sorting is : ",array)
    print(swaps," number of swaps and",comparison," comparisons")

def insertion_sort(array):         #function to sort array using insertion sort
    comparison=0
    shift=0
    for i in range(1,len(array)):
        j=i-1
        val=array[i]
        while(j>=0 and val<array[j]):
            shift+=1
            comparison+=1
            array[j+1]=array[j]
            array[j]=val
            j-=1
        comparison+=1
        print("Array after ",i+1,"th pass is : ",array)
    print("Array after sorting is : ",array)
    print(shift," number of shift and",comparison," comparisons")

def shell_sort(array):            #function to sort the array using shell sort 
    gap = len(array)//2
    shift=0
    times=0
    comparison=0
    while gap > 0:
        times+=1
        for i in range(gap,len(array)):
            temp = array[i]
            j = i
            while  j >= gap and array[j-gap] >temp:
                array[j] = array[j-gap]
                j -= gap
                comparison+=1
                shift+=1
            array[j] = temp
            comparison+=1
        print("Array after ",times,"th pass is : ",array)
        gap = gap//2
    print("Array after sorting is : ",array)
    print(shift," number of shift and",comparison," comparisons")

def optimised_bubble_sort(array):    #function to sort the array using optimised bubble sort
    swaps=0
    comparison=0
    isSwap=True
    i=0
    while(isSwap and i<len(array)):
        isSwap=False
        for j in range(1,len(array)):
            if(array[j-1]>array[j]):
                swaps+=1
                isSwap=True
                temp=array[j]
                array[j]=array[j-1]
                array[j-1]=temp
            comparison+=1
        print("Array after ",i+1,"th pass is : ",array)
        i+=1
    print("Array after sorting is : ",array)
    print(swaps," number of swaps and",comparison," comparisons")

if __name__ == '__main__':
    #input
    no_of_student=int(input("Number of Student : "))
    percentage=[]
    for i in range(no_of_student):
        percentage.append(float(input("Enter percentage of student : ")))
    

    #Calling sorting functions

    # shell_sort(percentage)
    # bubble_sort(percentage)
    # optimised_bubble_sort(percentage)
    # insertion_sort(percentage)
    selection_sort(percentage)
