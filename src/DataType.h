#ifndef DATATYPE_H
#define DATATYPE_H

enum StatusType {Free, Rented};
enum ClassType {Electric, Lady, Road, Hybrid};
enum StationType {
    Danshui, Hongshulin, Beitou, Shilin, Zhongshan, Xinpu,
    Ximen, Liuzhangli, Muzha, Guting, Gongguan, Jingmei
};
typedef char LicenseType[5];
struct BikeType {
    LicenseType license;
    StatusType status;
    int mileage;    // most recently one
    int cursor;     // pointer of entry in heap
    StationType station;
    ClassType classes;
};
typedef struct BikeType *BikePtr;
struct HeapType {
    BikePtr elem[256]; // heap implementation
    int number;
};
struct StationType{
    int net; //total income
    int netElectric;
    int netLady;
    int netRoad;
    int netHybrid;
    int numElectric;
    int numLady;
    int numRoad;
    int numHybrid;
    HeapType hRent;
    HeapType hElectric;
    HeapType hLady;
    HeapType hRoad;
    HeapType hHybrid;
};

#endif
