#include "../include/hash.hpp"
#include "../include/index.hpp"
#include "../include/misc.hpp"
#include "../include/reads.hpp"

/*
 * Usage: ./build_indices <directory_path_for_reference_genome_files> <number_of_genome_files>\
 *		  <number_of_reads> <read_length> <mapper_file_name> \
 *        <kmer_length> <no_of_hash_functions> \
 *        <bloom_filter_minimum_size> <bloom_filter_maximum_size> \
 *        <bloom_filter_minimum_number_of_hashes> <bloom_filter_maximum_number_of_hashes> \ 
 *        <bloom_filter_projected_element_count> <bloom_filter_false_positive_probability> \
 *        <bloom_filter_random_seed> <bloom_filter_number_of_hashes> <bloom_filter_table_size> 
 */

int main (int argc, const char * argv[]) 
{
	if (argc!=6) {
		printf("Invalid arguments\n");
		return 0;
	}
	char genome_folder[100]; 
	strcpy(genome_folder,argv[1]);
	uint number_of_genome_files = atoi(argv[2]);
	uint number_of_reads = atoi(argv[3]);
	uint read_length = atoi(argv[4]);
	char mapper_file_name[100];
	strcpy(mapper_file_name,argv[5]);

	//uint kmer_length = atoi(argv[6]);
	//uint hash_function_count = atoi(argv[7]);
	
	/*
	unsigned long long int bloom_filter_minimum_size = atoll(argv[6]);
	unsigned long long int bloom_filter_maximum_size = atoll(argv[7]);
	uint bloom_filter_minimum_number_of_hashes = atoi(argv[8]);
	uint bloom_filter_maximum_number_of_hashes = atoi(argv[9]);
	unsigned long long int bloom_filter_projected_element_count = atoll(argv[10]);
	double bloom_filter_false_positive_probability = atof(argv[11]);
	unsigned long long int bloom_filter_random_seed = atoll(argv[12]);
	uint bloom_filter_number_of_hashes = atoi(argv[13]);
	unsigned long long int bloom_filter_table_size = atoll(argv[14]);
	*/

	create_read_files(genome_folder, number_of_genome_files, number_of_reads, read_length, mapper_file_name);
	
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