#include "../include/hash.hpp"
#include "../include/index.hpp"
#include "../include/misc.hpp"

int main (int argc, const char * argv[]) 
{
	string path1 = argv[1];
	string path2 = argv[2];
	uint numberHash = atoi(argv[3]);
	uint numberKMers = atoi(argv[4]);
	vector<string> shortStrings = readFromPath(path1);
	vector<string> longStrings = readFromPath(path2);
	vector<vector<vector<float>>> result;
	vector<vector<float>> rowVector;
	vector<float> everyPair;
	for(int i =0; i< shortStrings.size();i++)
	{
		rowVector.clear();
		for(int j =0; j< longStrings.size();j++)
		{
			everyPair.clear();
			float jakardIndex = getJacardIndex(shortStrings[i], longStrings[j], numberKMers);
			float minHashIndex = minHash(shortStrings[i], longStrings[j], numberHash, numberKMers);
			float containmentHashIndex = containmentHash(shortStrings[i], longStrings[j], numberHash, numberKMers);
			everyPair.push_back(jakardIndex);
			everyPair.push_back(minHashIndex);
			everyPair.push_back(containmentHashIndex);
			rowVector.push_back(everyPair);
		}
		result.push_back(rowVector);
	}
	printResult(result);

    return 0;
}