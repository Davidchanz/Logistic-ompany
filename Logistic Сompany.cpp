#include <iostream>
#include "conio.h"
#include "avl_tree.h"
#include "abstract factory.h"
#include "Interface.h"
#include <vector>

using namespace std;

Doc_form* InputNewDoc()
{
	Doc_form* doc = new Doc_form;
	int val;
	cout << "Enter Documents Id:  " << endl;
	cin >> val;
	doc->info.id = val;
	return doc;
}

void ClientCode(const AbstractFactory& factory, int numDoc, vector <Doc_form*> Orders, Interface<Doc_form*>* collection) {
	for (int i = 0; i < numDoc; i++)
	{
		const AbstractDocForm* new_Doc = factory.CreateDocForm();
		Orders.push_back(new_Doc->CreateDocForm());
		delete new_Doc;
	}
	for (int i = 0; i < numDoc; i++)
	{
		collection->insert(Orders[i]);
	}
}

int main()
{
	const char* point[10]
	{
		"--->",
		"    ",
		"    ",
		"    ",
		"    ",
		"    "
	};
	const char* str[10]
	{
		"1. Add",
		"2. Print",
		"3. Delete",
		"4. Search",
		"5. Exit"
	};
    int code;
	int pos = 0;
	Strategy <Doc_form*>* compId = new DocId_strategy;
	//AVLTree<Doc_form*>* tree = new AVLTree<Doc_form*>(compId);
	Doc_form* value = new Doc_form;
	int value1;
	vector <Doc_form*> Orders;
	DocFactory* f1 = new DocFactory();

	Interface<Doc_form*>* component = new ConcretteInterface<Doc_form*>;

	Interface<Doc_form*>* tree_decor = new TreeDecorator<Doc_form*, DocId_strategy>(component);

	Interface<Doc_form*>* queue_decor = new QueueDecorator<Doc_form*>(component);

	while (1)
	{
		system("cls");
		cout << "Select the number of orders" << endl;
		cout << "1: 10" << endl;
		cout << "2: 100" << endl;
		cout << "3: 1000" << endl;
		cout << "4: 500000" << endl;
		cin >> code;
		switch (code)
		{
		case 1://10
			value1 = 10;
			break;
		case 2://100
			value1 = 100;
			break;
		case 3://1000
			value1 = 1000;
			break;
		case 4://1000
			value1 = 500000;
			break;
		}
		ClientCode(*f1, value1, Orders, tree_decor);
		ClientCode(*f1, value1, Orders, queue_decor);
		break;
	}
    while (1)
    {
		system("cls");
		cout << "Select type of collection" << endl;
		cout << "1: Tree" << endl;
		cout << "2: " << endl;

		system("cls");
		for (int i = 0; i < 4; i++)
		{
			cout << point[i] << str[i] << '\n';
		}
		code = _getch();
		if (code == 0 || code == 224) {
			code = _getch();
			switch (code)
			{
			case 72://вверх
				pos--;
				if (pos < 0) {
					pos = 3;
				}
				break;
			case 80://вниз
				pos++;
				if (pos > 3) {
					pos = 0;
				}
				break;
			}
			for (int i = 0; i < 4; i++) {
				if (point[i] == "--->") {
					point[i] = "    ";
					break;
				}
			}
			point[pos] = "--->";
		}
		else if (code == 13) {
				switch (pos)
				{
				case 0://  добавление
					value = InputNewDoc();
					//tree->insert_(value);
					//tree_decor->insert(value);
					queue_decor->insert(value);
					//tree->insert_(value);
					break;
				case 1://  вывод всех
					//tree->inorder(tree->root);
					//tree_decor->inorder();
					queue_decor->inorder();
					_getch();
					break; 
				case 2://  удаление
					cout << "Enter key what you want to delete:  " << endl;
					value = InputNewDoc();
					//tree->remove(tree->root, value);
					break;
				case 3://  поиск по ключу
					cout << "Enter key for search:  ";
					value = InputNewDoc();
					//if(tree->findnode(tree->root, value)) cout << *(tree->findnode(tree->root, value)->Data) << endl;
					_getch();
					break;
				case 4://  exit
					exit(0);
					break;
				}
			}
    }
}