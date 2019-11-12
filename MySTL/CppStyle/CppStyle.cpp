#include <iostream>

// --------------------------------------------------------------- CPP

template <class T>
class CPPStyleContainer
{
	// Max size.
	enum { MAX_SIZE = 1000 }; // Never use an enum.

	// Container size.
	unsigned int m_size = 0;

	// Object Array
	T m_data[MAX_SIZE];

public:
	// Ctor.
	CPPStyleContainer() :
		m_size(0)
	{

	}

	// Dtor.
	~CPPStyleContainer() { }

	// Push back
	void pushBack(const T& ob)
	{
		// Insert.
		m_data[m_size++] = ob;
	}

	// Pop back
	void popBack() { --m_size; }

	// Getter.
	const T& operator[](unsigned int i) const { return m_data[i]; }

	// Setter.
	T& operator[](unsigned int i) { return m_data[i]; }

	// Get size.
	inline unsigned int size() const { return m_size; }
	
	// Get init.
	inline T* begin() { return m_data; }

	// Get end.
	inline T* end() { return m_data + m_size; }

	// isShorted
	// bool isShorted() const
	// {
	// 	for (auto i = 0; i < m_size - 1; ++i)
	// 	{
	// 		if (m_data[i] > m_data[i + 1])
	// 			return false;
	// 	}
	// 
	// 	return true;
	// }
};

template <class T>
bool isSorted(const T& cCont, unsigned int init, unsigned int end)
{
	for (auto i = init; i < end - 1; ++i)
	{ // Check
		if (cCont[i] > cCont[i + 1])
			return false;
	}

	return true;
}

template <class T>
bool isSorted(T* init, T* end)
{
	if (init == end) return true;
	
	for (auto p = init, pp = ++p; pp != end; ++p, ++pp)
		if (*p > *pp)
			return false;

	return true;
}

struct MyClass
{
	// 
	int m_a = 0;

	// Ctor.
	MyClass() : MyClass(0) {}

	// Ctor params.
	MyClass(int a) { m_a = a; }

	virtual bool operator<(const MyClass& o) const
	{
		return m_a < o.m_a;
	}

	virtual bool operator>(const MyClass& o) const
	{
		return m_a > o.m_a;
	}
};


int main()
{
	CPPStyleContainer<MyClass> cppCont;
	MyClass cppA(1), cppB(2), cppC;

	cppCont.pushBack(cppA);
	cppCont.pushBack(cppB);
	cppCont.pushBack(cppA);
	cppCont.pushBack(cppB);

	cppC = cppCont[1];
	
	std::cout << cppC.m_a << "\n";

	if (isSorted(cppCont, 0, cppCont.size()))
		std::cout << "Esta ordenado\n";

	if (isSorted(cppCont.begin(), cppCont.end()))
		std::cout << "Esta ordenado\n";
}