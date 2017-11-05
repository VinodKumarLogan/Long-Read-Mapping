import numpy as np

def buildShortAndLongReads(m, len_small_string, len_large_string, short_reads, long_reads):
	for i in range(m):
		short_read = ''.join(np.random.choice(['A', 'C', 'T', 'G'], len_small_string))
		long_read = ''.join(np.random.choice(['A', 'C', 'T', 'G'], len_large_string)) + short_read
		short_reads.write(short_read + '\n')
		print(short_read)
		long_reads.write(long_read + '\n')
		print(long_read)
	short_reads.close()
	long_reads.close()

short_read_path = '..\\data\\short_read.txt'
short_reads = open(short_read_path,'w')
long_read_path = '..\\data\\long_read.txt'
long_reads = open(long_read_path,'a')		
buildShortAndLongReads(10, 100, 1400, short_reads, long_reads)