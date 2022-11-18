#ifndef SIDLIB_DYNAMIC_ARRAY
#define SIDLIB_DYNAMIC_ARRAY

#include <cstddef>
#include <iterator>
#include <stdexcept>

namespace sidlib 
{
    template <typename elem_t>
    struct darray
    {
    public:
        using value_type                = elem_t;
        using size_type                 = size_t;
        using difference_type           = std::ptrdiff_t;
        using pointer                   = value_type*
        using const_pointer             = const value_type*
        using reference                 = value_type&;
        using const_reference           = const value_type&;
        using iterator                  = pointer;
        using const_iterator            = const_pointer;
        using reverse_iterator          = std::reverse_iterator<pointer>;
        using const_reverse_iterator    = std::reverse_iterator<const_pointer>;        

        darray() {
            // allocate 2 elements
            realloc(2);
        }
        // size
        // max_size
        // reserve
        // resize
        // shrink_to_fit
        
        // at
        // front
        // back
        // data
        
        // assign & operator=
        // clear
        // erase
        // remove
        // push_back
        // pop_back
        // insert
    private:   
        void realloc(size_type new_capacity) {
            // 1. allocate a new block of memory
            // 2. copy/move elemnts from old to new
            // 3. delete old block

            value_type* new_block = new value_type[new_capacity];
            
        }

    private:
        value_type* m_data = new value_type[];
        size_type m_size = 0;
        size_type m_capacity = 0;
    };
}

#endif