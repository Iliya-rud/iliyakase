import os
#Количество различных элементов последовательности, значения элементов которой принадлежат множеству {1, 2, 3, 4, 5}
#Случай, когда в задаче слово различных имеет смысл "всех" (то есть условие верно для всех элементов последовательности)
#f = open("file.txt")
#n = int(f.readline())
#for i in xrange
print("hi")
b=0
s=0
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
        for i in d.split(' '):#таким образом указали пробел в качестве разделителя
            b=int(i)#теперь значение b целое
            #print("b =",b)
            if((b==1) or (b==2) or (b==3) or (b==4) or (b==5)):
                s=s+1
print("rez:")
print("ANSVER:")
print("The number of sequence elements belonging to the set of {1, 2, 3, 4, 5} is ",s)
#res=open("result.txt", "w")
#res.write("")
#res.close

