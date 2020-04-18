print("hi")
#Каких элементов последовательности больше: с четными значениями, или с нечетными?
#f = open("file.txt")
#n = int(f.readline())
#for i in xrange
even=0
uneven=0
r=0
with open("file.txt") as f:#эта конструкция позволяет не беспокоиться о закрытии файла
    for d in f:
        print("d =",d)
        r=1
        print ()
        for i in d.split(' '):#таким образом указали пробел в качестве разделителя
            b=int(i)
            print("b =",b)
            if b%2==0:
            	even += 1
            	print("even =",even)
            if b%2==1:
            	uneven += 1
            	print("uneven =",uneven)
print("rez:")
print("even =",even)
print("uneven =",uneven)
if r==0:
    print("FILE WITHOUT NUMBERS")
if r==1:
    if even>uneven:
        print("EVEN")
    if even<uneven:
        print("UNEVEN")
    if even==uneven:
        print("EQUALLY")
#res=open("result.txt", "w")
#res.write("")
#res.close
