#include "map_class.hpp"
#define _pair ft::pair
#define T1 int
#define T2 int
typedef ft::map<T1, T2>::iterator iterator;

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

typedef ft::map<int, int>::iterator iterator;
int main(void)
{
    ft::map<int, int> mp;
    _pair<iterator, bool> tmp;

    tmp = mp.insert(ft::pair<int, int>(1, 20));
    printPair(tmp.first);
    tmp = mp.insert(ft::pair<int, int>(2, 40));
    mp.insert(ft::pair<int, int>(3, 60));
    mp.insert(ft::pair<int, int>(4, 80));
    mp.insert(ft::pair<int, int>(5, 100));


    return 0;
}