# pwGen
A simple implementation of a password generator that you can run at the command line.

## Usage
Run `make` after cloning. If wanted to have it executable outside of repository run `make install`

``pwGen <option> <value>``

option(s): 

``-l <integer value>     Edits length of generated password.``

``-s                     Prevents any adjacent character from repeating``


If no options are given it will output a 12 character password. 

Due to the nature of the seed (time(NULL)), rapid execution will result in the same password being generated. It's not recommended for large batch password generation, but it's possible if you just allow the system to sleep between executions.

## Make it better? 

Feel free to use this little script however you see fit. Any suggested improvements would be great! I left a lot to be desired in terms of customization. 
