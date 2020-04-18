print("hi")
#Что больше: сумма элементов последовательности с четными значениями, или с нечетными?
#f = open("file.txt")
#n = int(f.readline())
#for i in xrange
r=0
summE=0
summUNE=0
with open("file.txt") as f:#эта конструкция позволяет не беспокоиться о закрытии файла
    for d in f:
        print("d =",d)
        r=1
        for i in d.split(' '):#таким образом указали пробел в качестве разделителя
            b=int(i)#теперь значение b является целым
            print("b =",b)
            if b%2==0:
                summE=summE+b
                print("summE =",summE)
            if b%2==1:
                summUNE=summUNE+b
                print("summUNE =",summUNE)
print("rez:")
print("summE =",summE)
print("summUNE =",summUNE)
if r==0:
    print("FILE WITHOUT NUMBERS")
if r==1:
    if summE>summUNE:
        print("the sum of even numbers is greater than odd numbers")
    if summE<summUNE:
        print("the sum of odd numbers is greater than even numbers")
    if summE==summUNE:
        print("the sum of even and odd numbers is the same")
#res=open("result.txt", "w")
#res.write("")
#res.close
