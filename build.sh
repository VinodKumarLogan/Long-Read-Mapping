#clang++ -g -Wall -std=c++11 src/min_hash.cpp src/utils/misc.cpp src/utils/hash.cpp src/utils/random.cpp src/utils/index.cpp -o bin/min_hash
#clang++ -g -Wall -std=c++11 src/containment_hash.cpp src/utils/misc.cpp src/utils/hash.cpp src/utils/random.cpp src/utils/index.cpp -o bin/containment_hash
#clang++ -g -Wall -std=c++11 src/jacard_index.cpp src/utils/misc.cpp src/utils/hash.cpp src/utils/index.cpp -o bin/jacard_index
#clang++ -g -Wall -std=c++11 src/main.cpp src/utils/hash.cpp src/utils/random.cpp src/utils/misc.cpp src/utils/index.cpp src/utils/bloom_io.cpp -o bin/result
clang++ -g -Wall -std=c++11 src/build_indices.cpp src/utils/hash.cpp src/utils/random.cpp src/utils/misc.cpp src/utils/index.cpp src/utils/reads.cpp src/utils/bloom_io.cpp src/utils/kmer_io.cpp -o bin/indices
clang++ -g -Wall -std=c++11 src/query.cpp src/utils/hash.cpp src/utils/random.cpp src/utils/misc.cpp src/utils/index.cpp src/utils/reads.cpp src/utils/bloom_io.cpp src/utils/kmer_io.cpp -o bin/indices
