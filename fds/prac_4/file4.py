def input_matrix():                       # function to take matrix as input
    row1=int(input("\nEnter no of rows in Matrix : "))
    col1=int(input("Enter no of column in Matrix : "))
    matrix=[[0]*col1]*row1
    for i in range(row1):
        ls=list(map(int,input().split()))
        while(len(ls)!=col1):
            print("Enter",i+1,"th row again: ")
            ls=list(map(int,input().split()))
        matrix[i]=ls
    return matrix

def upper_triangular(matrix):               #function to check whether the matrix is upper triangular or not
    for i in range(1,len(matrix)):
        for j in range(0,i):
            if matrix[i][j]!=0:
                return False
    return True

def addition_of_matrix(matrix_a,matrix_b):  #function to calculate the summation of two matrix
    matrix=[]
    for i in range(len(matrix_a)):
        tam=[]
        for j in range(len(matrix_a[0])):
            tam.append(matrix_a[i][j]+matrix_b[i][j])
        matrix.append(tam)
    return matrix

def product_of_matrix(matrix_a,matrix_b):  #function to calculate the product of two matrix (if possible)
    result=[]
    for i in range(len(matrix_a)):
        te=[]  
        for j in range(len(matrix_b[0])):
            res=0
            for k in range(len(matrix_b)): 
                res += matrix_a[i][k] * matrix_b[k][j] 
            te.append(res)
        result.append(te)
    return result

def transpose_of_matrix(matrix): #function to calculate the transpose of the matrix
    temp=[]
    for i in range (len(matrix[0])):
        t=[]
        for j in range (len(matrix)):
            t.append(matrix[j][i])
        temp.append(t)
    return temp

def mini(array):                  #function to find the minimum of the array
    minimum=array[0]
    indx=0
    for i in range(len(array)):
        if(minimum>array[i]):
            indx=i
            minimum=array[i]
    return minimum,indx

def saddle_point(matrix):           #function to calculate saddle point if any exist
    for i in range(len(matrix)):
        minu,idx=mini(matrix[i])
        for j in range(len(matrix)):
            if(matrix[j][idx]>minu):
                ans=False
                break
            else:
                ans=True
        if(ans):    
            return i,idx
    return -1,-1

def diagonal_sum(matrix):             #function to calculate the diagonal sum (both principle and other diagonal sum)
    principal=0
    other=0
    for i in range(len(matrix)):
        principal+=matrix[i][i]
        other+=matrix[i][len(matrix)-1-i]
    return principal,other

def check_magic_square(matrix,val):    #function to check whether matrix is magic square or not
    for i in range(len(matrix)):
        row_sum=0
        col_sum=0
        for j in range(len(matrix)):
            row_sum+=matrix[i][j]
            col_sum+=matrix[j][i]
            if(matrix[i][j]<1 or matrix[i][j]>(len(matrix)*len(matrix))):
                return False
        if(row_sum!=val or col_sum!=val):
            return False
        
    return True



if __name__ == '__main__':
    #input 2 matrix
    matrix_1=input_matrix()
    matrix_2=input_matrix()

    #diagonal sum of Matrix 1
    if(len(matrix_1)!=len(matrix_1[0])):
        print("\nSum of Diagonals cannot be calculated as it is not square matrix")
    else:
        princi_dia_1,other_dia_1=diagonal_sum(matrix_1)
        print("\nSum of Principle Diagonal of Matrix 1 is",princi_dia_1," and sum of Other Diagonal of Matrix 1 is",other_dia_1)
    
    #diagonal sum of Matrix 2
    if(len(matrix_2)!=len(matrix_2[0])):
        print("\nSum of Diagonals cannot be calculated as it is not square matrix")
    else:
        princi_dia_2,other_dia_2=diagonal_sum(matrix_2)
        print("\nSum of Principle Diagonal of Matrix 1 is",princi_dia_2," and sum of Other Diagonal of Matrix 2 is",other_dia_2)


    # addition of two matrix
    if(len(matrix_1)!=len(matrix_2) or len(matrix_1[0])!=len(matrix_2[0])):
        print("\nThe given two matrix cannot be added as they dont have same no of rows or same no of column")
    else:
        sum_of_mat1_and_mat2=addition_of_matrix(matrix_1,matrix_2)
        print("\nMatrix formed by addition of Matrix 1 and Matrix 2 is:")
        for i in sum_of_mat1_and_mat2:
            print(i)


    #product of matrix 1 and matrix 2
    if(len(matrix_1[0])==len(matrix_2)):
        mat=product_of_matrix(matrix_1,matrix_2)
        print("\nMatrix produced by product of Given Matrix is : ")
        for i in mat:
            print(i)
    else:
        print("\nGiven Matrix cannot be multipied")


    #transpose of Matrix 1
    trans_mat_1=transpose_of_matrix(matrix_1)
    print("\nTranspose of amtrix 1 is : ")
    for i in trans_mat_1:
        print(i)

    #transpose of Matrix 2
    trans_mat_2=transpose_of_matrix(matrix_2)
    print("\nTranspose of matrix 2 is : ")
    for i in trans_mat_2:
        print(i)


    # matrix 1 is upper triangular of not
    if(len(matrix_1)==len(matrix_1[0]) and upper_triangular(matrix_1)):
        print("\nMatrix 1 is upper traingular matrix")
    else:
        print("\nMatrix 1 is not upper triangular matrix")

    # matrix 2 is upper triangular or not
    if(len(matrix_2)==len(matrix_2[0]) and upper_triangular(matrix_2)):
        print("\nMatrix 2 is upper traingular matrix")
    else:
        print("\nMatrix 2 is not upper triangular matrix")


    #check matrix 1 is magic square or not
    if(len(matrix_1)==len(matrix_1[0]) and princi_dia_1==other_dia_1 and check_magic_square(matrix_1,princi_dia_1)):
        print("\nWOW!! Matrix 1 is Magic square!!")
    else:
        print("\nMatrix 1 is not Magic square!!")

    #check matrix 2 is magic square or not
    if(len(matrix_2)==len(matrix_2[0]) and princi_dia_2==other_dia_2 and check_magic_square(matrix_2,princi_dia_2)):
        print("\nWOW!! Matrix 2 is Magic square!!")
    else:
        print("\nMatrix 2 is not Magic square!!")


    #find saddle point if exist in matrix 1
    i_co,j_co=saddle_point(matrix_1)
    if(i_co>=0 and j_co>=0):
        print("\nSaddle point is at position",i_co+1,j_co+1,"of matrix 1(where count start with 1)")
    else:
        print("\nSaddle point does not exist in matrix 1")
    
    #find saddle point if exist in matrix 2
    i_co1,j_co2=saddle_point(matrix_2)
    if(i_co1>=0 and j_co2>=0):
        print("\nSaddle point is at position",i_co1+1,j_co2+1,"of matrix 2(where count start with 1)")
    else:
        print("\nSaddle point does not exist in matrix 2")