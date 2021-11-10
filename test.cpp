/*#include "map_class.hpp"
#include "map.hpp"
#include "utils.hpp"
#include "MapIter.hpp"*/
#include "marc_tester/srcs/map/common.hpp"

#define T1 int
#define T2 std::string

struct ft_more {
	bool	operator()(const T1 &first, const T1 &second) const {
		return (first > second);
	}
};

typedef ft::map<T1, T2, ft_more > ft_mp;
typedef ft::map<T1, T2, ft_more >::iterator iterator;
typedef ft::pair<T1, T2> pair;

/*template <typename T>
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
}*/

int main(void)
{
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

	ft_mp mp;
	iterator ret;
	iterator it;

	ret = mp.insert(it, pair(42, "fgzgxfn"));
	ret = mp.insert(it, pair(25, "funny"));
	ret = mp.insert(it, pair(80, "hey"));
	ret = mp.insert(it, pair(12, "no"));
	ret = mp.insert(it, pair(27, "bee"));
	ret = mp.insert(it, pair(90, "8"));
	printSize(mp);

	/*mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";*/
    return 0;
}