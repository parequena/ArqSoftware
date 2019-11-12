#include <iostream>

// --------------------------------------------------------------- JAVA

// Simules the Java Object type.
struct Object
{
	virtual bool operator<(const Object& o) const = 0;
	virtual bool operator>(const Object& o) const = 0;
};

class JavaStyleContainer
{
	// Max size.
	enum { MAX_SIZE = 1000 }; // Never use an enum.

	// Container size.
	unsigned int m_size = 0;

	// Object Array
	Object* m_data[MAX_SIZE];

public:
	// Ctor.
	JavaStyleContainer() :
		m_size(0)
	{

	}

	// Dtor.
	~JavaStyleContainer() { }

	// Push back
	void pushBack(Object& ob)
	{
		// Insert.
		m_data[m_size++] = &ob;
	}

	// Pop back
	void popBack() { --m_size; }

	// Getter.
	const Object& operator[](unsigned int i) const { return *m_data[i]; }

	// Setter.
	Object& operator[](unsigned int i) { return *m_data[i]; }

	// Get size.
	inline unsigned int size() const { return m_size; }

	// isSorted
	// bool isSorted() const
	// {
	// 	for (auto i = 0; i < m_size-1; ++i)
	// 	{
	// 		if (*m_data[i] > *m_data[i + 1])
	// 			return false;
	// 	}
	// 
	// 	return true;
	// }
};

bool isSorted(const JavaStyleContainer& jCont, unsigned int init, unsigned int end)
{
	for (auto i = init; i < end-1; ++i)
	{
		if (jCont[i] > jCont[i + 1])
			return false;
	}
	 
	return true;
}

struct MyClassJC : public Object
{
	int a = 0;

	MyClassJC() :
		MyClassJC(0)
	{}

	MyClassJC(int _a)
	{
		a = _a;
	}

	// Operator.
	bool operator<(const Object& o) const
	{
		const MyClassJC& rO = (const MyClassJC&)o;
		return a < rO.a;
	}

	bool operator>(const Object& o) const
	{
		const MyClassJC& rO = (const MyClassJC&)o;
		return a > rO.a;
	}
};

int main()
{
	JavaStyleContainer jCont;
	MyClassJC jA(1), jB(2), jC;

	jCont.pushBack(jA);
	jCont.pushBack(jB);

	jC = (MyClassJC&)jCont[1];

	std::cout << jC.a << "\n";

	if (isSorted(jCont, 0, jCont.size()))
		std::cout << "Esta ordenado\n";

}