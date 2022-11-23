#pragma once

#include <memory>
#include <iostream>

namespace ft{
    template< class T, class Alloc = std::allocator<T> > 
    class vector{
        private:

        public:
                typedef T                                               value_type;
                typedef Alloc                                           allocator_type;
                typedef typename allocator_type::reference              reference;
                typedef typename allocator_type::const_reference        const_reference;
                typedef typename allocator_type::pointer                poiner;
                typedef typename allocator_type::const_pointer          const_poiner;
                typedef typename allocator_type::reference              iterator;
                typedef typename allocator_type::reference              reference;
                typedef typename allocator_type::reference              reference;


                
        // прописать все данные
public:
        default (1)	
        explicit vector (const allocator_type& alloc = allocator_type());
        fill (2)	
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
        range (3)	
        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
        copy (4)	
        vector (const vector& x);
        ~vector(){}

private:
        alloc	-	allocator to use for all memory allocations of this container
        count	-	the size of the container
        value	-	the value to initialize elements of the container with
        first, last	-	the range to copy the elements from
        other	-	another container to be used as source to initialize the elements of the container with
        init	-	initializer list to
        };
        
         
};