#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void del_martix(int **, int, int *);
int intget(char *, int *);
void pr(FILE*, int **, int, int *);
char * lineget(FILE*);
int **matrixget(FILE*, int *, int **);
int task(int**matrix, int n, int *m);
void del_string(int**matrix, int *n, int *m, int x);

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
        if(strchr(s,'\n')){
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
    if(sscanf(str, "%d%n", k, &pos)==1)
        return pos;
    if(sscanf(str, "%s", str)==1)
        return -1;
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
    printf("printf1\r\n");
    while(buf = lineget(in)){
        j = 0;
        if(i%NMax == 0){
            NMax *=2;
            printf("printf2\r\n");
            matr = (int**)realloc(matr, NMax*sizeof(int*));
            printf("printf3\r\n");
            *m = (int*)realloc(*m,NMax*sizeof(int));
            printf("printf4\r\n");
            }
        matr[i]=(int *)malloc(strlen(buf)*sizeof(int));
        while(pos=intget(buf,&xt)){
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
    printf("kyky_end\r\n");
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

int task(int**matrix,int n,int *m){
    int i,S,s,j,p,f=0;
    int e=0;
    for(i=0;i<n;i++){
        for(s=0;s<m[i];s++){//находим сумму элементов строки номера i
            S=S+matrix[i][s];//находим сумму элементов строки номера i
        }
        printf("Summ string %d=%d\n",i ,S);
        printf("m[%d]=%d\n",i,m[i]);
        printf("nado tyt!!\r\n");
        for(j=0;j<m[i];j++){//проходим по строке
            printf("tyt\r\n");
            printf("matrix[%d][%d]=%d\n",i,j,matrix[i][j]);
            if((S==(m[i])*matrix[i][j])&&(f==0)){
                printf("need del string %d\r\n",i);
                /*сдвигаем все нижнее строчки наверх на 1
                освобождаем
                меняем размерность matrix*/
                free(matrix[i]);
                for(p=i;p<n;p++){
                    printf("_n=%d\n",n);
                    printf("p=%d\n",p);
                    matrix[p]=matrix[p+1];
                    m[p]=m[p+1];
                    printf("fffffffffffffffffffff\r\n");
                }
                printf("ff\r\n");
                //free(matrix[n-1]);
                n=n-1;
                e=e+1;//счётчик на количество удалённых строк
                f++;//счётчик на количество средних арифметических в строке
                i=i-1;
                printf("e=%d\n",e);
                printf("fff\r\n");
            }
        }
        S=0;f=0;
    }
    return e;
}

void At1(void);
void At1(void){
	FILE* i_f;
	int **mtx;
	int x, *y;
	printf("AutoTest1\r\n");
    int rz;
	i_f = fopen("At1.txt", "r");
	printf("AutoTest1ddd\r\n");
	mtx=matrixget(i_f,&x,&y);
	printf("AutoT1\r\n");
	fclose(i_f);
	rz=task(mtx, x, y);
    printf("rz=%d\r\n",rz);
    if (rz!=0){
        x=x-rz;
    }
    printf("AutoTest///1\r\n");
    //pr(stdout,mtx,x,y);
    if((mtx[0][0]==2)&&(mtx[0][1]==4)&&(mtx[1][0]==55)&&(mtx[1][1]==2)&&(mtx[2][0]==3)&&(mtx[2][1]==3)&&(mtx[2][2]==2)){
    	printf("AutoTest1 passed...\r\n");
    }
    else{
    	printf("AutoTest1 failed!!!\r\n");
    }
    del_matrix(mtx,x,y);
	return;
}

int main(void){
	At1();
    FILE* input_file;//input_file - указатель задекларировали типа FILE
    FILE* rez_file;
    input_file = fopen("dataTXT.txt", "r");
    int n, *m;
    int res;
    int**matrix;
    printf("decloration\r\n");
    if(input_file == 0){
        printf("File input_file (data.txt) is not found\n");
        return -1;
    }
    matrix=matrixget(input_file,&n,&m);
	fclose(input_file);
	if(!matrix){
        printf("Bad file\n");
		return -1;
    }
    puts("Begin:");
	pr(stdout,matrix,n,m);
    printf("iiii\r\n");
    res=task(matrix, n, m);
    printf("res=%d\r\n",res);
    if (res!=0){
        n=n-res;
    }
    printf("n=%d\n",n);
	puts("Result:");
    pr(stdout,matrix,n,m);
    rez_file= fopen("dataREZ.txt", "w");//выводим получившийся результат(массив arr) в файл data.rez
    if(rez_file == 0){
        printf("File rez_file (dataREZ.txt) is not found\r\n");
        return -1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m[i]; j++){
            fprintf(rez_file ,"%d ", matrix[i][j]);
        }
        fprintf(rez_file,"\n");
    }
    fclose(rez_file);
    printf("SUCSESS!!!");
    del_matrix(matrix,n,m);
    return 0;
}
