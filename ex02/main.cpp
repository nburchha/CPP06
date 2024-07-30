#include "Base.hpp"

Base* generate(void)
{
	static bool seeded = false;
	if (!seeded)
	{
		seeded = true;
		srand(static_cast<unsigned int>(time(NULL)));
	}
	int random = rand() % 3;
	switch (random)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception&) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception&) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception&) {}
}


int main()
{
	for (int i = 0; i < 5; i++)
	{
		Base* base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	return 0;
}