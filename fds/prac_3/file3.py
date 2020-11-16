
def Merge(div_a,count_of_div_A,div_b,count_of_div_B):  # function to sort and merge the DOB of students of computer division A and division B
    combined={}
    i=0
    j=0
    while ((i < count_of_div_A) and (j < count_of_div_B)):
        for keyA in div_a:
            for keyB in div_b:

                if div_b[keyB][1] < div_a[keyA][1]:
                    combined[keyB] = div_b[keyB]
                    div_b.pop(keyB)
                    j += 1
                    break

                elif div_a[keyA][1] == div_b[keyB][1] and div_a[keyA][0] == div_b[keyB][0]:
                    combined[keyA] = div_a[keyA]
                    div_a.pop(keyA)
                    i += 1
                    combined[keyB] = div_b[keyB]
                    div_b.pop(keyB)
                    j += 1
                    break

                elif div_a[keyA][1] < div_b[keyB][1]:
                    combined[keyA] = div_a[keyA]
                    div_a.pop(keyA)
                    i += 1
                    break

                elif div_a[keyA][1] == div_b[keyB][1] and div_b[keyB][0] < div_a[keyA][0]:
                    combined[keyB] = div_b[keyB]
                    div_b.pop(keyB)
                    j += 1
                    break
                
                elif div_a[keyA][1] == div_b[keyB][1] and div_a[keyA][0] < div_b[keyB][0]:
                    combined[keyA] = div_a[keyA]
                    div_a.pop(keyA)
                    i += 1
                    break

                
                
            break

    if i < count_of_div_A:
        for keyA in div_a:
            combined[keyA] = div_a[keyA]
    elif j < count_of_div_B:
        for keyB in div_b:
            combined[keyB] = div_b[keyB]
    return combined



def input_class_detail(number_of_student):  #function for taking input details of student
    temp = dict()
    for i in range(number_of_student):
        print("Enter detail of student:")
        stud_detail=list(map(int,input().split()))
        prn = stud_detail[0]
        dob_list = []
        date=stud_detail[1]
        dob_list.append(date)
        month=stud_detail[2]
        dob_list.append(month)
        temp[prn] = dob_list
    return temp


#input

num_A = int(input("Enter the number of students in SE Computer Div A: "))
num_B = int(input("Enter the number of students in SE Computer Div B: "))

print("Enter the details of students in SE Computer Division A in the order: PRN, Date of Birth, Month of Birth: ")
div_A=input_class_detail(num_A)

print("Enter the details of students in SE Computer Division B in the order: PRN, Date of Birth, Month of Birth: ")
div_B=input_class_detail(num_B)


#output


List_SE_Comp_DOB= Merge(div_A,num_A,div_B,num_B)

print("\n The Merged and Sorted Information of Date of Births of Students :")
print("-----------------------")
print(" PRN \t Date \t Month")
for key in List_SE_Comp_DOB:
    print("",key,"\t",List_SE_Comp_DOB[key][0],"\t",List_SE_Comp_DOB[key][1])
print("-----------------------")