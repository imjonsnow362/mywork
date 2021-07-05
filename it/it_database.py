class student:    
    def add_record():
                a=list()
                print("Enter student ID-")
                id =int(input())
                print("Enter name-")
                name=input()
                print("Enter age-")
                age=int(input())
                print("Enter marks in Maths-")
                markmath=int(input())
                print("Enter marks in Science-")
                markscience=int(input())
                print("Enter marks in English-")
                markenglish=int(input())
                a=[markmaths,markscience,markenglish]
                return a
                
                
                
       
    def cal_record(math,science,english):
            total =math+science+english
            avg=total/3
            percentage=total/3
            if(m1>=50 and s1>=50 and e1>=50):
                print("status:Passed)")
            else:
                print("status:Fail")
            
            if(percentage>=75):
                print("Grade:A")
            if(percentage>=60 and percentage<75):
                print("Grade:B")
            if(percentage>=50 and percentage<60):
                print("Grade:C")
            if(percentage<50):
                 print("No Grade")
           
               
        
        
        
            
        
   
            
print("enter the number of students do u want to add:")
n=int(input())
for i in range(0,n):
    p=list()
    p=student.add_record()
    one,two,three=tuple(p)
    student.cal_record(one,two,three)
