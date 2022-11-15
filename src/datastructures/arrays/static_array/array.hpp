#ifndef SIDLIB_STATIC_ARRAY
#define SIDLIB_STATIC_ARRAY

#include <iterator>
#include <cstddef>
#include <stdexcept>

namespace sidlib 
{
    template<typename elem_t, size_t elem_s>
    struct array
    {
    public:
        using value_type              = elem_t;
        using size_type               = size_t;
        using difference_type         = std::ptrdiff_t;
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
            return iterator{data() + elem_s};
        }
        constexpr auto end() const {
            return const_iterator{data() + elem_s};
        }
        constexpr auto cend() const {
            return const_iterator{data() + elem_s};
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
            return m_data[index];
        }
        constexpr const_reference operator[](size_type index) const {
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

        constexpr size_type size() const {
            return elem_s;
        }
        constexpr size_type max_size() const {             
            return elem_s;
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
            if (index >= elem_s) {
                throw std::out_of_range("RANGE ERROR: [sidlib::array] attempt to access index outside of range");
            }
        }
        
    private:
        value_type  m_data[elem_s];
    };
}

#endif