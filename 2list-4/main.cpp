#include <iostream>
#include <cstdlib>
#include <iomanip>
#include"list.h"

#define NUM_OF_MENU_ELEMENTS 10

using namespace std;

const string* TypeName[4];

class DebugList : public List
{
public:
	void PrintList()
	{
		int i;
		Node* item;
		item = getHead();

		cout << "List: " << this << "\tHead: " << getHead() << "\tTail: " << getTail() << endl << endl;
		cout << "#\tp" << "\t\t" << "prev" << "\t\t" << "next" << endl;

		for (i = 0; item != NULL; i++)
		{
			PrintNode(item, i);
			item = item->getNext();
		}

		printf("\n");
	}

	int DoMenu(const char* s[], int max)
	{
		int i;
		for (i = 1; i <= max; i++)
			printf("%d. %s\n", i, s[i]);
		printf("> ");

		fflush(stdin);
		scanf("%d", &i);
		return i < 1 || i > max ? 0 : i;
	}

	void PrintNode(const Node* p, int index)
	{
		if (!p || index < 0)
			return;

		cout << index << "\t" << p << "\t" << setw(8) << setfill('0') << p->getPrev() << "\t" << p->getNext() << endl;
	}

	int InputNumber()
	{
		int num;

		while (fflush(stdin), !scanf("%d", &num))
			printf("Ошибка ввода, попробуйте еще раз: ");

		return num;
	}
};

int main()
{
	system("chcp 1251 > nul");

	DebugList list;
	int nodeCount;
	Node* element;
	int index;
	int key = 0;
	const char* menu[NUM_OF_MENU_ELEMENTS + 1] =
	{ "(none)", "Добавить узел", "Вывести список", "Размер списка", "Вывести узел по индексу", "Исключить элемент",
	"Удалить узел", "Получить индекс", "Вставить элемент", "Очистить список", "Выход" };

	while (key != 10)
	{
		key = list.DoMenu(menu, NUM_OF_MENU_ELEMENTS);
		system("cls");

		switch (key)
		{
		case 1:
			element = new Node();
			list.Add(element);
			system("cls");
			printf("Узел добавлен в конец списка.\n\n");
			break;
		case 2:
			list.PrintList();
			system("pause");
			system("cls");
			break;
		case 3:
			nodeCount = list.Count();
			printf("Количество узлов в списке: %d\n\n", nodeCount);
			break;
		case 4:
			printf("Узел под каким индексом вы хотите получить?\n> ");
			index = list.InputNumber();

			element = list.GetItem(index);
			cout << "#\tp" << "\t\t" << "prev" << "\t\t" << "next" << endl;
			list.PrintNode(element, index);
			system("pause");
			system("cls");
			break;
		case 5:
			printf("Узел под каким индексом вы хотите исключить?\n> ");
			index = list.InputNumber();

			list.Remove(index);
			system("cls");
			printf("Узел исключен.\n\n");
			break;
		case 6:
			printf("Узел под каким индексом вы хотите удалить?\n> ");
			index = list.InputNumber();

			list.Delete(index);
			system("cls");
			printf("Узел удален.\n\n");
			break;
		case 7:
			printf("Индекс узла под каким адресом вы хотите получить?\n> ");
			scanf("%p", &element);
			index = list.GetIndex(element);

			if (index < 0)
				printf("Такого элемента не существует.\n\n");
			else
				printf("Индекс элемента: %d\n\n", index);
			break;
		case 8:
			printf("Под каким индексом будет новый элемент?\n> ");
			nodeCount = list.Count();
			index = list.InputNumber();

			element = new Node();
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
			break;
		default:
			printf("Ошибка ввода.\n");
			break;
		}
	}

	return 0;
}
