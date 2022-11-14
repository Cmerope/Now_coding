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
			// деструкторы
				~reverse_iterator(){}
				
			// 
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

				reference operator*() const{
					Iter tmp = this->current;
    				return *--tmp;
				}

				// возврат адреса итератора
				pointer operator->() const{
					return (&(operator*()));
				}
				
	};

}

#endif