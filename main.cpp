# include <iostream>
using namespace std;

class Block
{
    private:
        string previous_block_hash;
        /* timestamp will be assigned a value at the time of block object creation
        more details in experimentation file*/
        string timestamp;
        // A unified hash that is a combination of all the transactions hashes
        string Merkle_Root;
        //A random number used in mining (idk)
        int Nonce;
        //deficulty level of the block in mining
        int difficulty_level;
        //nuLL by default
        string next_block_hash;
};
int main()
{
    return 0;
}