#ifndef FT_REVERSE_ITERATOR_HPP
# define FT_REVERSE_ITERATOR_HPP

#include <iostream>
#include <iterator>
#include "ft_iterator.hpp"

namespace ft {
	//  проверить - можно ли удалить ФТ внутри !!!
	template< class Iter >
	class reverse_iterator : public ft::iterator< typename ft::iterator_traits<Iter>::iterator_category,
									typename ft::iterator_traits<Iter>::value_type,
									typename ft::iterator_traits<Iter>::difference_type, 
									typename ft::iterator_traits<Iter>::pointer,
									typename ft::iterator_traits<Iter>::reference >{

		protected:
				iterator_type													current;

		public:
				typedef Iter													iterator_type;
				typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
				typedef typename ft::iterator_traits<Iter>::value_type			value_type;
				typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
				typedef typename ft::iterator_traits<Iter>::pointer				pointer;
				typedef typename ft::iterator_traits<Iter>::reference			reference;

			// конструкторы
				reverse_iterator(){}

				explicit reverse_iterator (iterator_type it) : current(it){}

				template <class Iter>
				// rev_it.current или так забрать!
				reverse_iterator (const reverse_iterator<Iter>& rev_it) : current(rev_it.base()){}
				
				template< class Iter > 
				reverse_iterator& operator=( const reverse_iterator<Iter>& other ){
					if (this == &other)
						return (*this);
					this->current = other.current;
					return (*this);
				}

				iterator_type base() const{
					return(current);
				}
			
			// операторы отношений
				reference operator*() const{
					Iter tmp = this->current;
    				return *--tmp;
				}

				// возврат адреса итератора
				pointer operator->() const{
					return (&(operator*()));
				}

				reference operator[]( difference_type n ) const{
					// return *(*this - n) - проверить !!; 
					return base()[-n - 1];
				}

				reverse_iterator& operator++()  {
					--this->current;
					return (*this);

				}

				reverse_iterator& operator--()  {
					++this->current;
					return (*this);
				}

				reverse_iterator operator++( int )  {
					reverse_iterator tmp = *this;
					--(*this);
					return tmp;
				}

				reverse_iterator operator--( int )  {
					reverse_iterator tmp = *this;
					++(*this);
					return tmp;
				}

				reverse_iterator operator+( difference_type n ) const  {
					// this->current =  this->current - n; return *this;
					return reverse_iterator(base() - n);	
				}

				reverse_iterator operator-( difference_type n ) const  {
					return reverse_iterator(base() + n);	
				}

				reverse_iterator& operator+=( difference_type n )  {
					this->current -= n;
					return *this;
				}

				reverse_iterator& operator-=( difference_type n )  {
					this->current += n;
					return *this;
				}

				// деструкторы
				~reverse_iterator(){}
		};
	// финито класс
	
//	non-member functions

//	operator ==
		template< class Iterator1, class Iterator2 >
		bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
						 const ft::reverse_iterator<Iterator2>& rhs ){
			return lhs.base() == rhs.base();
		}

//	operator !=
		template< class Iterator1, class Iterator2 >
		bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
		                 const ft::reverse_iterator<Iterator2>& rhs ){
			return lhs.base() != rhs.base();
		}

//	operator <
		template< class Iterator1, class Iterator2 >
		bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
		                const ft::reverse_iterator<Iterator2>& rhs ){
			return lhs.base() > rhs.base();
		}

//	operator <=
		template< class Iterator1, class Iterator2 >
		bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
		                 const ft::reverse_iterator<Iterator2>& rhs ){
			return lhs.base() >= rhs.base();
}

//	operator >
		template< class Iterator1, class Iterator2 >
		bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
		                const ft::reverse_iterator<Iterator2>& rhs ){
			return lhs.base() < rhs.base();
		}

//	operator >=
		template< class Iterator1, class Iterator2 >
		bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
		                 const ft::reverse_iterator<Iterator2>& rhs ){
			return lhs.base() <= rhs.base();
		}

//	operator +
		template <class Iterator>
		reverse_iterator<Iterator> operator+ ( typename reverse_iterator<Iterator>::difference_type n,
											const reverse_iterator<Iterator>& rev_it){
			return reverse_iterator<Iterator>(rev_it.base() - n);
		}

//	operator -
		template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator- ( const reverse_iterator<Iterator>& lhs,
																	const reverse_iterator<Iterator>& rhs){
			return lhs.base() - rhs.base();
		}

	}
	// финито нейм спейся)

#endif