#ifndef HEAP_HPP
#define HEAP_HPP
#include <vector>
#include <array>
template<typename T>
class Heap
{
private:
	std::vector<T>data;
	bool ismax = true;
	//These should be include functions that dont modify any of the data
	constexpr int Parent(int i) const;
	constexpr int Left(int i) const;
	constexpr int Right(int i) const;
	void Heapify(int i, bool turn_max);

public:
	//Shall have a default construct
	Heap() = default;
	//Shall have a constructor taking in vector
	explicit constexpr Heap(const std::vector<T>& arr);
	//Takies in a explicit array of point  type
	explicit constexpr Heap(const T* arr);
	//Takes in a explicit array array
	template<std::size_t SIZE>
	explicit constexpr Heap(const std::array<T, SIZE>& array);
	//Take into two ranges of variable types
	template<typename InputIterator>
	constexpr Heap(const InputIterator& start, const InputIterator& end);
	//Take in initalizer list
	constexpr Heap(const std::initializer_list<T>& list);

	//Copy construction
	Heap(const Heap<T>& target);
	//Move constructor
	Heap(Heap<T>&& source);
	//Assignment operator
	Heap<T>& operator =(const Heap<T>& target);
	//Move semantics
	Heap<T>& operator=(Heap<T>&& source);
	//Allow the user to switch between heaps if they want to Max heap they make Max heap (Pass into heapify to notify that we are max heapify
	void MakeMaxHeap();
	//Allow the user to swtich between heaps if they want a Min then they make min heap(Pass into heapify to notify that we want to mainatain heapfify
	void MakeMinHeap();

	T& top(); //Gets the top of the array and eliminates it. And then reheapify according to if its a min heap or a max heap
	T& remove();// Remove top element and return it
	//Insert element accordinat to its position.Inserts at the end  and then heapify
	void Insert(T& element);
	//Increase the key
	void KeyChange(int& x, int newval);
};
#ifndef HEAP_CPP
#include "Heap.cpp"
#endif //
//Shifting right by 1
template<typename T>
inline constexpr int Heap<T>::Parent(int i) const
{
	return i >> 1;
}
//Shifting left by one
template<typename T>
inline constexpr int Heap<T>::Left(int i) const
{
	return i << 1;
}
//Shifting left by 1 and adding one
template<typename T>
inline constexpr int Heap<T>::Right(int i) const
{
	return (i << 1) + 1;
}

#endif