
int numberOfRows = 5;

int length[5] = { 3, 4, 2, 5, 4 };

int** irregularArray = new int* [numberOfRows];

for (int i = 0; i < numberOfRows; i++) {
	irregularArray[i] = new int[length[i]];
}

irregularArray[0][0] = 1;
irregularArray[0][1] = 2;
irregularArray[0][2] = 3;


cout << irregularArray[0][1] << endl; // Output: 2
cout << irregularArray[3][4] << endl; // Output: (undefined value, as it has not been initialized)



