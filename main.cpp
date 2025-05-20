#include <iostream>

#include "bruteforce.h"
#include "greedy.h"
#include "dynamic_prog.h"
#include "reader.h"
#include "pallet.h"
#include "ilp.cpp"

using namespace std;

int main() {
    vector<Pallet> pallets;
    readPalletsFile("C:/Users/Dival/Documents/Universidade/2ANO/2_SEM/DA/SecondProject/SecondProjectDA/pallets.csv",pallets);

    Data data;
    readTruckFile("C:/Users/Dival/Documents/Universidade/2ANO/2_SEM/DA/SecondProject/SecondProjectDA/truckandpallets.csv",data);

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
    cout << "4 - Integer Linear Programming\n"; 
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
            ilp(data, pallets);  
            break;
        }
        default:
            cout << "Invalid option. Please run the program again and choose a valid option.\n";
    }

    return 0;
}

