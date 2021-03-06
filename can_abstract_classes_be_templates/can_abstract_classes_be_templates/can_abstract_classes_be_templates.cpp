// can_abstract_classes_be_templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

class myAbstractClass
{
protected:
	int x;
public:
	myAbstractClass() = default;
	virtual void setX(int val) = 0; // pure virtual function
	int getX() const { return x; };
	~myAbstractClass() = default;
};

class myConcreteClass : public myAbstractClass
{
public:
	myConcreteClass() = default;
	void setX(int val) override { x = val; };
	~myConcreteClass() = default;
};

class myOtherConcreteClass : public myAbstractClass
{
public:
	myOtherConcreteClass() = default;
	void setX(int val) override { x = val; };
	~myOtherConcreteClass() = default;
};

class concreteBaseClass
{
	int val;
public:
	concreteBaseClass() = default;
	~concreteBaseClass() = default;
};

int main()
{
	concreteBaseClass a;
	std::cout << sizeof(a) << '\n';

	myConcreteClass b;
	std::cout << sizeof(b) << '\n';

	std::vector<myAbstractClass*> container;
	
	myConcreteClass example;
	example.setX(1);
	
	myOtherConcreteClass example1;
	example1.setX(2);
	
	myConcreteClass* heap_example = new myConcreteClass;
	heap_example->setX(100);
	myOtherConcreteClass* heap_example1 = new myOtherConcreteClass;
	heap_example1->setX(200);

	container.push_back(&example);
	container.push_back(&example1);
	container.push_back(heap_example);
	container.push_back(heap_example1);
	
	unsigned const size = container.size();
	for (unsigned i = 0; i < size; ++i)
	{
		myAbstractClass* tmp = container[i];
		std::cout << (*tmp).getX() << ' ';
	}	
	//std::cout << container[i]->getX() << ' ';	//prints out garbage twice like garbage garbage
	//container[i] is myAbstractClass* which we use -> to dereference and access
	//member getX() of the object. Because we can never put a non-concrete class
	//in the vector dereference will be valid.
}