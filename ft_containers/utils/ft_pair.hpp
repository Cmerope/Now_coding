#ifndef PAIR_HPP
# define PAIR_HPP

#include <iostream>
#include <iterator>

namespace ft {
// std::pair
	template< class T1, class T2 > 
	struct pair{
		typedef  T1 first_type;
		typedef  T2 second_type;

		first_type  first;
		second_type second;

		pair() : first(T1()), second(T2()) {}
		// copy (2)	
		template<class U, class V> 
		pair (const pair  <U, V>& pr) : first(pr.first), second(pr.second){}
		// initialization (3)	
		pair (const first_type& a, const second_type& b) : first(a), second(b){}
		~pair()

		pair& operator= (const pair& pr){
			if (this == &pr)
				return (*this);
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
			}
	};
	
	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y){
		return ( pair<T1,T2>(x,y) );
  		}

	template< class T1, class T2 >
	bool operator == ( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs ){
		return (lhs.first == rhs.first) && (lhs.second == rhs.second)
		}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return !(lhs==rhs); 
		}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); 
		}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return !(rhs<lhs);
		}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return rhs<lhs;
		}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return !(lhs<rhs);
		}
}

#endif