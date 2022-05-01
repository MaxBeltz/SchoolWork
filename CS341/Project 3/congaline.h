#ifndef CONGALINE_H
#define CONGALINE_H

#include <iostream>
#include <fstream>
using namespace std;

#include "pirate.h"
#include "node.h"

// CongaLine will always be of length 20 prior to the execution of core functions
// Semantically, we think of CongaLine as horizontal line, where the head is on the left, and the tail is on the right

class CongaLine {
    private:
        Node * head;
        Node * tail;
        Node * doubleEdgedSword;
        int barHeight;
        ifstream pirateFile;
        ifstream commandFile;
    
        void fill(); //fills the list to 20
        int length();
        
        bool insertAtTail(Pirate);
        Node * search(int);             // takes an integer value i and returns ith element of the list
        bool deleteAtNode(Node *);
		int getIntPos(Node *);
        
    public:
        // Basic class setup
        CongaLine();
        ~CongaLine();
		
		bool insertAtHead(Pirate);
        
        // Access functions
        void setBarHeight(int bh) {barHeight = bh;}
        int getBarHeight() {return barHeight;}
        
        // Core functionality
        // For both lshift and rshift, if you are too close to the edge of the array to execute the full shift, do as much as you can and then terminate normally
        void lshift(int);               // moves the double-edged sword to the left and pirates must limbo underneath, inserts replacement pirates at the tail
        void rshift(int);               // moves the double-edged sword to the right and pirates must limbo underneath, inserts replacement pirates at the head
        void hammer(int);               // takes an integer value from [0, 20) and deletes the node at that list location, then inserts a new pirate at the tail
        void lowerBar();                // decrements the value of the bar height by 1, as long as it is positive. If the bar is already 0 when this function is called, set the bar back to 10
        void setBar(int);               // sets the height of the double-edged sword to the input value
        
        // Reset functions
        void tacticalNuke();            // executes hammer(0) 20 times
		
		//runs the command file
        void run();
		
		void print();
};

#endif