#include "../include/hash.hpp"
#include "../include/index.hpp"
#include "../include/misc.hpp"
#include "../include/reads.hpp"
#include "../include/io.hpp"
#include <sstream>

/*
 * Usage: ./query <long_read_filename> <directory_path_for_reference_genome_files> <number_of_genome_files>\
 *		  <number_of_reads> <read_length> <mapper_file_name> \
 *        <kmer_length> <no_of_hash_functions>
 */

int main (int argc, const char * argv[]) 
{
	if (argc!=8) {
		printf("Invalid arguments\n");
		return 0;
	}
	string long_read_filename = argv[1];
	char genome_folder[100]; 
	strcpy(genome_folder,argv[2]);
	uint number_of_genome_files = atoi(argv[3]);
	uint number_of_reads = atoi(argv[4]);
	//uint read_length = atoi(argv[5]);
	char mapper_file_name[100];
	strcpy(mapper_file_name,argv[6]);

	uint kmer_length = atoi(argv[7]);
	int no_of_hash_functions = atoi(argv[8]);
	
	float indices[number_of_reads][3];

	for (int i=0;i<number_of_genome_files;i++) {
		string filename = genome_folder+ std::string("/") + std::to_string(i);
		string shingle_filename = filename + ".shingle";
		string min_filename = filename + ".min";
		string bloom_filename = filename + ".bloom";

		vector<string> shingles = returnShringlesFromFile(shingle_filename);
		vector<uint> minsequences = returnMinSequenceFromFile(min_filename);
		bloom_filter filter;
		get_bloom_filter(bloom_filename.c_str(), &filter); 

		std::ifstream t(long_read_filename);
		std::stringstream buffer;
		buffer << t.rdbuf();

		for (int j=0;j<number_of_reads;j++) {
			string read;
			getline(buffer,read,'\n');
			//indices[j][0] = ; //Jaccard
			indices[j][1] = min_hash_query(read, no_of_hash_functions, kmer_length, minsequences); //Minhash
			indices[j][2] = containment_hash_query(read, no_of_hash_functions, kmer_length, &filter); //Containment
		}
	}
	
	/*
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
	*/
    return 0;
}