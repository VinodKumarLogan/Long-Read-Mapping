#include "../include/index.h"

float getJacardIndex(vector<uint> sequence1, vector<uint> sequence2)
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
    
    cout << "Intersection : "<< intesectionGroup << endl;
    cout << "Union : "<< unionGroup << endl;
    float index = float(intesectionGroup)/float(unionGroup);
    return index;
}