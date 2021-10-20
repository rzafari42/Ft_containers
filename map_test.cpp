#include "map_class.hpp"
#define _pair ft::pair

typedef ft::map<int, int>::iterator iterator;
int main(void)
{
    ft::map<int, int> mp;
    _pair<iterator, bool> tmp;

    tmp = mp.insert(ft::pair<int, int>(1, 20));
    tmp = mp.insert(ft::pair<int, int>(2, 40));
    mp.insert(ft::pair<int, int>(3, 60));
    mp.insert(ft::pair<int, int>(4, 80));
    mp.insert(ft::pair<int, int>(5, 100));

    ft::map<int, int>::iterator ite;

    for (it = mp.begin(); it != ite; it++)
    {
        std::cout << it->first << it->second << std::endl;
        it++;
    }

    return 0;
}