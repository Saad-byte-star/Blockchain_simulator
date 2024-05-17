# include <iostream>
# include "sqlite3.h"
# include <vector>
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
         */ return ""; 
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