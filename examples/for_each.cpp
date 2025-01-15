
#define USE_PARLAY

#include "parlay_hash/unordered_map.h"

#include <iostream>


int main()
{
    parlay::parlay_unordered_map<int, int> M(1'048'576);

    M.for_each(
        [&](const std::pair<int, int>&)
        {}
    );

    return 0;
}
