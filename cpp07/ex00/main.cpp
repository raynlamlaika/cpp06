#include "whatever.hpp"

// template <typename T>

// int main( void ) {
//     // int a = 2;
//     // int b = 3;
//     // ::swap( a, b );
//     // std::cout << "a = " << a << ", b = " << b << std::endl;
//     // std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//     // std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
//     // std::string c = "chaine1";
//     // std::string d = "chaine2";
//     // ::swap(c, d);
//     // std::cout << "c = " << c << ", d = " << d << std::endl;
//     // std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
//     // std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

//     int a = 12;
//     int b = 10;

//     ::swap<int>(b, a);
//     // ::swap<int>(b, a);

//     std::cout << "this is the value of the (in first it was 12)a:" << a << std::endl;
//     std::cout << " this is the value of the (in first it was 10) b:" << b << std::endl;


//     // later check the over flow
//     std::cout << " this is the MAX value " << max<int>(a, b) << std::endl;
//     std::cout << " this is the MIN value " << min<int>(a, b) << std::endl;
    
//     return 0;
// }


int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}