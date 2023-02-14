

def read(before,r):
    if r>0:
        nextt = input()
        read(nextt,r-1)
        print(before)
    else:
        print(before)

read("",5)