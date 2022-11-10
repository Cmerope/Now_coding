#ifndef FT_ITERATOR_HPP
# define FT_ITERATOR_HPP

#include <iostream>
#include <iterator>

namespace ft {

	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	// шаблон структуры iterator
	template< class Category, class T,
	            class Distance = std::ptrdiff_t,
	            class Pointer = T*,
	            class Reference = T& > 
	struct iterator{
	            //  переопределение названия данных - typedef Category iterator<Category, T, Distance, Pointer, Reference>::iterator_category
	            // iterator category tags
	            typedef Category    iterator_category;
	            // тип итератора
	            typedef T           value_type;
	            // тип определения дистанции между итераторами
	            typedef Distance    difference_type;
	            //указатель и ссылка на элемент куда указывает указатель
	            typedef Pointer     pointer;	
	            typedef Reference   reference;
	};
	// шаблон структуры iterator_traits со специализациями
	template< class Iter >
	struct iterator_traits{
		        typedef typename Iter::difference_type      difference_type;
		        typedef typename Iter::value_type           value_type;
		        typedef typename Iter::pointer              pointer;
		        typedef typename Iter::reference            reference;
		        typedef typename Iter::iterator_category    iterator_category;
	
	};

	
	template< class T >
	struct iterator_traits<T*>{
	    	    typedef typename std::ptrdiff_t            difference_type;
		        typedef T                                  value_type;
		        typedef T*                                 pointer;
		        typedef T&                                 reference;
		        typedef random_access_iterator_tag		iterator_category;
	};
	
	template< class T >
	struct iterator_traits<const T*>{
	    	    typedef typename std::ptrdiff_t             difference_type;
		        typedef T                                 	value_type;
		        typedef const T*                            pointer;
		        typedef const T&							reference;
		        typedef random_access_iterator_tag			iterator_category;
	};
	

	template<bool B, class T, class F>
	struct conditional { 
		typedef T type; 
		};
 
	template<class T, class F>
	struct conditional<false, T, F> { 
		typedef F type;  };

	
	template<bool B, class T = void>
	struct enable_if {};
 
	template<class T>
	struct enable_if<true, T> { 
		typedef T type; 
		};

	
	template <typename T>
	struct is_integral {
		static const bool value = false;
	};

	template <>
	struct is_integral <char> {
		static const bool value = true;
	};

	template <>
	struct is_integral <unsigned short int> {
		static const bool value = true;
	};

	template <>
	struct is_integral <wchar_t> {
		static const bool value = true;
	};

	template <>
	struct is_integral <signed char> {
		static const bool value = true;
	};

	template <>
	struct is_integral <short int> {
		static const bool value = true;
	};

	template <>
	struct is_integral <int> {
		static const bool value = true;
	};

	template <>
	struct is_integral <long int> {
		static const bool value = true;
	};

	template <>
	struct is_integral <long long int> {
		static const bool value = true;
	};

	template <>
	struct is_integral <unsigned char> {
		static const bool value = true;
	};

	template <>
	struct is_integral <unsigned int> {
		static const bool value = true;
	};

	template <>
	struct is_integral <unsigned long int> {
		static const bool value = true;
	};

	template <>
	struct is_integral <unsigned long long int> {
		static const bool value = true;
	};
}


#endif