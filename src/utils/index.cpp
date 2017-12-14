#include "../../include/index.hpp"
#include "../../include/misc.hpp"

float getMinHashIndex(vector<uint> sequence1, vector<uint> sequence2, uint minHashNumber)
{
    uint intesectionGroup = 0;
    uint unionGroup = 0;
    for(uint i =0; i<sequence1.size();i++)
    {
        if(sequence1[i] == sequence2[i])
        {
            intesectionGroup++;
            unionGroup++;
        }
        else
        {
            unionGroup += 2;
        }
    }
    float index = float(intesectionGroup)/float(minHashNumber);
    return index;
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
    float unionSize =  (float)unionSet.size();
    float jacardIndex = interesectionSize / unionSize;
    return jacardIndex;
}

float jaccard_index_query(string shortRead, set<string> loSingles, uint iSingleLen)
{
    set<string>  shSingles = getShringlesSet(shortRead, iSingleLen);
    vector<string> intersectionSet;
    vector<string> unionSet;
    set_intersection(loSingles.begin(),loSingles.end(),shSingles.begin(),shSingles.end(),back_inserter(intersectionSet));
    set_union(loSingles.begin(),loSingles.end(),shSingles.begin(),shSingles.end(),back_inserter(unionSet));
    float interesectionSize =  (float)intersectionSet.size();
    float unionSize =  (float)unionSet.size();
    float jacardIndex = interesectionSize / unionSize;
    return jacardIndex;
}