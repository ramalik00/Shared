#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void print(const vector<string>& censusData, const vector<string>& uniqueOccupations) {
    cout << censusData.size() << endl;
    for (const auto& data : censusData) {
        cout << data << endl;
    }
    cout << uniqueOccupations.size() << endl;
    for (const auto& occupation : uniqueOccupations) {
        cout << occupation << endl;
    }
}

void writeTest(int test) {
    startTest(test);

    vector<string> censusData;
    vector<string> uniqueOccupations;

    if(test == 0) {
        censusData = {
            "123 456 789,4,teacher,60000",
            "234 567 890,3,teacher,70000",
            "345 678 901,5,engineer,80000",
            "456 789 012,2,engineer,90000",
            "567 890 123,6,doctor,100000",
            "678 901 234,1,doctor,110000"
        };
        uniqueOccupations = {"teacher", "engineer", "doctor"};
        print(censusData, uniqueOccupations);
    }
    if(test == 1) {
        censusData = {
            "987 654 321,3,lawyer,120000",
            "876 543 210,4,lawyer,130000",
            "765 432 109,5,accountant,140000",
            "654 321 098,2,accountant,150000",
            "543 210 987,6,manager,160000",
            "432 109 876,1,manager,170000"
        };
        uniqueOccupations = {"lawyer", "accountant", "manager"};
        print(censusData, uniqueOccupations);
    }
    if(test == 2) {
        censusData = {
            "321 786 980,6,engineer,9000000",
            "321 786 981,3,engineer,1000000",
            "321 786 982,7,engineer,5000000",
            "321 786 984,10,engineer,3000000",
            "321 786 970,1,doctor,1800000",
            "321 786 971,1,doctor,1800000",
            "321 786 972,3,doctor,1800000",
            "321 786 990,4,nurse,300000",
            "321 786 991,4,nurse,300000",
            "321 786 920,5,farmer,90000",
            "321 786 921,3,farmer,90000",
            "321 786 921,6,farmer,80000",
            "321 786 930,2,business,9000000"
        };
        uniqueOccupations = {"engineer", "doctor", "nurse", "farmer", "business"};
        print(censusData, uniqueOccupations);
    }
    if(test == 3) {
        censusData = {
            "321 456 789,4,teacher,80000",
            "123 567 890,2,engineer,90000",
            "234 678 901,6,doctor,100000",
            "456 789 012,1,lawyer,110000",
            "345 890 123,5,accountant,120000",
            "567 901 234,3,manager,130000"
        };
        uniqueOccupations = {"teacher", "engineer", "doctor", "lawyer", "accountant", "manager"};
        print(censusData, uniqueOccupations);
    }
    if(test == 4) {
        censusData = {
            "112 233 344,3,chef,50000",
            "223 344 455,4,teacher,60000",
            "334 455 566,2,engineer,70000",
            "445 566 677,5,doctor,80000",
            "556 677 788,3,lawyer,90000",
            "667 788 899,4,accountant,100000",
            "778 899 900,2,manager,110000"
        };
        uniqueOccupations = {"chef", "teacher", "engineer", "doctor", "lawyer", "accountant", "manager"};
        print(censusData, uniqueOccupations);
    }
    if(test == 5) {
        censusData = {
            "998 877 665,5,pilot,150000",
            "887 776 554,2,teacher,65000",
            "776 665 443,3,engineer,85000",
            "665 554 332,4,doctor,95000",
            "554 443 221,6,lawyer,115000",
            "443 332 110,1,accountant,125000",
            "332 221 009,3,manager,135000"
        };
        uniqueOccupations = {"pilot", "teacher", "engineer", "doctor", "lawyer", "accountant", "manager"};
        print(censusData, uniqueOccupations);
    }
    if(test == 6) {
        censusData = {
            "999 888 777,4,scientist,200000",
            "888 777 666,3,teacher,70000",
            "777 666 555,5,engineer,90000",
            "666 555 444,2,doctor,110000",
            "555 444 333,6,lawyer,130000",
            "444 333 222,1,accountant,150000",
            "333 222 111,3,manager,160000"
        };
        uniqueOccupations = {"scientist", "teacher", "engineer", "doctor", "lawyer", "accountant", "manager"};
        print(censusData, uniqueOccupations);
    }
    if(test == 7) {
        censusData = {
            "321 321 321,4,artist,75000",
            "432 432 432,3,teacher,80000",
            "543 543 543,2,engineer,95000",
            "654 654 654,5,doctor,100000",
            "765 765 765,1,lawyer,120000",
            "876 876 876,6,accountant,140000",
            "987 987 987,3,manager,160000"
        };
        uniqueOccupations = {"artist", "teacher", "engineer", "doctor", "lawyer", "accountant", "manager"};
        print(censusData, uniqueOccupations);
    }
    if(test == 8) {
        censusData = {
            "101 202 303,3,actor,200000",
            "202 303 404,2,teacher,60000",
            "303 404 505,4,engineer,80000",
            "404 505 606,5,doctor,100000",
            "505 606 707,3,lawyer,120000",
            "606 707 808,1,accountant,140000",
            "707 808 909,6,manager,160000"
        };
        uniqueOccupations = {"actor", "teacher", "engineer", "doctor", "lawyer", "accountant", "manager"};
        print(censusData, uniqueOccupations);
    }
    if(test >= 9) {
        int numOfEntries = 100;
        censusData.resize(numOfEntries);
        uniqueOccupations = {
            "teacher", "engineer", "doctor", "lawyer", "accountant", "manager", "nurse", "farmer", 
            "business", "chef", "pilot", "scientist", "artist", "actor", "writer", "journalist",
            "photographer", "musician", "painter", "dancer", "athlete", "coach", "consultant", 
            "developer", "analyst", "architect", "designer", "electrician", "plumber", "mechanic",
            "carpenter", "blacksmith", "tailor", "barber", "beautician", "dentist", "pharmacist",
            "veterinarian", "psychologist", "therapist", "counselor", "social worker", "librarian",
            "curator", "archivist", "translator", "interpreter", "tour guide", "real estate agent"
        };

        for (int i = 0; i < numOfEntries; ++i) {
            int ssn1 = rnd.next(100, 999);
            int ssn2 = rnd.next(100, 999);
            int ssn3 = rnd.next(100, 999);
            int familySize = (rnd.next(0,9)) + 1;
            int s = uniqueOccupations.size();
            string occupation = uniqueOccupations[rnd.next(0, s - 1)];
            int income = rnd.next(0, 99999) + 50000;

            stringstream ss;
            ss << ssn1<<" "<<ssn2<<" "<<ssn3<< "," << familySize << "," << occupation << "," << income;
            censusData[i] = ss.str();
        }
        print(censusData, uniqueOccupations);
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int tests = atoi(argv[1]);
    for (int i = 0; i < tests; i++)
        writeTest(i);
    return 0;
}