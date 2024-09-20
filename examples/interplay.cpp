
#define USE_PARLAY

#include "parlay/parallel.h"
#include "parlay_hash/unordered_map.h"

#include <iostream>


int main()
{
    std::cerr << "#workers before init: " << parlay::num_workers() << "\n";

    parlay::parlay_unordered_map<int, int> M(1'048'576, true);

    std::cerr << "#workers after init:  " << parlay::num_workers() << "\n";

    return 0;
}
