#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Block {
 unsigned char value[4];
 unsigned int tag; //create the Block struct
 unsigned char valid;
};

//all functions
void initializeCache(struct Block* cache);
unsigned int getOffset(unsigned int address);
unsigned int getSet(unsigned int address);
unsigned int getTag(unsigned int address) ;
void write(int address, int value, struct Block* cache);
void read(int address, struct Block* cache);
void print(struct Block* cache);
void printValueBlock(char* valueArray);
void writeValueBlock(char* valueArray, int value);

int main(){
    
    struct Block *cache = (struct Block*) malloc(16*sizeof(struct Block));
    initializeCache(cache);
    char buffer[256];
    char c;
    do {
        printf("\nEnter 'r' for read, 'w' for write, 'p' to print, 'q' to quit: ");
        fgets(buffer, 256, stdin);
        c = buffer[0];
        if (c == 'w') {
          printf("Enter 32-bit unsigned hex address: "); //print message
          fgets(buffer, 256, stdin);
          int address = (int)strtol(buffer, NULL, 0); //convert to integer
          if (address == 0 && !strcmp(buffer, "0x0")){ //check if valid input is given
              printf("Invalid Input!");
              continue;
          }
          printf("Enter 32-bit unsigned hex value: "); //print message
          fgets(buffer, 256, stdin);
          int value = (int)strtol(buffer, NULL, 0); //convert to integer
          if (value == 0 && !strcmp(buffer, "0x0")){ //check if valid input is given
              printf("Invalid Input!");
              continue;
          }
          
          write(address, value, cache); //write if W is entered
          
        } 
        else if (c == 'r') {
          printf("Enter 32-bit unsigned hex address: "); //print message
          fgets(buffer, 256, stdin);
          int address = (int)strtol(buffer, NULL, 0); //convert to integer
          if (address == 0 && !strcmp(buffer, "0x0")){ //check if valid input is entered
              printf("Invalid Input!");
              continue;
          }
          
          read(address, cache); //read if r is entered
        } 
        else if (c == 'p') {
            print(cache); //print if p is entered
        
        }
    }
    while (c != 'q'); //quit if q is entered
    
    free(cache); //free the cache at the end
    printf("done\n"); //end
}
 
unsigned int getOffset(unsigned int address){
    // returns the byte offset of the address within the block
    return address&3; //first two bits
}

unsigned int getSet(unsigned int address) {
    // returns the cache set for the addresD
    return (address>>2)&15; //last four bits after removing offset
}

unsigned int getTag(unsigned int address) {
    //returns the cache tag for the address
    return (address>>6); //26 bits for the tag
}

 //simulate write value at address
void write(int address, int value, struct Block* cache){
    unsigned int offset = getOffset(address);
    unsigned int set = getSet(address); //set
    unsigned int tag = getTag(address); //get tag
    
    struct Block* current = (cache+set); //get the block w/ number set
    
    //start printing details if block is already valid
    if (current->valid  == 1){
        printf("Existing Block:\n");
        printf("existing set: %d - tag: %d - valid: %d - value: ", set, current->tag, current->valid);
        
        //print value array
        printValueBlock(current->value);
        printf("\n");
        
        //override block
        current->tag = tag;
        writeValueBlock(current->value, value);
        printf("New Overriden Block:\n");
        printf("wrote set: %d - tag: %d - valid: %d - value: ", set, tag, 1);
        printValueBlock(current->value);
        printf("\n");
        return;
        
    }

    //if block is invalid at beginning, then override
    current->tag = tag;
    current->valid = 1;
    writeValueBlock(current->value, value);
    printf("wrote set: %d - tag: %d - valid: %d - value: ", set, tag, current->valid);
    printValueBlock(current->value);
    printf("\n");
    
}
    void read(int address,struct Block* cache){
    unsigned int offset = getOffset(address);
    unsigned int set = getSet(address);
    unsigned int tag = getTag(address);
    
    printf("looking for set: %d - tag: %d\n ", set, tag);
    
    struct  Block* current = (cache+set); //required set/block
    if (current->valid == 0){
        
        //if the block/set not found then return and give error
        printf("no valid set found - it's a miss!\n");
        return;
    }
    printf("found set: %d - tag: %d - valid: %d - value: ", set, tag, current->valid);
    printValueBlock(current->value);
    printf("\n");
    
    if (tag == current->tag){
        printf("hit!\n");
        return;
    }
    else{
        printf("tags don't match - it's a miss!\n");
    }
}

 
//function to print the block
void print(struct Block* cache){
    int i;
    struct Block* current;
    for (i=0; i<16; i++){
        current = (cache+i);
        if (current->valid == 1){
            //if the block is valid
            printf("set: %d - tag: %d - valid: %d - value: ", i, current->tag, current->valid);
            printValueBlock(current->value);
            printf("\n");
        }
    }
}


 //function to initalize the cache
void initializeCache(struct Block* cache){
    int i;
    struct Block* current;
    for (i=0; i<16; i++){
        current = (cache+i);
        current->tag = 0;
        current->valid = 0;
    }
}

//helper to print the bytes from the value array in correct format shown
void printValueBlock(char* valueArray){
    int i;
    for (i=0; i<4; i++){
        unsigned char aByte = *(valueArray + i);
        printf("%x ", aByte);
    }
}

//function to write the given value properly on valueArray
void writeValueBlock(char* valueArray, int value){
    int i;
    for (i=0; i<4; i++){
        *(valueArray + i) =(unsigned char) value&0xff; //get the last byte of the value
        value = value>>8; //remove 8 bits from value
    }
}