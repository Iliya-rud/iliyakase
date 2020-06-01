/*№9 В файле data.dat задан двумерный массив целых чисел с различным
количеством элементов в каждой строке. Элементы массива задаются через
пробел. Ограничения на количество строк в массиве нет.
     Ввести двумерный массив из файла в массив в программе, отведя соответствующим образом память.
Определить, существуют ли в массиве элементы, равные среднему арифметическому элементов массива из строки,
содержащей данный элемент. Если существуют, то уничтожить из массива
все строки с найдеными элементами. Вывести в файл data.res полученный
двумерный массив.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void del_martix(int **, int, int *);
int intget(char *, int *);
void pr(FILE*, int **, int, int *);
char * lineget(FILE*);
int **matrixget(FILE*, int *, int **);
int task(int**matrix, int n, int *m);

char *lineget(FILE*in){
    static char *s;
    static int LMax;
    int begin = 0;
    if(!LMax){
        s = (char*)malloc(2);
        LMax = 2;
    }
    while(fgets(s+begin, LMax-begin, in)){
        begin = LMax - 1;
        if(strchr(s,'\n')){//указывает порядковый номер элемента '\n' начиная с единицы в строке s
            break;
        }
        LMax *=2;
        s = (char*)realloc(s, LMax);
        if(!s){
            return 0;
        }
    }
    if(begin == 0){
        free(s);
        return 0;
    }
    return s;
}

int intget(char *str, int *k){
    int pos = 0;
    if(sscanf(str, "%d%n", k, &pos)==1){//sscanf возвращает число успешно сосканированных символов
        return pos;//вернет индекс, где sscanf будет в строке str после завершения sscanf
    }
    if(sscanf(str, "%s", str)==1){//если в строке один символ (т. е. переход на другую строку)
        return -1;
    }
    return 0;
}

void del_matrix(int**matr_ix, int n, int *m){
    int i;
    for(i = 0; i<n; i++){
        free(matr_ix[i]);
    }
    free(matr_ix);
    free(m);
}

int **matrixget(FILE*in, int *n, int **m){
    int NMax = 1;
    int xt, pos;
    char *buf;
    int **matr = 0;
    int i=0, j;
    *m=0;
    while(buf = (lineget(in))){
        j = 0;
        if(i%NMax == 0){//это типа для редактирования матрицы и счетчика количества элементов
            NMax *=2;
            matr = (int**)realloc(matr, NMax*sizeof(int*));
            *m = (int*)realloc(*m,NMax*sizeof(int));
            }
        matr[i]=(int *)malloc(strlen(buf)*sizeof(int));
        while(pos=(intget(buf,&xt))){
            if(pos == -1){
                del_matrix(matr, i+1, *m);
                buf = lineget(in);
                if(buf){
                    free(buf);
                }
                return 0;
            }
            matr[i][j] = xt;
            j++;
            buf +=pos;//buf=buf+pos
        }
        (*m)[i] = j;
        i++;
    }
    *n = i;
    free(buf);
    return matr;
}

void pr(FILE*out, int **a, int n, int *m){//матрица в консоле
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<m[i]; j++){
            fprintf(out,"%d ",a[i][j]);
        }
        fprintf(out, "\n");
    }
}

int task(int**matrix,int n,int *m){// n - число всех строк в файле  //функция task вернет число удаленных строк
    int i=0;//i - номер строки, m[i]-число элементов строки номера i
    int S=0;//S - сумма элементов строки
    int s=0;//s - счетчик элементов в строке i
    int j=0;//j - счетчик (такой же как и s) элементов в строке i
    int p=0;//p - счетчик для сдвига строк
    int e=0;//e - счётчик на количество удалённых строк
    //printf("n=%d\r\n",n);
    for(i=0;i<n;i++){//пробег по строкам
        //printf("m[_%d_]=%d\r\n", i, m[i]);
        for(s=0;s<m[i];s++){//находим сумму элементов строки номера i
            S=S+matrix[i][s];//находим сумму элементов строки номера i
        }
        //printf("Summ string %d=%d\r\n",i ,S);
        for(j=0;j<m[i];j++){//пробег по строке слево на право
            //printf("tyt\r\n");
            //printf("m[_%d_]=%d\r\n", i, m[i]);
            //printf("j=%d\r\n",j);
            //printf("p=%d\r\n",p);
            //printf("s=%d\r\n",s);
            //printf("i=%d\r\n",i);
            //printf("S=%d\r\n",S);
            //printf("e=%d\r\n",e);
            //printf("matrix[%d][%d]=%d\r\n",i,j,matrix[i][j]);//вывод текущего элемента, который проходит проверку
            if(S==(m[i])*matrix[i][j]){//проверка на среднее арифметическое (см. условие)
                //printf("need del string %d\r\n",i);//вывод текущей строки
                /*сдвигаем все нижнее строчки наверх на 1, освобождаем, меняем размерность matrix*/
                //free(matrix[i]);//ПРАВИЛЬНО ЛИ ОСВОБОДИЛИ ПАМЯТЬ!?
                //free(m[i]);
                for(p=i; p+1<n; p++){// циклом сдвигаем выше на одну позицию все строки, находящиеся выше текущей
                    //printf("p=%d\r\n",p);
                    matrix[p]=matrix[p+1];
                    m[p]=m[p+1];
                    //printf("now there is a shift of %d string\r\n",p+1);//произошел сдвиг строк матрицы
                }
                //free(matrix[n-1]);
                //pr(stdout, matrix, n, m);
                n=n-1;
                e=e+1;//счётчик на количество удалённых строк
                i=i-1;
                //printf("e=%d\r\n",e);
                break;
            }
        }
        S=0;
    }
    return e;//вернет количество удаленных строк
}

void At1(void);
void At1(void){
    int **mix;
    int n=3;
    int *m;
    int g=0;
    mix = (int**)malloc(3 * sizeof(int*));
    for(int i = 0; i < 3; ++i){
        mix[i] = (int*)malloc(3 * sizeof(int));
        }
    m[0]=3;
    m[1]=3;
    m[2]=3;
    mix[0][0]=1;
    mix[0][1]=2;
    mix[0][2]=4;
    mix[1][0]=0;
    mix[1][1]=11;
    mix[1][2]=0;
    mix[2][0]=0;
    mix[2][1]=12;
    mix[2][2]=0;
    g=task(mix, n, m);
    pr(stdout, mix, n, m);
    int i;
    if(mix[0][0]==1&&mix[0][1]==2&&mix[0][2]==4&&mix[1][0]==0&&mix[1][1]==11&&mix[1][2]==0&&mix[2][0]==0&&mix[2][1]==12&&mix[2][2]==0){
        printf("AutoTest1 passed...\r\n");
        }
    else{
        printf("AutoTest1 failed!!!\r\n");
        }
    free(mix[0]);
    free(mix[1]);
    free(mix[2]);
    free(mix);
    return;
}

int main(void){
	At1();
    FILE* input_file;//input_file - указатель задекларировали типа FILE
    FILE* rez_file;
    int n, *m;
    int res=0;
    int**matrix;
    input_file = fopen("data.txt", "r");
    if(input_file == 0){
        printf("File input_file (data.txt) is not found\r\n");
        return -1;
    }
    else{
        //printf("decloration\r\n");
        //pr(FILE*out, matrix,n, m);
        matrix=matrixget(input_file,&n,&m);
    	if(!matrix){
            printf("Bad file\r\n");
    		return -1;
        }
        puts("Begin. In file 'data.txt':");
    	pr(stdout, matrix, n, m);
        res=task(matrix, n, m);
        //printf("n=%d\r\n",n);
        //printf("res=%d\r\n",res);
        if (res!=0){
            n=n-res;
        }
        //printf("n=%d\r\n",n);
    	puts("Result:");
        pr(stdout,matrix,n,m);
        rez_file= fopen("dataREZ.txt", "w");//выводим получившийся результат (массив arr) в файл data.rez
        if(!rez_file){
            printf("File rez_file (dataREZ.txt) is not found\r\n");
            return -1;
        }
        else{
            for(int i=0; i<n; i++){
                for(int j=0; j<m[i]; j++){
                    fprintf(rez_file ,"%d ", matrix[i][j]);
                }
                fprintf(rez_file,"\n");
            }
            del_matrix(matrix,n,m);
            fclose(input_file);
            fclose(rez_file);
            printf("The end of program!");
            return 0;
        }
    }
}
