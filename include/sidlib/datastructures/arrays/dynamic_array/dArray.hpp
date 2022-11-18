#ifndef SIDLIB_DYNAMIC_ARRAY
#define SIDLIB_DYNAMIC_ARRAY

#include <cstddef>
#include <iterator>
#include <stdexcept>
#include "format.hpp"

namespace sidlib 
{
    template <typename elem_t>
    struct darray
    {
    public:
        using value_type                = elem_t;
        using size_type                 = size_t;
        using difference_type           = std::ptrdiff_t;
        using pointer                   = value_type*;
        using const_pointer             = const value_type*;
        using reference                 = value_type&;
        using const_reference           = const value_type&;
        using iterator                  = pointer;
        using const_iterator            = const_pointer;
        using reverse_iterator          = std::reverse_iterator<pointer>;
        using const_reverse_iterator    = std::reverse_iterator<const_pointer>;        

        // iterators
        [[nodiscard]] constexpr auto begin() noexcept {
            return iterator{data()};
        }
        [[nodiscard]] constexpr auto begin() const noexcept {
            return const_iterator{data()};
        }
        [[nodiscard]] constexpr auto cbegin() const noexcept {
            return const_iterator{data()};
        }
        [[nodiscard]] constexpr auto rbegin() noexcept {
            return reverse_iterator{end()};
        }
        [[nodiscard]] constexpr auto rbegin() const noexcept {
            return const_reverse_iterator{end()};
        }
        [[nodiscard]] constexpr auto crbegin() const noexcept {
            return const_reverse_iterator{end()};
        }
        
        [[nodiscard]] constexpr auto end() noexcept {
            return iterator{data() + m_capacity};
        }
        [[nodiscard]] constexpr auto end() const noexcept {
            return const_iterator{data() + m_capacity};
        }
        [[nodiscard]] constexpr auto cend() const noexcept {
            return const_iterator{data() + m_capacity};
        }
        [[nodiscard]] constexpr auto rend() noexcept {
            return iterator{begin()};
        }
        [[nodiscard]] constexpr auto rend() const noexcept {
            return const_reverse_iterator{begin()};
        }
        [[nodiscard]] constexpr auto crend() const noexcept {
            return const_reverse_iterator{begin()};
        }

        // utility
        constexpr void push_back(const value_type& value) {
            
        }

        // constructor
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
        [[nodiscard]] constexpr pointer data() noexcept {
            return m_data;
        }
        [[nodiscard]] constexpr const_pointer data() const noexcept {
            return m_data;
        }

        constexpr void out_of_range_check(size_type index) const {
            if (index >= elem_s) {
                throw std::out_of_range(sidlib::format(
                    "\nRANGE ERROR: [sidlib::darray]\n\t     "
                    "Attempt to access index [{}] when max size is [{}]\n", index, elem_s));
            }
        }

        constexpr void realloc(size_type new_capacity) {
            // 1. allocate a new block of memory
            // 2. copy/move elemnts from old to new
            // 3. delete old block

            value_type* new_block = new value_type[new_capacity];

            if (new_capacity < m_size) {
                m_size = new_capacity;
            }

            for (size_type i = 0; i < m_size; i++) {
                new_block[i] = m_data[i];
            }

            delete[] m_data;
            m_data = new_block;
            m_capacity = new_capacity;
        }

    private:
        pointer m_data = new value_type[];
        size_type m_size = 0;
        size_type m_capacity = 0;
    };
}

#endif