#include <iostream>
#include <cstdlib>
#include <iomanip>
#include"list.h"

#define NUM_OF_MENU_ELEMENTS 10

using namespace std;

const string * TypeName[4];

class DebugList : public List
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
            PrintNode(item, i);
            item = item->next;
        }

        printf("\n");
    }
    
    int DoMenu(const char *s[], int max)
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
    
		cout << index << "\t" << p << "\t" << setw(8) << setfill('0') << p->prev << "\t" << p->next << endl;
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
	system("chcp 1251 > nul");
	
	DebugList list;
	int nodeCount;
	Node *element;
	int index;
	int key = 0;
	const char *menu[NUM_OF_MENU_ELEMENTS + 1] =
        { "(none)", "�������� ����", "������� ������", "������ ������", "������� ���� �� �������", "��������� �������",
		"������� ����", "�������� ������", "�������� �������", "�������� ������", "�����"};
	
	list = *(DebugList*)list.CreateList();
	
	while(key != 10)
	{
		key = list.DoMenu(menu, NUM_OF_MENU_ELEMENTS);
		system("cls");
		
		switch(key)
		{
			case 1:
				element = new Node(((List*)&list));
				list.Add(element);
				system("cls");
				printf("���� �������� � ����� ������.\n\n");
				break;
			case 2:				
				list.PrintList();
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
						
				element = list.GetItem(index);
				cout << "#\tp" << "\t\t" << "prev" << "\t\t" << "next" << endl;
				list.PrintNode(element, index);
				system("pause");
				system("cls");
				break;
			case 5:
				printf("���� ��� ����� �������� �� ������ ���������?\n> ");
				index = list.InputNumber();
				
				list.Remove(index);
				system("cls");
				printf("���� ��������.\n\n");
				break;
			case 6:
				printf("���� ��� ����� �������� �� ������ �������?\n> ");
				index = list.InputNumber();
				
				list.Delete(index);
				system("cls");
				printf("���� ������.\n\n");
				break;
			case 7: 
				printf("������ ���� ��� ����� ������� �� ������ ��������?\n> ");
				scanf("%p", &element);
				index = list.GetIndex(element);
				
				if(index < 0)
					printf("������ �������� �� ����������.\n\n");
				else
					printf("������ ��������: %d\n\n", index);	
				break;
			case 8:
				printf("��� ����� �������� ����� ����� �������?\n> ");
				nodeCount = list.Count();
				index = list.InputNumber();
				
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
				break;
			default:
				printf("������ �����.\n");
				break;
		}
	}
	
	return 0;
}
