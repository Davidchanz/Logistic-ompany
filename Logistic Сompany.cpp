#include <iostream>
#include <vector>
#include <ctime>
#include "user_interface.h"

using namespace std;

Doc_form* InputNewDoc(int type)
{
	Doc_form* doc = new Doc_form;
	int intval;
	string strval;
	if (type == 1)
	{
		// Id
		cout << "Enter Documents Id:  " << endl;
		cin >> intval;
		if (cin.fail())
			return nullptr;
		doc->info.id = intval;
	}
	else
	{
		// Id
		cout << "Enter Documents Id:  " << endl;
		cin >> intval;
		if (cin.fail())
			return nullptr;
		doc->info.id = intval;

		//  Name
		cout << "Enter Documents Name:  " << endl;
		cin >> strval;
		if (cin.fail())
			return nullptr;
		doc->info.name = strval;

		//  Weight
		cout << "Enter Documents Weight:  " << endl;
		cin >> intval;
		if (cin.fail())
			return nullptr;
		doc->info.weight = intval;

		//  Sender
		cout << "Enter Documents Sender:  " << endl;
		cin >> strval;
		if (cin.fail())
			return nullptr;
		doc->info.sender = strval;

		//  Recipient
		cout << "Enter Documents Recipient:  " << endl;
		cin >> strval;
		if (cin.fail())
			return nullptr;
		doc->info.recipient = strval;

		//  Price product
		cout << "Enter Documents Price product:  " << endl;
		cin >> intval;
		if (cin.fail())
			return nullptr;
		doc->info.price_product = intval;

		//  Price deliver
		cout << "Enter Documents Price deliver:  " << endl;
		cin >> intval;
		if (cin.fail())
			return nullptr;
		doc->info.price_delivery = intval;

		//  Content
		cout << "Enter Documents Content:  " << endl;
		cin >> strval;
		if (cin.fail())
			return nullptr;
		doc->info.content = strval;

		//  Point sender
		cout << "Enter Documents Point sender:  " << endl;
		cin >> intval;
		if (cin.fail())
			return nullptr;
		doc->info.sender = intval;

		//  Point deliver
		cout << "Enter Documents Point deliver:  " << endl;
		cin >> strval;
		if (cin.fail())
			return nullptr;
		doc->info.point_deliver = strval;
	}
		return doc;
}

Doc_form* InputSearchCritNewDoc(int type)
{
	Doc_form* doc = new Doc_form;
	int intval;
	string strval;
	switch(type)
	{
		case 0:// Id
			cout << "Enter Documents Id:  " << endl;
			cin >> intval;
			if (cin.fail())
				return nullptr;
			doc->info.id = intval;
			break;
		case 1://  Name
			cout << "Enter Documents Name:  " << endl;
			cin >> strval;
			if (cin.fail())
				return nullptr;
			doc->info.name = strval;
			break;
		case 2://  Weight
			cout << "Enter Documents Weight:  " << endl;
			cin >> intval;
			if (cin.fail())
				return nullptr;
			doc->info.weight = intval;
			break;
		case 3://  Sender
			cout << "Enter Documents Sender:  " << endl;
			cin >> strval;
			if (cin.fail())
				return nullptr;
			doc->info.sender = strval;
			break;
		case 4://  Recipient
			cout << "Enter Documents Recipient:  " << endl;
			cin >> strval;
			if (cin.fail())
				return nullptr;
			doc->info.recipient = strval;
			break;
		case 5://  Price product
			cout << "Enter Documents Price product:  " << endl;
			cin >> intval;
			if (cin.fail())
				return nullptr;
			doc->info.price_product = intval;
			break;
		case 6://  Price deliver
			cout << "Enter Documents Price deliver:  " << endl;
			cin >> intval;
			if (cin.fail())
				return nullptr;
			doc->info.price_delivery = intval;
			break;
		case 7://  Content
			cout << "Enter Documents Content:  " << endl;
			cin >> strval;
			if (cin.fail())
				return nullptr;
			doc->info.content = strval;
			break;
		case 8://  Point sender
			cout << "Enter Documents Point sender:  " << endl;
			cin >> intval;
			if (cin.fail())
				return nullptr;
			doc->info.sender = intval;
			break;
		case 9://  Point deliver
			cout << "Enter Documents Point deliver:  " << endl;
			cin >> strval;
			if (cin.fail())
				return nullptr;
			doc->info.point_deliver = strval;
			break;
	}
	return doc;
}


int main()
{
	srand(time(NULL));

	const char* point[10]
	{
		"--->",
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
		"4. Search"
	};
    int code;
	int pos = 0;
	int CollType = 0, DocNum = 0, SearchType = 0;
	Doc_form* value = new Doc_form;
	vector <Doc_form*> Orders;
	DocFactory* f1 = new DocFactory();

	Interface<Doc_form*>* component = new ConcretteInterface<Doc_form*>;

	Interface<Doc_form*>* queue_decor = new QueueDecorator<Doc_form*>(component);

	SearchType = SearchCriteria();
	Interface<Doc_form*>* tree_decor = TreeStrategy<Doc_form*>(SearchType, component);
	DocNum = NumRecords();
	CollType = Collection_Type(*f1, DocNum, Orders, tree_decor, queue_decor);

    while (1)
    {
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
			for (int i = 0; i < 4; i++) 
{
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
					value = InputNewDoc(0);
					if (!value)
					{
						cout << "Incorrectly entered data!" << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						_getch();
						break;
					}
					if(CollType == 0) tree_decor->insert(value);
					else if(CollType == 1) queue_decor->insert(value);
					//tree->insert_(value);
					break;
				case 1://  вывод всех
					//tree->inorder(tree->root);
					if (CollType == 0) tree_decor->inorder();
					else if (CollType == 1) queue_decor->inorder();
					_getch();
					break; 
				case 2://  удаление
					value = InputSearchCritNewDoc(SearchType);
					if (!value)
					{
						cout << "Incorrectly entered data!" << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						_getch();
						break;
					}
					//tree->remove(tree->root, value);
					if (CollType == 0) tree_decor->remove(value);
					else if (CollType == 1) queue_decor->remove(value, SearchStrategy<Doc_form*>(SearchType));
					break;
				case 3://  поиск по 
					value = InputSearchCritNewDoc(SearchType);
					if (!value)
					{
						cout << "Incorrectly entered data!" << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						_getch();
						break;
					}
					//if(tree->findnode(tree->root, value)) cout << *(tree->findnode(tree->root, value)->Data) << endl;
					if (CollType == 0) tree_decor->find(value, SearchStrategy<Doc_form*>(SearchType));
					else if (CollType == 1) queue_decor->find(value, SearchStrategy<Doc_form*>(SearchType));
					_getch();
					break;
				}
			}
    }
	return 0;
}