#include "../../include/io.hpp"

using namespace std;

void addShringlesToFile(string input, int k, string filename)
{
    vector<string> shringles1 = getShringles(input, k);
    //ofstream myfile;
    ofstream myfile;
    myfile.open (filename);
    if (myfile.is_open())
    {
        for(int i = 0; i < shringles1.size(); i++)
        {
            myfile << shringles1[i] << "\n";
        }
        myfile.close();
    }
}

vector<string> returnShringlesFromFile(string filename)
{
    vector<string> result;
    ifstream myReadFile;
    myReadFile.open(filename);
    char output[10000];
    if (myReadFile.is_open()) {
        while (myReadFile >> output) {
            result.push_back(output);
        }
    }
    return result;
}

void addMinSequenceToFile(string input1, string filename, uint m, uint k)
{
    vector<string> shringles1 = getShringles(input1, k);
    vector<pair<string, vector<uint> > > shringleHashPair1;
    vector<uint> randoms = generateRandoms(m);
    
    
    for(uint i =0 ;i<shringles1.size();i++)
    {
        size_t h1 = hash<string>{}(shringles1[i]);
        vector<uint> hashValues = generateRandomMinHashes(h1, randoms);
        shringleHashPair1.push_back(make_pair(shringles1[i], hashValues));
    }
    
    
    for(uint i = 0; i< shringleHashPair1.size(); i++)
    {
        pair<string, vector<uint> > temp = shringleHashPair1[i];
        vector<uint> tempVector = temp.second;
    }
    
    vector<uint> minSequence1 = getMinSequence(shringleHashPair1);
    
    ofstream myfile;
    myfile.open (filename);
    if (myfile.is_open())
    {
        for(int i = 0; i < minSequence1.size(); i++)
        {
            myfile << minSequence1[i] << "\n";
        }
        myfile.close();
    }
    
}

vector<uint> returnMinSequenceFromFile(string filename)
{
    vector<uint> result;
    ifstream myReadFile;
    myReadFile.open(filename);
    char output[10000];
    if (myReadFile.is_open()) {
        while (myReadFile >> output) {
            result.push_back(stoi(output));
        }
    }
    return result;
    
    
}