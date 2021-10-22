#include "map.hpp"
#include "map_class.hpp"
#include <iostream>
#include <string>

#define T1 int
#define T2 int

typedef ft::map<T1, T2>::iterator iterator;
int main(void)
{
    ft::map<T1, T2> mp;
    ft::pair<iterator, bool> tmp;

    tmp = mp.insert(ft::pair<T1, T2>(1, 20));
    tmp = mp.insert(ft::pair<T1, T2>(2, 40));
    tmp = mp.insert(ft::pair<T1, T2>(3, 60));
    tmp = mp.insert(ft::pair<T1, T2>(4, 80));
    tmp = mp.insert(ft::pair<T1, T2>(5, 100));

    return 0;
}