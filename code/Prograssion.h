//
// Created by jeanlee on 5/06/19.
//

#ifndef CODE_PROGRASSION_H
#define CODE_PROGRASSION_H

#include "GeoProgression.h"

class arith_iterator{
    int item;
    int inc;
    friend class ArithProgression;
    arith_iterator(int item, int inc): item{item}, inc{inc} {}

public:
    bool operator==(const arith_iterator& other) const;
    bool operator!=(const arith_iterator& other) const;
    int& operator*();
    arith_iterator& operator++();
    arith_iterator& operator++(int);
};

class ArithProgression{
    long start;
    long stop;
    long inc;
public:
    ArithProgression():start{0}, stop{0}, inc{0} {};
    ArithProgression(long start, long stop, long inc): start{start}, stop{stop}, inc{inc} {};
    //long nextValue();
    using iterator = arith_iterator;
    iterator begin() const {
        return ArithProgression::iterator(start,inc);
    }
    iterator end() const{
        return ArithProgression::iterator(stop,inc);
    }
};


bool arith_iterator::operator==(const arith_iterator &other) const {
    return item == other.item;
}

bool arith_iterator::operator!=(const arith_iterator &other) const {
    return item < other.item;
}

int &arith_iterator::operator*() {
    return item;
}

arith_iterator & arith_iterator::operator++() {
    item += inc;
    return *this;
}

arith_iterator & arith_iterator::operator++(int) {
    auto it = this;
    ++(*this);
    return *it;
}

#endif //CODE_PROGRASSION_H
