#include <random>
std::mt19937 rng_engine{(size_t)(new char)};
std::uniform_int_distribution<int> dist{1, 1000000000};//1-1000 inclusive
int random_int = dist(rng_engine);
