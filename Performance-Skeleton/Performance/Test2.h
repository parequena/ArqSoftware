#ifndef TEST2_H
#define TEST2_H

#include "Test.h"
#include "TestRunner.h"
#include <iostream>

#define N1 10

struct Test2 : public Test
{
	// Ctor.
	Test2(const std::string& str) :
		Test(str)
	{ }

	// Dtor.
	~Test2() {}

	// Run
	void run()
	{
		long long fact = N1;
		for (auto i = (N1-1); i > 1; --i) {
			fact *= i;
		}

		std::cout << fact << "\n";	
	}

private:
	std::string _name = "";
};

struct Test2B : public Test
{
	// Ctor.
	Test2B(const std::string& str) :
		Test(str)
	{ }

	// Dtor.
	~Test2B() {}

	// Run
	void run()
	{
		std::cout << factRecursivo(N1) << "\n";
	}

	long long factRecursivo(long long valor) {
		if (!valor)
			return 1;
		return valor *= factRecursivo(valor - 1);
	}

private:
	std::string _name = "";
};

class TestRunner2 : public TestRunner
{
public:
	TestRunner2() : TestRunner()
	{
		addTest(new Test2B("iter"));
		addTest(new Test2("rec"));
	}

	virtual ~TestRunner2() { };
};

#endif // !TEST1_H

