template <typename T>
const char *Array<T>::ArrayTooBig::what() const throw()
{
	return ("Array is too big, can't exceed 1000");
}

template <typename T>
const char *Array<T>::OutOfBounds::what() const throw()
{
	return ("Index is out of bounds");
}

template <typename T>
Array<T>::Array()
{
	std::cout << B_G "Default constructor of Array has been called" RESET << std::endl;
	size = 0;
	array = new T[0]();
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << B_G "Constructor of Array has been called" RESET << std::endl;
	if (n > 1000)
		throw (ArrayTooBig());
	size = n;
	array = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &second)
{
	std::cout << B_G "Copy constructor of Array has been called" RESET << std::endl;
	size = second.get_size();
	array = new T[size]();
	for (unsigned int x = 0; x < size; x++)
	{
		array[x] = second.array[x];
	}
}

template <typename T>
Array<T>::~Array()
{
	std::cout << B_R "Destructor of Array has been called" RESET << std::endl;
	delete[] array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
	std::cout << B_Y "Surchage operator of Array has been called" RESET << std::endl;
	delete[] array;
	size = copy.get_size();
	array = new T[size]();
	for (unsigned int x = 0; x < size; x++)
	{
		array[x] = copy.array[x];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](const unsigned int x)
{
	if (x < size)
		return (array[x]);
	else
		throw (OutOfBounds());
}

template<typename T>
unsigned int Array<T>::get_size() const
{
	return size;
}