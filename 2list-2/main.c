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
		printf("1. Äîáàâèòü óçåë\n2. Âûâåñòè ñïèñîê\n3. Ðàçìåð ñïèñêà\n4. Âûâåñòè óçåë ïî èíäåêñó\n5. Èñêëþ÷èòü ýëåìåíò\n"
		"6. Óäàëèòü óçåë\n7. Ïîëó÷èòü èíäåêñ\n8. Âñòàâèòü ýëåìåíò\n9. Î÷èñòèòü ñïèñîê\n0. Âûõîä\n\n> ");
		scanf("%d", &key);				
		system("cls");
		
		switch(key)
		{
			case 1:
				element = malloc(sizeof(Node));
				
				Add(list, element);
				system("cls");
				printf("Óçåë äîáàâëåí â êîíåö ñïèñêà.\n\n");
				break;
			case 2:				
				PrintList(list);
				system("pause");				
				system("cls");
				break;
			case 3:
				nodeCount = Count(list);
				printf("Êîëè÷åñòâî óçëîâ â ñïèñêå: %d\n\n", nodeCount);
				break;
			case 4:
				printf("Óçåë ïîä êàêèì èíäåêñîì âû õîòèòå ïîëó÷èòü?\n> ");
				index = InputNumber();
						
				element = GetItem(list, index);
				PrintItem(element, index);
				system("pause");
				system("cls");
				break;
			case 5:
				printf("Óçåë ïîä êàêèì èíäåêñîì âû õîòèòå èñêëþ÷èòü?\n> ");
				index = InputNumber();
				
				Remove(list, index);
				system("cls");
				printf("Óçåë èñêëþ÷åí.\n\n");
				break;
			case 6:
				printf("Óçåë ïîä êàêèì èíäåêñîì âû õîòèòå óäàëèòü?\n> ");
				index = InputNumber();
				
				Delete(list, index);
				system("cls");
				printf("Óçåë óäàëåí.\n\n");
				break;
			case 7: 
				printf("Èíäåêñ óçëà ïîä êàêèì àäðåñîì âû õîòèòå ïîëó÷èòü?\n> ");
				scanf("%p", &element);
				index = GetIndex(list, element);
				
				printf("Èíäåêñ ýëåìåíòà: %d\n\n", index);
				break;
			case 8:
				printf("Ïîä êàêèì èíäåêñîì áóäåò íîâûé ýëåìåíò?\n> ");
				nodeCount = Count(list);
				index = InputNumber();
				
				element = malloc(sizeof(Node));
				Insert(list, element, index);
				system("cls");
				printf("Óçåë äîáàâëåí.\n\n");
				break;
			case 9:
				Clear(list);
				system("cls");
				printf("Ñïèñîê î÷èùåí.\n\n");
				break;
			case 0:
				break;
			default:
				printf("Îøèáêà ââîäà.\n");
				break;
		}
	}
	
	return 0;
}
