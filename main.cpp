#include <iostream>

#include "bruteforce.h"
#include "greedy.h"
#include "dynamic_prog.h"
#include "reader.h"
#include "pallet.h"

using namespace std;

int main() {
    vector<Pallet> pallets;
    readPalletsFile("/home/bia/Documents/feup/DA/SecondProjectDA/pallets.csv",pallets);

    Data data;
    readTruckFile("/home/bia/Documents/feup/DA/SecondProjectDA/truckandpallets.csv",data);

    for (int i=0; i<pallets.size(); i++) {
        cout<<pallets[i].id<<endl;
        cout<<pallets[i].weight<<endl;
        cout<<pallets[i].profit<<endl;
    }

    cout<<data.capacity<<endl;
    cout<<data.n_pallets<<endl;


    int option;
    cout << "Choose an algorithm:\n";
    cout << "1 - Brute Force\n";
    cout << "2 - Dynamic Programming\n";
    cout << "3 - Greedy Approach\n";
    cout << "4 - Linear Programming (Not Implemented)\n";
    cout << "Enter your choice: ";
    cin >> option;

    switch (option) {
        case 1: {
            bruteforce(data, pallets);
            break;
        }
        case 2: {
            dynamicProgramming(data, pallets);
            break;
        }
        case 3: {
            greedy(data, pallets);
            break;
        }
        case 4: {
            cout << "Linear Programming algorithm is not implemented yet.\n";
            break;
        }
        default:
            cout << "Invalid option. Please run the program again and choose a valid option.\n";
    }

    return 0;
}

