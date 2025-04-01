#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	Base *tmp = generate();
	Base *wrong = NULL;
	identify(tmp);
	identify(*tmp);
	identify(*wrong);
	delete tmp;
}