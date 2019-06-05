//
// Created by jeanlee on 5/06/19.
//

#ifndef CODE_GEOPROGRESSION_H
#define CODE_GEOPROGRESSION_H


class geo_iterator{
    int item;
    int base;
    friend class GeoProgression;
    geo_iterator(int item, int inc): item{item}, base{inc} {}

public:
    bool operator==(const geo_iterator& other) const;
    bool operator!=(const geo_iterator& other) const;
    int& operator*();
    geo_iterator& operator++();
    geo_iterator& operator++(int);
};

class GeoProgression{
    long start;
    long stop;
    long base;
public:
    GeoProgression():start{1}, stop{0}, base{0} {};
    GeoProgression(long start, long stop, long base): start{start}, stop{stop}, base{base} {};
    //long nextValue();
    using iterator = geo_iterator;
    iterator begin() const {
        return GeoProgression::iterator(start,base);
    }
    iterator end() const{
        return GeoProgression::iterator(stop,base);
    }
};


bool geo_iterator::operator==(const geo_iterator &other) const {
    return item == other.item;
}

bool geo_iterator::operator!=(const geo_iterator &other) const {
    return item < other.item;
}

int &geo_iterator::operator*() {
    return item;
}

geo_iterator &geo_iterator::operator++() {
    item *= base;
    return *this;
}

geo_iterator &geo_iterator::operator++(int) {
    auto it = this;
    ++(*this);
    return *it;
}


#endif //CODE_GEOPROGRESSION_H
