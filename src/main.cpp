//
//  main.cpp
//  Computational Biology
//
//  Created by Anand Kulkarni on 11/1/17.
//  Copyright © 2017 Anand Kulkarni. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<string> getShringles(string s, unsigned int k)
{
    vector<string> shringles1;
    for(unsigned int i=0; i<s.size()-k+1;i++)
    {
        shringles1.push_back(s.substr(i,k));
    }
    return shringles1;
}

vector<unsigned int> generateRandomMinHashes(unsigned int hashValue,vector<unsigned int> randoms)
{
    vector<unsigned int> hashValues;
    hashValues.push_back(hashValue);
    for(unsigned int i=0;i<randoms.size();i++)
    {
        unsigned int temp = hashValue ^ randoms[i];
        hashValues.push_back(temp);
    }
    return hashValues;
}

vector<unsigned int> generateRandoms(unsigned int m)
{
    vector<unsigned int> randoms;
    unsigned int z;
    srand(time(NULL));
    for(unsigned int l = 0; l<m-1;l++)
    {
        z = 0;
        for(unsigned int i =0; i< 10; i++)
        {
            unsigned int y = rand() % 10;
            z = z*10+y;
        }
        randoms.push_back(z);
    }
//    cout<<"Randoms : " << endl;
//    for(unsigned int i=0; i<m-1;i++)
//    {
//        cout << randoms[i] << endl;
//    }
    return randoms;
}

vector<unsigned int> getMinSequence(vector<pair<string,vector<unsigned int>>> hashValuesPair)
{
    vector<unsigned int> minSequence;
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

float getJacardIndex(vector<unsigned int> sequence1, vector<unsigned int> sequence2)
{
    unsigned int intesectionGroup = 0;
    unsigned int unionGroup = 0;
    for(unsigned int i =0; i<sequence1.size();i++)
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

void minHash(string input1, string input2, unsigned int m, unsigned int k)
{
    vector<string> shringles1 = getShringles(input1, k);
    vector<string> shringles2 = getShringles(input2, k);
    vector<pair<string, vector<unsigned int>>> shringleHashPair1;
    vector<pair<string, vector<unsigned int>>> shringleHashPair2;
    vector<unsigned int> randoms = generateRandoms(m);
    for(unsigned int i =0 ;i<shringles1.size();i++)
    {
        size_t h1 = hash<string>{}(shringles1[i]);
        vector<unsigned int> hashValues = generateRandomMinHashes(h1, randoms);
        shringleHashPair1.push_back(make_pair(shringles1[i], hashValues));
    }
    
    for(unsigned int i =0 ;i<shringles2.size();i++)
    {
        size_t h2 = hash<string>{}(shringles2[i]);
        vector<unsigned int> hashValues = generateRandomMinHashes(h2, randoms);
        shringleHashPair2.push_back(make_pair(shringles2[i], hashValues));
    }
    
    cout << "STRING 1 :" << endl;
    for(unsigned int i = 0; i< shringleHashPair1.size(); i++)
    {
        pair<string, vector<unsigned int>> temp = shringleHashPair1[i];
        cout << temp.first << " " << endl;
        vector<unsigned int> tempVector = temp.second;
        for(unsigned int j =0; j< tempVector.size();j++)
        {
            cout << tempVector[j] << endl;
        }
    }
    
    cout << "STRING 2 :" << endl;
    
    for(unsigned int i = 0; i< shringleHashPair2.size(); i++)
    {
        pair<string, vector<unsigned int>> temp = shringleHashPair2[i];
        cout << temp.first << " " << endl;
        vector<unsigned int> tempVector = temp.second;
        for(unsigned int j =0; j< tempVector.size();j++)
        {
            cout << tempVector[j] << endl;
        }
    }
    
    vector<unsigned int> minSequence1 = getMinSequence(shringleHashPair1);
    vector<unsigned int> minSequence2 = getMinSequence(shringleHashPair2);
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

    int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<string> shringles = getShringles("ABCDE",3);
//    for(unsigned int i =0 ; i< shringles.size();i++)
//    {
//        cout << shringles[i]<< endl;
//    }
//    minHash("CATGGACCGACCAG", "GCAGTACCGATCGT",4,3);
      minHash("ABCDEF", "ABCDEE",4,3);

    return 0;
}
