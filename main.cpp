# include <iostream>
# include "sqlite3.h"
# include <vector>
#include <openssl/sha.h> // SHA HASHING ALGORITM LIBRARY , NOT A BUILT IN LIBRARY , WE'LL NEED TO GET IT BEFORE RUNNING THE CODE.
using namespace std;

class Transaction;
class Block
{
    private:
        string blockHash;
        string previousBlockHash;
        string timestamp;
        string merkleRoot;
        int nonce;
        int difficultyLevel;
        vector<Transaction> transactions;
        
    public:
        Block(const string& prevHash, int diffLevel) : previousBlockHash(prevHash), difficultyLevel(diffLevel) {
            timestamp = getCurrentTimestamp(); // Initialize timestamp
            nonce = 0; // Initialize nonce
        }

        // Getter methods
        string getBlockHash()  
        {
             return blockHash;
        }
        string getPreviousBlockHash() 
        { 
            return previousBlockHash; 
        }
        string getTimestamp() 
        { 
            return timestamp; 
        }
        string getMerkleRoot()
        { 
            return merkleRoot; 
        }
        int getNonce() 
        {
            return nonce;
        }
        int getDifficultyLevel() 
        { 
            return difficultyLevel;
        }
        vector<Transaction> getTransactions()  
        { 
            return transactions; 
        }

        // Setter methods
        void setBlockHash(string hash) 
        { 
            blockHash = hash; 
        }
        void setMerkleRoot( string root) 
        { 
            merkleRoot = root;
        }
        void addTransaction( Transaction& txn) 
        { 
            transactions.push_back(txn);
        }

        // Utility method to get current timestamp (you can implement your own)
        string getCurrentTimestamp() 
        {
             /* TODO
             to implement this function go through the experimantation.cpp file
              */ 
        return ""; 
        }

        // Method to calculate block hash (you can implement your own)
        string calculateBlockHash() 
        { /* TODO
            read about block hashing and hashing algorithm to complete this
         */
         string dataToHash = previousBlockHash + timestamp + merkleRoot + to_string(nonce) + to_string(difficultyLevel); // GIVES IT DATA WHICH WILL BE USED IN THE HASH

        // SHA256 ALGORITHM USED
        SHA256_CTX sha256Context;
        SHA256_Init(&sha256Context);    // TELLS THE COMPILER THE HASHING PATTERN/ALGORITHM
        
        SHA256_Update(&sha256Context, dataToHash.c_str(), dataToHash.length());   // ADDS OUR DATA STRING TO THE HASHING ALOGORITHM
        
        unsigned char hashResult[SHA256_DIGEST_LENGTH];
        SHA256_Final(hashResult, &sha256Context);    // FINALIZEZ THE HASHING PROCESS AND GIVES A HASHED DIGEST
        
        // CONVERTING THE HASHED RESULT INTO A HEXADECIMAL STRING
        string hashString;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            char buf[3];
            sprintf(buf, "%02x", hashResult[i]);
            hashString += buf;
        }
        
        return hashString; // RETURNS HASH
        }

        // Method to mine the block (you can implement your own)
        void mineBlock() 
        { /* TODO
         read about mining */ 
        }
};
        
int main()
{
    return 0;
}
