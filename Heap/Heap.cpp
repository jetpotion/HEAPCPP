#include "Heap.hpp"
#ifndef HEAP_CPP
#define HEAP_CPP
template<typename T>
 constexpr Heap<T>::Heap(const std::vector<T>& arr) : data(arr)
{
	 MakeMaxHeap();
}
template<typename T>
 constexpr Heap<T>::Heap(const T* arr): data(arr)
{
	 MakeMaxHeap();
}
template<typename T>
constexpr Heap<T>::Heap(const std::initializer_list<T>& list): data(list)
{
	MakeMaxHeap();
}
template<typename T>
 Heap<T>::Heap(const Heap<T>& target): data(target.data)
{
	
}
template<typename T>
 Heap<T>::Heap(Heap<T>&& source): data(std::move(source.data))
{

}
template<typename T>
 Heap<T>& Heap<T>::operator=(const Heap<T>& target)
{
	 if (*this == &target)
		 return *this;
	// TODO: insert return statement here
	 data = target.data;
	 return *this;
 }
template<typename T>
 Heap<T>& Heap<T>::operator=(Heap<T>&& source)
{
	 if (*this = &source)
		 return*this;
	 data = std::move(source.data);
	 return *this;
	// TODO: insert return statement here
}
 //Important functions 
 template<typename T>
 void Heap<T>::MakeMaxHeap()
 {
	 //Now call heapify 
	 int heap_length = data.size();
	 for (int i = data.size() / 2; i >= 0; i--)
	 {
		 Heapify(i, true);
	 }
 }

 template<typename T>
 void Heap<T>::MakeMinHeap()
 {
	 //Now call heapify 
	 int heap_length = data.size();
	 for (int i = data.size() / 2; i >= 0; i--)
	 {
		 Heapify(i, false);
	 }
 }
 template<typename T>
 T& Heap<T>::top()
 {
	 return data[0];
 }
 template<typename T>
 T& Heap<T>::remove()
 {
	 T var= top();
	 data.erase(data.begin());
	 //Heapify depending if its a max
	 Heapify(0,smax);
	 return var;
 }
 template<typename T>
 void Heap<T>::Insert(T& element)
 {
	 data.insert(0);
	 data[data.size() - 1] = INT_MIN;
	 KeyChange(data.size() - 1, element);
	 
 }
 template<typename T>
 void Heap<T>::KeyChange(int& x, int newval)
 {
	 if ((newval < data[x] && smax) || (newval > data[x] && !smax))
	 {
		 throw std::exception("Not valid key");
	}
	 else
	 {
		 if (smax)
		 {
			 data[x] = newval;
			 while (x > 0 && data[Parent(x)] < data[x])
			 {
				 std::swap(data[x], data[Parent(x)]);
				 x = Parent[x];
			 }
		 }
		 else
		 {

			 data[x] = newval;
			 while (x > 0 && data[Parent(x)] > data[x])
			 {
				 std::swap(data[x], data[Parent(x)]);
				 x = Parent[x];
			 }
		 }
	 }
 }
 template<typename T>
 void Heap<T>::Heapify(int i, bool turn_max)
 {
	 smax = turn_max;
	 //Then its a max heap 
	 if (smax)
	 {
		 int left = Left(i);
		 int right = Right(i);
		 int largest;
		 if (left <= data.size() && data[left] > data[i])
		 {
			 largest = left;
		 }
		 else
			 largest = i;
		 if (right <= data.size() && data[right] > data[i])
			 largest = right;
		 if (largest != i)
		 {
			 std::swap(data[i], data[largest]);
			 Heapify(largest, smax);
		 }
	 }//The nits a min heap 
	 else
	 {
		 int left = Left(i);
		 int right = Right(i);
		 int min;
		 if (left <= data.size() && data[left] < data[i])
		 {
			 min = left;
		 }
		 else
			 min = i;
		 if (right <= data.size() && data[right] < data[i])
			 min = right;
		 if (largest != i)
		 {
			 std::swap(data[i], data[min]);
			 Heapify(min, smax);
		 }

	 }
 }




 
template<typename T>
template<std::size_t SIZE>
 constexpr Heap<T>::Heap(const std::array<T, SIZE>& array)
{
	 data(array.begin(), array.end());
	 MakeMaxHeap();
}
//Create a input iterator 
template<typename T>
template<typename InputIterator>
 constexpr Heap<T>::Heap(const InputIterator& start, const InputIterator& end)
{
	 for (auto it = start; it != end; it++)
	 {
		 data.push_back(*it);
	 }
	 MakeMaxHeap();
}
#endif