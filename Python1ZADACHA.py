import os
print("hi")
#Каких элементов последовательности больше: с четными значениями, или с нечетными?
#f = open("file.txt")
#n = int(f.readline())
#for i in xrange
even=0
uneven=0
filename = "file.txt"
def CheckFile(file):#проверка файла на наличие открытия
    try:
        if (os.stat(file).st_size >= 0):
            print("File opened successfully")
            f = open(file, "r")
            check_string = f.read()
            if (len(check_string) == 0):
                print("Error, empty file")
                raise Exception("Empty file exception")#выдаст ошибку, если файл пуст
    except OSError:
        print("Error: cannot open file, or file is empty")
        raise Exception("No file in the directory")
    f.close()
CheckFile(filename)
with open("file.txt") as f:#эта конструкция позволяет не беспокоиться о закрытии файла
    for d in f:
        print("d =",d)
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
print("ANSVER:")
if even>uneven:
    print("EVEN")
if even<uneven:
    print("UNEVEN")
if even==uneven:
    print("EQUALLY")
#res=open("result.txt", "w")
#res.write("")
#res.close
