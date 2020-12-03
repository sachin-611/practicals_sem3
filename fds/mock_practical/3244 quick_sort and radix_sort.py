import math
def partition(arr,l,h):
    if(l>=h):
        return;
    pivot=arr[l]
    i=l
    j=h
    while(i<j):
        while(arr[i]<=pivot and i<h):
            i+=1
        while(arr[j]>pivot and j>l):
            j-=1
        if(i<j):
            arr[i],arr[j]=arr[j],arr[i]
    arr[l],arr[j]=arr[j],arr[l]
    return j

def quick_sort(arr,l,h):
    if(l<h):
        indx=partition(arr,l,h)
        quick_sort(arr,l,indx-1)
        quick_sort(arr,indx+1,h)

def manupulate(arr,value,n):
    bucket=[[],[],[],[],[],[],[],[],[],[]]
    ind=pow(10,value)
    for i in range(n):
        digit=((arr[i]%ind)//(ind//10))
        bucket[digit].append(arr[i])
    k=0
    for i in range(0,10):
        if(len(bucket[i])>0):
            for j in bucket[i]:
                arr[k]=j
                k+=1

def radix_sort(arr,n):
    max_element=arr[0]
    for i in range(n):
        max_element=max(max_element,arr[i])
    times=math.ceil(math.log10(max_element))
    for i in range(times):
        manupulate(arr,i+1,n)

if __name__ == "__main__":
    n=int(input("Enter number of elements : "))
    arr=list(map(int,input().split()))
    quick_sort(arr,0,n-1)
    print("sorted using quick sort : ",arr)
    n=int(input("Enter number of elements : "))
    arr=list(map(int,input().split()))
    radix_sort(arr,n)
    print("sorted using radix sort : ",arr)
