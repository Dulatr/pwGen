# Password Security

A few things to mention before proceeding to use this program. 

Firstly, I make no guarantees that this password generation technique is going to be "uncrackable". Anyone who knows the open source code provided could likely come up with some method to create a hash table. Always use safe practices, like avoid websites that don't have a maximum number of attempts or has a history of date breaches.

A better method here would be to require a new seed each rand() call such as seeding by the machine cycle, johnson noise and possibly many others I've no knowledge of at this time. 

#### Combinations

There are 85 possible characters to choose from for a password which is pretty much all printable ASCII characters. The minimum length I've defined is 12 for a string, so the minimum possible combinations is on the order of ~10^14 and the upper bound of ~10^24. Passwords of length 40 are considered "strong" from pwGen with an information entropy of 256 bits (in theory, see [Wiki page](https://en.wikipedia.org/wiki/Password_strength#Random_passwords)). Although options I include may likely reduce the pool of possible passwords, there's plenty of debate on the topic so do so at your own discretion.

# Like the project?

I'm using this program as a means for learning various string manipulation and PRNG applications. I invite anyone to try and develop improvements, feel free to use the  or even methods of cracking generated passwords As I learn more I'll apply it to the program in a reasonable way. See [program general info](https://github.com/Dulatr/pwGen/blob/master/README.md "home page") for new updates.