# pwGen
A simple implementation of a password generator that you can run at the command line.

## Usage
Compile with gcc or cc, make sure the output is executable.

``pwGen <option> <value>``

option(s): 

``-l <integer value>     Edits length of generated password.``

``-s                     Prevents any adjacent character from repeating``


If no options are given it will output a 12 character password. 

This program using a more secure RNG from sys/random.h, which does not rely on direct file reading from /dev/urandom/ so it should work on different distributions and without root permissions to perform. 

## Make it better? 

Feel free to use this little script however you see fit. Any suggested improvements would be great! I left a lot to be desired in terms of customization. 
