#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

# define B_B "\x1B[0;36m"
# define B_R   "\x1B[1;31m"
# define B_G   "\x1B[1;32m"
# define B_Y   "\x1B[1;33m"
# define B_M  "\x1B[1;35m"
# define RESET "\x1B[0m"

class Rpn
{
    public :
        Rpn();
        ~Rpn();
        void HandleArg(char **argv);
        void AddNumber(float number);
        void OperatorAdd(void);
        void OperatorSub(void);
        void OperatorMul(void);
        bool OperatorDiv(void);
    private :
        std::stack<int> Arg;
        Rpn &operator=(const Rpn &second);
        Rpn(const Rpn &copy);
};

#endif