#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Document
{
	int id;
	string name;
	int weight;
	string sender;
	string recipient;
	int price_product;
	int price_delivery;
	string content;

	string point_sender;
	string time_sender;
	string point_deliver;
	string time_deliver;
	string transport;

	void print()
	{
		cout << "-----------------------------------" << endl;
		cout << "Id: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Weight: " << weight << endl;
		cout << "Sender: " << sender << endl;
		cout << "Recipient: " << recipient << endl;
		cout << "Price product: " << price_product << "$" << endl;
		cout << "Price delivery: " << price_delivery << "$" << endl;
		cout << "Content: " << content << endl;
		cout << endl;
		cout << "Point sender: " << point_sender << endl;
		cout << "Time sender: " << time_sender << endl;
		cout << "Point deliver: " << point_deliver << endl;
		cout << "Time deliver: " << time_deliver << endl;
		cout << "Transport: " << transport << endl;
		cout << "-----------------------------------" << endl;
	}
	Document()
	{
		id = 0;
		name = "";
		weight = 0;
		sender = "";
		recipient = "";
		price_product = 0;
		price_delivery = 0;
		content = "";
		point_sender = "";
		time_sender = "";
		point_deliver = "";
		time_deliver = "";
		transport = "";
	}
};

class Form
{
public:
	virtual ~Form() {}
	virtual void filling() = 0;
};

 class Doc_form : public Form
 {
	
 private: static int id;
	
 public: Document info;
	
 public:
	 Doc_form()
	 {
		 info.id = 0;
	 }
	~Doc_form()
	{
		info.name = "";
		info.weight = 0;
		info.sender = "";
		info.recipient = "";
		info.price_product = 0;
		info.price_delivery = 0;
		info.content = "";
		info.point_sender = "";
		info.time_sender = "";
		info.point_deliver = "";
		info.time_deliver = "";
		info.transport = "";
	}
	
	friend std::ostream& operator<< (std::ostream& out, Doc_form& data)
	{
		data.info.print();
		return out;
	}

	void filling() override
	{
		int tmp_int = 0;
		int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
		string tmp_str;
		const char* transportlist[4]
		{
			"Car",
			"Railway",
			"Nautical",
			"Aviation"
		};
		
		info.name = string_generator(1 + rand() % 20);
		info.weight = int_generator(1 + rand() % 5);
		info.sender = string_generator(1 + rand() % 15);
		info.recipient = string_generator(1 + rand() % 18);
		info.price_product = int_generator(1 + rand() % 5);
		info.price_delivery = int_generator(1 + rand() % 5);
		info.content = string_generator(1 + rand() % 13);
		info.point_sender = string_generator(1 + rand() % 13);
		year = 1 + rand() % 2099;
		month = 1 + rand() % 12;
		day = 1 + rand() % 30;
		hour = 1 + rand() % 23;
		minute = 1 + rand() % 59;
		second = 1 + rand() % 59;
		info.time_sender = to_string(month) + "." + to_string(day) + "." + to_string(year) + " " + to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
		info.point_deliver = string_generator(1 + rand() % 13);
		year = 1 + rand() % 2099;
		month = 1 + rand() % 12;
		day = 1 + rand() % 30;
		hour = 1 + rand() % 23;
		minute = 1 + rand() % 59;
		second = 1 + rand() % 59;
		info.time_deliver = to_string(month) + "." + to_string(day) + "." + to_string(year) + " " + to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
		tmp_int = rand() % 4;
		info.transport = transportlist[tmp_int];
		info.id = ++id;
	}
	
	string string_generator(int size)
	{
		int j = 0;
		string string;
		
		for (int i = 0; i < size; i++)
		{
			j = rand() % 50 + 1;
			
				if (j > size - i) 
					j = size - i;
				i += j;
			
				for (int k = 0; k < j; k++)
				{
					string += (char)(rand() % 26 + 97);
				}
			break;
			string += ' ';
		}
		return string;
	}
	
	int int_generator(int size)
	{
		string tmp;
		for (int i = 0; i < size; i++)
		{
			if (i == 10)
				break;
			int j = (rand() % 9);
			tmp += to_string(j);
		}
		return stoi(tmp);
	}
};

 int Doc_form::id = 0;