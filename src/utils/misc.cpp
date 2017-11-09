#include "../../include/misc.hpp"
#include <iomanip>

vector<string> getShringles(string s, uint k)
{
    vector<string> shringles1;
    for(uint i=0; i<s.size()-k+1;i++)
    {
        shringles1.push_back(s.substr(i,k));
    }
    return shringles1;
}

set<string> getShringlesSet(string s, uint k)
{
    set<string> shringles1;
    for(uint i=0; i<s.size()-k+1;i++)
    {
        shringles1.insert(s.substr(i,k));
    }
    return shringles1;
}

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
    cout.setf(ios::fixed);
    //cout << setprecision(3) << a << endl;

	for(int i =0;i<result.size();i++)
	{
		for(int j = 0; j< result[i].size();j++)
		{
			cout << setprecision(3) << result[i][j][0] << ", " << result[i][j][1] << ", " << result[i][j][2] << "\t";
		}
        cout << endl;
	}
}
