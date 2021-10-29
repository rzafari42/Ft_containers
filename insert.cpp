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
    iterator it;

    std::cout << std::boolalpha;

    tmp = mp.insert(ft::map<T1, T2>::value_type(1, 20));
    ft::printPair(tmp.first);
    tmp = mp.insert(ft::map<T1, T2>::value_type(2, 40));
    ft::printPair(tmp.first);
    tmp = mp.insert(ft::map<T1, T2>::value_type(3, 60));
    ft::printPair(tmp.first);
    tmp = mp.insert(ft::map<T1, T2>::value_type(4, 80));
    ft::printPair(tmp.first);
    tmp = mp.insert(ft::map<T1, T2>::value_type(5, 100));
    ft::printPair(tmp.first);
    tmp = mp.insert(ft::map<T1, T2>::value_type(6, 120));
    ft::printPair(tmp.first);
    
    
    std::cout << "\nbegin\n" ;
    it = mp.begin();
    ft::printPair(it);
    std::cout << "end\n" ;
    it = mp.end();
   
    ft::printPair(it);

    std::cout << "\nPrint In Order" << std::endl;
    mp.PrintInOrder(mp.get_root());

    return 0;
}