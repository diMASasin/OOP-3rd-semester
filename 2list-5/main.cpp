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
        { "(none)", "�������� � ����� ������", "������� ������", "������ ������", "����� ���� �� �������", "��������� ����", "������� ����", 
		"�������� ������ ���� �� ������", "�������� ����", "�������� ������", "������������� �� ��������� ��������", "������������� �� ������������ ��������", 
		"������� ������ �������", "����� �� ���������� ����", "����� �� ������������� ����", "�����" };
	system("chcp 1251 > nul");
	
	list = *(DebugList*)list.CreateList();
	
	while(key != NUM_OF_MENU_ELEMENTS)
	{
		key = list.DoMenu(menu, NUM_OF_MENU_ELEMENTS);
		system("cls");
		
		switch(key)
		{
			case 1:
				printf("����� ��� ���������� ��������?\n");
				t = (ItemType)list.DoMenu(TypeName, 3);
          		p = p->Create(t, &list);
          		printf("\n������� ������ ����������:\n");
          		p->Input();
          		list.Add((Node*)p);
				system("cls");
				if(t != 0)
					printf("���� �������� � ����� ������.\n\n");
				else
					printf("������ �����.\n\n");
				break;
			case 2:				
				list.PrintTransportList();
				system("pause");				
				system("cls");
				break;
			case 3:
				nodeCount = list.Count();
				printf("���������� ����� � ������: %d\n\n", nodeCount);
				break;
			case 4:
				printf("���� ��� ����� �������� �� ������ ��������?\n> ");
				index = InputNumber();
						
				p = (Base*)list.GetItem(index);
				if(!element)
				{
					system("cls");
					printf("���� � ����� �������� ���.\n\n");
					break;	
				}
				
				printf("\n");
				p->Print();
				system("pause");
				system("cls");
				break;
			case 5:
				printf("���� ��� ����� �������� �� ������ ���������?\n> ");
				index = InputNumber();
				
				element = list.Remove(index);
				
				system("cls");
				if(!element)
					printf("���� � ����� �������� ���.\n\n");
				else
					printf("���� ��������.\n\n");
				break;
			case 6:
				printf("���� ��� ����� �������� �� ������ �������?\n> ");
				index = InputNumber();
				
				int result;
				result = list.Delete(index);
				
				system("cls");
				if(!result)
					printf("���� � ����� �������� ���.\n\n");
				else
					printf("���� ������.\n\n");
				break;
			case 7: 
				printf("������ ���� ��� ����� ������� �� ������ ��������?\n> ");
				scanf("%p", &element);
				index = list.GetIndex(element);
				
				system("cls");
				if(index < 0)
					printf("���� � ����� ������� ���\n\n");
				else
					printf("������ ��������: %d\n\n", index);
				break;
			case 8:
				printf("��� ����� �������� ����� ����� �������?\n> ");
				nodeCount = list.Count();
				index = InputNumber();
				
				element = new Node((List*)&list);
				list.Insert(element, index);
				system("cls");
				printf("���� ��������.\n\n");
				break;
			case 9:
				list.Clear();
				system("cls");
				printf("������ ������.\n\n");
				break;
			case 10:
				list.SortByRangeOfMovement();
				system("cls");
				printf("������ ������������ �� ��������� ��������.\n\n");
				break;
			case 11:
				list.SortByMaxSpeed();
				system("cls");
				printf("������ ������������ �� ������������ ��������.\n\n");
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
				printf("������ �����.\n\n");
				break;
		}
	}
	
	return 0;
}
