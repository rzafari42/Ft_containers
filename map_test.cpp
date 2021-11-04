#include "map.hpp"
#include <iostream>
#include <map>
#include <string>

#define T1 int
#define T2 int
typedef ft::map<T1, T2>::iterator iterator;

typedef ft::map<int, int>::iterator iterator;
int main(void)
{
    ft::map<int, int> mp;
    ft::pair<iterator, bool> tmp;

    tmp = mp.insert(ft::pair<int, int>(1, 20));
    std::cout << tmp;
    tmp = mp.insert(ft::pair<int, int>(2, 40));
    mp.insert(ft::pair<int, int>(3, 60));
    mp.insert(ft::pair<int, int>(4, 80));
    mp.insert(ft::pair<int, int>(5, 100));

    return 0;
}