#ifndef TEST1_H
#define TEST1_H

#include "Test.h"
#include "TestRunner.h"
#include <iostream>

#define N1 100000

struct Test1 : public Test
{
	// Ctor.
	Test1(const std::string& str) :
		Test(str)
	{ }

	// Dtor.
	~Test1() {}

	// Run
	void run()
	{
		for(auto i = 0; i < N1; ++i)
			std::cout << "Hola Mundo\n";
	}

private:
	std::string _name = "";
};

struct Test1B : public Test
{
	// Ctor.
	Test1B(const std::string& str) :
		Test(str)
	{ }

	// Dtor.
	~Test1B() {}

	// Run
	void run()
	{
		for (auto i = 0; i < N1; ++i)
			printf("Hola Mundo\n");
	}

private:
	std::string _name = "";
};

class TestRunner1 : public TestRunner
{
public:
	TestRunner1() : TestRunner()
	{
		addTest(new Test1B("printf"));
		addTest(new Test1("cout"));
	}

	virtual ~TestRunner1() { };
};

#endif // !TEST1_H
