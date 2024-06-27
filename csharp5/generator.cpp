#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int n,m;
class Resource {
public:
    string resourceName;
    int quantity;
    double unitCost;
    Resource() { }  // default constructor
    Resource(string resourceName, int quantity, double unitCost)
         { 
                this->resourceName = resourceName;
                this->quantity = quantity;
                this->unitCost = unitCost;
         }
};
vector<string> resourceNames = {"Table","Chair","Desk","Monitor","Keyboard","Mouse","Printer","Scanner","Projector","Speaker","Laptop","CPU","GPU","RAM","Motherboard","HardDisk","SSD","Cabinet","UPS","Router","Switch","Firewall","AccessPoint","Cable","Hub","Modem","Server","Workstation","Mainframe","Supercomputer","Smartphone","Tablet","Smartwatch","FitnessTracker","Earphones","Headphones","Speaker","Microphone","Webcam","Camera","Drone","GPS","Projector","Printer","Scanner","Fax","Photocopier","Plotter","Speaker","Amplifier","Microphone","Headphones","Earphones","SmartSpeaker","SmartDisplay","SmartCamera","SmartDoorbell","SmartLock","SmartThermostat","SmartLight","SmartPlug","SmartSwitch","SmartSensor","SmartAlarm","SmartVacuum","SmartOven","SmartFridge","SmartKettle","SmartCoffeeMaker","SmartToaster","SmartMicrowave","SmartDishwasher","SmartWashingMachine","SmartDryer","SmartVacuumCleaner","SmartAirPurifier","SmartDehumidifier","SmartHumidifier","SmartFan","SmartHeater","SmartAirConditioner","SmartThermostat","SmartLightBulb","SmartCurtain","SmartBlind","SmartWindow","SmartDoor","SmartGarageDoor","SmartLock","SmartSecurityCamera","SmartDoorbell","SmartAlarm","SmartSmokeDetector","SmartCarbonMonoxideDetector","SmartWaterLeakDetector","SmartWaterShutoffValve","SmartIrrigationController","SmartSprinkler","SmartPoolController","SmartHotTub","SmartGarden","SmartLawnMower","SmartGrill","SmartPestControl","SmartComposter","SmartTrashCan","SmartRecyclingBin","SmartMailbox","SmartPackageDeliveryBox","SmartPetFeeder","SmartPetDoor","SmartPetCamera","SmartPetTracker","SmartPetActivityTracker","SmartPetHealthMonitor","SmartPetWaterDispenser","SmartPetLitterBox","SmartPetToilet","SmartPetShower","SmartPetDryer","SmartPetGroomer","SmartPetToy","SmartPetBed","SmartPetHouse","SmartPetCarrier","SmartPetCollar","SmartPetLeash","SmartPetHarness","SmartPetBowl","SmartPetFeeder","SmartPetWaterDispenser","SmartPetLitterBox","SmartPetToilet","SmartPetShower","SmartPetDryer","SmartPetGroomer","SmartPetToy","SmartPetBed","SmartPetHouse","SmartPetCarrier","SmartPetCollar","SmartPetLeash","SmartPetHarness","SmartPetBowl","SmartPetFeeder","SmartPetWaterDispenser","SmartPetLitterBox","SmartPetToilet","SmartPetShower","SmartPetDryer","SmartPetGroomer","SmartPetToy","SmartPetBed","SmartPetHouse","SmartPetCarrier","SmartPetCollar","SmartPetLeash","SmartPetHarness","SmartPetBowl","SmartPetFeeder","SmartPetWaterDispenser","SmartPetLitterBox","SmartPetToilet","SmartPetShower","SmartPetDryer","SmartPetGroomer","SmartPetToy","SmartPetBed","SmartPetHouse","SmartPetCarrier","SmartPetCollar","SmartPetLeash","SmartPetHarness","SmartPetBowl","SmartPetFeeder","SmartPetWaterDispenser","SmartPetLitterBox","SmartPetToilet","SmartPetShower","SmartPetDryer","SmartPetGroomer","SmartPetToy","SmartPetBed","SmartPetHouse","SmartPetCarrier","SmartPetCollar","SmartPetLeash","SmartPetHarness","SmartPetBowl","SmartPetFeeder","SmartPetWaterDispenser","SmartPetLitterBox","SmartPetToilet","SmartPetShower","SmartPetDryer","SmartPetGroomer","SmartPetToy","SmartPetBed","SmartPetHouse","SmartPetCarrier","SmartPetCollar","SmartPetLeash","SmartPetHarness","SmartPetBowl","SmartPetFeeder","SmartPetWaterDispenser","SmartPetLitterBox","SmartPetToilet","SmartPetShower","SmartPetDryer","SmartPetGroomer","SmartPetToy","SmartPetBed","SmartPetHouse","SmartPetCarrier","SmartPetCollar","SmartPetLeash","SmartPetHarness","SmartPetBowl","SmartPetFeeder","SmartPetWaterDispenser","SmartPetLitterBox","SmartPetToilet","SmartPetShower","SmartPetDryer","SmartPetGroomer","SmartPetToy","SmartPetBed","SmartPetHouse","SmartPetCarrier","SmartPetCollar","SmartPetLeash","SmartPetHarness","SmartPetBowl","SmartPetFeeder","SmartPetWaterDispenser","SmartPetLitterBox","SmartPetToilet","SmartPetShower","SmartPetDryer","AirPurifier","Dehumidifier","Humidifier","Fan","Heater","AirConditioner","Thermostat","LightBulb","Curtain","Blind","Window","Door","GarageDoor","Lock","SecurityCamera","Doorbell","Alarm","SmokeDetector","CarbonMonoxideDetector","WaterLeakDetector","WaterShutoffValve","IrrigationController","Sprinkler","PoolController","HotTub","Garden","LawnMower","Grill","PestControl","Composter","TrashCan","RecyclingBin","Mailbox","PackageDeliveryBox","PetFeeder","PetDoor","PetCamera","PetTracker","PetActivityTracker","PetHealthMonitor","PetWaterDispenser","PetLitterBox","PetToilet","PetShower","PetDryer","PetGroomer","PetToy","PetBed","PetHouse","PetCarrier","PetCollar","PetLeash","PetHarness","PetBowl","PetFeeder","PetWaterDispenser","PetLitterBox","PetToilet","PetShower","PetDryer","PetGroomer","PetToy","PetBed","PetHouse","PetCarrier","PetCollar","PetLeash","PetHarness","PetBowl","PetFeeder","PetWaterDispenser","PetLitterBox","PetToilet","PetShower","PetDryer","PetGroomer","PetToy","PetBed","PetHouse","PetCarrier","PetCollar","PetLeash","PetHarness","PetBowl","PetFeeder","PetWaterDispenser","PetLitterBox","PetToilet","PetShower","PetDryer","PetGroomer","PetToy","PetBed","PetHouse","PetCarrier","PetCollar","PetLeash","PetHarness","PetBowl","PetFeeder","PetWaterDispenser","PetLitterBox","PetToilet","PetShower","PetDryer","PetGroomer","PetToy","PetBed","PetHouse","PetCarrier","PetCollar","PetLeash","PetHarness","PetBowl","PetFeeder","PetWaterDispenser","PetLitterBox","PetToilet","PetShower","PetDryer","PetGroomer","PetToy","PetBed","PetHouse","PetCarrier","PetCollar","PetLeash","PetHarness","PetBowl","PetFeeder","PetWaterDispenser"};
vector<Resource> database;
vector<pair<array<string,2>,int>> requisition;
void printTest() {
    cout << n << endl;
    for(int i=0;i<n;i++){
        cout<<database[i].resourceName<<" "<<database[i].quantity<<" "<<database[i].unitCost<<endl;
    }
    cout<<m<<endl;
    for(int i=0;i<m;i++){
        cout<<requisition[i].first[0]<<" "<<requisition[i].first[1]<<" "<<requisition[i].second<<endl;
    }
}

void writeTest(int test) {
    startTest(test);
    database.clear();
    requisition.clear();
    if(test == 0){
        n = 3;
        database = {Resource("Table",15,300),Resource("Chair",30,100),Resource("Desk",10,500)};
        m = 4;
        requisition = {{{"Add","Table"},10},{{"Add","Chair"},20},{{"Remove","Table"},5},{{"Add","Desk"},5}};
        printTest();
    }
    if(test == 1){
        n = 2;
        database = {Resource("Monitor",8,200),Resource("Keyboard",15,50),Resource("Desk",10,500)};
        m = 4;
        requisition = {{{"Add","Monitor"},10},{{"Add","Keyboard"},12},{{"Remove","Monitor"},3},{{"Add","Keyboard"},5}};
        printTest();

    }
    if(test >= 2){
        if(test<=5)n = rnd.next(10,20);
        if(test>=6 && test<=8)n = rnd.next(50,90);
        if(test>=9 && test<=14)n = resourceNames.size();
        shuffle(resourceNames.begin(),resourceNames.end());
        map<string,int> mp,removed;
        for(int i=0;i<n;i++){
            int quantity = rnd.next(1,100);
            double unitCost = rnd.next(1,1000);
            database.push_back(Resource(resourceNames[i],quantity,unitCost));
            mp[database[i].resourceName] = database[i].quantity;
        }
        m = rnd.next(n,2*n);
        for(int i=0;i<m;i++){
            int p = rnd.next(1,3);
            string s= "Add";
            if(p<=2){
                int resourceIndex = rnd.next(0,n-1);
                string resourceName = database[resourceIndex].resourceName;
                int avail = mp[resourceName]/3;
                if(avail == 0)avail = 1;
                int q = rnd.next(1,avail);
                if(i%60==59)q = mp[resourceName]+rnd.next(2,3);
                requisition.push_back({{s,resourceName},q});
                q = min(q,mp[resourceName]);
                mp[resourceName] -= q;
                removed[resourceName] += q;
            }
            else{
                s = "Remove";
                int resourceIndex = rnd.next(0,n-1);
                string resourceName = database[resourceIndex].resourceName;
                int avail = removed[resourceName];
                if(avail == 0)avail = 1;
                int q = rnd.next(1,avail+100);
                requisition.push_back({{s,resourceName},q});
                q = min(q,removed[resourceName]);
                removed[resourceName] -= q;
                mp[resourceName] += q;
            }
        }
        printTest();
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int tests = atoi(argv[1]);
    for (int i = 0; i < tests; i++)
        writeTest(i);
    return 0;
}
