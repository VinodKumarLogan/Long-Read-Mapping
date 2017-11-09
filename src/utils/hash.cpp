#include "../../include/hash.hpp"
#include "../../include/index.hpp"
#include "../../include/random.hpp"
#include "../../include/misc.hpp"
#include "../bloom_filter/bloom_filter.hpp"

vector<uint> getMinSequence(vector<pair<string,vector<uint> > > hashValuesPair)
{
    vector<uint> minSequence;
    for(int i=0; i< hashValuesPair[0].second.size();i++)
    {
        int min = hashValuesPair[0].second[i];
        for(int j =1; j< hashValuesPair.size();j++)
        {
            if(min > hashValuesPair[j].second[i])
            {
                min = hashValuesPair[j].second[i];
            }
        }
        minSequence.push_back(min);
    }
    return minSequence;
}

vector<string> getMinSequenceStrings(vector<pair<string,vector<uint> > > hashValuesPair)
{
    vector<string> minSequence;
    for(int i=0; i< hashValuesPair[0].second.size();i++)
    {
        int min = hashValuesPair[0].second[i];
        string minString = hashValuesPair[0].first;
        for(int j =1; j< hashValuesPair.size();j++)
        {
            if(min > hashValuesPair[j].second[i])
            {
                min = hashValuesPair[j].second[i];
                minString = hashValuesPair[j].first;
            }
        }
        minSequence.push_back(minString);
    }
    return minSequence;
}

float minHash(string input1, string input2, uint m, uint k)
{
    vector<string> shringles1 = getShringles(input1, k);
    vector<string> shringles2 = getShringles(input2, k);
    vector<pair<string, vector<uint> > > shringleHashPair1;
    vector<pair<string, vector<uint> > > shringleHashPair2;
    vector<uint> randoms = generateRandoms(m);


    for(uint i =0 ;i<shringles1.size();i++)
    {
        size_t h1 = hash<string>{}(shringles1[i]);
        vector<uint> hashValues = generateRandomMinHashes(h1, randoms);
        shringleHashPair1.push_back(make_pair(shringles1[i], hashValues));
    }
    
    for(uint i =0 ;i<shringles2.size();i++)
    {
        size_t h2 = hash<string> {} (shringles2[i]);
        vector<uint> hashValues = generateRandomMinHashes(h2, randoms);
        shringleHashPair2.push_back(make_pair(shringles2[i], hashValues));
    }
    
    for(uint i = 0; i< shringleHashPair1.size(); i++)
    {
        pair<string, vector<uint> > temp = shringleHashPair1[i];
        vector<uint> tempVector = temp.second;
    }
    
    
    for(uint i = 0; i< shringleHashPair2.size(); i++)
    {
        pair<string, vector<uint> > temp = shringleHashPair2[i];
        vector<uint> tempVector = temp.second;
    }
    
    vector<uint> minSequence1 = getMinSequence(shringleHashPair1);
    vector<uint> minSequence2 = getMinSequence(shringleHashPair2);
    
    float minHashIndex = getMinHashIndex(minSequence1,minSequence2, m);
    return minHashIndex;
}

float containmentHash(string smallString, string largeString, uint noOfHashFns, uint kMerLength)
{
    bloom_parameters parameters;

    vector<string> shringles1 = getShringles(smallString, kMerLength);
    vector<string> shringles2 = getShringles(largeString, kMerLength);
    vector<pair<string, vector<uint> > > shringleHashPair1;
    
    parameters.projected_element_count = shringles2.size();
    parameters.maximum_number_of_hashes = noOfHashFns;
    parameters.compute_optimal_parameters();
    bloom_filter filter(parameters);

    //cout << shringles2.size() << endl;


    vector<uint> randoms = generateRandoms(noOfHashFns);
    for(uint i =0 ;i<shringles1.size();i++)
    {
        size_t h1 = hash<string>{}(shringles1[i]);
        vector<uint> hashValues = generateRandomMinHashes(h1, randoms);
        shringleHashPair1.push_back(make_pair(shringles1[i], hashValues));
    }

    vector<string> minSequence1 = getMinSequenceStrings(shringleHashPair1);

    for(uint i =0 ;i<shringles2.size();i++)
    {
        filter.insert(shringles2[i]);
    }

    uint intersectionCount = 0;

    for(uint i =0 ;i<minSequence1.size();i++) 
    {
        if (filter.contains(minSequence1[i]))
            intersectionCount++;
    } 
    
    float containmentIndex = (float)(intersectionCount - (int)(parameters.false_positive_probability*noOfHashFns))/(float)noOfHashFns;
    return containmentIndex;
}




