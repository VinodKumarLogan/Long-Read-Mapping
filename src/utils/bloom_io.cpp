#include "../../include/io.hpp"

using namespace std;

bloom_filter get_bloom_filter(const char* filename) 
{
	ifstream file;
	bloom_filter filter;
    file.open(filename, ios::in);
    file.read((char*)&filter, sizeof(bloom_filter));
    file.close();
    return filter;
}

void save_bloom_filter(const char* filename, bloom_filter filter) 
{
	ofstream file;
    file.open(filename, ios::out);
    file.write((char*)&filter, sizeof(bloom_filter));
    file.close();
}