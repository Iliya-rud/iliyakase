//gcc CKK3Z.c -o CKK3Z.exe -std=c99
//№17  
/*Создать тип данных структура Student, содержащую поля: строка Name, целое Group, целое с номером школы, где 
учился студент, School. Для создания массива структур Student создать переменную типа Student*. Записать в 
файл соответствующие данные по студентам (по одному студенту в строке). Загрузить указанные данные в указанный 
массив структур. Перераспределить студентов по группам, чтобы студенты из одной группы, по возможности, 
заканчивали одинаковые школы. Вариант решения: за один проход для каждого студента с индексом в массиве i если 
у него в другой  группе есть одношкольник с индексом j>i, то ищем студента из группы студента i с индексом k>i, 
закончившего другую школу. Если таковые студенты найдены, то меняем местами группы студентов с индексами k и j. 
Вывести полученные данные по студентам в файл в том же формате, что и исходный файл.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef
struct Student_{
    char Name[256];
    int Group;
    int School;
}Student;

int Input(Student* Stud_array, FILE* file, int number_of_students);//приём и создание данных
int Output(Student* Stud_array, int number_of_students);//вывод данных в консоль
void alter(Student* Stud_array, int* number_of_students);//изменение

int Input(Student* Stud_array, FILE* file, int number_of_students){//приём и создание данных
    Student Tmp_student;
    int temp_Group = 0;
    char temp_Name[256];
    int temp_School = 0;

    for (int i = 0; i  < number_of_students; i++){

        fscanf(file, "%s", &temp_Name);
        fscanf(file, "%d", &temp_Group);
        fscanf(file, "%d", &temp_School);

        Stud_array[i].Group = temp_Group;
        Stud_array[i].School = temp_School;
        strcpy(Stud_array[i].Name, temp_Name);

    }
    return 0;
}

int Output(Student* Stud_array, int number_of_students){//вывод данных в консоль
    for (int i = 0; i < number_of_students; i++){
        printf("%s  %d  %d\n", Stud_array[i].Name, Stud_array[i].Group, Stud_array[i].School);
    }
    return 0;
}
void alter(Student* Stud_array, int* number_of_students){//изменение
	Student Temp_student;
	int* tmp_array_Group;//создали временнй массив с группами
	int* tmp_array_School;//создали временнй массив со школами
	int buff=-1;
	printf("%d\n", *number_of_students);

	tmp_array_Group = (int*)malloc(*number_of_students * sizeof(int));//создали временнй массив с группами
    for(int i = 0; i < *number_of_students; i++){
    	tmp_array_Group[i] = Stud_array[i].Group;
    	}

	tmp_array_School = (int*)malloc(*number_of_students * sizeof(int));//создали временнй массив со школами
    for(int i = 0; i < *number_of_students; i++){
    	tmp_array_School[i] = Stud_array[i].School;
    	}

	for(int i=0; i<*number_of_students; i++){//запустили пробег по школьникам
		for(int j=0; j<*number_of_students; j++){
			if((Stud_array[i].Group!=Stud_array[j].Group)&&(j>i)&&(Stud_array[i].School==Stud_array[j].School)){
				for(int k=0; k<*number_of_students; k++){
					if((Stud_array[i].Group==Stud_array[k].Group)&&(k>i)&&(Stud_array[i].School!=Stud_array[k].School)){
						buff = Stud_array[k].Group;
						Stud_array[k].Group=Stud_array[j].Group;
						Stud_array[j].Group = buff;
						}
					}
				}
			}
		}
	free(tmp_array_Group);
	free(tmp_array_School);
	}

int main(void){
    FILE* input_file;
    Student* Stud_array;
    int number_of_students = 0;
    char count_temp[512];
    int* tmp_array;

    input_file = fopen("File.txt", "r");
    if (!input_file){
        printf("File 'File.txt' cannot be opened\r\n");
        exit(-1);
    }
    else{
	    while (fgets(count_temp, sizeof(count_temp), input_file) != NULL){
	        number_of_students++;//так нашли число студентов в файле!
	    }
	    printf("%d\n", number_of_students);
	    fseek(input_file, 0, 0);
	    Stud_array = (Student*)malloc(number_of_students*sizeof(Student));
	    if (Stud_array==NULL)
	    {
	        printf("Memory cannot be allocated\r\n");
	        return 1;
	    }
	    Input(Stud_array, input_file, number_of_students);
	    Output(Stud_array, number_of_students);//выводим массив до изменений
	    printf("\r\n");
	    alter(Stud_array, &number_of_students);//суть задачи
	    Output(Stud_array, number_of_students);//выводим массив после изменений в консоль
	    fclose(input_file);
	    free(Stud_array);
		}
    return 0;
}
