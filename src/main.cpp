<<<<<<< HEAD
#include "boost/program_options.hpp" 
=======
//#include "boost/program_options.hpp" 
>>>>>>> 3becf3b6fdf6b9813b897181bb27f70d1cca2573
#include "../include/hash.hpp"
#include "../include/index.hpp"
#include "../include/misc.hpp"

<<<<<<< HEAD
namespace po = boost::program_options;
=======
//namespace po = boost::program_options;
>>>>>>> 3becf3b6fdf6b9813b897181bb27f70d1cca2573
/*
bool processCommandLine(int argc, char **argv, string short_read_path, string long_read_path, uint hash, uint kmer)
{
    try
    {
        po::options_description desc("Program Usage", 1024, 512);
        desc.add_options()
          ("help,h", "Usage: ./result -")
          ("short-read,s", po::value<string>(&short_read_path)->required(), "path of file to short reads")
          ("long-read,l", po::value<string>(&long_read_path)->required(), "path of file to long reads")
          ("hash-count,c", po::value<uint>(&hash)->required(), "number of hash functions")
          ("k-mer-length,k", po::value<uint>(&kmer)->required(), "legth of k mers")
        ;

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);

        if (vm.count("help"))
        {
            std::cout << desc << "\n";
            return false;
        }
        po::notify(vm);
    }
    catch(std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return false;
    }
    catch(...)
    {
        std::cerr << "Unknown error!" << "\n";
        return false;
    }

    return true;
}
*/
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