# Long-Read-Mapping
Implementing Long Read Mapping Algorithms


Project Description: Implement MinHash and Containment Hash for long reads and a very basic mapper. Long reads are the results of third-generation sequencing of genomes and transcriptomes which, unlike the short read sequencing, (i.e. second or “next”-generation sequencing) methodologies, generate a very long substrings of the reference, but have a higher error rate compared to short reads (~10-15% vs <1% for short reads) and hence should be treated using algorithms, data structures and approaches other than those commonly used in short read analysis. Specifically, approaches that use the idea of Min Hashing or related algorithms have recently drawn a lot of attention in the computational biology community, and have been shown to be useful in assembling and mapping long reads. In this approach, which is borrowed from NLP and estimating document similarity, we use a Min Hash to approximate overlap of two long reads or approximately map a long read to a reference. In addition to this, another approach named containment hashing has been proposed that as an advantage to Min Hashing is addressing potential length differences between the two strings being compared. The basic idea of Min Hashing is well explained in Figure 1 in this paper. 

The goal of this project is to implement the Min Hash and Containment Hash approaches in C++ (one of the implementations is available in Python in MinHashMetagenomics repository on github) and using the simulators SimulatedBiologicalData and/or SimulatedBiologicalDataSmall, compare the performance of these two approaches on the simulated data. Then we would like to implement a very basic mapper that given a set of input long reads and a reference (a genome or transcriptome) maps long reads to the reference just if the Min Hash sketch of long read and genome have a similarity higher than a threshold.

Input: None (Except some source codes to start with)

Output: 
Simulated Data
Min Hash algorithm implemented in C++
Containment Hash algorithm implemented in C++
Mapper function

Midway Result: Implementing Min Hash and Containment Hash approaches

keywords: C++, Locality sensitive hashing, Min Hash, Containment Hash, Long Reads

