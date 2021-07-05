import pandas as pd

def read(fname):
    try:
        file=open(fname)
    except:
        print("The file doesn't exist, Please check again")
    else:
        for line in file:
            print(line.rstrip())
        file.close()

def write(fname):
    try:
        file=open(fname,"a")
    except:
        print("The file doesn't exist, Please check again")
    else:
        print("Please start writing :\n")
        feed=input()
        file.write(feed)
        print("The content written successfully...")
        file.close()
        choice=input("Do you want to print the file content to console[y/n]: ")
        if choice in ("Y","y"):
            read(fname)
        file.close()

def csv_file(fname):
    try:
        df=pd.read_csv(fname)
    except:
        print("The file doesn't exist, Please check again")
    else:
        print(df.isnull().sum())
        



while True:
    print("\n-------------------------------------------------")
    choice=int(input(" 1.Read a file\n 2.make a new file and write to it\n 3.Write to an existing file(append)\n 4.Read and display CSV files using pandas\n 5.EXIT\nPlease choose an option: "))
    if(choice==5):
        break
    elif(choice in (1,2,3,4)):
        name=input("Please enter the filename: ")
        print("-------------------------------------------------")
        if(choice==1):
            read(name)
        elif(choice==2):
            write(name)
        elif(choice==3):
            write(name)
        elif(choice==4):
            csv_file(name)
    else:
        print("Please enter a valid choice")

