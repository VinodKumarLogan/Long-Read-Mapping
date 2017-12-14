#include "../../include/io.hpp"

using namespace std;

void get_bloom_filter(const char* filename, bloom_filter* filter) 
{
	ifstream file;
    file.open(filename, ios::in);
    file.read((char*)filter, sizeof(bloom_filter));
    file.close();
}

void save_bloom_filter(string input1, const char* filename, bloom_parameters parameters, uint kMerLength) 
{
	vector<string> shringles2 = getShringles(input1, kMerLength);
	bloom_filter *filter = new bloom_filter(parameters);
	for(uint i =0 ;i<shringles2.size();i++)
    {
        filter->insert(shringles2[i]);
    }
	ofstream file;
    file.open(filename, ios::out);
    file.write((char*)filter, sizeof(bloom_filter));
    file.close();
}