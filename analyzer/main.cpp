#include <iostream>
#include "StringData.h"


int linearSerach(std::vector<std::string> stringData, std::string element) {

	for (int i = 0; i < stringData.size(); i++) {
		if ((stringData[i] == element)) return i;
	}

	return -1;
}

int binarySearch(std::vector<std::string> stringData, std::string element) {
	
	int index = 0;
	int high = stringData.size()-1;
	int low = 0;
	if (stringData[0] == element) {
		return 0;
	}
	
	while (high-low ) {
	
		int midPoint = low + ((high -low) / 2);

		for (int i = 0; i < element.size(); i++) {

			if ((int)element[i] < (int)stringData[midPoint][i]) {
				high = midPoint;
				break;

			}
			else if ((int)element[i] > (int)stringData[midPoint][i]) {
				low = midPoint;
				index += midPoint;
				break;
			}
		}
		if (element == stringData[midPoint]) {
			return  midPoint;
		}
		else if (element == stringData[low]) return low;
		else if (element == stringData[high]) return high;
		
	}

	return -1;
}

int main() {
	
	long long preTime = systemTimeNanoseconds();
	std::vector<std::string> stringData = getStringData();
	long long endTime = systemTimeNanoseconds();
	printf("time to make list %i\n", endTime - preTime);


	preTime = systemTimeNanoseconds();
	int index = linearSerach(stringData, "zzzzz");
	endTime = systemTimeNanoseconds();
	printf("Index @ %i\n", index);
	printf("time to linear %i\n", endTime - preTime);

	preTime = systemTimeNanoseconds();
	index = binarySearch(stringData, "zzzzz");
	endTime = systemTimeNanoseconds();
	printf("Index @ %i\n", index);
	printf("time to bianry %i\n", endTime - preTime);

	return 0;

}