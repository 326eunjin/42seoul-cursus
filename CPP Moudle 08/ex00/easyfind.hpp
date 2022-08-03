#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>

int easyfind(const std::vector<int> &a, int b) {

    int ret = std::find(a.begin(), a.end(), b);
    // throw std::exception();
}
#endif