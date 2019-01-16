import sys
import re

#Get version number as input from the user
version1 = input("Enter First version number to be compared: ")
version2 = input("Enter Second version number to be compared: ")

#Regular expression to check the version number format
val = re.compile('(\d+\.)?(\d+\.)?(\d+\.)?(\*|\d)$')

#Compare the input with respect to regular expression defined
check1 = val.match(version1)
check2 = val.match(version2)

#Check the format of the input
#If format is correct do nothing
#If format is wrong display an error message to used and exit from the program
if check1: 
    print("")
else:
    print("Oops..Wrong version format\nEnter version number in this format: d.d.d.d")
    sys.exit()

if check2:
    print("")
else:
    print("Oops..Wrong version format\nEnter version number in this format: d.d.d.d")
    sys.exit()
        

#Split the input with respect to dot
arg1 = version1.split(".")
arg2 = version2.split(".")

#Check the length of the list are if not equal to 4 then make the length as 4 by appending 0’s 
L1 = len(arg1)
while L1 != 4:
    L1 = len(arg1)+1
    arg1.append("0")

L2 = len(arg2)
while L2 != 4:
    L2 = len(arg2)+1
    arg2.append("0")

#Index variables
i = 0
j = 0

#Compare the numbers and if any of number is greater than other, print and quit. 
#If equal the check next number.
#For example: if input is 1.2 and 2.2 then 2.2 is greater irrespective of next number
while L1 == 4:
    if int(arg1[i]) > int(arg2[j]):
        print("Version one is greater than version two")
        break
    elif int(arg1[i]) < int(arg2[j]):
        print("Version one is lesser than version two")
        break
    else:
        i = i + 1
        j = j + 1
        if i == 4:
            print("Versions are equal")
            break
