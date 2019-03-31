#make file, install target just places compiled pwGen into $HOME/bin
CC=gcc
DIR=/home/$$USER/bin

pwGen: Main/pwGen.c
	$(CC) -o pwGen $<
Tests: Tests/PsuedoWords.c
	$(CC) -o PsuedoWords $<
install:
	make pwGen
	mv pwGen $(DIR)

