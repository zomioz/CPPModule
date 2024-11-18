#include "Fixed.hpp"
#include <bitset>

int	main(void)
{
    //{
    //    Fixed test1(10.5f);
    //    Fixed test3(10.5f);
    //    Fixed test2(10);
    //    Fixed test4(10);
//
    //    std::cout << "test 1 raw bits : " << test1.getRawBits() << std::endl;
    //    std::cout << "test 2 raw bits : " << test2.getRawBits() << std::endl;
    //    std::cout << "test 3 raw bits : " << test3.getRawBits() << std::endl;
    //    std::cout << "test 4 raw bits : " << test4.getRawBits() << std::endl;
    //    std::cout << "test 1 to Float : " << test1.toFloat() << std::endl;
    //    std::cout << "test 3 to Float : " << test3.toFloat() << std::endl;
    //    std::cout << "test 2 to Int : " << test2.toInt() << std::endl;
    //    std::cout << "test 4 to Int : " << test4.toInt() << std::endl << std::endl;
//
    //    if (test1 == test3)
    //        std::cout << "YES 10.5 == 10.5" << std::endl << std::endl;
//
    //    std::cout << "10.5 + 10.5 : " << test1 + test3 << std::endl;
    //    std::cout << "10.5 - 10.5 : " << test1 - test3 << std::endl;
    //    std::cout << "10.5 * 10.5 : " << test1 * test3 << std::endl;
    //    std::cout << "10.5 / 10.5 : " << test1 / test3 << std::endl << std::endl;
//
    //    Fixed yolo = test1++;
    //    std::cout << "yolo = test1++" << std::endl;
    //    std::cout << "yolo raw bits : " << yolo.getRawBits() << std::endl;
    //    std::cout << "test 1 raw bits : " << test1.getRawBits() << std::endl << std::endl;
//
    //    Fixed _min = _min.min(test1, --test3);
    //    std::cout << "min between 10.5 and --10.5 to Float : " << _min.toFloat() << std::endl;
    //    return (0);
    //}
    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
    }
}
