#include "../include/hash.h"
#include "../include/index.h"

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
    srand(time(NULL));
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

void minHash(string input1, string input2, uint m, uint k)
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
    
    cout << "STRING 1 :" << endl;
    for(uint i = 0; i< shringleHashPair1.size(); i++)
    {
        pair<string, vector<uint> > temp = shringleHashPair1[i];
        cout << temp.first << " " << endl;
        vector<uint> tempVector = temp.second;
        for(uint j =0; j< tempVector.size();j++)
        {
            cout << tempVector[j] << endl;
        }
    }
    
    cout << "STRING 2 :" << endl;
    
    for(uint i = 0; i< shringleHashPair2.size(); i++)
    {
        pair<string, vector<uint> > temp = shringleHashPair2[i];
        cout << temp.first << " " << endl;
        vector<uint> tempVector = temp.second;
        for(uint j =0; j< tempVector.size();j++)
        {
            cout << tempVector[j] << endl;
        }
    }
    
    vector<uint> minSequence1 = getMinSequence(shringleHashPair1);
    vector<uint> minSequence2 = getMinSequence(shringleHashPair2);
    cout << "MIN SEQUENCE 1 : " << endl;
    for(int i =0; i< minSequence1.size(); i++)
    {
        cout <<minSequence1[i]<< endl;
    }
    
    cout << "MIN SEQUENCE 2 : " << endl;
    for(int i =0; i< minSequence2.size(); i++)
    {
        cout <<minSequence2[i]<< endl;
    }
    float jacardIndex = getJacardIndex(minSequence1,minSequence2);
    cout << "JACARD INDEX : "<< jacardIndex << endl;
}