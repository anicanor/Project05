//sim.cpp
//Aaron Nicanor
//anicanor

//Included libraries used
#include<iostream>
#include<string>
#include<fstream>
#include<assert.h>
#include<stdlib.h>

//Header files
#include"cust.h"
#include"pqueue.h"

using namespace std;

struct Checker{

	Cust *ptrCust;
	double checker_money;
	int finishedTime;
	int breakTime;
};

//Functions used
void simStart(Pqueue &, int,int,ostream &);
bool checkerAvailable(Checker [], int, int&);
bool validInt(char *);

//The three priority queues
Pqueue arrival_queue;
Pqueue checker_queue;
Pqueue shopping_queue;
int main(int argc, char *argv[]){

	//Detects if there's an error. This codes writes out the error using the command lines
	if (argc < 5 || argc > 5){
  
    	cerr << "Error: invalid number of command line arguments."<<endl;
    	exit(1);
	}
	ifstream my_ifile(argv[3], ios::in);
	ofstream my_ofile(argv[4], ios::out);
	if (!my_ifile){
  
    	cerr << "Error: could not open input file <" << argv[3] << ">."<<endl;
    	exit(1);
	}
	if(!my_ofile){
  
    	cerr << "Error: could not open output file <" << argv[4] << ">." << endl;
    	exit(1);
	}
	if(!validInt(argv[1]) || atoi(argv[1]) < 1){
  
    	cerr << "Error: invalid number of checkers specified." << endl;
    	exit(1);
	}
	if(!validInt(argv[2]) || atoi(argv[2]) < 0){
  
    	cerr << "Error: invalid checker break duration specified." <<endl;
    	exit(1);
	}
  
	//Variable declaration
	int numItems;
	int arrivalTime;
	bool isShopper;
	string name;
	string shopperStatus;
	string input;

	while(my_ifile >> name){
  
    	my_ifile >> shopperStatus;
    	if(shopperStatus == "shopper")
          isShopper = true;
    	else
        	isShopper = false;
          
    	my_ifile >> arrivalTime;
    	my_ifile >> numItems;
    	arrival_queue.enqueue(new Cust(name, isShopper,arrivalTime,numItems),arrivalTime);
	}
  
//Begins the simulation
simStart(arrival_queue, atoi(argv[1]),atoi(argv[2]),my_ofile);

return 0;
}
//Defining functions
void simStart(Pqueue &arrival_queue, int num_checkers, int check_break_duration, ostream &os){

	//Variable declaration
	int end_time = 0;
	int finishedShopTime;
	int numCustomers = arrival_queue.length();
	Checker *checkers = new Checker[num_checkers];
  
	//This loop will initialize the checkers
	for(int i = 0; i < num_checkers; i++){
  
    	checkers[i].checker_money = 250;
    	checkers[i].breakTime = 0;
    	checkers[i].ptrCust = NULL;
	}
  
	//This loop will play out until all the customers are done
	for(int clock = 1; numCustomers > 0; clock++){
  
    	//Checks if the customers are still at the store
    	while(arrival_queue.priorityOne() == clock){
      
        	Cust *removedCust = arrival_queue.dequeue();
        	removedCust->print_entered(os,clock);
        	finishedShopTime = removedCust->arrivalTime() + removedCust->numItems()*2;
        	shopping_queue.enqueue(removedCust, finishedShopTime);
    	}
      
    	//Checks if the customers are done
    	while(shopping_queue.priorityOne() == clock){
      
        	Cust *removedCust = shopping_queue.dequeue();
        	removedCust->print_finished_shopping(os,clock);
        	checker_queue.enqueue(removedCust, 0);
    	}
      
    	//Will run through the checker
    	for(int i = 0; i < num_checkers; i++){
      
        	//Checks if the customer is being served and items being bought
        	if(checkers[i].ptrCust != NULL && clock == checkers[i].finishedTime){
          
            	//Checks if the customer is a robber
            	if(checkers[i].ptrCust->is_robber()){
              
                	checkers[i].ptrCust->print_finished_checkout(os,clock,i,checkers[i].checker_money);
                	checkers[i].checker_money = 0;
                	checkers[i].breakTime = check_break_duration;
            	}else{
              
                	checkers[i].ptrCust->print_finished_checkout(os,clock,i,checkers[i].checker_money);
                	checkers[i].checker_money = checkers[i].checker_money + checkers[i].ptrCust->numItems()*3;
            	}
            	delete checkers[i].ptrCust;
     	        numCustomers--;
            	checkers[i].ptrCust = NULL;
            }
      }
      	int checkerReady = 0;
        
      	//Looks if checker is open
      	while(checker_queue.length() > 0 && checkerAvailable(checkers,num_checkers,checkerReady)){
        
        	Cust *removedCust = checker_queue.dequeue();
        	checkers[checkerReady].ptrCust = removedCust;
          
        	//Checks if the customer is a robber
        	if(checkers[checkerReady].ptrCust->is_robber())
            	checkers[checkerReady].finishedTime = clock + 7;
        	else
            	checkers[checkerReady].finishedTime = clock + checkers[checkerReady].ptrCust->numItems();//*2;
              
        	checkers[checkerReady].ptrCust->print_begin_checkout(os,clock,checkerReady);
       	}
        
       	//This loop drops the checker's break time
       	for(int i = 0; i < num_checkers; i++){
        
        	if(checkers[i].breakTime > 0){
          
            	checkers[i].breakTime--;
        	}
       	}
       	end_time++;
      }
      
//Prints the checker's money
for( int i = 0; i < num_checkers; i++){

	os << "registers[" << i << "] = $" << checkers[i].checker_money << endl;
}

//Prints out the end time
os << "time = " << end_time + 1 << endl;
}

//This function looks to see if the checker is available
bool checkerAvailable(Checker checkers[], int num_checkers, int &checkerAvailable){

	for(int i = 0; i < num_checkers; i++){
  
    	if(checkers[i].breakTime == 0 && checkers[i].ptrCust == NULL){
      
        	checkerAvailable = i;
        	return true;
    	}
	}
	return false;
}

//Checks if the input is a digit
bool validInt(char *str){

	while(*str != 0){
  
    	if(!isdigit(*str))
    	return false;
    	str++;
	}
	return true;
}
