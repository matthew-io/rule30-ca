#include <iostream>
using namespace std;
#define square "\u2588"

int gen_rules(int left, int center, int right);
void print_generation(const int* cells, int arrayLength);
void next_generation(int* cells, int arrayLength, int* new_generation);

int main() 
{
    // sets the width of the 1d array/automaton
    // size reflects the amount of cells in a single generation
    int size = 50;
    int cells[size];

    // initialises all cells to 0 (i.e. dead), middle cell to 1 (i.e. alive).
    for (int i =0;i<size;i++) {
        cells[i] = 0;
    }
    cells[size/2] = 1;

    // gets length of cell array
    int arrayLength = sizeof(cells) / sizeof(cells[0]);
    
    // displays initial generation
    print_generation(cells, arrayLength);

    // sets number of generations, can be increased 
    int numGenerations = 20;  

    for (int generation = 0; generation < numGenerations; generation++) {
        int new_generation[arrayLength];
        next_generation(cells, arrayLength, new_generation);

        for (int i = 0; i < arrayLength; i++) {
            cells[i] = new_generation[i];
        }

        print_generation(cells, arrayLength);
    }

    return 0;
}

void next_generation(int* cells, int arrayLength, int* new_generation) {
    // applies rule 30 ruleset to each cell, with boundary cells being an exception
    for (int i = 1; i < arrayLength - 1; i++) {
        int l = cells[i-1];
        int c = cells[i];
        int r = cells[i+1];
        new_generation[i] = gen_rules(cells[i - 1], cells[i], cells[i + 1]);
    }

    new_generation[0] = 0; 
    new_generation[arrayLength - 1] = 0; 
}

void print_generation(const int* cells, int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        cout << (cells[i] ? square : " ");
    }
    cout << endl;
}

// rule 30 ruleset
int gen_rules(int left, int center, int right)
{
    if (left == 1 && center == 1 && right == 1) return 0;
    if (left == 1 && center == 1 && right == 0) return 0;
    if (left == 1 && center == 0 && right == 1) return 0;
    if (left == 1 && center == 0 && right == 0) return 1;
    if (left == 0 && center == 1 && right == 1) return 1;
    if (left == 0 && center == 1 && right == 0) return 1;
    if (left == 0 && center == 0 && right == 1) return 1;
    if (left == 0 && center == 0 && right == 0) return 0;

    return 0;
}