/*
	Author: Dung Harry
	Date created: 8th, November 2013
	Operating System: Ubuntu 13.04 Desktop x86_64
	Compiler: GNU compiler 4.8.1

	Description: this is the program about binary seach in C++ programming language
*/

#include <iostream>

using namespace std;

#define NOT_FOUND -1

class BinarySearch {
	public:
		BinarySearch();
		BinarySearch(int iSumElement);
		~BinarySearch();
		void vBinarySearch(int first, int last, int value, int &key);
		int getSumElement();
		void setSumElement(int iNewSum);
		void vEnterData();
		void vSort();
		void vDisplay();

	private:
		int *lpiData;
		int iSumElement;
};

BinarySearch::BinarySearch() {
	cout<<"Enter number of array do you want: ";
	cin>>this->iSumElement;
	this->lpiData = new int[this->iSumElement];

	this->vEnterData();
};

BinarySearch::BinarySearch(int iSumElement) : iSumElement(iSumElement) {
	this->lpiData = new int[this->iSumElement];

	this->vEnterData();
};

BinarySearch::~BinarySearch() {
	delete[] this->lpiData;
};

void BinarySearch::vEnterData() {
	cout<<"Enter the data part..."<<endl<<endl;

	for(int i = 0; i < this->iSumElement; i ++) {
		cout<<"Enter the value of element "<<i<<": ";
		cin>>*(this->lpiData + i);
	}

	cout<<"Finish entering data..."<<endl<<endl;
};

int BinarySearch::getSumElement() {
	return this->iSumElement;
};

void BinarySearch::setSumElement(int iNewSum) {
	this->iSumElement = iNewSum;
};

void BinarySearch::vSort() {
	for(int i = 0; i < this->iSumElement; i ++) {
		for(int j = 0; j <= i; j ++) {
			if(*(this->lpiData + i) < *(this->lpiData + j)) {
				*(this->lpiData + i) ^= *(this->lpiData + j);
				*(this->lpiData + j) ^= *(this->lpiData + i);
				*(this->lpiData + i) ^= *(this->lpiData +j);
			}
		}
	}
};

void BinarySearch::vBinarySearch(int first, int last, int value, int &key) {
	int iMiddle = static_cast<int>((first + last) / 2);

	while((last > first) && (*(this->lpiData + iMiddle) != value)) {
		*(this->lpiData + iMiddle) < value ? first = iMiddle + 1 : last = iMiddle - 1;

		iMiddle = static_cast<int>((first + last) / 2);
	}

	 *(this->lpiData + iMiddle) == value ? key = iMiddle : key = NOT_FOUND;
};

void BinarySearch::vDisplay() {
	for(int i = 0; i < this->iSumElement; i ++) {
		cout<<"Element "<<i<<": "<< *(this->lpiData + i) <<endl;
	}
};

int main(int argc, char *argv[]) {
	cout<<"Author: Dung Harry. Date created: 9th, November 2013"<<endl<<endl;

	BinarySearch object;
	int index, value;

	object.vSort();

	cout<<"The array after sorting is as following: "<<endl<<endl;

	object.vDisplay();

	cout<<"Enter the value you want to search: ";
	cin>>value;

	object.vBinarySearch(0, object.getSumElement() - 1, value, index);

	if(index == NOT_FOUND) {
		cout<<"Not found"<<endl;
	} else {
		cout<<"The result is: "<<index<<endl;
	}
}
