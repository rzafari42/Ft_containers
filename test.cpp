#include <iostream>
#include "map.hpp"
#include "utils.hpp"

int main()
{
    ft::map<int, int> mp;
    ft::pair<ft::map<int, int>::iterator, bool> tmp;

    mp.insert(ft::map<int, int>::value_type(0, 2));
    mp.insert(ft::map<int, int>::value_type(1, 3));
    mp.insert(ft::map<int, int>::value_type(2, 4));
    ft::map<int, int>::iterator ite = mp.end();

    return 0;
}