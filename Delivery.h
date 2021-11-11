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

	void print()
	{
		cout << "-----------------------------------" << endl;
		cout << "Id: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Weight: " << weight << endl;
		cout << "Sender: " << sender << endl;
		cout << "Recipient: " << recipient << endl;
		cout << "Price product: " << price_product << endl;
		cout << "Price delivery: " << price_delivery << endl;
		cout << "Content: " << content << endl;
		cout << endl;
		cout << "Point sender: " << point_sender << endl;
		cout << "Time sender: " << time_sender << endl;
		cout << "Point deliver: " << point_deliver << endl;
		cout << "Time deliver: " << time_deliver << endl;
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
	}
	
	friend std::ostream& operator<< (std::ostream& out, Doc_form& data)
	{
		data.info.print();
		return out;
	}

	void filling() override
	{
		int tmp_int = 0;
		string tmp_str;
		
		info.name = string_generator(1 + rand() % 20);
		info.weight = int_generator(1 + rand() % 5);
		info.sender = string_generator(1 + rand() % 15);
		info.recipient = string_generator(1 + rand() % 18);
		info.price_product = int_generator(1 + rand() % 5);
		info.price_delivery = int_generator(1 + rand() % 5);
		info.content = string_generator(1 + rand() % 13);
		info.point_sender = string_generator(1 + rand() % 13);
		info.time_sender = string_generator(1 + rand() % 13);
		info.point_deliver = string_generator(1 + rand() % 13);
		info.time_deliver = string_generator(1 + rand() % 13);

			/*tmp_str = string_generator(1 + rand() % 20);
		info.name = tmp_str;
		
			tmp_str = string_generator(1 + rand() % 18);
		info.name = tmp_str;
		info.patronymic = string_generator(1 + rand() % 12);
		info.age = 18 + rand() % 100;
		tmp_str = string_generator(1 + rand() % 10);
		info.gender = tmp_str;
		tmp_str = string_generator(1 + rand() % 9);
		info.citizenship = tmp_str;
		tmp_str = string_generator(1 + rand() % 8);
		info.nationality = tmp_str;
		info.phone = to_string(int_generator(7));*/
		
			/*info.index = int_generator(1 + rand() % 5);
		info.country = string_generator(1 + rand() % 44);
		info.region = string_generator(1 + rand() % 32);
		info.city = string_generator(1 + rand() % 19);
		info.street = string_generator(1 + rand() % 10);
		info.apartment = 1 + rand() % 100;
		info.entrance = 1 + rand() % 15;
		info.floor = 1 + rand() % 10;*/
		
		/*	tmp_int = id * 3;
		info.inn = tmp_int;
		info.period = int_generator(1 + rand() % 3);
		info.pmj = rand() % 4;
		info.registr = ++id;*/
		info.id = ++id;
	}
	
	string string_generator(int size)
	{
		int j = 0;
		string string;
		
			for (int i = 0; i < size; i++)
			{
			j = rand() % 50 + 1;
			
				if (j > size - i) j = size - i;
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