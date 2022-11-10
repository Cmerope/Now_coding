#ifndef FT_COND_HPP
# define FT_COND_HPP

#include <iostream>
#include <iterator>

namespace ft {
	template<bool B, class T, class F>
	struct conditional { 
		typedef T type; 
		};
 
	template<class T, class F>
	struct conditional<false, T, F> { 
		typedef F type;  };

// enable_if
	template<bool B, class T = void>
	struct enable_if {};
 
	template<class T>
	struct enable_if<true, T> { 
		typedef T type; 
		};

// is_inegral  bool  !char / !wchar_t / !signed char /
// !short int / !int / !long int/! long long int/ ! unsigned char/ !unsigned short int/ 
//! unsigned int/ !unsigned long int/ !unsigned long long int

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