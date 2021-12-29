//
//  main.cpp
//  OS Project
//
//  Created by Mario on 12/29/21.
//  Copyright © 2021 Mario. All rights reserved.
//


//Here Mario Shady and Mohamed Mohamed are giving a full dynamic and interactive user software to test and run different memory allocation algorithms including first fit, best fit, and worst fit.
//We are giving the option of choosing a template blocks and processes sizes in order to fully understand the different final stages of memory allocation algorithm between the three
//As also we gave the option of entering your block array as well as your process array.


#include <iostream>

using namespace std;

void getblocksize(int blockarray[], int numberofblocks);
void getprocesssize(int processarray[], int numberofprocceses);
void firstfit(int blockarray[], int numberofblocks, int processarray[], int numberofprocceses);
void bestfit(int blockarray[], int numberofblocks, int processarray[], int numberofprocceses);
void worstfit(int blockarray[], int numberofblocks, int processarray[], int numberofprocceses);

string name;

int main(int argc, const char * argv[]) {
  
    //Here we are giving template arrays, in case of the user want to test the differences between the three memory allocation algorithms
    int blockarray[] = {100, 500, 200, 300, 600};
    int processarray[] = {212, 417, 112, 426};
    
    
    char templateornot;
    
    cout<<"Please enter your first Name: "<<endl;
    cin>>name;
    
    cout<<"Hello Dr. "<<name<<endl;
    
    
    cout<<"Do you want to enter blocks' sizes & process' sizes or not"<<endl;
    cout<<"If yes, please enter y, if not please enter n"<<endl;
    cin>>templateornot;
    templateornot=tolower(templateornot);
    int numberofblocks=5 ,numberofprocceses =4;

    if(templateornot=='y')
    {
        //In case that he want to test his own numbers, so here is another function that we made in order to take from the user the blocks and their sizes, and the proccesses and their sizes
        
        cout << "Enter the number of blocks: ";
        cin >> numberofblocks;
        cout << "Enter the number of processes: ";
        cin >> numberofprocceses;
        getblocksize(blockarray, numberofblocks);
        getprocesssize(processarray, numberofprocceses);
              
    }
    
    //Here just to check that everything is going well
    
    cout<<"Number of blocks "<<numberofblocks<<endl;
    cout<<"Number of proccess "<<numberofprocceses<<endl;
    
    
    //Here to choose one of three memory allocation algorithms, either first fit, best fit, or worst fit
    char charactertochoose;

    cout<<"Dr. "<<name<<", Please enter :"<<endl;
    cout<<"1- f: to choose First Memory Allocation Algorithm: "<<endl;
    cout<<"2- b: to choose Best Memory Allocation Algorithm: "<<endl;
    cout<<"3- w: to choose Worst Memory Allocation Algorithm: "<<endl;
    
    cin>>charactertochoose;
    charactertochoose=tolower(charactertochoose);
    
   
    if(charactertochoose=='f')
      {
          firstfit(blockarray, numberofblocks, processarray, numberofprocceses);
      }
      else if(charactertochoose=='b')
      {
          //Best Fit
          bestfit(blockarray, numberofblocks, processarray, numberofprocceses);
      }
      else if(charactertochoose=='w')
      {
          //Worst Fit
          worstfit(blockarray, numberofblocks, processarray, numberofprocceses);

      }
      else
      {
          //To handle errors
          cout<<"Wrong Choice"<<endl;
      }
     
    //Endl in order not to make "program ended with 0 " affect the table
    cout<<endl;
    return 0;
}


void getblocksize(int blockarray[], int numberofblocks)
{
    cout << "Please Dr. "<<name<< ", Enter size of each block: "<<endl;
    for (int i = 1; i <= numberofblocks; i++)
    {
        cout << "Size of Block No." << i << ": ";
        cin >> blockarray[i];
    }
}


void getprocesssize(int processarray[], int numberofprocceses)
{
    cout << "Please Dr. "<<name<< ", Enter size of each process: "<<endl;

    for (int i = 1; i <= numberofprocceses; i++)
    {
        cout << "Size of Process No. " << i << ": ";
        cin >> processarray[i];
        cout<<endl;

    }
    
}

void firstfit(int blockarray[], int numberofblocks, int processarray[], int numberofprocceses)
{
    //Here is the first fit memory allocation algorithms
    //It basically sees the first hole that fits the process size and put this process in it. REGARDLESS FOR THE INTERNAL FRAGMENTATION
    
    
    cout<<"Welcome Dr. "<<name<<" To the First Fit Memory Allocation Algorithm"<<endl;
    int flags[10], allocation[10];

    for (int key1 = 0; key1 < 10; key1++)
    {
        flags[key1] = 0;
        allocation[key1] = -1;
    }
    
    
    cout<<endl;
    for (int key1 = 0; key1 < numberofprocceses; key1++)
    {
        for (int key2 = 0; key2 < numberofblocks; key2++)
        {
            if (flags[key2] == 0 && blockarray[key2] >= processarray[key1])
            {
                allocation[key2] = key1;
                flags[key2] = 1;
                break;
            }
        }
    }
    
    //Display Table
    cout << "Block no.  size        process no.     size";
    for (int key1 = 0; key1 < numberofblocks; key1++)
    {
        cout <<endl << key1 + 1 << "          " << blockarray[key1] << "          ";
        if (flags[key1] == 1)
            cout << allocation[key1] + 1 << "               " << processarray[allocation[key1]];
        else
            cout << "Not allocated" << "  No Size";
    }
};


void bestfit(int blockarray[], int numberofblocks, int processarray[], int numberofprocceses)
{
    //Here is the best fit memory allocation algorithms
    //It basically scans the whole free block holes, sees the smallest hole that fits the process size and put this process in it.
    //So it is the best algorithm to save the blocks' memories
    //and the smallest internal fragmentation that we can obtain from memory allocation algorithm
    //But as it scans the whole memory blocks to see the smallest hole that can fits the process
    //It takes much more time than the first fit.
    
    
    cout<<"Welcome Dr. "<<name<<" To the Best Fit Memory Allocation Algorithm"<<endl;
    
    int frag[20],  xyz, abc, changing, lowest = 9999;
    static int barray[20], parray[20];
    
    
    for (xyz = 1; xyz <= numberofprocceses; xyz++)
    {
        for (abc = 1; abc <= numberofblocks; abc++)
        {
            if (barray[abc] != 1)
            {
                changing = blockarray[abc] - processarray[xyz];
                if (changing >= 0)
                    if (lowest > changing)
                    {
                        parray[xyz] = abc;
                        lowest = changing;
                    }
            }
        }
        frag[xyz] = lowest;
        barray[parray[xyz]] = 1;
        lowest = 10000;
    }
    
    //Displaying the table
    cout << "Process_no     Process_size    Block_no    Block_size      Fragment";
    
    for (xyz = 1; xyz <= numberofprocceses && parray[xyz] != 0; xyz++)
        cout << endl<< xyz << "                 " << processarray[xyz] << "            " << parray[xyz] << "            " << blockarray[parray[xyz]] << "           " << frag[xyz];


};


void worstfit(int blockarray[], int numberofblocks, int processarray[], int numberofprocceses)
{
    //Here is the worst fit memory allocation algorithms
    //It basically scans the whole free block holes, sees the largest hole that fits the process size and put this process in it.
    //So it is the worst algorithm to save the blocks' memories
    //Because of two reasons
    //1- It scans the whole list so, it has a very large processing time
    //2- It obtains the largest internal fragmentation, and this reduces the memory efficiency exponentially
    //That's why it's called the Worst Algorithm
    
    
    cout<<"Welcome Dr. "<<name<<" To the Worst Fit Memory Allocation Algorithm"<<endl;

    
    //Here we stores the  block id of the block allocated to a process
    int allocation[numberofblocks];
    
    // Initially no block is assigned to any process,
    //In other words free array
    memset(allocation, -1, sizeof(allocation));
    
    //Here we  pick each process and find suitable blocks to fit,
    //according to its sizes and assign the processes to the chosen block holes
    //Giving us as in the description header above THE WORST ALGORITHM
    
    
    for (int i=0; i<numberofblocks; i++)
    {
        int wstIdx = -1;
        for (int j=0; j<numberofprocceses; j++)
        {
            if (blockarray[j] >= processarray[i])
            {
                if (wstIdx == -1)
                    wstIdx = j;
                else if (blockarray[wstIdx] < blockarray[j])
                    wstIdx = j;
            }
        }
        
        if (wstIdx != -1)
        {
            allocation[i] = wstIdx;
            blockarray[wstIdx] -= processarray[i];
        }
    }
    
    
    //Displaying table
    cout << "Process No.    Process Size    Block no."<<endl;
    for (int i = 0; i < numberofblocks; i++)
    {
        cout << "  " << i+1 << "                " << processarray[i] << "          ";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
