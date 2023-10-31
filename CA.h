#define SQUARE "\u2588"
#define MIN_GENERATIONS 35
#define MIN_SIZE 65
#define RULE_NUMBER 137
#include <vector>
#include <iostream>
using namespace std;

int gen_rules(int left, int center, int right, vector<int> binaryVector);
vector<int> decimalToBinary(int num);
void print_generation(const int* cells, int arrayLength);
void next_generation(int* cells, int arrayLength, int* new_generation, vector<int> binaryArray);

