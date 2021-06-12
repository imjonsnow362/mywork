//main.sh

#/!/bin/bash
 exit=0
 while [ $exit -ne 1 ]
 do
 echo " "
 echo "What operation do you want?"
 echo -e "1.add\n2.list\n3.find\n4.del\n5.update\n6.exit: "
 read answer
 if [ "$answer" = "1" ]
 then
 ./insert.sh
 elif [ "$answer" = "2" ]
 then
 ./disp.sh
 elif [ "$answer" = "3" ]
 then
 ./search.sh
 elif [ "$answer" = "4" ]
 then
 ./del.sh
 elif [ "$answer" = "5" ]
 then
 ./update.sh
 elif [ "$answer" = "6" ]
 then
 exit=1
 else
 echo "Enter correct choice."
 fi
 done
 exit 0
 
 



//insert.sh

#!/bin/bash
echo -e "\nINSERT:"
echo -n "Enter the name: "
read name
echo -n "Enter the phone number: "
read phone
echo -e "$name\t$phone" >> contacts.txt






//disp.sh

#!/bin/bash
echo -e "\nALL RECORDS:"
echo -e "Name\tPhone no."
cat contacts.txt





//search.sh

#!/bin/bash
echo -e "\nSEARCH:"
echo -n "Enter the name to search: "
read query
retval=$(grep -i "$query" contacts.txt)
if [ -n "$retval" ]; then
echo -e "\n$retval\n"
else
echo "Sorry, $query not found."
fi




//del.sh

#!/bin/bash
echo "Please input Name to delete:"
read name
sed "/$name/d" contacts.txt > contacts_tmp.txt
rm contacts.txt
mv contacts_tmp.txt contacts.txt
echo "$name is removed from your contacts"





//update.sh

#!/bin/bash
echo -n "What person or number are you seeking: "
 read find
 # Print the header before the answer
 if grep -qF "$find" contacts.txt; then
 echo "Found it"

 else
 echo "Sorry Record not found"
 fi

 echo "Name ; Phone number"
 grep -i $find contacts.txt

 echo -n "Enter New name: "
 read new_name

 sed -i "s/$find/$new_name/g" contacts.txt





