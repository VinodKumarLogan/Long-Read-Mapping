#include <fstream>
#include "../src/bloom_filter/bloom_filter.hpp"

bloom_filter get_bloom_filter(const char*);
void save_bloom_filter(const char*, bloom_filter);