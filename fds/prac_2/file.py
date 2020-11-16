#functions


def intersection(a,b):                      #fuction to calculate intersection of two set
    temp=[]
    for val in a:
        if val in b:
            temp.append(val)
    return temp

def both_cricket_and_badminton(a,b):        #function to calculate students who play both cricket and badminton
    both_cric_bady=intersection(a,b)
    return both_cric_bady

def both_cricket_and_football(a,c):         #function to calculate student who plays both cricket and football
    both_cric_fb=intersection(a,c)
    return both_cric_fb

def both_badminton_and_football(b,c):       #function to calculate student who plays both cricket and football
    both_bady_fb=intersection(b,c)
    return both_bady_fb

def play_all(both_cric_bady , both_bady_fb , both_cric_fb):    # function to calculate students who play all games i.e. cricket , football and badminton
    stud_all = [i for i in both_cric_bady if i in both_cric_bady and i in both_bady_fb and i in both_cric_fb]
    return stud_all

def either_cricket_or_badminton(a,b):       #funtion to calculate student who plays either cricket or badminton
    either_c_b = [i for i in a + b if i not in a or i not in b]
    return either_c_b

def neither_cricket_nor_badminton(total,a,b,both_cric_bady):   # fuction to calculate count of student who play neither cricket nor badminton
    count = total - len(a) -len(b) + len(both_cric_bady)
    return count

def both_cricket_and_football_but_not_badminton(total,c,both_cric_bady,both_bady_fb):  # function to calculate count of student who play both cricket and football but not badminton
    count = total - len(c) - len(both_cric_bady) - len(both_bady_fb)
    return count


#inputs


total = int(input("Total number of student in class:"))          #input of total no of students

cricket = input("Enter name of student playing cricket:")        #input of student who play cricket
a = cricket.split()

badminton = input("Enter the student playing badminton:")        #input of student who play badminton
b = badminton.split()

football = input("Enter the student playing football:")          #input of students who play football
c = football.split()


#outputs


cric_bady=both_cricket_and_badminton(a,b)
print("Students who play both cricket and badminton:",cric_bady)

bady_fb=both_badminton_and_football(b,c)
print("Students who play both badminton and football:",bady_fb)

cric_fb=both_cricket_and_football(a,c)
print("Students who play both cricket and football:",cric_fb)

print("Students who play all games:",play_all(cric_bady,bady_fb,cric_fb))

print("Students who play either cricket or badminton:",either_cricket_or_badminton(a,b))

print("Number of students who play neither circket nor badminton:",neither_cricket_nor_badminton(total,a,b,cric_bady))

print("Number of students who play both cricket and football but not badminton:",both_cricket_and_football_but_not_badminton(total,c,cric_bady,bady_fb))
