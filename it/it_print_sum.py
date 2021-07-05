import os
os.system('clear')

numList = input("Enter an array/list separated by space : ").split(" ")
print (numList)
print (numList[::-1])

sumList = list()

sumList = [int(x)+int(y) for x,y in zip(numList, numList[::-1])]

print(sumList)
print("\n")
