#include "../include/hash.hpp"


//using namespace std;


//set<string> getShringlesSet(string s, unsigned int k)
//{
//    set<string> shringles1;
//    for(unsigned int i=0; i<s.size()-k+1;i++)
//    {
//        shringles1.insert(s.substr(i,k));
//    }
//    return shringles1;
//}
//
//float getJacardIndex(string shortRead, string longRead, int iSingleLen)
//{
//    set<string> loSingles = getShringlesSet(longRead, iSingleLen);
//    set<string>  shSingles = getShringlesSet(shortRead, iSingleLen);
//    vector<string> intersectionSet;
//    vector<string> unionSet;
//    set_intersection(loSingles.begin(),loSingles.end(),shSingles.begin(),shSingles.end(),back_inserter(intersectionSet));
//    set_union(loSingles.begin(),loSingles.end(),shSingles.begin(),shSingles.end(),back_inserter(unionSet));
//    float interesectionSize =  (float)intersectionSet.size();
//    cout << interesectionSize << endl;
//    float unionSize =  (float)unionSet.size();
//    cout << unionSize << endl;
//    float jacardIndex = interesectionSize / unionSize;
//    cout << jacardIndex << endl;
//    return jacardIndex;
//}

int main(int argc, const char * argv[]) {
    cout << getJacardIndex("ABCDE","ABCFE",3) <<endl;
    return 0;
}

