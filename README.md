# DS2017 Final Project

### Environment
Makefile in Ubuntu 16.04 LTS

### Information file description

* `TCx`: Test cases
* `Final-Project_spec_2017.pdf`: Spec (Main doc)
* `Main arguments and command line.pdf`: Testing
* `OutputFormat_2017.docx`: Cmd and Outputs
* `Slides_2017.pptx`: TA's introductions

### Testing the program
* From `Main arguments and command line.pdf`

In cmd:
```
$ make
$ ./main ./Informations/TC1/testCase01 ./Informations/TC1/testMap out.txt
```
To clear object files:
```
$ make clean
```
### Function to implement
* NewBike
* JunkBikePtr
* TransBikePtr
* RentBikePtr
* Returns
* Inquire
* StationReport
* UbikeReport
* NetSearch
* BReport

<!-- ### Bike Information

* License number
    * Data structure: Binary search tree
    * Type: 5 alphanumeric char
* Mileage
    * Data structure: weight of Max heap
    * Type: int
* Class
    * Data structure: 5 max heap of each station
    * Type: enum string 
        * Electric
        * Lady
        * Road
        * Hybrid
* MRT station
    * Data structure: Graph with miles as edge weight
    * Type: enum string
        * Danshui(淡水)
        * Hongshulin(紅樹林)
        * Beitou(北投)
        * Shilin(士林)
        * Zhongshan(中山)
        * Xinpu(新埔)
        * Ximen(西門)
        * Liuzhangli(六張犁)
        * Muzha(木柵)
        * Guting(古亭)
        * Gongguan(公館)
        * Jingmei(景美)

### Bike rental charges

|Class|Discount|Original|
|-----|--------|--------|
|Electric|$30/mile|$40/mile|
|Lady|$25/mile|$30/mile|
|Road|$15/mile|$20/mile|
|Hybrid|$20/mile|$25/mile| -->

<!-- ### Operation usage and description
* From `OutputFormat_2017.docx`

#### NewBike
1. Create a node
2. Put License into tree and heap

Input:
```
$ NewBike Class License Mile StationName
```
Output:
```
New bike is received by Station StationName.
```

#### Junklt
1. Search the bike with license
2. Delete the bike

Input:
```
Junklt License
```
Output (3 conditions):
```
Bike License is deleted from StationName.
Bike License is now being rented.
Bike License does not belong to out company.
```

#### Rent
1. Find a free bike with the largest mileage
2. Perform function RentBikePtr for renting a bike. 

Input:
```
Rent StationName Class
```
Output (2 conditions):
```
A bike is rented from StationName.
No free bike is available.
```

#### Returns
1. Perform function Returns. 

Input:
```
Returns StationName License Mile
```
Output:
```
Rental charge for this bike is $$$.
```

#### Trans
1. Move the bike with license to StationName

Input:
```
Trans StationName License
```
Output (3 conditions):
```
Bike License is transferred to StationName.
Bike License does not belong to our company.
Bike License is now being rented.
```

#### Inquire

Input:
```
Inquire License
```
Output (each 15 chars):

|License|Mileage|Class|Station|
|-------|-------|-----|-------|
|00BC4|50|Lady|Danshui|

or
```
Bike License does not belong to our company.
```

#### StationReport

Input:
```
StationReport StationName
```
Output:
Checkout OutputFormat_2017.docx

#### UbikeReport

Input:
```
UbikeReport
```

Output:
Checkout OutputFormat_2017.docx

#### NetSearch

Input:
```
NetSearch StationName
```

Output:
Checkout OutputFormat_2017.docx -->
