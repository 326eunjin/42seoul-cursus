#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
  private:
  public:
    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack &m);
    MutantStack &operator=(const MutantStack &m);
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin();
    iterator end();
    // bool empty();
    // unsigned int size();
    // T top();
    // void push(T t);
    // void pop();
};

// ANCHOR canonical form
template <typename T> MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T> MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &m) : std::stack<T>(m) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &m) {
    if (this != &m) {
        std::stack<T>::operator=(m);
    }
    return (*this);
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin() {
    return (this->c.begin());
}
template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end() {
    return (this->c.end());
}
#endif
