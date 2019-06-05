#include <iostream>
#include "Prograssion.h"

int main() {

    for(auto it : ArithProgression{0,10,2})
        std::cout << it << " ";
    std::cout << std::endl;

    for(auto it : GeoProgression{1,10,2})
        std::cout << it << " ";
    std::cout << std::endl;

    return 0;
}