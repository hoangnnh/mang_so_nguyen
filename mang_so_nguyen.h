#ifndef MANGSONGUYEN_MANG_SO_NGUYEN_H
#define MANGSONGUYEN_MANG_SO_NGUYEN_H

#include <iostream>

class IntArray {

    friend std::ostream& operator<<(std::ostream&, const IntArray&);

    friend std::istream& operator>>(std::istream&, IntArray&);

private:
    int *data;
    int size;

public:

    IntArray();

    IntArray(const int[], const int);

    IntArray(const IntArray&);

    int getSize() {
        return size;
    }

    IntArray& operator=(const IntArray&);

    IntArray operator+(const IntArray&);

    // Prefix++
    IntArray &operator++();

    // Suffix++
    IntArray operator++(int);

    ~IntArray();

};


#endif //MANGSONGUYEN_MANG_SO_NGUYEN_H
