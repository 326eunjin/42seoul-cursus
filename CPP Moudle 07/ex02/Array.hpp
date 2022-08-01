#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T> class Array {
  private:
    unsigned int array_size;
    T *array;

  public:
    Array();
    Array(unsigned int n);
    Array(const Array<T> &a);
    ~Array();
    Array<T> &operator=(const Array<T> &a);

    T &operator[](unsigned int input);
    const T &operator[](unsigned int input) const;
    unsigned int size();
};

template <typename T> Array<T>::Array() {
    array = new T[0];
    array_size = 0;
}

template <typename T> Array<T>::Array(unsigned int n) {
    array = new T[n];
    array_size = n;
}

template <typename T> Array<T>::~Array() { delete[](array); }

template <typename T> Array<T>::Array(const Array<T> &a) {
    this->array_size = a.array_size;
    this->array = new T[a.array_size];
    for (unsigned int i = 0; i < array_size; i++)
        this->array[i] = a[i];
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &a) {
    if (this != &a) {
        this->array_size = a.array_size;
        delete[] this->array;                           //기존꺼 지우고
        this->array = new T[array_size];                //재할당
        for (unsigned int i = 0; i < array_size; i++) { //바꿔주기
            this->array[i] = a[i];
        }
    }
    return (*this);
}

template <typename T> T &Array<T>::operator[](unsigned int input) {
    if (input >= array_size)
        throw std::exception();
    return this->array[input];
}

template <typename T> const T &Array<T>::operator[](unsigned int input) const {
    if (input >= array_size)
        throw std::exception();
    return this->array[input];
}
template <typename T> unsigned int Array<T>::size() { return array_size; }

#endif
