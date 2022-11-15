#ifndef SIDLIB_STATIC_ARRAY
#define SIDLIB_STATIC_ARRAY

#include <iterator>
#include <cstddef>
#include <stdexcept>

namespace sidlib 
{
    template<typename T, size_t S>
    struct array
    {
    public:
        using value_type              = T;
        using size_type               = size_t;
        // using difference_type         = std::ptrdiff_t;      // searching to see what this is used for
        using pointer                 = value_type*;
        using const_pointer           = const value_type*;
        using reference               = value_type&;
        using const_reference         = const value_type&;
        using iterator                = pointer;
        using const_iterator          = const_pointer;
        using reverse_iterator        = std::reverse_iterator<pointer>;
        using const_reverse_iterator  = std::reverse_iterator<const_pointer>;

        constexpr auto begin() {
            return iterator{data()};
        }
        constexpr auto begin() const {
            return const_iterator{data()};
        }
        constexpr auto cbegin() const {
            return const_iterator{data()};
        }
        constexpr auto rbegin() {
            return reverse_iterator{end()};
        }
        constexpr auto rbegin() const {
            return const_reverse_iterator{end()};
        }
        constexpr auto crbegin() const {
            return const_reverse_iterator{end()};
        }

        constexpr auto end() {
            return iterator{data() + S};
        }
        constexpr auto end() const {
            return const_iterator{data() + S};
        }
        constexpr auto cend() const {
            return const_iterator{data() + S};
        }
        constexpr auto rend() {
            return reverse_iterator{begin()};
        }
        constexpr auto rend() const {
            return const_reverse_iterator{begin()};
        }
        constexpr auto crend() const {
            return const_reverse_iterator{begin()};
        }
        
        // access
        constexpr reference front() {
            return *begin();
        }
        constexpr const_reference front() const {
            return *begin();
        }

        constexpr reference back() {
            return *(end() - 1);
        }
        constexpr const_reference back() const {
            return *(end() - 1);
        }

        constexpr reference operator[](size_type index) {
            out_of_range_check(index);
            return m_data[index];
        }
        constexpr const_reference operator[](size_type index) const {
            out_of_range_check(index);
            return m_data[index];
        }

        constexpr reference at(size_type index) {
            out_of_range_check(index);
            return m_data[index];
        }
        constexpr const_reference at(size_type index) const {
            out_of_range_check(index);
            return m_data[index];
        }
        
        constexpr pointer data() {
            return m_data;
        }
        constexpr const_pointer data() const {
            return m_data;
        }

        // how many elements are currently held
        constexpr size_type size() const { // THIS IMPLEMENTATION IS NOT DONE YET  
            size_type count;
            for (auto it = begin(); it != end(); ++it) {
                if (it) {
                    ++count;
                }
            }             
            return count;
        }
        // how many elements can be held
        constexpr size_type max_size() const {             
            return S;
        }

        constexpr void fill(value_type value) {
            for (auto it = begin(); it != end(); ++it) {
                *it = value;
            }
        }
        // constexpr void swap(array<value_type, size_type>& other_data) {

        // }
        constexpr bool empty() const {
            if (size() == 0) {
                return true;
            }
            return false;
        }

        constexpr void out_of_range_check(size_type index) const {
            if (index >= S) {
                std::__throw_out_of_range_fmt("[sidlib::array] attempt to access index outside of range");
            }
        }
        
    private:
        T  m_data[S];
    };
}

#endif