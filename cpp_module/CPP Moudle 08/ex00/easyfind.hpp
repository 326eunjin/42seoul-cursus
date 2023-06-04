#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>

class NotInArray : public std::exception {
  public:
    const char *what() const throw();
};

template <typename T> int easyfind(T &a, int b) {
    typename T::iterator iter;
    iter = std::find(a.begin(), a.end(), b);
    if (iter == a.end())
        throw NotInArray();
    return (iter - a.begin());
}

#endif