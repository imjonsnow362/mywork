
file = open("program.txt", "r")

ALP = []
for line in file:
    temp = []
    temp = line.split()
    #print(temp)
    ALP.append(temp)

MDT = {}
cnt = 0
MNT = {}

MName = False

start = False
i = 0
for line in ALP:
    i += 1
    #print(len(line))
    if MName:
        MNT[cnt] = line[0]
        MName = False

    elif line[0] == "MACRO" and len(line) > 1:

        MNT[cnt] = line[1]
    elif line[0] == "MACRO" and len(line) == 1:
        MName = True

    elif line[0] != "START" and line[0] != "MACRO":
        MDT[cnt] = line
        cnt += 1
    elif line[0] == "START" or start:
        break


print(MNT, end="\n ")

print(MDT, end="\n ")
