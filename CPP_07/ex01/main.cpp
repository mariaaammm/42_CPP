#include "iter.hpp"

// int main( void )
// {
//     size_t n = 3;

//     std::cout << "String ->   ";
//     std::string arr1[] = {"Hello", "world", "!"};
//     iter(arr1, n, &printArr);
//     std::cout << std::endl;

//     std::cout << "Number ->   ";
//     int arr2[] = {7, 8, 9};
//     iter(arr2, n, &printArr);
//     std::cout << std::endl;

//     std::cout << "Float ->    ";
//     float arr3[] = {5.4, 2.1, 1.7};
//     iter(arr3, n, &printArr);
//     std::cout << std::endl;

//     std::cout << "Char ->     ";
//     char arr4[] = {'*', 'X', '7'};
//     iter(arr4, n, &printArr);
//     std::cout << std::endl;

//     return (0);
// }

// class Awesome
// {
//     public:
//         Awesome (void) : _n(42) {return; }
//         int get(void) const {return (this->_n);}

//     private:
//         int _n;
// };

// std::ostream &operator<<(std::ostream &o, Awesome const &rhs) {o << rhs.get(); return o;}
// template <typename T>
// void print(T const &x) {std::cout << x << std::endl; return ;}

// int    main()
// {
//     int tab[] = {0, 1, 2, 3, 4};
//     Awesome tab2[5];

//     iter (tab, 5, print);
//     iter (tab2, 5, print);

//     return (0);

// }

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}