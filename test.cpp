#include <iostream>
#include <map>
using namespace std;
  
/*int main()
{
    // declaration of map container
    map<char, int> mymap;
    mymap['z'] = 3;
    mymap['a'] = 1;
    mymap['b'] = 2;
    
  
    // using begin() to print map
    for (auto it = mymap.begin();
         it != mymap.end(); ++it)
        cout << it->first << " = "
             << it->second << '\n';
    return 0;
}*/

// map::key_comp
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;

  std::map<char,int>::key_compare mycomp = mymap.key_comp();

  mymap['a']=100;
  mymap['c']=200;
  mymap['b']=300;

  std::cout << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element

  std::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );


  return 0;
}