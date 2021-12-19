#include<stdio.h>
#include<stdlib.h>
#include"subj.h"

#define NUM_OF_MENU_ELEMENTS 15

const char * const TypeName[];

int main()
{
	List *list;
	int nodeCount;
	Node *element;
	Base *p;
	ItemType t;
	int index;
	int key;
	const char * const menu[NUM_OF_MENU_ELEMENTS + 1] =
        { "(none)", "Добавить в конец списка", "Вывести список", "Размер списка", "Найти узел по индексу", "Исключить узел", "Удалить узел", 
		"Получить индекс узла по адресу", "Вставить узел", "Очистить список", "Отсортировать по дальности движения", "Отсортировать по максимальной скорости", 
		"Вывести список адресов", "Найти по количеству мест", "Найти по максимальному весу", "Выход" };
	system("chcp 1251 > nul");
	
	list = CreateList();
	
	while(key != 15)
	{
		key = DoMenu(menu, NUM_OF_MENU_ELEMENTS);
		system("cls");
		
		switch(key)
		{
			case 1:
				printf("Какой вид транспорта добавить?\n");
				t = DoMenu(TypeName, 3);
          		p = Create(t);
          		printf("\nВведите данные транспорта:\n");
          		Input(p);
          		Add(list, (Node*)p);
				system("cls");
				if(t != 0)
					printf("Узел добавлен в конец списка.\n\n");
				else
					printf("Ошибка ввода.\n\n");
				break;
			case 2:	
				PrintTransportList(list);
				system("pause");				
				system("cls");
				break;
			case 3:
				nodeCount = Count(list);
				if(nodeCount < 0)
					nodeCount = 0;
				printf("Количество узлов в списке: %d\n\n", nodeCount);
				break;
			case 4:
				if(!list->head)
				{
					printf("Список пуст.\n\n");
					break;
				}
				
				printf("Узел под каким индексом вы хотите получить?\n> ");
				index = InputNumber(Count(list) - 1);
				printf("\n");
				
				element = GetItem(list, index);
				Print((Base*)element);
				system("pause");
				system("cls");
				break;
			case 5:
				if(!list->head)
				{
					printf("Список пуст.\n\n");
					break;
				}
				
				printf("Узел под каким индексом вы хотите исключить?\n> ");
				index = InputNumber(Count(list) - 1);
				
				Remove(list, index);
				system("cls");
				printf("Узел исключен.\n\n");
				break;
			case 6:
				if(!list->head)
				{
					printf("Список пуст.\n\n");
					break;
				}
				
				printf("Узел под каким индексом вы хотите удалить?\n> ");
				index = InputNumber(Count(list) - 1);
				
				Delete(list, index);
				system("cls");
				printf("Узел удален.\n\n");
				break;
			case 7: 
				if(!list->head)
				{
					printf("Список пуст.\n\n");
					break;
				}
				
				printf("Индекс узла под каким адресом вы хотите получить?\n> ");
				scanf("%p", &element);
				index = GetIndex(list, element);
				
				printf("Индекс элемента: %d\n\n", index);
				break;
			case 8:
				printf("В какое место вставить элемент?\n");
				index = InputNumber(Count(list));
				
				printf("Какой вид транспорта добавить?\n");
				t = DoMenu(TypeName, 3);
          		p = Create(t);
          		printf("\nВведите данные транспорта:\n");
          		Input(p);
          		Insert(list, (Node*)p, index);
				system("cls");
				printf("Узел добавлен в конец списка.\n\n");
				
				break;
			case 9:
				Clear(list);
				system("cls");
				printf("Список очищен.\n\n");
				break;
			case 10:
				SortByRangeOfMovement(list);
				system("cls");
				printf("Список отсортирован по дальности движения.\n\n");
				break;
			case 11:
				SortByMaxSpeed(list);
				system("cls");
				printf("Список отсортирован по максимальной скорости.\n\n");
				break;	
			case 12:
				PrintList(list);
				system("pause");
				system("cls");
				break;
			case 13:
				FindByMaxPassengerNumber(list);
				system("pause");
				system("cls");
				break;
			case 14:
				FindByMaxWight(list);
				system("pause");
				system("cls");
				break;
			case 15:
				break;
			default:
				printf("Ошибка ввода.\n\n");
				break;
		}
	}
	
	return 0;
}
