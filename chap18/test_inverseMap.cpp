// random_shuffle example
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <cassert>
#include "inverseMap.hpp"

using namespace graph_algo;

int main (int argc, char *argv[]) {
    unsigned seed = std::time(0);
    if (argc > 1) {
        seed = std::stoi(argv[1]);
    }

    std::srand ( seed );
    std::vector<int> vec;

    // set some values:
    for (int i=0; i<10; ++i) vec.push_back(i); // 0 1 2 3 4 5 6 7 8 9

    // using built-in random generator:
    std::random_shuffle ( vec.begin(), vec.end() );

    std::cout << "original map: \n";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << i << " -> " << vec[i] << "\n";
    }

    std::cout << '\n';

    std::vector<int> vec2 = inverseMap(vec);
    std::cout << "inverse map: \n";
    for (int i = 0; i < vec2.size(); ++i) {
        std::cout << i << " -> " << vec2[i] << "\n";
    }

    std::cout << '\n';

    std::vector<int> vec3 = inverseMap(vec2);
    assert(vec3 == vec);

    return 0;
}
