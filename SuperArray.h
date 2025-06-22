#pragma once
#include <iostream>                 //for cout
#include <random>					//for random
using namespace std;


//super array template class to be used for any arrays needed
template <class T>
class SuperArray
{
	int _maxSize = 4; //initialize max size attribute at 4
	T* _array = NULL; //initialize array pointer to null
	int _length = 0;  //initialize array length to 0
	T dummy;          //make a dummy value to return instead of crashing

	void grow()
	{
		//doube the array size  
		_maxSize *= 2;

		//create a temporary array
		T* temp = new T[_maxSize];

		//copy the old content into temp array
		for (int i = 0; i < _length; i++)
		{
			temp[i] = _array[i];
		}

		//free the old memory
		delete[] _array;

		//point _array at new, larger array
		_array = temp;

		//set temp array to null
		temp = NULL;
	}

public:

	//default constructor
	SuperArray()
		:
		_array(NULL),				  // the pointer isn't valid yet
		_maxSize(4),                  // initialize max size to 4
		_length(0)					  // initialize the length to 0
	{
		_array = new T[_maxSize];  //allocate new memory
	}

	//copy constructor
	SuperArray(const SuperArray& otherObj)
		:
		_array(NULL),				  // the pointer isn't valid yet
		_maxSize(otherObj._maxSize),  // copy the maxSize
		_length(otherObj._length)	  // copy the current length
	{
		//allocate memory for super array
		_array = new T[_maxSize];

		//copy each product
		for (int i = 0; i < _maxSize; i++)
		{
			_array[i] = otherObj._array[i]; //set the value at current position to the respective value in the other array
		}
	}

	//destructor
	~SuperArray()
	{
		//if the array isn't null
		if (_array)
		{
			//delete allocated memory
			delete[] _array;
		}
	}

	//assignment operator
	void operator=(const SuperArray& otherObj)
	{
		//set max size to the max size of the other object
		_maxSize = otherObj._maxSize;

		//set length to the length of the other object
		_length = otherObj._length;

		//if the pointer isn't null
		if (_array)
		{
			//delete allocated memory
			delete[] _array;
		}

		//allocate memory for super array
		_array = new T[_maxSize];

		//loop through the array
		for (int i = 0; i < _maxSize; i++)
		{
			//set the value to the corresponding value in the other object
			_array[i] = otherObj._array[i];
		}
	}

	//subscript operator 
	T& operator[](int index)
	{
		//if index is invalid
		if (index < 0 or index >= _length)
		{
			return dummy;
		}

		//return the value at index position
		return _array[index];
	}

	//const subscript operator 
	T operator[](int index) const
	{
		//if index is invalid
		if (index < 0 or index >= _length)
		{
			return dummy;
		}

		//return the value at index position
		return _array[index];
	}

	/**
	* function to insert a value into the array
	*
	* @param index                    the place to insert at
	* @param value                    the value to insert
	**/
	void insert(int index, T value)
	{
		//check if SuperArray is not intialized
		if (not _array)
		{
			//quit
			return;
		}

		//check if the index is invalid
		if (index < 0 or index > _length)
		{
			//quit
			return;
		}

		//check if the array is full
		if (_length >= _maxSize)
		{
			//call grow to expand the array
			grow();
		}

		//loop from the end to the index
		for (int i = _length; i > index; i--)
		{
			//shift the value from the left of current position, right
			_array[i] = _array[i - 1];
		}

		//set the value at index position to the value to be inserted
		_array[index] = value;

		//increase the length counter
		_length++;
	}

	void pushFront(T value)
	{
		//insert value at the beginning of the array
		insert(0, value);
	}

	void pushBack(T value)
	{
		//insert the value at the end of the allocated part of the array
		insert(_length, value);
	}

	T remove(int index)
	{
		//check if the index is invalid
		if (index < 0 or index >= _length)
		{
			//return placeholder
			return dummy;
		}

		//save the value before it's overwritten
		T save = _array[index];

		//loop from the index to be removed to the end
		for (int i = index; i < _length - 1; i++)
		{
			//overwrite the value to the value of the index to the right
			_array[i] = _array[i + 1];
		}

		//shorten the length by one
		_length--;

		//return the value of what was removed
		return save;
	}

	/**
	* get/set the first element
	**/
	T popFront()
	{
		//removes and returns first element
		return remove(0);
	}

	/**
	* get/set the last element
	**/
	T popBack()
	{
		//removes and returns last element
		return remove(_length - 1);
	}

	/**
	* print out every element
	**/
	void print() const
	{
		//if the pointer is null
		if (not _array)
		{
			//quit
			return;
		}

		//if array is empty
		if (_length == 0)
		{
			//tell user its empty
			cout << "empty array";

			//quit
			return;
		}

		//loop through every element in the array
		for (int i = 0; i < _length; i++)
		{
			//print out the element 
			cout << _array[i] << ", ";
		}
	}

	/**
	* shuffle the array
	**/
	void shuffle()
	{

		//cant shuffle nothing
		if (_length <= 0)
		{
			return;
		}
		//seed random number static so it happens once
		static random_device device;

		//generate a random number from 0 to the last element in the array
		uniform_int_distribution<int>bounds(0, _length - 1);

		//loop through the array until the last element
		for (int i = 0; i < _length; i++)
		{
			//make a variable to store the random number
			int index = bounds(device);

			//make a temporary variable to store an array element
			T temp = _array[i];

			//set the value at current index to the value at a random index
			_array[i] = _array[index];

			//set the value at that random index to the old value of the current index
			_array[index] = temp;
		}
	}

	/**
	* This  sorts the elements of an array using exchange sort.
	*
	* @param ascending                     whether or not to sort ascending
	*/
	void sort(bool ascending = true)
	{
		//loop through the number of passes needed
		for (int i = 0; i < _length - 1; i++)
		{
			//compare current element to every unsorted element
			for (int j = i + 1; j < _length; j++)
			{
				//check if elements out of order
				if ((ascending and _array[i] > _array[j]) or (!ascending and _array[i] < _array[j]))
				{
					T temp = _array[i];     //save the first
					_array[i] = _array[j];  //overwrite the first
					_array[j] = temp;     //overwrite the second          
				}
			}
		}
	}

	//getting the size
	int getSize() const
	{
		//return the size
		return _length;
	}
};
