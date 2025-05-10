#include "RPN.hpp"

bool IsOperator(char c);

Rpn::Rpn()
{
}

Rpn::~Rpn()
{
}

void Rpn::HandleArg(char **argv)
{
    size_t x = 0;
    std::string str(argv[1]);
    while (argv[1][x] != '\0')
    {
        if (argv[1][x] == ' ')
        {
            x++;
            continue ;
        }
        if (isdigit(argv[1][x]))
        {
            const char tmp[2] = {argv[1][x], '\0'};
            this->AddNumber(std::atoi(tmp));
        }
        if (IsOperator(argv[1][x]))
        {
            std::string index("+-*/");
            int i = 0;
            while (i < 4)
            {
                if (index[i] == argv[1][x])
                    break;
                i++;
            }
            switch(i)
            {
                case 0:
                {
                    this->OperatorAdd();
                    x++;
                    continue ;
                }
                case 1:
                {
                    this->OperatorSub();
                    x++;
                    continue ;
                }
                case 2:
                {
                    this->OperatorMul();
                    x++;
                    continue ;
                }
                case 3:
                {
                    if (!this->OperatorDiv())
                        return ;
                    x++;
                    continue ;
                }
            }
        }
        x++;
    }
    std::cout << B_G "Result is : " << Arg.top() << RESET << std::endl;
    Arg.pop();
}

void Rpn::OperatorAdd(void)
{
    float a;
    float b;
    a = Arg.top();
    Arg.pop();
    b = Arg.top();
    Arg.pop();
    Arg.push(b + a);
}

void Rpn::OperatorSub(void)
{
    float a;
    float b;
    a = Arg.top();
    Arg.pop();
    b = Arg.top();
    Arg.pop();
    Arg.push(b - a);
}

void Rpn::OperatorMul(void)
{
    float a;
    float b;
    a = Arg.top();
    Arg.pop();
    b = Arg.top();
    Arg.pop();
    Arg.push(b * a);
}

bool Rpn::OperatorDiv(void)
{
    float a;
    float b;
    a = Arg.top();
    Arg.pop();
    b = Arg.top();
    Arg.pop();
    if (a == 0)
    {
        std::cerr << B_R "Error : Division by zero is undefined, end of program" RESET << std::endl;
        return false;
    }
    Arg.push(b / a);
    return true;
}

void Rpn::AddNumber(float number)
{
    Arg.push(number);
}

Rpn::Rpn(const Rpn &copy)
{
    Arg = copy.Arg;
}

Rpn &Rpn::operator=(const Rpn &second)
{
    if (this != &second)
        *this = second;
    return *this;
}