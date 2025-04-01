#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << B_R "Destructor of Base has been called" RESET << std::endl;
}

Base *generate(void)
{
	Base *ret;
	srand(time(0));
	int random = rand() % 3;
	switch (random)
	{
		case (0):
			std::cout << B_B "Generate a Base pointer of time : " B_Y "A." RESET << std::endl;
			ret = new A();
			return (ret);
		case (1):
			std::cout << B_B "Generate a Base pointer of time : " B_Y "B." RESET << std::endl;
			ret = new B();
			return (ret);
		case (2):
			std::cout << B_B "Generate a Base pointer of time : " B_Y "C." RESET << std::endl;
			ret = new  C();
			return (ret);
		default:
			std::cout << B_R "Error during generate fonction" RESET << std::endl;
			return (NULL);
	}
}

void identify(Base *p)
{
	if (p == NULL)
		std::cout << B_M "*p is " B_Y "NULL" RESET << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << B_M "*p is type : " B_Y "A" RESET << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << B_M "*p is type : " B_Y "B" RESET << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << B_M "*p is type : " B_Y "C" RESET << std::endl;
}

void identify(Base &p)
{
	try
	{
        p = dynamic_cast<A&>(p);
        (void)p;
        std::cout << B_M "&p is type : " B_Y "A" RESET << std::endl;
    } 
    catch (std::exception&)
	{
    	try
		{
    		p = dynamic_cast<B&>(p);
    	    (void)p;
    	    std::cout << B_M "&p is type : " B_Y "B" RESET << std::endl;
    	}
    	catch (std::exception&)
		{
			try
			{
    	    	p = dynamic_cast<C&>(p);
    	    	(void)p;
    	    	std::cout << B_M "&p is type : " B_Y "C" RESET << std::endl;
    		}
    		catch (std::exception&)
			{
    	    	std::cout << B_M "dynamic cast failed &p isn't type A,B or C" RESET << std::endl;
    		}
		}
	}
}