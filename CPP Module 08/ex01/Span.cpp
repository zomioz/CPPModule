#include "Span.hpp"

Span::Span()
{
	std::cout << B_G "Default constructor of Span has been called" RESET << std::endl;
}

Span::Span(unsigned int n)
{
	std::cout << B_G "Constructor of Span has been called" RESET << std::endl;
	max = n;
}

Span::Span(const Span &copy)
{
	max = copy.get_max();
	for (size_t x = 0; x < copy.storage.size(); x++)
		storage.push_back(copy.storage[x]);
}

const Span &Span::operator=(const Span &second)
{
	if (max < second.get_max())
		throw(std::runtime_error("Error can't use operator '=', the maximum of Span one can't store the maximum of Span two"));
	max = second.get_max();
	if (!storage.empty())
		storage.clear();
	for (size_t x = 0; x < second.get_max(); x++)
		storage.push_back(second.storage[x]);
	return (*this);
}

Span::~Span()
{
	std::cout << B_R "Destructor of Span has been called" RESET << std::endl;
}

void Span::addNumber(int add)
{
	if (storage.size() == max)
	{
		throw(std::runtime_error("Error : can't stack more element, maximum already reach"));
	}
	storage.push_back(add);
	std::cout << B_M "Add : " B_Y << add << B_M " to storage" RESET << std::endl;
}

unsigned int Span::longestSpan()
{
	if (storage.size() < 2)
	{
		throw(std::runtime_error("Error : Span size is < 2, there is no range possible"));
		return (0);
	}
	std::sort(storage.begin(), storage.end());
		return (*--storage.end() - *storage.begin());
}

unsigned int Span::shortestSpan()
{
	if (storage.size() < 2)
	{
		throw(std::runtime_error("Error : Span size is < 2, there is no range possible"));
		return (0);
	}
	std::sort(storage.begin(), storage.end());
	std::vector<int>::iterator it1, it2;
	it1 = storage.begin();
	it2 = storage.begin() + 1;
	unsigned int result;
	result = *it2 - *it1;
	for (size_t x = 0; x < (storage.size() - 1); x++)
	{
		unsigned int tmp = *it2 - *it1;
		if (tmp < result)
			result = tmp;
		it1++;
		it2++;
	}
	return (result);
}

void Span::addMultipleNumber(unsigned int n)
{
	if (storage.size() + n > max)
		return (throw(std::runtime_error("Error : Span don't have enough space")));
	std::list<int> tmp;
	srand(time(NULL));
	for (unsigned int x = 0; x < n; x++)
		tmp.push_back(rand() / 123456);
	storage.insert(storage.begin(), tmp.begin(), tmp.end());
}

unsigned int Span::get_max() const
{
	return (max);
}

void Span::print_storage() const
{
	if (storage.empty())
		std::cout << B_M "Span is empty" RESET << std::endl;
	for (size_t x = 0; x < storage.size(); x++)
		std::cout << B_M "Span[" B_Y << x << B_M "] : " B_Y << storage[x] << RESET << std::endl;
}