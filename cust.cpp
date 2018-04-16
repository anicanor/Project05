//cust.cpp
//Aaron Nicanor
//anicanor
#include<iostream>
#include<assert.h>
#include<string>
#include"cust.h"

//Constructor
Cust::Cust(string name, bool isRobber, int arrivalTime, int numItems){
	
	m_name = name;
	m_isRobber = isRobber;
	m_arrivalTime = arrivalTime;
	m_numItems = numItems;
}

//Prints with os. It provides the number of items and the arrival time
void Cust::print(ostream &os){
	
	os << m_name << " ";
	if (m_isRobber)
		os << "shopper ";
	else
		os << "robber ";
	os << m_arrivalTime << " ";
	os << m_numItems << endl;
}

//Checks if the customer is a robber
bool Cust::is_robber(){
	
	if(m_isRobber)
		return false;
	else
		return true;
}

//Returns the number of items
int Cust::numItems(){
	
	return m_numItems;
}

//Returns arrival time
int Cust::arrivalTime(){
	
	return m_arrivalTime;
}

//Function that was given in directions
void Cust::print_entered(ostream &os, int clock){
	
	assert(clock == m_arrivalTime);
	os << clock << ": " << m_name << " entered store" << endl;
}

//Prints out a message when the shopping is finished
void Cust::print_finished_shopping(ostream &os, int clock){
	
	assert (clock == m_arrivalTime + m_numItems * 2);
	os << clock << ": " << m_name << " done shopping" << endl;
}

//Checks how much money was stolen
void Cust:: print_finished_checkout(ostream &os, int clock, int num_checker, int checker_money){
	
	if(m_isRobber == false){
		
    		os << clock << ": " << m_name << " stole $" << checker_money << " and "<< m_numItems;
    		if ( m_numItems == 1)
	 		os << " item ";
    		else
    			os << " items ";
    		os << "from checker " << num_checker << endl;
	}else{
		
    		os << clock << ": " << m_name << " paid $" << m_numItems*3 << " for " << m_numItems;
    		if ( m_numItems == 1)
    			os << " item ";
    		else
    			os << " items ";
    		os << "to checker " << num_checker << endl;
    	}
}

//Prints out when the customer started shopping
void Cust::print_begin_checkout(ostream &os, int clock, int num_checker){
	
	os << clock << ": " <<m_name << " started checkout with checker " << num_checker << endl;
}
