clang++ -g -Wall -std=c++11 src/min_hash.cpp src/utils/hash.cpp src/utils/index.cpp -o bin/min_hash
clang++ -g -Wall -std=c++11 src/containment_hash.cpp src/utils/hash.cpp src/utils/index.cpp -o bin/containment_hash
clang++ -g -Wall -std=c++11 src/jacard_index.cpp src/utils/hash.cpp src/utils/index.cpp -o bin/jacard_index
clang++ -g -Wall -std=c++11 src/project5.cpp src/utils/hash.cpp src/utils/index.cpp -o bin/result
