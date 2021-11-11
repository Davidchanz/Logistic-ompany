#pragma once
#include <iostream>
#include "Delivery.h"

/**
 * Каждый отдельный продукт семейства продуктов должен иметь базовый интерфейс.
 * Все вариации продукта должны реализовывать этот интерфейс.
 */
class AbstractDocForm {
public:
    virtual ~AbstractDocForm() {};
    virtual Doc_form* CreateDocForm() const = 0;
};

/**
 * Конкретные продукты создаются соответствующими Конкретными Фабриками.
 */
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

/**
 * Интерфейс Абстрактной Фабрики объявляет набор методов, которые возвращают
 * различные абстрактные продукты. Эти продукты называются семейством и связаны
 * темой или концепцией высокого уровня. Продукты одного семейства обычно могут
 * взаимодействовать между собой. Семейство продуктов может иметь несколько
 * вариаций, но продукты одной вариации несовместимы с продуктами другой.
 */
class AbstractFactory 
{
public:
    virtual AbstractDocForm* CreateDocForm() const = 0;
};

/**
 * Конкретная Фабрика производит семейство продуктов одной вариации. Фабрика
 * гарантирует совместимость полученных продуктов. Обратите внимание, что
 * сигнатуры методов Конкретной Фабрики возвращают абстрактный продукт, в то
 * время как внутри метода создается экземпляр конкретного продукта.
 */
class DocFactory : public AbstractFactory 
{
public:
    AbstractDocForm* CreateDocForm() const override 
    {
        return new ConcreteDocForm();
    }
};