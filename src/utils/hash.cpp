#include "../../include/hash.hpp"
#include "../../include/index.hpp"
#include "../bloom_filter/bloom_filter.hpp"
#include <set>

vector<string> getShringles(string s, uint k)
{
    vector<string> shringles1;
    for(uint i=0; i<s.size()-k+1;i++)
    {
        shringles1.push_back(s.substr(i,k));
    }
    return shringles1;
}

vector<uint> generateRandomMinHashes(uint hashValue,vector<uint> randoms)
{
    vector<uint> hashValues;
    hashValues.push_back(hashValue);
    for(uint i=0;i<randoms.size();i++)
    {
        uint temp = hashValue ^ randoms[i];
        hashValues.push_back(temp);
    }
    return hashValues;
}

vector<uint> generateRandoms(uint m)
{
    vector<uint> randoms;
    uint z;
    srand(1);
    for(uint l = 0; l<m-1;l++)
    {
        z = 0;
        for(uint i =0; i< 10; i++)
        {
            uint y = rand() % 10;
            z = z*10+y;
        }
        randoms.push_back(z);
    }
    return randoms;
}

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
    
    //cout << "STRING 1 :" << endl;
    for(uint i = 0; i< shringleHashPair1.size(); i++)
    {
        pair<string, vector<uint> > temp = shringleHashPair1[i];
        //cout << temp.first << " " << endl;
        vector<uint> tempVector = temp.second;
        for(uint j =0; j< tempVector.size();j++)
        {
            //cout << tempVector[j] << endl;
        }
    }
    
    //cout << "STRING 2 :" << endl;
    
    for(uint i = 0; i< shringleHashPair2.size(); i++)
    {
        pair<string, vector<uint> > temp = shringleHashPair2[i];
        //cout << temp.first << " " << endl;
        vector<uint> tempVector = temp.second;
        for(uint j =0; j< tempVector.size();j++)
        {
            //cout << tempVector[j] << endl;
        }
    }
    
    vector<uint> minSequence1 = getMinSequence(shringleHashPair1);
    vector<uint> minSequence2 = getMinSequence(shringleHashPair2);
    //cout << "MIN SEQUENCE 1 : " << endl;
    for(int i =0; i< minSequence1.size(); i++)
    {
        //cout <<minSequence1[i]<< endl;
    }
    
    //cout << "MIN SEQUENCE 2 : " << endl;
    for(int i =0; i< minSequence2.size(); i++)
    {
        //cout <<minSequence2[i]<< endl;
    }
    float minHashIndex = getMinHashIndex(minSequence1,minSequence2, m);
//    //cout << "MinHash INDEX : "<< jacardIndex << endl;
    return minHashIndex;
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

float containmentHash(string smallString, string largeString, uint noOfHashFns, uint kMerLength)
{
    bloom_parameters parameters;
    parameters.projected_element_count = largeString.size();
    parameters.false_positive_probability = 0.001;
    parameters.random_seed = 0xA5A5A5A5;
    parameters.compute_optimal_parameters();
    bloom_filter filter(parameters);

    vector<string> shringles1 = getShringles(smallString, kMerLength);
    vector<string> shringles2 = getShringles(largeString, kMerLength);
    vector<pair<string, vector<uint> > > shringleHashPair1;
    
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
    //cout << "Containment Index: " << containmentIndex << endl;
    return containmentIndex;
}

set<string> getShringlesSet(string s, unsigned int k)
{
    set<string> shringles1;
    for(unsigned int i=0; i<s.size()-k+1;i++)
    {
        shringles1.insert(s.substr(i,k));
    }
    return shringles1;
}


float getJacardIndex(string shortRead, string longRead, uint iSingleLen)
{
    set<string> loSingles = getShringlesSet(longRead, iSingleLen);
    set<string>  shSingles = getShringlesSet(shortRead, iSingleLen);
    vector<string> intersectionSet;
    vector<string> unionSet;
    set_intersection(loSingles.begin(),loSingles.end(),shSingles.begin(),shSingles.end(),back_inserter(intersectionSet));
    set_union(loSingles.begin(),loSingles.end(),shSingles.begin(),shSingles.end(),back_inserter(unionSet));
    float interesectionSize =  (float)intersectionSet.size();
    //cout << interesectionSize << endl;
    float unionSize =  (float)unionSet.size();
    //cout << unionSize << endl;
    float jacardIndex = interesectionSize / unionSize;
    //cout << jacardIndex << endl;
    return jacardIndex;
}




