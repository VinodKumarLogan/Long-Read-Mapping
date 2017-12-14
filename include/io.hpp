#include "common.hpp"
#include "misc.hpp"
#include "random.hpp"
#include "hash.hpp"
#include <fstream>
#include "../src/bloom_filter/bloom_filter.hpp"

void get_bloom_filter(const char*, bloom_filter*);
void save_bloom_filter(string, const char*, bloom_parameters, uint);
void addShringlesToFile(string, int, string);
vector<string> returnShringlesFromFile(string);
void addMinSequenceToFile(string, string, uint, uint);
vector<uint> returnMinSequenceFromFile(string);