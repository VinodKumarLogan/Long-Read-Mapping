#include "../../include/io.hpp"

using namespace std;

void get_bloom_filter(const char* filename, bloom_filter* filter) 
{
	ifstream file;
    file.open(filename, ios::in);
    file.read((char*)filter, sizeof(bloom_filter));
    file.close();
}

void save_bloom_filter(const char* filename, bloom_filter* filter) 
{
	ofstream file;
    file.open(filename, ios::out);
    file.write((char*)filter, sizeof(bloom_filter));
    file.close();
}