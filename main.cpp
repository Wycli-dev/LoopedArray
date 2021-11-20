#include <iostream>

#include "LoopedArray.h"
#include "LoopedArrayTemplate.h"

int main() {
    LoopedArray<int> la(100);

    la.append_first(10);
    la.append_first(20);
    la.append_last(30);
    la.append_last(40);
    la.insert(15, 2);

    for (int i = 0; i < 5; i++) std::cout << la[i] << std::endl;

    return 0;
}
