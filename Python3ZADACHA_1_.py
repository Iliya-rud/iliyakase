print("hi")#Количество различных элементов последовательности, значения элементов которой принадлежат множеству {1, 2, 3, 4, 5}
#Случай, когда в задаче слово различных имеет смысл "отличающихся" (то есть отличающихся)
#f = open("file.txt")
#n = int(f.readline())
#for i in xrange
r=0
b=0
b1=0
b2=0
b3=0
b4=0
b5=0
s=0
with open("file.txt") as f:#эта конструкция позволяет не беспокоиться о закрытии файла
    for d in f:
        print("d =",d)
        r=1
        for i in d.split(' '):#таким образом указали пробел в качестве разделителя
            b=int(i)#теперь значение b целое
            #print("b =",b)
            if((b==1) and (b1==0)):
                s=s+1
                b1=1
            if((b==2) and (b2==0)):
                s=s+1
                b2=1
            if((b==3) and (b3==0)):
                s=s+1
                b3=1
            if((b==4) and (b4==0)):
                s=s+1
                b4=1
            if((b==5) and (b5==0)):
                s=s+1
                b5=1
print("rez:")

if r==0:
    print("FILE WITHOUT NUMBERS!")
if r==1:
    print("ANSVER:")
    print("The number of sequence elements belonging to the set of {1, 2, 3, 4, 5} is ",s)
#res=open("result.txt", "w")
#res.write("")
#res.close
