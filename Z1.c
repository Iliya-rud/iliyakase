#include <stdio.h>
#include <stdlib.h>
int print(const char* filenameP);//до сих работает без учёта особого выделения памяти для массива, короче функция тапа пока табочая
int Ker(int **arr, int str2, int stl2);
void AutoTest1(void);
void AutoTest2(void);
int Ker(int **arr, int str2, int stl2){
    FILE *fout;
    int a=9;
    int summ=0;
    int e=10;
    printf("Before (in Ker):\r\n");
    for(int i=0; i<str2; i++){//выводим массив, который поступил в функцию
        for(int j=0; j<stl2; j++){
            printf("%d ", arr[i][j]);
            }
        printf("\r\n");
        }
    for(int i=0; i<str2; i++){
        for(int j=0; j<stl2; j++){
            summ=summ + arr[i][j];//найдем сумму элементов в строке i
            }
        printf("summ=%d;\r\n", summ);
        for(int p=0; p<stl2; p++){
            printf("...\r\n");
            if((arr[i][p])*(stl2)==summ){
                e=1;
                for(a=i; a<str2-1; a++){//удаляем строку
                    for(int j=0; j < stl2; j++){
                        printf("a=%d;\r\n", a);
                        arr[a][j]=arr[a+1][j];
                        }
                    }
                printf("stroka=%d;\r\n", i+1);
                printf("element=%d;\r\n", arr[i][p]);
                printf("sucsess;\r\n");
                free(arr[str2-1]);
                arr=(int**)realloc(arr, (str2-1)*sizeof(int*));
                printf("After(yes changes):\r\n");
                for(int i=0; i<str2-1; i++){//выводим получившийся массив в консоль
                    for(int j=0; j<stl2; j++){
                        printf("%d ", arr[i][j]);
                        }
                    printf("\r\n");
                    }
                fout = fopen("dataREZ.txt", "w");//выводим получившийся результат(массив arr) в файл data.rez
                for(int i=0; i<str2-1; i++){
                    for(int j=0; j<stl2; j++){
                        fprintf(fout ,"%d ", arr[i][j]);
                        }
                    fprintf(fout,"\n");
                    }
                fclose(fout);
                printf("SUCSESS!!!\r\n");
                return e;
                }
            }
        summ=0;
        }
    printf("After(no changes):\r\n");
    for(int i=0; i<str2; i++){//выводим получившийся массив в консоль
        for(int j=0; j<stl2; j++){
            printf("%d ", arr[i][j]);
            }
        printf("\r\n");
        }
    e=2;
    return e;
    }
int print(const char* filenameP){
    FILE* input_file;
    FILE *fout;
    int str=0;
    int stl=0;
    int** arr;
    input_file = fopen(filenameP, "r");
    if (!input_file){
        printf("Cannot open file data.txt\r\n");
        return 0;
        }
    fscanf(input_file, "%d", &str);
    fscanf(input_file, "%d", &stl);
    printf("_____________\r\n");
    printf("print begin:\r\n");
    printf("str=%d_____;\r\n", str);//размерность строки считали
    printf("stl=%d_____;\r\n", stl);//Размерость столбца считали
    //int arr[str][stl];//завели массив (в СИ 2011)
    arr=(int**)malloc((str)*sizeof(int*));
    for(int i=0; i<str; i++){
        arr[i]=(int*)malloc((stl)*sizeof(int));
        for(int j=0; j<stl; j++){
            fscanf(input_file, "%d" ,&(arr[i][j]));//заплонили его элементами из файла
            }
        }
    fclose(input_file);//здесь получили массив с которым работаем
    printf("Before:\r\n");
    for(int i=0; i<str; i++){//выводим массив, который был в файле, в консоль до его изменения
        for(int j=0; j<stl; j++){
            printf("%d ", arr[i][j]);
            }
        printf("\r\n");
        }
    printf("OK\r\n");//здесь начинаем работать с массивом, который получили
    if(Ker(arr, str, stl)==1){
        printf("After (in function print_1(e==1)):\r\n");
        printf("Answer:\r\n");
        for(int i=0; i<str-1; i++){//выводим новый массив из файла в консоль
            for(int j=0; j<stl; j++){
                printf("%d ", arr[i][j]);
                }
            printf("\r\n");
            }
        for(int i=0; i<str-1; i++){
            free(arr[i]);
            arr[i]=NULL;
            }
        free(arr);
        }
    else if(Ker(arr, str, stl)==2){
        printf("After (in function print_2(e==2)):\r\n");
        printf("Answer:\r\n");
        for(int i=0; i<str; i++){//выводим новый массив из файла в консоль
            for(int j=0; j<stl; j++){
                printf("%d ", arr[i][j]);
                }
            printf("\r\n");
            }
        fout = fopen("dataREZ.txt", "w");//выводим получившийся результат(массив arr) в файл data.rez
        for(int i=0; i<str; i++){
        	for(int j=0; j<stl; j++){
        		fprintf(fout ,"%d ", arr[i][j]);
                }
            fprintf(fout, "\n");
            }
        fclose(fout);
        printf("SUCSESS!!!\r\n");
        for(int i=0; i<str; i++){
            free(arr[i]);
            arr[i]=NULL;
            }
        free(arr);
        }
    return 0;
    }

void AutoTest1(void){
    int o=0;
    int** mass1;
    mass1=(int**)malloc((3)*sizeof(int*));
    for(int i=0; i<3; i++){
        mass1[i]=(int*)malloc((2)*sizeof(int));
        for(int j=0; j<2; j++){
            mass1[i][j]=o+1;
            o=o+1;
            }
        }
    Ker(mass1, 3, 2);
    if(mass1[0][0]==1 && mass1[0][1]==2 && mass1[1][0] == 3 && mass1[1][1]==4 && mass1[2][0]==5 && mass1[2][1] == 6){
        printf("AutoTest1 passed...\r\n");
    }
    else{
        printf("AutoTest1 failed!!!\r\n");
    }
    for(int i=0; i<3; i++){
        free(mass1[i]);
        mass1[i]=NULL;
        }
    free(mass1);
}

void AutoTest2(void){
    int** mass2;
    mass2=(int**)malloc((2)*sizeof(int*));
    mass2[0]=(int*)malloc((3)*sizeof(int));
    mass2[1]=(int*)malloc((3)*sizeof(int));
    mass2[0][0]=4;
    mass2[0][1]=1;
    mass2[0][2]=7;
    mass2[1][0]=9;
    mass2[1][1]=1;
    mass2[1][2]=3;
    Ker(mass2, 2, 3);
    printf("After:\r\n");
    for(int i=0; i<1; i++){//выводим новый массив из файла в консоль
        for(int j=0; j<3; j++){
            printf("%d ", mass2[i][j]);
            }
        printf("\r\n");
        }
    if(mass2[0][0]==9 && mass2[0][1]==1 && mass2[0][2] == 3){
        printf("AutoTest2 passed...\r\n");
    }
    else{
        printf("AutoTest2 failed!!!\r\n");
    }
    for(int i=0; i<1; i++){
        free(mass2[i]);
        mass2[i]=NULL;
        }
    free(mass2);
}

int main(void){
    AutoTest1();
    AutoTest2();
    print("data.txt");
    return 0;
}
