#ifndef FT_REVERSE_ITERATOR_HPP
# define FT_REVERSE_ITERATOR_HPP

#include <iostream>
#include <iterator>
#include "ft_iterator.hpp"

namespace ft {
	//  проверить - можно ли удалить ФТ внутри !!!
	template< class Iter >
	class reverse_iterator : public ft::iterator< typename ft::iterator_traits<Iter>::iterator_category,
									typename ft::iterator_traits<Iter>::value_type, typename ft::iterator_traits<Iter>::difference_type, 
									typename ft::iterator_traits<Iter>::pointer, typename ft::iterator_traits<Iter>::reference >{
		public:
				typedef Iter													iterator_type;
				typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
				typedef typename ft::iterator_traits<Iter>::value_type			value_type;
				typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
				typedef typename ft::iterator_traits<Iter>::pointer				pointer;
				typedef typename ft::iterator_traits<Iter>::reference			reference;

				reverse_iterator();
				explicit reverse_iterator (iterator_type it);

				template <class Iter>
				reverse_iterator (const reverse_iterator<Iter>& rev_it){};
				iterator_type base() const{};
				~reverse_iterator();

		protected:
				iterator_type													current;
	};

}

#endif