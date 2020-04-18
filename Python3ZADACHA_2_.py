#Количество различных элементов последовательности, значения элементов которой принадлежат множеству {1, 2, 3, 4, 5}
#Случай, когда в задаче слово различных имеет смысл "всех" (то есть условие верно для всех элементов последовательности)
#f = open("file.txt")
#n = int(f.readline())
#for i in xrange
r=0
b=0
s=0
with open("file.txt") as f:#эта конструкция позволяет не беспокоиться о закрытии файла
    for d in f:
        print("d =",d)
        r=1
        for i in d.split(' '):#таким образом указали пробел в качестве разделителя
            b=int(i)#теперь значение b целое
            #print("b =",b)
            if((b==1) or (b==2) or (b==3) or (b==4) or (b==5)):
                s=s+1
print("rez:")
if r==0:
    print("FILE WITHOUT NUMBERS!")
if r==1:
    print("ANSVER:")
    print("The number of sequence elements belonging to the set of {1, 2, 3, 4, 5} is ",s)
#res=open("result.txt", "w")
#res.write("")
#res.close
