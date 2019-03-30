#make file, install target just places compiled pwGen into $HOME/bin
DIR=/home/$$USER/bin

pwGen:  
	gcc -o pwGen Main/pwGen.c
install:
	make pwGen
	mv pwGen $(DIR)

