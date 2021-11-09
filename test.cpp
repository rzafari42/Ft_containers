#include "map_class.hpp"
#include "map.hpp"
#include "utils.hpp"

/*struct ft_more {
	bool	operator()(const int &first, const std::string &second) const {
		return (first > second);
	}
};*/

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}


int main(void)
{
	ft::map<int, std::string> mp;
    
    //ft::map<int, std::string>::iterator ite;

    /*mp[42] = "fgzgxfn";
	printSize(mp);
	mp[25] = "funny";
    ite = mp.end();
    ite--;

    std::cout << "mp.end(): key: " << ite->first << " | value: " << ite->second << std::endl;
	printSize(mp);
	mp[80] = "hey";
	printSize(mp);
	mp[12] = "no";
	printSize(mp);
	mp[27] = "bee";
	printSize(mp);
	mp[90] = "8";
	printSize(mp);*/
	
	mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";
	printSize(mp);

    return 0;
}