#include "CA.h"
#include "Helper.h"
using namespace std;

int main() 
{
    int size = MIN_SIZE;
    int cells[size];

    for (int i =0;i<size;i++) {
        cells[i] = 0;
    }
    cells[size/2] = 1;

    int arrayLength = sizeof(cells) / sizeof(cells[0]);
    
    print_generation(cells, arrayLength);

    int numGenerations = MIN_GENERATIONS;  

    vector<int> binaryArray = decimalToBinary(RULE_NUMBER);

    for (int generation = 0; generation < numGenerations; generation++) {
        int new_generation[arrayLength];
        next_generation(cells, arrayLength, new_generation, binaryArray);

        for (int i = 0; i < arrayLength; i++) {
            cells[i] = new_generation[i];
        }

        print_generation(cells, arrayLength);
    }

    return 0;
}

void next_generation(int* cells, int arrayLength, int* new_generation, vector<int> binaryArray) {
    for (int i = 1; i < arrayLength - 1; i++) {
        int l = cells[i - 1];
        int c = cells[i];
        int r = cells[i + 1];
        new_generation[i] = gen_rules(l, c, r, binaryArray);
    }

    new_generation[0] = 0; 
    new_generation[arrayLength - 1] = 0; 
}

void print_generation(const int* cells, int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        cout << (cells[i] ? SQUARE : " ");
    }
    cout << endl;
}

int gen_rules(int left, int center, int right, vector<int> binaryVector)
{
    if (left == 1 && center == 1 && right == 1) return binaryVector[0];
    if (left == 1 && center == 1 && right == 0) return binaryVector[1];
    if (left == 1 && center == 0 && right == 1) return binaryVector[2];
    if (left == 1 && center == 0 && right == 0) return binaryVector[3];
    if (left == 0 && center == 1 && right == 1) return binaryVector[4];
    if (left == 0 && center == 1 && right == 0) return binaryVector[5];
    if (left == 0 && center == 0 && right == 1) return binaryVector[6];
    if (left == 0 && center == 0 && right == 0) return binaryVector[7];

    return 0;
}