import os
print("hi")
#Что больше: сумма элементов последовательности с четными значениями, или с нечетными?
#f = open("file.txt")
#n = int(f.readline())
#for i in xrangeeven=0
summE=0
summUNE=0
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
                f.close()
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
if summE>summUNE:
    print("the sum of even numbers is greater than odd numbers")
if summE<summUNE:
    print("the sum of odd numbers is greater than even numbers")
if summE==summUNE:
    print("the sum of even and odd numbers is the same")
f.close()
#res.write("")
