#include <iostream>
#include <cstdlib>
#include <iomanip>
#include"subj.h"

#define NUM_OF_MENU_ELEMENTS 15

using namespace std;

class DebugList : public SubjList
{
   public:
    void PrintList()
    {
        int i;
        Node* item;
        item = head;

        cout << "List: " << this << "\tHead: " << head << "\tTail: " << tail<< endl << endl;
        cout << "#\tp" << "\t\t" << "prev" << "\t\t" << "next" << endl;

        for (i = 0; item != NULL; i++) 
		{
            PrintNode(item);
            item = item->next;
        }

        printf("\n");
    }
    
    int DoMenu(const char* const s[], int max)
	{	
		int i;
   		for (i = 1; i <= max; i++)
    		printf("%d. %s\n", i, s[i]);
   		printf("> ");
    
    	fflush(stdin);
    	scanf("%d", &i);
    	return i < 1 || i > max ? 0 : i;
	}
     
    void PrintNode(const Node *p)
    {	
    	if(!p)
    		return;
    	
    	int index = GetIndex((Node*)p);
		cout << index << "\t" << p << "\t" << setw(8) << setfill('0') << p->prev << "\t" << p->next << endl;
    }
};

int main()
{
	DebugList list;
	int nodeCount;
	Node *element;
	int index;
	Base *p;
	ItemType t;
	int key = 0;
	const char *menu[NUM_OF_MENU_ELEMENTS + 1] =
        { "(none)", "Добавить в конец списка", "Вывести список", "Размер списка", "Найти узел по индексу", "Исключить узел", "Удалить узел", 
		"Получить индекс узла по адресу", "Вставить узел", "Очистить список", "Отсортировать по дальности движения", "Отсортировать по максимальной скорости", 
		"Вывести список адресов", "Найти по количеству мест", "Найти по максимальному весу", "Выход" };
	system("chcp 1251 > nul");
	
	list = *(DebugList*)list.CreateList();
	
	while(key != NUM_OF_MENU_ELEMENTS)
	{
		key = list.DoMenu(menu, NUM_OF_MENU_ELEMENTS);
		system("cls");
		
		switch(key)
		{
			case 1:
				printf("Какой вид транспорта добавить?\n");
				t = (ItemType)list.DoMenu(TypeName, 3);
          		p = p->Create(t, &list);
          		printf("\nВведите данные транспорта:\n");
          		p->Input();
          		list.Add((Node*)p);
				system("cls");
				if(t != 0)
					printf("Узел добавлен в конец списка.\n\n");
				else
					printf("Ошибка ввода.\n\n");
				break;
			case 2:				
				list.PrintTransportList();
				system("pause");				
				system("cls");
				break;
			case 3:
				nodeCount = list.Count();
				printf("Количество узлов в списке: %d\n\n", nodeCount);
				break;
			case 4:
				printf("Узел под каким индексом вы хотите получить?\n> ");
				index = InputNumber();
						
				p = (Base*)list.GetItem(index);
				if(!element)
				{
					system("cls");
					printf("Узла с таким индексом нет.\n\n");
					break;	
				}
				
				printf("\n");
				p->Print();
				system("pause");
				system("cls");
				break;
			case 5:
				printf("Узел под каким индексом вы хотите исключить?\n> ");
				index = InputNumber();
				
				element = list.Remove(index);
				
				system("cls");
				if(!element)
					printf("Узла с таким индексом нет.\n\n");
				else
					printf("Узел исключен.\n\n");
				break;
			case 6:
				printf("Узел под каким индексом вы хотите удалить?\n> ");
				index = InputNumber();
				
				int result;
				result = list.Delete(index);
				
				system("cls");
				if(!result)
					printf("Узла с таким индексом нет.\n\n");
				else
					printf("Узел удален.\n\n");
				break;
			case 7: 
				printf("Индекс узла под каким адресом вы хотите получить?\n> ");
				scanf("%p", &element);
				index = list.GetIndex(element);
				
				system("cls");
				if(index < 0)
					printf("Узла с таким адресом нет\n\n");
				else
					printf("Индекс элемента: %d\n\n", index);
				break;
			case 8:
				printf("Под каким индексом будет новый элемент?\n> ");
				nodeCount = list.Count();
				index = InputNumber();
				
				element = new Node((List*)&list);
				list.Insert(element, index);
				system("cls");
				printf("Узел добавлен.\n\n");
				break;
			case 9:
				list.Clear();
				system("cls");
				printf("Список очищен.\n\n");
				break;
			case 10:
				list.SortByRangeOfMovement();
				system("cls");
				printf("Список отсортирован по дальности движения.\n\n");
				break;
			case 11:
				list.SortByMaxSpeed();
				system("cls");
				printf("Список отсортирован по максимальной скорости.\n\n");
				break;	
			case 12:
				list.PrintList();
				system("pause");
				system("cls");
				break;
			case 13:
				list.FindByMaxPassengerNumber();
				system("pause");
				system("cls");
				break;
			case 14:
				list.FindByMaxWight();
				system("pause");
				system("cls");
				break;
			case NUM_OF_MENU_ELEMENTS:
				break;
			default:
				printf("Ошибка ввода.\n\n");
				break;
		}
	}
	
	return 0;
}
