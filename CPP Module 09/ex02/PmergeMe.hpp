#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <deque>
#include <cstdlib>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

# define B_B "\x1B[0;36m"
# define B_R   "\x1B[1;31m"
# define B_G   "\x1B[1;32m"
# define B_Y   "\x1B[1;33m"
# define B_M  "\x1B[1;35m"
# define RESET "\x1B[0m"

class PmergeMe
{
    public :
        PmergeMe();
        ~PmergeMe();
        void FillVector(char **argv, int argc);
        void FillDeque(char **argv, int argc);

        //ALGO
        void CreatePairVector(std::vector<int> Argcontainer);
        void InsertWithBinarySearchVector(std::vector<std::vector<int> > &Jacobsthal, std::vector<std::vector<int> > &comparison);
        std::vector<std::vector<int> >CreateJacobsthalVector(std::vector<int> Argcontainer);

        void CreatePairDeque(std::deque<int> Argcontainer);
        std::deque<std::deque<int> > CreateJacobsthalDeque(std::deque<int> Argcontainer);
        void InsertWithBinarySearchDeque(std::deque<std::deque<int> > &Jacobsthal, std::deque<std::deque<int> > &comparison);

        //UTILS
        std::string MeasureCreatePairVector(std::vector<int> Argcontainer);
        std::string MeasureCreatePairDeque(std::deque<int> Argcontainer);
        void PrintContainerVector(void);
        void PrintContainerDeque(void);
        void PrintContainerVectorSorted(void);
        void PrintContainerDequeSorted(void);
        size_t getSizeVector();
        size_t getSizeDeque();
        const std::vector<int> &getContainerVector()const;
        const std::vector<int> &getContainerVectorSorted()const;
        const std::deque<int> &getContainerDeque()const;
        const std::deque<int> &getContainerDequeSorted()const;

    private :
        std::vector<int> container_vector;
        std::vector<int> container_vector_sorted;
        std::deque<int> container_deque;
        std::deque<int> container_deque_sorted;
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &second);
};

#endif