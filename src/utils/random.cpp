#include "../../include/random.hpp"

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