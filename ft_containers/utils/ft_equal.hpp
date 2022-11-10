#ifndef EQUAL_HPP
# define EQUAL_HPP

#include <iostream>
#include <iterator>

namespace ft {
	// если обе последовательности равны в рамках выбранного диапозона (если 2я последовательность больше 1й - это игнориурется)
	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2){
		while (first1 != last1) {
    		if (!(*first1 == *first2)) 
      			return false;
   			 ++first1; ++first2;
  		}
	return true;
	}


	// class BinaryPredicate - двоичная функция, принимает 2 значения и возвращает тип бул если они равны в рамках контекста данной функции
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred){
		while (first1 != last1) {
    		if (!(pred(*first1,*first2)))
      			return false;
   			 ++first1; ++first2;
  		}
	return true;
	}
// Сравнение продолжается, пока не будет найдена первая пара различных элементов, не достигнута пара [last1,last2]
//  или хотя бы один из элементов last1 или last2 (если последовательности имеют разные длины). При обнаружении первой пары различных элементов алгоритм возвращает:
// если меньше элемент первой последовательности, то true, иначе false;
// если last1 достигнут, а last2 нет, то true; ++ 
// если last2 достигнут, а last1 нет, то false;++
// если достигнуты и last1, и last2 (т.е. все элементы одинаковы), то false.++

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2){
		for (; first1 != last1; ++first1, ++first2) {
			if (*first1 < *first2)
				return (true);
			else if ((*first2 < *first1) || (first2 == last2))
				return (false);
			}
			return (first2 != last2);
	}
	
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp){
		for (; first1 != last1; ++first1, ++first2) {
			if (comp(*first1, *first2))
				return (true);
			else if (comp(*first2, *first1) || (first2 == last2))
				return (false);
			}
		return (first2 != last2);	
	}
}


#endif