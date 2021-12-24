#include <iostream>
#include <cstdlib>
#include <iomanip>
#include"subj.h"

#define NUM_OF_MENU_ELEMENTS 15

using namespace std;

class DebugList : public SubjList
{
   public:
    void PrintTransportList()
    {
        int i;
        Node* item;
        item = getHead();
        
        for (i = 0; item != NULL; i++) 
		{
            ((Base*)item)->Print();
            item = item->getNext();
        }

        printf("\n");
    }
    
    void PrintList()
    {
        int i;
        Node* item;
        item = getHead();

        cout << "List: " << this << "\tHead: " << getHead() << "\tTail: " << getTail()<< endl << endl;
        cout << "#\tp" << "\t\t" << "prev" << "\t\t" << "next" << endl;

        for (i = 0; item != NULL; i++) 
		{
            PrintNode(item, i);
            item = item->getNext();
        }

        printf("\n");
    }
    
    int DoMenu(const char * const s[], int max)
	{	
		int i;
   		for (i = 1; i <= max; i++)
    		printf("%d. %s\n", i, s[i]);
   		printf("> ");
    
    	fflush(stdin);
    	scanf("%d", &i);
    	return i < 1 || i > max ? 0 : i;
	}
     
    void PrintNode(const Node *p, int index)
    {	
    	if(!p || index < 0)
    		return;
    
		cout << index << "\t" << p << "\t" << setw(8) << setfill('0') << p->getPrev() << "\t" << p->getNext() << endl;
    }
    
	int InputNumber()
	{
		int num;
	
		while(fflush(stdin), !scanf("%d", &num))
			printf("������ �����, ���������� ��� ���: ");
	
		return num;
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
				index = list.InputNumber();
						
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
				index = list.InputNumber();
				
				element = list.Remove(index);
				
				system("cls");
				if(!element)
					printf("���� � ����� �������� ���.\n\n");
				else
					printf("���� ��������.\n\n");
				break;
			case 6:
				printf("���� ��� ����� �������� �� ������ �������?\n> ");
				index = list.InputNumber();
				
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
				index = list.InputNumber();
				
				printf("����� ��� ���������� ��������?\n");
				t = (ItemType)list.DoMenu(TypeName, 3);
          		p = p->Create(t, &list);
          		printf("\n������� ������ ����������:\n");
          		p->Input();
          		list.Insert((Node*)p, index);
				system("cls");
				if(t != 0)
					printf("���� ��������.\n\n");
				else
					printf("������ �����.\n\n");
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
