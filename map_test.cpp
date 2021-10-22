#include <iostream>
#include <string>
#include "map.hpp"
#include "map_class.hpp"
#include "MapIter.hpp"
#include "MapIter_class.hpp"
#include <stdbool.h>

#define T1 int
#define T2 int

typedef ft::map<T1, T2>::iterator iterator;
typedef ft::map<T1, T2>::reverse_iterator reverse_iterator;

int main(void)
{
    ft::map<T1, T2> mp;
    ft::pair<iterator, bool> tmp;

    tmp = mp.insert(ft::map<T1, T2>::value_type(1, 20));
    tmp = mp.insert(ft::map<T1, T2>::value_type(2, 40));
    tmp = mp.insert(ft::map<T1, T2>::value_type(3, 60));
    tmp = mp.insert(ft::map<T1, T2>::value_type(4, 80));
    tmp = mp.insert(ft::map<T1, T2>::value_type(5, 100));

/*     reverse_iterator it = mp.rbegin();
    reverse_iterator ite = mp.rend();

    for (; it != ite; it++)
        std::cout << it->second << std::endl; */
    return 0;
}