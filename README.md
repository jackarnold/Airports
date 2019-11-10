CONTRIBUTIONS - 
Chris Go: KD tree implementation. KNN within KD tree. Helped with RPC debugging. Helped with code to read in places2k.txt. 
Jack Arnolds: Trie implementation.
Finnegan Carroll: RPC calls. Helped with code to read in places2k.txt.

STRUCTURES AND ALGORITHMS -
A Trie was used to match city/state names to their corresponding coordinates. 
A KD tree was used to construct a data structure capable of efficiently storing the information located in the file airport-locations.txt (and would work with any file that has airport information in the same format).
KNN is used on the KD tree to locate the 5 closest airports given the client's coordinates (which is obtained by the trie), and a KNN value of 5.

THIRD PARTY CODE -

STRENGTHS AND WEAKNESSES - 
RPC: There was a ton of trouble getting the RPCs to work, it ended up being the case that clnt_create() in plane_server.c was setting errno to 13
which messed up the whole return list. As a result errno is set back to zero after the client is created. Additionally we decided to use a single 
struct with 6 char* to simplify our datatypes. This implementation is easier to debug and program but less extensible as we will only ever
beable to return 5 airports.

Another extremely difficult thing to work with, was the fact that the servers were incapable of producing any form of output. If something segfaulted (which often happened) we had to figure out what happened in our minds eye, instead of physically debugging it like you would on a non-RPC program. Any changes made to the RPC program that result in segfaults will be subject to this again.

Trie:

KD tree: 
PROS
Works with any file of any size, assuming it is formatted like airport-locations.txt
KD trees are searched through more efficiently than brute force methods like large vectors or dynamically sized arrays

CONS:
No error checking for lack of file. This project was designed with the user always having an airport-locations.txt file in their directory. If no such file exists, the KD tree will not be constructed, meaning KNN algorithm will try to access a KD tree that does not exist. This results in a seg fault.
Many casting to get things be in char* form to return to client. This was the first time I had worked with char* to this degree, so I did not know a more efficient way to convert data in an airport struct form to char*. I went about this by casting airport to string, then casting string to char*. Casting airport directly to char* resulted in memory issues that I did not know how to resolve without the string intermediary step.
Does not work when the k-dimension value is set to 3. I designed the KD-tree to work only with (x,y) coordinates, not (x,y,z) coordinates. Getting those to work (and we don't really need to) would require a lot of the code to be massively rewritten.
Does not work with a KD tree of size less than 5. Also did not account for this, because the file given was something like 1000 lines long.

RUNNING THE PROGRAM - 
make
./places&
./airports&
./client server1host server2host city state

Program does not run unless "places2k.txt" and "airport-locations.txt" are in the same directory as the program files.
