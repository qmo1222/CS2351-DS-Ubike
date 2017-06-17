#include "UBikeSys.h"

UBikeSys::UBikeSys(string fileName){
	this->fileOut.open(fileName, ifstream::out);

	int i, j;
	for (i=0; i<STATION_NUM; i++) {
		for (j=0; j<CLASS_NUM; j++){
			this->stationInfo[STATIONS[i]][CLASSES[j]];
			this->net[STATIONS[i]][CLASSES[j]] = 0;
		}
	}
}

// add new bike to company
void UBikeSys::newBike(string bikeClass, string license, int mile, string station){
	// create new bike
	Bike *bike = new Bike;
	bike->bikeClass = bikeClass;
	bike->license = license;
	bike->mile = mile;
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
		fileOut << "Bike " << license << " does not belong to our company.";
		fileOut << endl;
		return;
	}

	// if rented
	if (bike->status) {
		fileOut << "Bike " << license << " is now being rented.";
		fileOut << endl;
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

	if (bike == NULL) {
		fileOut << "No free bike is available.";
		fileOut << endl;
		return;
	}

	bike->status = true;
	this->stationInfo[station][RENTED].addBike(bike);

	fileOut << "A bike is rented from " << station << ".";
	fileOut << endl;
}

// return bike
void UBikeSys::returns(string station2, string license, int mile){
	Bike *bike = this->bikeOwn.searchBike(license);
	string station1 = bike->station;
	string bikeClass = bike->bikeClass;

	// calculate charges
	int way = this->price.distance[station1][station2];
	int charge = 0;
	if (way == mile - bike->mile) {
		charge = (mile - bike->mile) * DISCOUNT_PRICE.at(bikeClass);
	}
	else {
		charge = (mile - bike->mile) * ORIGIN_PRICE.at(bikeClass);
	}

	this->net[station1][bikeClass] += charge;

	// update bike info
	bike->mile = mile;
	bike->station = station2;
	bike->status = false;
	this->stationInfo[station1][RENTED].junkBike(license);
	this->stationInfo[station2][bikeClass].addBike(bike);

	fileOut << "Rental charge for this bike is " << charge;
	fileOut << endl;
}

// transfer bike to other station
void UBikeSys::trans(string station2, string license){
	Bike *bike = this->bikeOwn.searchBike(license);

	// if no bike
	if (bike == NULL) {
		fileOut << "Bike " << license << " does not belong to our company.";
		fileOut << endl;
		return;
	}

	// if rented
	if (bike->status) {
		fileOut << "Bike " << license << " is now being rented.";
		fileOut << endl;
		return;
	}

	string station1 = bike->station;
	string bikeClass = bike->bikeClass;

	// transfer bike
	bike->station = station2;
	this->stationInfo[station1][bikeClass].junkBike(license);
	this->stationInfo[station2][bikeClass].addBike(bike);

	fileOut << "Bike " << license << " is transferred to " << station2;
	fileOut << endl;
}
// inquire certain bike
void UBikeSys::inquire(string license){
	Bike *bike = this->bikeOwn.searchBike(license);

	if (bike == NULL) {
		fileOut << "Bike " << license << " does not belong to our company.";
		fileOut << endl;
		return;
	}

	// print the table
	fileOut << setw(15) << "License" << setw(15) << "Mileage";
	fileOut << setw(15) << "Class" << setw(15) << "Station";
	fileOut << endl;

	int i;
	for (i=0; i<60; i++) {
		fileOut << "=";
	}
	fileOut << endl;

	fileOut << setw(15) << bike->license << setw(15) << bike->mile;
	fileOut << setw(15) << bike->bikeClass << setw(15) << bike->station;
	fileOut << endl << endl;
}

// report certain station
void UBikeSys::stationReport(string station){
	int i, j;
	int bikeTotal = 0;
	int bikeNum[CLASS_NUM];
	for (i=0; i<CLASS_NUM; i++){
		bikeNum[i] = 0;
	}

	fileOut << setw(30) << station << endl;

	// print free bikes
	fileOut << setw(30) << "Free Bikes" << endl;
	fileOut << setw(15) << "License" << setw(15) << "Mileage";
	fileOut << setw(15) << "Class" << setw(15) << "SubTotal";
	fileOut << endl;
	for (i=0; i<60; i++) {
		fileOut << "=";
	}
	fileOut << endl;
	for (i=0; i<CLASS_NUM; i++){
		vector<Bike*> bikeArr;
		bikeArr = this->stationInfo[station][CLASSES[i]].showBike();
		for (j=0; j<bikeArr.size(); j++){
			Bike *bike = bikeArr.at(j);
			fileOut << setw(15) << bike->license << setw(15) << bike->mile;
			fileOut << setw(15) << bike->bikeClass;
			fileOut << endl;
		}
		bikeTotal += bikeArr.size();
		bikeNum[i] = bikeArr.size();
	}
	for (i=0; i<60; i++) {
		fileOut << "=";
	}
	fileOut << endl;
	fileOut << setw(60) << bikeTotal << endl;
	fileOut << endl;

	// print rented bikes
	fileOut << setw(30) << "Rented Bikes" << endl;
	fileOut << setw(15) << "License" << setw(15) << "Mileage";
	fileOut << setw(15) << "Class" << setw(15) << "SubTotal";
	fileOut << endl;
	for (i=0; i<60; i++) {
		fileOut << "=";
	}
	fileOut << endl;
	vector<Bike*> rentArr;
	rentArr = this->stationInfo[station][RENTED].showBike();
	for (j=0; j<rentArr.size(); j++){
		Bike *bike = rentArr.at(j);
		fileOut << setw(15) << bike->license << setw(15) << bike->mile;
		fileOut << setw(15) << bike->bikeClass;
		fileOut << endl;
	}
	for (i=0; i<60; i++) {
		fileOut << "=";
	}
	fileOut << endl;
	fileOut << setw(60) << rentArr.size() << endl;
	fileOut << endl;

	// print summary
	fileOut << setw(12) << "Net";
	for (i=0; i<CLASS_NUM; i++){
		fileOut << setw(12) << CLASSES[i];
	}
	fileOut << endl;
	for (i=0; i<60; i++) {
		fileOut << "=";
	}
	fileOut << endl;
	int stationNet = 0;
	for (i=0; i<CLASS_NUM; i++) {
		stationNet += this->net[station][CLASSES[i]];
	}
	fileOut << setw(12) << stationNet;
	for (i=0; i<CLASS_NUM; i++){
		fileOut << setw(12) << bikeNum[i];
	}
	fileOut << endl;
	for (i=0; i<60; i++) {
		fileOut << "=";
	}
	fileOut << endl;
	fileOut << endl;

}
// report all bikes info
void UBikeSys::uBikeReport(){
	int i, j, k;
	int bikeTotal = 0;
	int bikeNum[CLASS_NUM];
	for (i=0; i<CLASS_NUM; i++){
		bikeNum[i] = 0;
	}

	fileOut << setw(30) << "Taipei U-bike" << endl;

	// print free bikes
	fileOut << setw(30) << "Free Bikes" << endl;
	fileOut << setw(12) << "License" << setw(12) << "Mileage";
	fileOut << setw(12) << "Class" << setw(12) << "SubTotal";
	fileOut << setw(12) << "Total" << endl;
	for (i=0; i<60; i++) {
		fileOut << "=";
	}
	fileOut << endl;
	for (i=0; i<STATION_NUM; i++){
		for (j=0; j<CLASS_NUM; j++){
			vector<Bike*> bikeArr;
			bikeArr = this->stationInfo[STATIONS[i]][CLASSES[j]].showBike();
			for (k=0; k<bikeArr.size(); k++){
				Bike *bike = bikeArr.at(k);
				fileOut << setw(12) << bike->license << setw(12) << bike->mile;
				fileOut << setw(12) << bike->bikeClass << setw(12) << bike->station;
				fileOut << endl;
			}
			bikeTotal += bikeArr.size();
			bikeNum[j] += bikeArr.size();
		}
	}
	for (i=0; i<60; i++) {
		fileOut << "=";
	}
	fileOut << endl;
	fileOut << setw(60) << bikeTotal << endl;
	fileOut << endl;

	int rentNum = 0;
	// print rented bikes
	fileOut << setw(30) << "Rented Bikes" << endl;
	fileOut << setw(12) << "License" << setw(12) << "Mileage";
	fileOut << setw(12) << "Class" << setw(12) << "Station";
	fileOut << setw(12) << "Total" << endl;
	for (i=0; i<60; i++) {
		fileOut << "=";
	}
	fileOut << endl;
	for (i=0; i<STATION_NUM; i++) {
		vector<Bike*> rentArr;
		rentArr = this->stationInfo[STATIONS[i]][RENTED].showBike();
		for (j=0; j<rentArr.size(); j++){
			Bike *bike = rentArr.at(j);
			fileOut << setw(12) << bike->license << setw(12) << bike->mile;
			fileOut << setw(12) << bike->bikeClass << setw(12) << bike->station;
			fileOut << endl;
		}
		rentNum += rentArr.size();
	}
	for (i=0; i<60; i++) {
		fileOut << "=";
	}
	fileOut << endl;
	fileOut << setw(60) << rentNum << endl;
	fileOut << endl;

	// print summary
	fileOut << setw(12) << "Net";
	for (i=0; i<CLASS_NUM; i++){
		fileOut << setw(12) << CLASSES[i];
	}
	fileOut << endl;
	for (i=0; i<60; i++) {
		fileOut << "=";
	}
	fileOut << endl;
	int totalNet = 0;
	for (i=0; i<STATION_NUM; i++){
		for (j=0; j<CLASS_NUM; j++) {
			totalNet += this->net[STATIONS[i]][CLASSES[j]];
		}
	}
	fileOut << setw(12) << totalNet;
	for (i=0; i<CLASS_NUM; i++){
		fileOut << setw(12) << bikeNum[i];
	}
	fileOut << endl;
	for (i=0; i<60; i++) {
		fileOut << "=";
	}
	fileOut << endl;
	fileOut << endl;
}
// report money earn by the station
void UBikeSys::netSearch(string station){
	int i, j;
	int total = 0;

	fileOut << station;
	for (i=0; i<15; i++){
		fileOut << "=";
	}
	fileOut << endl;
	for (i=0; i<CLASS_NUM; i++){
		int classTotal = 0;
		for (j=0; j<STATION_NUM; j++){
			classTotal += this->net[STATIONS[j]][CLASSES[i]];
		}
		total += classTotal;
		fileOut << CLASSES[i] << " " << classTotal;
		fileOut << endl;
	}
	for (i=0; i<15; i++){
		fileOut << "=";
	}
	fileOut << endl;
	fileOut << "Total " << total << endl;
	fileOut << endl;
}
// print binary search tree
void UBikeSys::bReport(){
	fileOut << "Binary Search Tree" << endl;
	fileOut << this->bikeOwn.preorder() << endl;
	fileOut << this->bikeOwn.inorder() << endl;
}
