#include "PmergeMe.hpp"

///////////////////////////////////////////////////////////////////////////////////ALGO//////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////VECTOR////////////////////////////////////////////////////////////////////////////

void PmergeMe::CreatePairVector(std::vector<int> Argcontainer)
{
    std::vector<int> container_max;
    std::vector<int> container_min;
    std::vector<std::vector<int> > comparison;

    if (Argcontainer.size() >= 2)
    {
        for (size_t x = 0; x < Argcontainer.size() - 1; x += 2)
        {
            if (Argcontainer[x] > Argcontainer[x + 1])
            {
                container_max.push_back(Argcontainer[x]);
                container_min.push_back(Argcontainer[x + 1]);
                std::vector<int> tmp;
                tmp.push_back(Argcontainer[x + 1]);
                tmp.push_back(Argcontainer[x]);
                comparison.push_back(tmp);
                tmp.clear();
            }
            else
            {
                container_min.push_back(Argcontainer[x]);
                container_max.push_back(Argcontainer[x + 1]);
                std::vector<int> tmp;
                tmp.push_back(Argcontainer[x]);
                tmp.push_back(Argcontainer[x + 1]);
                comparison.push_back(tmp);
                tmp.clear();
            }
        }
        Argcontainer.erase(Argcontainer.begin(), Argcontainer.begin() + container_max.size() + container_min.size());
        if (Argcontainer.size())
        {
            std::vector<int>::iterator maxIt = std::max_element(container_max.begin(), container_max.end());
            if (maxIt != Argcontainer.end() && *maxIt > Argcontainer[0])
                container_min.push_back(Argcontainer[0]);
            else
                container_max.push_back(Argcontainer[0]);

        }
    }
    if (container_max.size() > 1)
        this->CreatePairVector(container_max);
    else
        container_vector_sorted.push_back(container_max[0]);
    std::vector<std::vector<int> > Jacobsthal;
    Jacobsthal = this->CreateJacobsthalVector(container_min);
    this->InsertWithBinarySearchVector(Jacobsthal, comparison);
}

std::vector<std::vector<int> > PmergeMe::CreateJacobsthalVector(std::vector<int> Argcontainer)
{
    size_t n_minus_one = 0;
    size_t n_minus_two = 1;
    size_t n = 0;
    std::vector<std::vector<int> > result;

    for(size_t pos = 0; pos < Argcontainer.size();)
    {
        n = n_minus_one + 2 * n_minus_two;
        n_minus_two = n_minus_one;
        n_minus_one = n;
        std::vector<int> tmp;
        size_t x = 0;
        while (x < n && (x + pos) < Argcontainer.size())
        {
            tmp.push_back(Argcontainer[x + pos]);
            x++;
        }
        pos += x;
        result.push_back(tmp);
        tmp.clear();
    }
    for (size_t x = 0; x < result.size(); x++)
    {
        std::reverse(result[x].begin(), result[x].end());
    }
    return result;
}

void PmergeMe::InsertWithBinarySearchVector(std::vector<std::vector<int> > &Jacobsthal, std::vector<std::vector<int> > &comparison)
{
    for (size_t i = 0; i < Jacobsthal.size(); ++i)
    {
        for (size_t j = 0; j < Jacobsthal[i].size(); ++j)
        {
            int value = Jacobsthal[i][j];
            int reference = -1;

            for (size_t k = 0; k < comparison.size(); ++k)
            {
                if (comparison[k][0] == value)
                {
                    reference = comparison[k][1];
                    break;
                }
            }

            if (container_vector_sorted.empty() || value < container_vector_sorted.front())
            {
                container_vector_sorted.insert(container_vector_sorted.begin(), value);
                continue;
            }
            if (value > container_vector_sorted.back())
            {
                container_vector_sorted.push_back(value);
                continue;
            }

            std::vector<int>::iterator insertPos = container_vector_sorted.end();
            if (reference != -1)
            {
                std::vector<int>::iterator refPos = std::find(container_vector_sorted.begin(), container_vector_sorted.end(), reference);
                if (refPos != container_vector_sorted.end())
                    insertPos = std::lower_bound(container_vector_sorted.begin(), refPos, value);
            }

            if (insertPos == container_vector_sorted.end())
                insertPos = std::lower_bound(container_vector_sorted.begin(), container_vector_sorted.end(), value);
            container_vector_sorted.insert(insertPos, value);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////DEQUE////////////////////////////////////////////////////////////////////////////

void PmergeMe::CreatePairDeque(std::deque<int> Argcontainer)
{
    std::deque<int> container_max;
    std::deque<int> container_min;
    std::deque<std::deque<int> > comparison;

    if (Argcontainer.size() >= 2)
    {
        for (size_t x = 0; x < Argcontainer.size() - 1; x += 2)
        {
            if (Argcontainer[x] > Argcontainer[x + 1])
            {
                container_max.push_back(Argcontainer[x]);
                container_min.push_back(Argcontainer[x + 1]);
                std::deque<int> tmp;
                tmp.push_back(Argcontainer[x + 1]);
                tmp.push_back(Argcontainer[x]);
                comparison.push_back(tmp);
                tmp.clear();
            }
            else
            {
                container_min.push_back(Argcontainer[x]);
                container_max.push_back(Argcontainer[x + 1]);
                std::deque<int> tmp;
                tmp.push_back(Argcontainer[x]);
                tmp.push_back(Argcontainer[x + 1]);
                comparison.push_back(tmp);
                tmp.clear();
            }
        }
        Argcontainer.erase(Argcontainer.begin(), Argcontainer.begin() + container_max.size() + container_min.size());
        if (Argcontainer.size())
        {
            std::deque<int>::iterator maxIt = std::max_element(container_max.begin(), container_max.end());
            if (maxIt != Argcontainer.end() && *maxIt > Argcontainer[0])
                container_min.push_back(Argcontainer[0]);
            else
                container_max.push_back(Argcontainer[0]);

        }
    }
    if (container_max.size() > 1)
        this->CreatePairDeque(container_max);
    else
        container_deque_sorted.push_back(container_max[0]);
    std::deque<std::deque<int> > Jacobsthal;
    Jacobsthal = this->CreateJacobsthalDeque(container_min);
    this->InsertWithBinarySearchDeque(Jacobsthal, comparison);
}

std::deque<std::deque<int> > PmergeMe::CreateJacobsthalDeque(std::deque<int> Argcontainer)
{
    size_t n_minus_one = 0;
    size_t n_minus_two = 1;
    size_t n = 0;

    std::deque<std::deque<int> > result;

    for(size_t pos = 0; pos < Argcontainer.size();)
    {
        n = n_minus_one + 2 * n_minus_two;
        n_minus_two = n_minus_one;
        n_minus_one = n;
        std::deque<int> tmp;
        size_t x = 0;
        while (x < n && (x + pos) < Argcontainer.size())
        {
            tmp.push_back(Argcontainer[x + pos]);
            x++;
        }
        pos += x;
        result.push_back(tmp);
        tmp.clear();
    }
    for (size_t x = 0; x < result.size(); x++)
    {
        std::reverse(result[x].begin(), result[x].end());
    }
    return result;
}

void PmergeMe::InsertWithBinarySearchDeque(std::deque<std::deque<int> > &Jacobsthal, std::deque<std::deque<int> > &comparison)
{
    for (size_t i = 0; i < Jacobsthal.size(); ++i)
    {
        for (size_t j = 0; j < Jacobsthal[i].size(); ++j)
        {
            int value = Jacobsthal[i][j];
            int reference = -1;

            for (size_t k = 0; k < comparison.size(); ++k)
            {
                if (comparison[k][0] == value)
                {
                    reference = comparison[k][1];
                    break;
                }
            }

            if (container_deque_sorted.empty() || value < container_deque_sorted.front())
            {
                container_deque_sorted.insert(container_deque_sorted.begin(), value);
                continue;
            }
            if (value > container_deque_sorted.back())
            {
                container_deque_sorted.push_back(value);
                continue;
            }

            std::deque<int>::iterator insertPos = container_deque_sorted.end();
            if (reference != -1)
            {
                std::deque<int>::iterator refPos = std::find(container_deque_sorted.begin(), container_deque_sorted.end(), reference); 
                if (refPos != container_deque_sorted.end())
                    insertPos = std::lower_bound(container_deque_sorted.begin(), refPos, value);
            }
            
            if (insertPos == container_deque_sorted.end())
                insertPos = std::lower_bound(container_deque_sorted.begin(), container_deque_sorted.end(), value);
            container_deque_sorted.insert(insertPos, value);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////UTILS//////////////////////////////////////////////////////////////////////////////

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
    container_vector.clear();
    container_vector_sorted.clear();
    container_deque.clear();
    container_deque_sorted.clear();
}

void PmergeMe::FillVector(char **argv, int argc)
{
    for (int x = 1; x < argc; x++)
    {
        container_vector.push_back(std::atoi(argv[x]));
    }
}

void PmergeMe::FillDeque(char **argv, int argc)
{
    for (int x = 1; x < argc; x++)
    {
        container_deque.push_back(std::atoi(argv[x]));
    }
}

void PmergeMe::PrintContainerVector(void)
{
    std::vector<int>::iterator it = container_vector.begin();
    std::cout << B_M "Vector Array Before : " << B_Y;
    while (it != container_vector.end())
    {
        std::cout << *it;
        if (it != container_vector.end() - 1)
            std::cout << " ";
        it++;
    }
    std::cout << RESET << std::endl;
}

void PmergeMe::PrintContainerDeque(void)
{
    std::deque<int>::iterator it = container_deque.begin();
    std::cout << B_M "Deque Array Before : " << B_Y;
    while (it != container_deque.end())
    {
        std::cout << *it;
        if (it != container_deque.end() - 1)
            std::cout << " ";
        it++;
    }
    std::cout << RESET << std::endl;
}

void PmergeMe::PrintContainerVectorSorted(void)
{
    std::vector<int>::iterator it = container_vector_sorted.begin();
    std::cout << B_M "Vector Array After : " << B_Y;
    while (it != container_vector_sorted.end())
    {
        std::cout << *it;
        if (it++ != container_vector_sorted.end() - 1)
            std::cout << " ";
    }
    std::cout << RESET << std::endl;
}

void PmergeMe::PrintContainerDequeSorted(void)
{
    std::deque<int>::iterator it = container_deque_sorted.begin();
    std::cout << B_M "Deque Array After : " << B_Y;
    while (it != container_deque_sorted.end())
    {
        std::cout << *it;
        if (it++ != container_deque_sorted.end() - 1)
            std::cout << " ";
    }
    std::cout << RESET << std::endl;
}

std::string PmergeMe::MeasureCreatePairVector(std::vector<int> Argcontainer)
{
    std::clock_t start = std::clock();
    this->CreatePairVector(Argcontainer);
    std::clock_t end = std::clock();

    double duration = static_cast<double>(end - start) * 1000.0 / CLOCKS_PER_SEC;

    std::ostringstream oss;
    oss << B_M "Time Vector[" << container_vector_sorted.size() << "] : " << B_Y << std::fixed << std::setprecision(3) << duration << " milliseconds" << RESET;
    return oss.str();
}

std::string PmergeMe::MeasureCreatePairDeque(std::deque<int> Argcontainer)
{
    std::clock_t start = std::clock();
    this->CreatePairDeque(Argcontainer);
    std::clock_t end = std::clock();

    double duration = static_cast<double>(end - start) * 1000.0 / CLOCKS_PER_SEC;

    std::ostringstream oss;
    oss << B_M "Time Deque[" << container_deque_sorted.size() << "] : " << B_Y << std::fixed << std::setprecision(3) << duration << " milliseconds" << RESET;
    return oss.str();
}

size_t PmergeMe::getSizeVector()
{
    return container_vector.size();
}

size_t PmergeMe::getSizeDeque()
{
    return container_deque.size();
}

const std::vector<int> &PmergeMe::getContainerVector() const
{
    return container_vector;
}

const std::vector<int> &PmergeMe::getContainerVectorSorted() const
{
    return container_vector_sorted;
}

const std::deque<int> &PmergeMe::getContainerDequeSorted() const
{
    return container_deque_sorted;
}

const std::deque<int> &PmergeMe::getContainerDeque() const
{
    return container_deque;
}


PmergeMe::PmergeMe(const PmergeMe &copy)
{
    if (!container_deque.empty())
        container_deque.clear();
    if (!container_vector.empty())
        container_vector.clear();
    if (!container_deque_sorted.empty())
        container_deque_sorted.clear();
    if (!container_vector_sorted.empty())
        container_vector_sorted.clear();
    container_deque = copy.getContainerDeque();
    container_vector = copy.getContainerVector();
    container_deque_sorted = copy.getContainerDequeSorted();
    container_vector_sorted = copy.getContainerVectorSorted();
}

PmergeMe &PmergeMe::operator=(const PmergeMe &second)
{
    if (!container_deque.empty())
        container_deque.clear();
    if (!container_vector.empty())
        container_vector.clear();
    if (!container_deque_sorted.empty())
        container_deque_sorted.clear();
    if (!container_vector_sorted.empty())
        container_vector_sorted.clear();
    container_deque = second.getContainerDeque();
    container_vector = second.getContainerVector();
    container_deque_sorted = second.getContainerDequeSorted();
    container_vector_sorted = second.getContainerVectorSorted();
    return *this;
}