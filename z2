#include <stdio.h>
#include <string.h>

int search (const char *file_name, char *word);//наша функция поиска слова
int is_capital_letter (char c);// большая буква английского алфавита
int is_letter (char c);//большая или маленькая буква английского алфавита
int word_is_acceptable (const char *word);//слово приемлемо
void AT1(void);
void AT2(void);

int is_capital_letter (char c){//если буква большая, то возвращает 1, а иначе 0
  return ('A' <= c && c <= 'Z');
}

int is_letter (char c){//если это обычная буква английского алфавита, то вернёт 1, иначе 0
  return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

int word_is_acceptable (const char *word){//проверка слова на корректность (по условию оно должно начинаться с большой буквы)
  int len, i;// хранит то, что возвращает sizeof (вообще len т. е. length=длина) Переменные этого типа хронят
   //указатели. Применяется для счетчиков циклов, индексации массивов, хранения размеров. Можно сменить тип на size_t, если не работает
  if (!is_capital_letter (word[0])){
    return 0;//если первая буква слова не заглавная, то 0
  }
  len = strlen (word);
  for (i = 1; i < len; i++){
      if (!is_letter (word[i])){//если буква не из английского алфавита, то 0
        return 0;
      }
    }
  return 1;
}

void AT1(void){
    char p[]="AT1.txt";//имя файла для автотеста
    char mAT1[512];
    char Ok[]="Ok";
    printf("AutoTest1 goooooooooooooooooooooooooooooooooooooooo\r\n");
    printf("word before function search:...%s...\r\n", mAT1);
    search(p, mAT1);
    printf("word after function search:...%s...\r\n", mAT1);
    if(strcmp(mAT1,Ok)==0){//сравнение
        printf("AutoTest1 passed...\r\n");
    }
    else{
        printf("AutoTest1 faled!!!\r\n");
    }
    printf("AutoTest1 eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeend\r\n");
}

void AT2(void){
    char pt[]="AT2.txt";//имя файла для автотеста
    char mAT2[512];
    char Okey[]="Okey";
    printf("AutoTest2 goooooooooooooooooooooooooooooooooooooooo\r\n");
    printf("word before function search:...%s...\r\n", mAT2);
    search(pt, mAT2);
    printf("word after function search:...%s...\r\n", mAT2);
    if(strcmp(mAT2,Okey)==0){//сравнение
        printf("AutoTest2 passed...\r\n");
    }
    else{
        printf("AutoTest2 faled!!!\r\n");
    }
    printf("AutoTest2 eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeend\r\n");
}


int search (const char *file_name, char *word){
  FILE *imput_file = 0;
  char buf[512];
  char min[512];
  char *token = 0, *line = 0;//инициализация и декларация указателей которые хранят адрес переемнных token и line
  int line_number = 0;//номер строки
  int min_length = 0, token_length = 0;//если не работает программа, то поставить тип size_t вместо int
  imput_file = fopen (file_name, "r");
  if (!imput_file){
    return -1;
  }
  memset (min, 0, 512 * sizeof(char));//функция, котороая заполняет строку min нулями от начала до конца (т. к. 512*sizeof(char)) memset(что, чем, сколько)
  while (fgets(buf, 512, imput_file)){//пока считываем из imput_file
      /*if (buf[strlen(buf) - 1] != '\n'){
        fprintf (stderr, "Warning: too long line!.................................\n");
      }*/
      line = buf;//запомнили всю строку не длинее 512 символов
      printf ("in function search line is:%s\r\n", line);
      //((пока строка разделяется)) 
      while (token = strtok(line, " \t\r\n")){// strtok(что нужно разбить, что является разделителем(в нашем случае пробел" " и табуляция"\t\r\n")) strtok вернет указатель на начало выделенной строки
          fprintf (stderr, "Line: %d, word(variable) \"%s\"\n", line_number + 1, token);
          if ((word_is_acceptable (token))==1){
              fprintf (stderr, "Accepted: %s\n", token);//Accepted=принятый (выводим то, что вернула strtok, т. е. слово)
              token_length = strlen (token);//запоминаем длинну слова, которое вернула strtok
              if (min_length == 0 || token_length < min_length){//собственно сам поиск минимального слова
                  strcpy (min, token);
                  min_length = token_length;
                }
              }
          line = 0;//зануляем строку
      }
      line_number++;
  }
  strcpy (word, min);//результат отработки алгоритвма закидываем в слово word
  printf ("in function search min is:...%s...\r\n", min);
  printf ("in function search word is:...%s...\r\n", word);
  fclose (imput_file);
  return 0;
}

int main (void){
  int result;
  char word[512];
  char file_name[]="txt.txt";
  AT1();
  AT2();
  result = search (file_name, word);
  if (result == -1){
    fprintf (stderr, "Cannot open file 'txt.txt'!\r\n");
    return 0;
  }
  printf ("Answer:\r\n");
  printf ("%s\n", word);
  return result;
}
