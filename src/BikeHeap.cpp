#include "BikeHeap.h"
#include <iostream>
using namespace std;

// add bike into this->heap
void BikeHeap::addBike(Bike *bike){
	this->heap.push_back(bike);
	bubbleUp(this->heap.size()-1);
}

// remove bike
void BikeHeap::junkBike(string license){
	// for(Bike* b:this->heap){
	// 	cout<<b->license<<endl;
	// }

	int i;
	for(i=0; i<this->heap.size(); i++){
		if(this->heap[i]->license == license) break;
	}
	this->heap[i] = this->heap.back();
	this->heap.pop_back();

	//if bigger than parent bubble up, else bubble down
	this->heap[(i-1)/2]->mile<this->heap[i]->mile?bubbleUp(i):bubbleDown(i);
}

// rent bike with largest mileage
Bike* BikeHeap::rentBike(){
	// return bike ptr
	if(this->heap.size()==0)	return NULL;
	else{
		Bike *temp = this->heap[0]; 
		this->heap[0] = this->heap.back();
		this->heap.pop_back();

		bubbleDown(0);

		return temp;
	}
	return NULL;
}

// traverse the heap with max to min
vector<Bike*> BikeHeap::showBike(){
	return this->heap;
}

void BikeHeap::bubbleUp(int i){
	if(i && this->heap[(i-1)/2]->mile<this->heap[i]->mile){	//if parent<child
		Bike* temp = this->heap[(i-1)/2];
		this->heap[(i-1)/2] = this->heap[i];
		this->heap[i] = temp;

		bubbleUp((i-1)/2);
	}
}

void BikeHeap::bubbleDown(int i){
	int left = 2*i + 1;	
	int right = 2*i + 2;
	int large = i;
	
	//replace parent to the largest child
	//if the same, change the left one
	if(left<this->heap.size() && this->heap[left]->mile>this->heap[i]->mile)
			large = left;
	if(right<this->heap.size() && this->heap[right]->mile>this->heap[large]->mile)
			large = right;

	if(large != i){
		Bike* temp = this->heap[large];
		this->heap[large] = this->heap[i];
		this->heap[i] = temp;
		bubbleDown(large);
	}
}