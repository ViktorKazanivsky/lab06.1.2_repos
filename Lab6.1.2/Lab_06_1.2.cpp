#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int ARRAY_SIZE = 21;

int RandomNumberGeneration(int min, int max) {
    return min + (rand() % (max - min + 1));
}

void GenerateArray(int array[], int min, int max, int index = 0) {
    if (index < ARRAY_SIZE) {
        array[index] = RandomNumberGeneration(min, max);
        GenerateArray(array, min, max, index + 1);
    }
}

void Print(int array[], int size, int index = 0) {
    if (index < size) {
        cout << setw(4) << array[index] << " ";
        Print(array, size, index + 1);
    }
    else {
        cout << endl;
    }
}

int CountCorrectElements(int array[], int index = 0) {
    if (index == ARRAY_SIZE) {
        return 0;
    }

    int count = CountCorrectElements(array, index + 1);

    if (array[index] % 2 != 0 || index % 13 == 0) {
        count++;
    }

    return count;
}

int SumCorrectElements(int array[], int index = 0) {
    if (index == ARRAY_SIZE) {
        return 0;
    }

    int sum = SumCorrectElements(array, index + 1);

    if (array[index] % 2 != 0 || index % 13 == 0) {
        sum += array[index];
    }

    return sum;
}

void ReplaceWithZeros(int array[], int index = 0) {
    if (index < ARRAY_SIZE) {
        if (array[index] % 2 == 0 || index % 13 == 0) {
            array[index] = 0;
        }
        ReplaceWithZeros(array, index + 1);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int Array[ARRAY_SIZE];
    GenerateArray(Array, 15, 85);

    cout << "Unmodified Array:" << endl;
    Print(Array, ARRAY_SIZE);

    int count = CountCorrectElements(Array);
    int sum = SumCorrectElements(Array);

    cout << "Count of correct elements: " << count << endl;
    cout << "Sum of correct elements: " << sum << endl;

    ReplaceWithZeros(Array);

    cout << "Modified Array:" << endl;
    Print(Array, ARRAY_SIZE);

    return 0;
}