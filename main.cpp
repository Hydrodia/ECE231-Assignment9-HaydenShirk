#include <iostream>
using namespace std;

template <typename T>
class GenericArray{
    private:
	T* data;
	int length;
    public:
	//default constructor
	GenericArray(){
	    data = nullptr;
	    length = 0;
 	}

	//default destructor
	~GenericArray(){
	    delete[] data;
	}

	//output array
	void output(){
	    for(int i = 0; i < length; i++){
	        cout << data[i] << ", ";
	    }
	}

	//add element to end of array
	void addElement(T param){
	    T* newArray = new T[length + 1];

	    for(int i = 0; i < length; i++){
		newArray[i] = data[i];
	    }

	    newArray[length] = param;

	    delete[] data;

	    data = newArray;
	    length++;
	}

	//return element at a specific index
	T at(int param){
	    if(param < 0 || param >= length){
		cout << "Index out of bounds!" << endl;
		return 1;
	    }
	    return data[param];
	}

	//reutrn size of array
	int size(){
	    return length;
	}

	// sum of all the elements
	T sum(){
	    T total = 0;

	    for(int i = 0; i < length; i++){
		total += data[i];
	    }

	    return total;
	}

	//return max of data array
	T max(){
	    if(length == 0){
		cout << "Array is empty!" << endl;
		return 1;
	    }

	    T max = data[0];

	    for(int i = 0; i < length; i++){
		if(data[i] > max){
		    max = data[i];
		}
	    }

	    return max;
	}

	//return min of data array
	T min(){
	    if(length == 0){
		cout << "Array is empty!" << endl;
		return 1;
	    }

	    T min = data[0];

	    for(int i = 0; i < length; i++){
		if(data[i] < min){
		    min = data[i];
		}
	    }

	    return min;
	}

	//make new array between two indexs of the data array
	T* slice(int begin, int end){
	    if(begin < 0 || end >= length || begin > end){
		cout << "Not vaild bounds!" << endl;
		return nullptr;
	    }

	    int sliceSize = end - begin + 1;

	    T* slicedArray = new T[sliceSize];

	    for(int i = 0; i < sliceSize; i++){
		slicedArray[i] = data[(begin - 1) + i];
	    }

	    return slicedArray;
	}
};

int main(){
    GenericArray<int> int_array;

    int_array.addElement(10);
    int_array.addElement(20);
    int_array.addElement(30);
    int_array.addElement(40);
    int_array.addElement(50);
    int_array.addElement(60);
    
    cout << "Array: ";
    int_array.output();
    cout<< endl;
    cout << "Size of array is: " << int_array.size() << endl;
    cout << "Sum of the array is: " << int_array.sum() << endl;
    cout << "Max of array is: " << int_array.max() << endl;
    cout << "Min of the array is: " << int_array.min() << endl;
    cout << "Element at index 3 is :" << int_array.at(3) << endl;

    int* slicedArray = int_array.slice(2, 5);

    cout << "Sliced Array from 2 to 5: ";

    for(int i = 0; i < 4; i++){
	cout << slicedArray[i] << ", ";
    }

    cout << endl;

    delete[] slicedArray;

    return 0;
}
