import os
print("hi")
#Каких элементов последовательности больше: с четными значениями, или с нечетными?
even=0
uneven=0
filename = "file.txt"
err_code =0
def CheckFile(filename):#проверка файла на наличие открытия
    try:
        if (os.stat(filename).st_size >= 0):
            print("File opened successfully")
            f = open(filename, "r")
            check_string = f.read()
            if (len(check_string) == 0):
                print("Error, empty file")
                f.close()#41
                raise Exception("Empty file exception")#выдаст ошибку, если файл пуст (переходит в указанное исключение)
            f.close()
            return 0
    except Exception:#кроме #исключение
        print("Error: cannot open file, or file is empty")
        return 1
err_code = CheckFile(filename)
if err_code !=0:
    exit()

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
f.close()
#res.write("")
