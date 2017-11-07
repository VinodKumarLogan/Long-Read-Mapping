import numpy as np

def buildShortAndLongReads(m, lenSmallString, lenLargeString, shortReads, longReads):
	for i in range(m):
		shortRead = ''.join(np.random.choice(['A', 'C', 'T', 'G'], lenSmallString))
		longRead = ''.join(np.random.choice(['A', 'C', 'T', 'G'], lenLargeString)) + shortRead
		shortReads.write(shortRead + '\n')
		longReads.write(longRead + '\n')

def main():
	numberOfSequences = 10
	shortReadLength = 100
	longReadLength = 1000
	shortReadPath = '../data/short_read.txt'
	longReadPath = '../data/long_read.txt'

	shortReads = open(shortReadPath,'w')
	longReads = open(longReadPath,'a')	

	buildShortAndLongReads(numberOfSequences, shortReadLength, longReadLength, shortReads, longReads)
	
	shortReads.close()
	longReads.close()

if __name__=="__main__":
	main()
