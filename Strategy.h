#pragma once
#include "Delivery.h"

template < typename T/*, typename _allocator = allocator<T>*/>
 class Strategy
 {
 public:
	 virtual ~Strategy() {}
	 virtual int compare(const T & obj1, const T & obj2) const = 0;
	 };

//12 class Documents_inn_strategy : public Strategy<Doc_form*> {
//13 public:
//	14 int compare(Doc_form* const& obj1, Doc_form* const& obj2) const override {
//		15 if (obj1->info.inn != obj2->info.inn) {
//			16 return obj1->info.inn < obj2->info.inn ? -1 : 1;
//			17
//		}
//		18 else {
//			19 return 0;
//			20
//		}
//		21
//	}
//	22
//};
//23
//24 class Documents_name_strategy : public Strategy<Doc_form*> {
//25 public:
//	26 int compare(Doc_form* const& obj1, Doc_form* const& obj2) const override {
//		27 if (obj1->info.name != obj2->info.name) {
//			28 return obj1->info.name < obj2->info.name ? -1 : 1;
//			29
//		}
//		30 else {
//			31 return 0;
//			32
//		}
//		33
//	}
//	34
//};
//35
//36 class Documents_surname_strategy : public Strategy<Doc_form*> {
//37 public:
//	38 int compare(Doc_form* const& obj1, Doc_form* const& obj2) const override {
//		39 if (obj1->info.surname != obj2->info.surname) {
//			40 return obj1->info.surname < obj2->info.surname ? -1 : 1;
//			41
//		}
//		42 else {
//			43 return 0;
//			44
//		}
//		45
//	}
//	46
//};
//47
//48 class Documents_citizenship_strategy : public Strategy<Doc_form*> {
//49 public:
//	50 int compare(Doc_form* const& obj1, Doc_form* const& obj2) const override {
//		51 if (obj1->info.citizenship != obj2->info.citizenship) {
//			52 return obj1->info.citizenship < obj2->info.citizenship ? -1 : 1;
//			12
//				53
//		}
//		54 else {
//			55 return 0;
//			56
//		}
//		57
//	}
//	58
//};

 class DocId_strategy : public Strategy<Doc_form*> {
 public:
	 int compare(Doc_form* const& obj1, Doc_form* const& obj2) const override {
		 if (obj1->info.id != obj2->info.id) {
			 return obj1->info.id < obj2->info.id ? -1 : 1;
		 }
		 else {
			 return 0;
		 }
	 }
};
