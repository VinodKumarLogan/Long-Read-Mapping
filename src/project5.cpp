#include "../include/hash.hpp"

vector<string> readFromPath(string path)
{
    vector<string> stringCollection;
    string line;
    ifstream fileDisc(path);
    if (fileDisc.is_open())
    {
        while ( getline (fileDisc,line) )
        {
            stringCollection.push_back(line);
        }
    }
    return stringCollection;
}

void printResult(vector<vector<vector<float>>> result)
{
	for(int i =0;i<result.size();i++)
	{
		for(int j = 0; j< result[i].size();j++)
		{
			cout << result[i][j][0] << "," << result[i][j][1] << "," << result[i][j][2] << "  ";
		}
		cout << endl;
	}
}

void printFloatVector(vector<float> myVector)
{
	for(int i = 0;i<myVector.size();i++)
	{
		// cout << myVector[i] << " ";
	}
	// cout << endl;
}

void printStringVector(vector<string> myVector)
{
	for(int i = 0;i<myVector.size();i++)
	{
		// cout << myVector[i] << " ";
	}
	// cout << endl;
}


int main (int argc, const char * argv[]) {
	string path1 = argv[1];
	// cout << "PATH1 : " << path1<<endl; 
	string path2 = argv[2];
	// cout << "PATH2 : " << path2<<endl; 
	uint numberHash = atoi(argv[3]);
	// cout << "numberHash : " << numberHash<<endl; 
	uint numberKMers = atoi(argv[4]);
	// cout << "numberKMers : " << numberKMers<<endl; 
	vector<string> shortStrings = readFromPath(path1);
	// cout << "shortStrings : " ; printStringVector(shortStrings);
	vector<string> longStrings = readFromPath(path2);
	// cout << "longStrings : " ; printStringVector(longStrings);
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