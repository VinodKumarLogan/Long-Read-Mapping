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
	
	float indices[number_of_reads][number_of_genome_files][3];

	for (int i=0;i<number_of_genome_files;i++) {
		string filename = genome_folder+ std::string("/genome") + std::to_string(i);
		string shingle_filename = filename + ".shingle";
		string min_filename = filename + ".min";
		string bloom_filename = filename + ".bloom";

		set<string> shingles = returnShringlesFromFile(shingle_filename);
		vector<uint> minsequences = returnMinSequenceFromFile(min_filename);
		bloom_filter filter;
		get_bloom_filter(bloom_filename.c_str(), &filter); 

		std::ifstream t(long_read_filename);
		std::stringstream buffer;
		buffer << t.rdbuf();

		for (int j=0;j<number_of_reads;j++) {
			string read;
			getline(buffer,read,'\n');
			indices[j][i][0] = jaccard_index_query(read, shingles,kmer_length); //Jaccard
			indices[j][i][1] = min_hash_query(read, no_of_hash_functions, kmer_length, minsequences); //Minhash
			indices[j][i][2] = containment_hash_query(read, no_of_hash_functions, kmer_length, &filter); //Containment
		}
	}
	
	std::ifstream t(long_read_filename);
	std::stringstream buffer;
	buffer << t.rdbuf();

	cout << "Long Read\t\t\tMax Jaccard Genome ID\tMax Minhash Genome ID\tMax Containment Genome ID\n"; 
	for (int i=0;i<number_of_reads;i++) {
		string read;
		getline(buffer,read,'\n');
		cout << "\n" << read << "\t\t";
		for (int k=0;k<3;k++) {
			int max = 0;
			for(int j=1;j<number_of_genome_files;j++) {
				if (indices[i][j][k]>= indices[i][max][k])
					max = j;
			}
			cout << indices[i][max][k] << "\t";
		}
	}

    return 0;
}