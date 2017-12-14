#include "common.hpp"
#include "../src/bloom_filter/bloom_filter.hpp"
#include <set>

float minHash(string, string, uint, uint);
float containmentHash(string, string, uint, uint);
vector<uint> getMinSequence(vector<pair<string,vector<uint> > >);
vector<string> getMinSequenceStrings(vector<pair<string,vector<uint> > >);
float containment_hash_query(string , uint , uint , bloom_filter* );
float min_hash_query(string, uint, uint, vector<uint>);

