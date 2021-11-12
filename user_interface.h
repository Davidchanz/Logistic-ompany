#pragma once

#include <iostream>
#include "conio.h"
#include "avl_tree.h"
#include "abstract factory.h"
#include "Interface.h"

using namespace std;

void FactoryWork(const AbstractFactory& factory, int numDoc, vector <Doc_form*> Orders, Interface<Doc_form*>* collection) {
	string tmp;
	for (int i = 0; i < numDoc; i++)
	{
		const AbstractDocForm* new_Doc = factory.CreateDocForm();
		Orders.push_back(new_Doc->CreateDocForm());
		delete new_Doc;
	}
	for (int i = 0; i < numDoc - 1; i++)
	{
		Orders[i + 1]->info.point_sender = Orders[i]->info.point_deliver;
		collection->insert(Orders[i]);
	}
	collection->insert(Orders[numDoc - 1]);
}

int NumRecords()
{
	int const size = 4;
	const char* point[size]
	{
		"--->",
		"    ",
		"    ",
		"    "
	};
	const char* str[size]
	{
		"1. 10",
		"2. 100",
		"3. 1000",
		"4. 5000"
	};
	int pos = 0;
	int code;
	int value1;
	while (1)
	{
		system("cls");
		cout << "Select the number of orders:" << endl;
		for (int i = 0; i < size; i++)
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
					pos = size-1;
				}
				break;
			case 80://вниз
				pos++;
				if (pos > size-1) {
					pos = 0;
				}
				break;
			}
			for (int i = 0; i < size; i++) {
				if (point[i] == "--->") {
					point[i] = "    ";
					break;
				}
			}
			point[pos] = "--->";
		}
		else if (code == 13)
		{
			switch (pos)
			{
			case 0://10
				value1 = 10;
				break;
			case 1://100
				value1 = 100;
				break;
			case 2://1000
				value1 = 1000;
				break;
			case 3://1000
				value1 = 5000;
				break;
			}
			break;
		}
	}
	return value1;
}

int Collection_Type(const AbstractFactory& factory, int numDoc, vector <Doc_form*> Orders, Interface<Doc_form*>* tree, Interface<Doc_form*>* queue)
{
	int const size = 2;
	const char* point[size]
	{
		"--->",
		"    "
	};
	const char* str[size]
	{
		"1. Tree",
		"2. Queue"
	};
	int pos = 0;
	int code;
	int value1;
	while (1)
	{
		system("cls");
		cout << "Select type of collection" << endl;
		for (int i = 0; i < size; i++)
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
					pos = size-1;
				}
				break;
			case 80://вниз
				pos++;
				if (pos > size-1) {
					pos = 0;
				}
				break;
			}
			for (int i = 0; i < size; i++)
			{
				if (point[i] == "--->")
				{
					point[i] = "    ";
					break;
				}
			}
			point[pos] = "--->";
		}
		else if (code == 13)
		{
			switch (pos)
			{
			case 0://  tree
				FactoryWork(factory, numDoc, Orders, tree);
				value1 = 0;
				break;
			case 1://  queue
				FactoryWork(factory, numDoc, Orders, queue);
				value1 = 1;
				break;
			}
			break;
		}
	} 
	return value1;
}

int SearchCriteria()
{
	int const size = 10;
	const char* point[size]
	{
		"--->",
		"    ",
		"    ",
		"    ",
		"    ",
		"    ",
		"    ",
		"    ",
		"    ",
		"    "
	};
	const char* str[size]
	{
		"1. Id",
		"2. Name",
		"3. Weight",
		"4. Sender",
		"5. Recipient",
		"6. Price product",
		"7. Price deliver",
		"8. Content",
		"9. Point sender",
		"10. Point deliver"
	};
	int pos = 0;
	int code;
	int value1;
	while (1)
	{
		system("cls");
		cout << "Select Search Criteria" << endl;
		for (int i = 0; i < size; i++)
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
					pos = size - 1;
				}
				break;
			case 80://вниз
				pos++;
				if (pos > size - 1) {
					pos = 0;
				}
				break;
			}
			for (int i = 0; i < size; i++)
			{
				if (point[i] == "--->")
				{
					point[i] = "    ";
					break;
				}
			}
			point[pos] = "--->";
		}
		else if (code == 13)
		{
			switch (pos)
			{
			case 0:// Id
				value1 = 0;
				break;
			case 1://  Name
				value1 = 1;
				break;
			case 2://  Weight
				value1 = 2;
				break;
			case 3://  Sender
				value1 = 3;
				break;
			case 4://  Recipient
				value1 = 4;
				break;
			case 5://  Price product
				value1 = 5;
				break;
			case 6://  Price deliver
				value1 = 6;
				break;
			case 7://  Content
				value1 = 7;
				break;
			case 8://  Point sender
				value1 = 8;
				break;
			case 9://  Point deliver
				value1 = 9;
				break;
			}
			break;
		}
	}
	return value1;
}

template <typename T> Interface<T>* TreeStrategy(int SearchCriteriaType, Interface<Doc_form*>* component)
{
	switch (SearchCriteriaType)
	{
	case 0:// Id
		return new TreeDecorator<Doc_form*, DocId_strategy>(component);
		break;
	case 1://  Name
		return new TreeDecorator<Doc_form*, DocName_strategy>(component);
		break;
	case 2://  Weight
		return new TreeDecorator<Doc_form*, DocWeight_strategy>(component);
		break;
	case 3://  Sender
		return new TreeDecorator<Doc_form*, DocSender_strategy>(component);
		break;
	case 4://  Recipient
		return new TreeDecorator<Doc_form*, DocRecipient_strategy>(component);
		break;
	case 5://  Price product
		return new TreeDecorator<Doc_form*, DocPriceProduct_strategy>(component);
		break;
	case 6://  Price deliver
		return new TreeDecorator<Doc_form*, DocPriceDelivery_strategy>(component);
		break;
	case 7://  Content
		return new TreeDecorator<Doc_form*, DocContect_strategy>(component);
		break;
	case 8://  Point sender
		return new TreeDecorator<Doc_form*, DocPointSender_strategy>(component);
		break;
	case 9://  Point deliver
		return new TreeDecorator<Doc_form*, DocPointDeliver_strategy>(component);
		break;
	}
	return new TreeDecorator<Doc_form*, DocId_strategy>(component);
}

template <typename T> Strategy<T>* SearchStrategy(int SearchCriteriaType)
{
	switch (SearchCriteriaType)
	{
	case 0:// Id
		return new DocId_strategy;
		break;
	case 1://  Name
		return new DocName_strategy;
		break;
	case 2://  Weight
		return new DocWeight_strategy;
		break;
	case 3://  Sender
		return new DocSender_strategy;
		break;
	case 4://  Recipient
		return new DocRecipient_strategy;
		break;
	case 5://  Price product
		return new DocPriceProduct_strategy;
		break;
	case 6://  Price deliver
		return new DocPriceDelivery_strategy;
		break;
	case 7://  Content
		return new DocContect_strategy;
		break;
	case 8://  Point sender
		return new DocPointSender_strategy;
		break;
	case 9://  Point deliver
		return new DocPointDeliver_strategy;
		break;
	}
	return new DocId_strategy;
}