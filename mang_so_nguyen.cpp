#include "mang_so_nguyen.h"

IntArray::IntArray() {
    size = 0;
    data = new int[size];
}

IntArray::IntArray(const int arr[], const int sz) {
    size = sz;
    data = new int[size];

    for (int i = 0; i < size; i++) {
        data[i] = arr[i];
    }
}

IntArray::IntArray(const IntArray &other) {
    size = other.size;
    data = new int[size];

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

IntArray &IntArray::operator=(const IntArray &other) {
    if (this == &other) {
        return *this;
    }

    size = other.size;
    data = new int[size];

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }

    return *this;
}

IntArray IntArray::operator+(const IntArray &other) {

    using std::cout;



    IntArray longer = (other.size < this->size) ? *this : other;
    IntArray shorter = (other.size < this->size) ? other : *this;

    // Assign result array to array with greater size
    IntArray result = longer;

    for (int i = 0; i < shorter.size; i++) {
        result.data[i] = this->data[i] + other.data[i];
    }

    if (shorter.size != longer.size) {
        for (int i = shorter.size; i < longer.size; i++) {
            result.data[i] = longer.data[i];
        }
    }


    return result;
}

IntArray& IntArray::operator++() {
    for (int i = 0; i < size; i++) {
        data[i]++;
    }

    return *this;
}


IntArray IntArray::operator++(int) {
    IntArray result = *this;
    for (int i = 0; i < size; i++) {
        result.data[i]++;
    }

    return result;
}


std::ostream &operator<<(std::ostream &out, const IntArray &arr) {
    for (int i = 0; i < arr.size; i++) {
        out << arr.data[i] << " ";
    }

    return out;
}

std::istream &operator>>(std::istream &in, IntArray &arr) {
    std::cout << "Size of int array: ";
    in >> arr.size;

    for (int i = 0; i < arr.size; i++) {
        in >> arr.data[i];
    }

    return in;
}


IntArray::~IntArray() {
    delete[] data;
}