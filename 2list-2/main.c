#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int main()
{
	List *list;
	int nodeCount;
	Node *element;
	int index;
	int key = 15;
	system("chcp 1251 > nul");
	
	list = CreateList();
	
	while(key != 0)
	{
		printf("1. Добавить узел\n2. Вывести список\n3. Размер списка\n4. Вывести узел по индексу\n5. Исключить элемент\n"
		"6. Удалить узел\n7. Получить индекс\n8. Вставить элемент\n9. Очистить список\n0. Выход\n\n> ");
		scanf("%d", &key);				
		system("cls");
		
		switch(key)
		{
			case 1:
				element = malloc(sizeof(Node));
				
				Add(list, element);
				system("cls");
				printf("Узел добавлен в конец списка.\n\n");
				break;
			case 2:				
				PrintList(list);
				system("pause");				
				system("cls");
				break;
			case 3:
				nodeCount = Count(list);
				printf("Количество узлов в списке: %d\n\n", nodeCount);
				break;
			case 4:
				printf("Узел под каким индексом вы хотите получить?\n> ");
				index = InputNumber();
						
				element = GetItem(list, index);
				PrintItem(element, index);
				system("pause");
				system("cls");
				break;
			case 5:
				printf("Узел под каким индексом вы хотите исключить?\n> ");
				index = InputNumber();
				
				Remove(list, index);
				system("cls");
				printf("Узел исключен.\n\n");
				break;
			case 6:
				printf("Узел под каким индексом вы хотите удалить?\n> ");
				index = InputNumber();
				
				Delete(list, index);
				system("cls");
				printf("Узел удален.\n\n");
				break;
			case 7: 
				printf("Индекс узла под каким адресом вы хотите получить?\n> ");
				scanf("%p", &element);
				index = GetIndex(list, element);
				
				printf("Индекс элемента: %d\n\n", index);
				break;
			case 8:
				printf("Под каким индексом будет новый элемент?\n> ");
				nodeCount = Count(list);
				index = InputNumber();
				
				element = malloc(sizeof(Node));
				Insert(list, element, index);
				system("cls");
				printf("Узел добавлен.\n\n");
				break;
			case 9:
				Clear(list);
				system("cls");
				printf("Список очищен.\n\n");
				break;
			case 0:
				break;
			default:
				printf("Ошибка ввода.\n");
				break;
		}
	}
	
	return 0;
}
