# pwGen
A simple implementation of a password generator that you can run at the command line.

## Usage
Run `make` after cloning. If wanted to have it executable outside of repository run `make install`

``pwGen <option> <value>``

option(s): 

``-l <integer value>     Edits length of generated password.``

``-s                     Prevents any adjacent character from repeating``


If no options are given it will output a 12 character password. 

This program is using a more secure RNG from sys/random.h, which does not rely on direct file reading from /dev/urandom/ so it should work on different distributions and without root permissions to perform [testing wanted!].

## Make it better? 

Feel free to use this little script however you see fit. Any suggested improvements would be great! I left a lot to be desired in terms of customization. 

# Recent changes

**04/2019**

Switched from using time() for PRNG to sys/random library. Finished SecureGen feature goal of improved source of entropy.