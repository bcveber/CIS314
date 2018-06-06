/*
  Simulates a 64B direct-mapped cache with 4B blocks. 8-2.
  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Block {
 unsigned char value[4];
 unsigned int tag;
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
          printf("Enter 32-bit unsigned hex address: ");
          fgets(buffer, 256, stdin);
          int address = (int)strtol(buffer, NULL, 0);
          if (address == 0 && !strcmp(buffer, "0x0")){
              printf("Invalid Input!");
              continue;
          }
          printf("Enter 32-bit unsigned hex value: ");
          fgets(buffer, 256, stdin);
          int value = (int)strtol(buffer, NULL, 0);
          if (value == 0 && !strcmp(buffer, "0x0")){
              printf("Invalid Input!");
              continue;
          }
          
          write(address, value, cache);
          
        } 
        else if (c == 'r') {
          printf("Enter 32-bit unsigned hex address: ");
          fgets(buffer, 256, stdin);
          int address = (int)strtol(buffer, NULL, 0);
          if (address == 0 && !strcmp(buffer, "0x0")){
              printf("Invalid Input!");
              continue;
          }
          
          read(address, cache);
        } 
        else if (c == 'p') {
            print(cache);
        
        }
    }
    while (c != 'q');
    
    free(cache);
    printf("done\n");
}
 
unsigned int getOffset(unsigned int address){
    return address&3;
}

unsigned int getSet(unsigned int address) {
    return (address>>2)&15;
}

unsigned int getTag(unsigned int address) {
    return (address>>6);
}

 //simulate write value at address
void write(int address, int value, struct Block* cache){
    unsigned int offset = getOffset(address);
    unsigned int set = getSet(address);
    unsigned int tag = getTag(address);
    
    struct Block* current = (cache+set);

    if (current->valid  == 1){
        printf("Existing Block:\n");
        printf("existing set: %d - tag: %d - valid: %d - value: ", set, current->tag, current->valid);
        
        printValueBlock(current->value);
        printf("\n");

        current->tag = tag;
        writeValueBlock(current->value, value);
        printf("New Overriden Block:\n");
        printf("wrote set: %d - tag: %d - valid: %d - value: ", set, tag, 1);
        printValueBlock(current->value);
        printf("\n");
        return;
        
    }

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
        *(valueArray + i) =(unsigned char) value&0xff;
        value = value>>8;
    }
}