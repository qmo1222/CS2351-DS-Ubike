#include "UBikeSys.h"

UBikeSys::UBikeSys(string fileName){
	this->fileOut.open(fileName, ifstream::out);

	int i, j;

	for (i=0; i<STATION_NUM; i++) {
		for (j=0; j<HEAP_NUM; j++){
			string station = STATIONS[i];
			string bikeClass = HEAPS[j];
			this->stationInfo[station][bikeClass];
		}
	}
}

// add new bike to company
void UBikeSys::newBike(string bikeClass, string license, int mile, string station){
	// create new bike
	Bike *bike = new Bike;
	bike->bikeClass = bikeClass;
	bike->license = license;
	bike->mileage = mileage;
	bike->station = station;
	bike->status = false;
	
	// add to binary tree and heap
	this->bikeOwn.addBike(bike);
	this->stationInfo[station][bikeClass].addBike(bike);

	fileOut << "New bike is received by Station " << station << ".";
	fileOut << endl;
}
// remove bike from company
void UBikeSys::junkIt(string license){
	Bike *bike = this->bikeOwn.searchBike(license);

	// if no bike
	if (bike == NULL) {
		fileOut << "Bike " << license << " does not belong to our company."
		return;
	}

	// if rented
	if (bike->status) {
		fileOut << "Bike " << license << " is now being rented."
		return;
	}

	// delete bike
	string station = bike->station;
	string bikeClass = bike->bikeClass;
	this->bikeOwn.junkBike(license);
	this->stationInfo[station][bikeClass].junkBike(license);
	delete bike;

	fileOut << "Bike " << license << " is deleted from " << station << ".";
	fileOut << endl;
}
// rent the bike
void UBikeSys::rent(string station, string bikeClass){
	Bike *bike = this->stationInfo[station][bikeClass].rentBike();
	bike->status = true;

	fileOut << "A bike is rented from " << station << ".";
	// fileOut << "No free bike is available."
	fileOut << endl;
}
// fileOut << bike
void UBikeSys::returns(string station, string license, int mile){
	Bike *bike = this->bikeOwn.searchBike(license);

	int charge = 0;
	fileOut << "Rental charge for this bike is " << charge;
	fileOut << endl;
}
// transfer bike to other station
void UBikeSys::trans(string station, string license){
	fileOut << "Bike " << license << " is transferred to " << station;
	// fileOut << "Bike " << license << " does not belong to our company.";
	// fileOut << "Bike " << license << "is now being rented.";
	fileOut << endl;
}
// inquire certain bike
void UBikeSys::inquire(string license){
	fileOut << "Bike " << license << " does not belong to our company.";
	// fileOut << setw(15) << "License" << setw(15) << Mileage << ...
	fileOut << endl;
}
// report certain station
void UBikeSys::stationReport(string station){
	fileOut << "stationReport function still making";
	fileOut << endl;
}
// report all bikes info
void UBikeSys::uBikeReport(){
	fileOut << "uBikeReport function still making";
	fileOut << endl;
}
// report money earn by the station
void UBikeSys::netSearch(string station){
	fileOut << "netSearch function still making";
	fileOut << endl;
}
// print binary search tree
void UBikeSys::bReport(){
	fileOut << "bReport function still making";
	fileOut << endl;
}