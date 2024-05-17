# include <iostream>
# include "sqlite3.h"
# include <vector>
#include <ctime> // Library to Use DataTime Capabilities in CPP
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
            time_t currentTimestamp = time(nullptr); // THIS LINE GETS THE CURRENT TIME IN SECOND SINCE THE ENOCH ( WHICH IS A STANDARD STARTING POINT BY UNIX FOR RECORDING TIME ) 
            tm* localTime = localtime(&currentTimestamp); // THE TM IS A CONSTRUCTOR IN THE CTIME LIBRARY , USED TO TIME IN SECONDS INTO LOCAL TIME FORMAT
            string dateTime = to_string(1900 + localTime->tm_year) + "-" +
                            to_string(1 + localTime->tm_mon) + "-" +
                            to_string(localTime->tm_mday) + " " +
                            to_string(localTime->tm_hour) + ":" +
                            to_string(localTime->tm_min) + ":" +
                            to_string(localTime->tm_sec); // ALL THIS WILL RETURN A STRING OF DATE AND TIME WHICH IF NEEDED WE CAN PARSE AND USE LATER
            
        return dateTime; 
            // QEUSTIONS 
            // IS THIS METHOD FOR SETTING THE TIMESTAMP FOR THE BLOCK CREATION AND UPDATION? I MEAN WHENVEVER THE BLOCK IS UPDATED OR IF ITS CREATED , THIS METHOD WILL BE CALLED AND WILL UPDATE THE TIMESTAMP? RIGHT?
            // IF THE ABOVE IS RIGHT THEN WILL WE STORE THE UPDATION TIMESTAMP IN THE DATABASE FOR TRACKING FOR WILL BE UPDATE THE TIMESTAMP PROPERTY VARIABLE AND SET IT TO THE LATEST TIMESTAMP ( WHICH IS THE UPDATION TIMESTAMP )
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
