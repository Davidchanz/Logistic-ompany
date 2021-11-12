#pragma once
#include "Delivery.h"

template < typename T>
 class Strategy
 {
 public:
	 virtual ~Strategy() {}
	 virtual int compare(const T & obj1, const T & obj2) const = 0;
	 };

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

 class DocName_strategy : public Strategy<Doc_form*> {
 public:
	 int compare(Doc_form* const& obj1, Doc_form* const& obj2) const override {
		 if (obj1->info.name != obj2->info.name) {
			 return obj1->info.name < obj2->info.name ? -1 : 1;
		 }
		 else {
			 return 0;
		 }
	 }
 };

 class DocWeight_strategy : public Strategy<Doc_form*> {
 public:
	 int compare(Doc_form* const& obj1, Doc_form* const& obj2) const override {
		 if (obj1->info.weight != obj2->info.weight) {
			 return obj1->info.weight < obj2->info.weight ? -1 : 1;
		 }
		 else {
			 return 0;
		 }
	 }
 };

 class DocSender_strategy : public Strategy<Doc_form*> {
 public:
	 int compare(Doc_form* const& obj1, Doc_form* const& obj2) const override {
		 if (obj1->info.sender != obj2->info.sender) {
			 return obj1->info.sender < obj2->info.sender ? -1 : 1;
		 }
		 else {
			 return 0;
		 }
	 }
 };

 class DocRecipient_strategy : public Strategy<Doc_form*> {
 public:
	 int compare(Doc_form* const& obj1, Doc_form* const& obj2) const override {
		 if (obj1->info.recipient != obj2->info.recipient) {
			 return obj1->info.recipient < obj2->info.recipient ? -1 : 1;
		 }
		 else {
			 return 0;
		 }
	 }
 };

 class DocPriceProduct_strategy : public Strategy<Doc_form*> {
 public:
	 int compare(Doc_form* const& obj1, Doc_form* const& obj2) const override {
		 if (obj1->info.price_product != obj2->info.price_product) {
			 return obj1->info.price_product < obj2->info.price_product ? -1 : 1;
		 }
		 else {
			 return 0;
		 }
	 }
 };

 class DocPriceDelivery_strategy : public Strategy<Doc_form*> {
 public:
	 int compare(Doc_form* const& obj1, Doc_form* const& obj2) const override {
		 if (obj1->info.price_delivery != obj2->info.price_delivery) {
			 return obj1->info.price_delivery < obj2->info.price_delivery ? -1 : 1;
		 }
		 else {
			 return 0;
		 }
	 }
 };

 class DocContect_strategy : public Strategy<Doc_form*> {
 public:
	 int compare(Doc_form* const& obj1, Doc_form* const& obj2) const override {
		 if (obj1->info.content != obj2->info.content) {
			 return obj1->info.content < obj2->info.content ? -1 : 1;
		 }
		 else {
			 return 0;
		 }
	 }
 };

 class DocPointSender_strategy : public Strategy<Doc_form*> {
 public:
	 int compare(Doc_form* const& obj1, Doc_form* const& obj2) const override {
		 if (obj1->info.point_sender != obj2->info.point_sender) {
			 return obj1->info.point_sender < obj2->info.point_sender ? -1 : 1;
		 }
		 else {
			 return 0;
		 }
	 }
 };

 class DocPointDeliver_strategy : public Strategy<Doc_form*> {
 public:
	 int compare(Doc_form* const& obj1, Doc_form* const& obj2) const override {
		 if (obj1->info.point_deliver != obj2->info.point_deliver) {
			 return obj1->info.point_deliver < obj2->info.point_deliver ? -1 : 1;
		 }
		 else {
			 return 0;
		 }
	 }
 };