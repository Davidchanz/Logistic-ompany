#pragma once
#include <iostream>
#include "Delivery.h"

class AbstractDocForm {
public:
    virtual ~AbstractDocForm() {};
    virtual Doc_form* CreateDocForm() const = 0;
};

class ConcreteDocForm : public AbstractDocForm 
{
public:
    Doc_form* CreateDocForm() const override
    {
        Doc_form* newDoc = new Doc_form;
        newDoc->filling();
        return newDoc;
    }
};

class AbstractFactory 
{
public:
    virtual AbstractDocForm* CreateDocForm() const = 0;
};

class DocFactory : public AbstractFactory 
{
public:
    AbstractDocForm* CreateDocForm() const override 
    {
        return new ConcreteDocForm();
    }
};