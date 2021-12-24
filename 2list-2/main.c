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
		printf("1. �������� ����\n2. ������� ������\n3. ������ ������\n4. ������� ���� �� �������\n5. ��������� �������\n"
		"6. ������� ����\n7. �������� ������\n8. �������� �������\n9. �������� ������\n0. �����\n\n> ");
		scanf("%d", &key);				
		system("cls");
		
		switch(key)
		{
			case 1:
				element = malloc(sizeof(Node));
				
				Add(list, element);
				system("cls");
				printf("���� �������� � ����� ������.\n\n");
				break;
			case 2:				
				PrintList(list);
				system("pause");				
				system("cls");
				break;
			case 3:
				nodeCount = Count(list);
				printf("���������� ����� � ������: %d\n\n", nodeCount);
				break;
			case 4:
				printf("���� ��� ����� �������� �� ������ ��������?\n> ");
				index = InputNumber();
						
				element = GetItem(list, index);
				PrintItem(element, index);
				system("pause");
				system("cls");
				break;
			case 5:
				printf("���� ��� ����� �������� �� ������ ���������?\n> ");
				index = InputNumber();
				
				Remove(list, index);
				system("cls");
				printf("���� ��������.\n\n");
				break;
			case 6:
				printf("���� ��� ����� �������� �� ������ �������?\n> ");
				index = InputNumber();
				
				Delete(list, index);
				system("cls");
				printf("���� ������.\n\n");
				break;
			case 7: 
				printf("������ ���� ��� ����� ������� �� ������ ��������?\n> ");
				scanf("%p", &element);
				index = GetIndex(list, element);
				
				printf("������ ��������: %d\n\n", index);
				break;
			case 8:
				printf("��� ����� �������� ����� ����� �������?\n> ");
				nodeCount = Count(list);
				index = InputNumber();
				
				element = malloc(sizeof(Node));
				Insert(list, element, index);
				system("cls");
				printf("���� ��������.\n\n");
				break;
			case 9:
				Clear(list);
				system("cls");
				printf("������ ������.\n\n");
				break;
			case 0:
				break;
			default:
				printf("������ �����.\n");
				break;
		}
	}
	
	return 0;
}
