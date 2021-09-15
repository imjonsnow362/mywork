str = input('Enter the string: ')
count = 0
str=str.replace(","," ")
print(str)
for i in str:
    if i == ' ':
        count = count+1
print('Number of words are:',count+1)
