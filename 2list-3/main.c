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
        { "(none)", "�������� � ����� ������", "������� ������", "������ ������", "����� ���� �� �������", "��������� ����", "������� ����", 
		"�������� ������ ���� �� ������", "�������� ����", "�������� ������", "������������� �� ��������� ��������", "������������� �� ������������ ��������", 
		"������� ������ �������", "����� �� ���������� ����", "����� �� ������������� ����", "�����" };
	system("chcp 1251 > nul");
	
	list = CreateList();
	
	while(key != 15)
	{
		key = DoMenu(menu, NUM_OF_MENU_ELEMENTS);
		system("cls");
		
		switch(key)
		{
			case 1:
				printf("����� ��� ���������� ��������?\n");
				t = DoMenu(TypeName, 3);
          		p = Create(t);
          		printf("\n������� ������ ����������:\n");
          		Input(p);
          		Add(list, (Node*)p);
				system("cls");
				if(t != 0)
					printf("���� �������� � ����� ������.\n\n");
				else
					printf("������ �����.\n\n");
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
				printf("���������� ����� � ������: %d\n\n", nodeCount);
				break;
			case 4:
				if(!list->head)
				{
					printf("������ ����.\n\n");
					break;
				}
				
				printf("���� ��� ����� �������� �� ������ ��������?\n> ");
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
					printf("������ ����.\n\n");
					break;
				}
				
				printf("���� ��� ����� �������� �� ������ ���������?\n> ");
				index = InputNumber(Count(list) - 1);
				
				Remove(list, index);
				system("cls");
				printf("���� ��������.\n\n");
				break;
			case 6:
				if(!list->head)
				{
					printf("������ ����.\n\n");
					break;
				}
				
				printf("���� ��� ����� �������� �� ������ �������?\n> ");
				index = InputNumber(Count(list) - 1);
				
				Delete(list, index);
				system("cls");
				printf("���� ������.\n\n");
				break;
			case 7: 
				if(!list->head)
				{
					printf("������ ����.\n\n");
					break;
				}
				
				printf("������ ���� ��� ����� ������� �� ������ ��������?\n> ");
				scanf("%p", &element);
				index = GetIndex(list, element);
				
				printf("������ ��������: %d\n\n", index);
				break;
			case 8:
				printf("� ����� ����� �������� �������?\n");
				index = InputNumber(Count(list));
				
				printf("����� ��� ���������� ��������?\n");
				t = DoMenu(TypeName, 3);
          		p = Create(t);
          		printf("\n������� ������ ����������:\n");
          		Input(p);
          		Insert(list, (Node*)p, index);
				system("cls");
				printf("���� �������� � ����� ������.\n\n");
				
				break;
			case 9:
				Clear(list);
				system("cls");
				printf("������ ������.\n\n");
				break;
			case 10:
				SortByRangeOfMovement(list);
				system("cls");
				printf("������ ������������ �� ��������� ��������.\n\n");
				break;
			case 11:
				SortByMaxSpeed(list);
				system("cls");
				printf("������ ������������ �� ������������ ��������.\n\n");
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
				printf("������ �����.\n\n");
				break;
		}
	}
	
	return 0;
}
