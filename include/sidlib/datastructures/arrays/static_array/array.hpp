#ifndef SIDLIB_STATIC_ARRAY_HPP
#define SIDLIB_STATIC_ARRAY_HPP

#include <cstddef>
#include <iterator>
#include <stdexcept>
#include "format.hpp"

namespace sidlib 
{
    template<typename elem_t, size_t elem_s>
    struct array
    {
    public:
        using value_type              = elem_t;
        using size_type               = size_t;
        using difference_type         = ptrdiff_t;
        using pointer                 = value_type*;
        using const_pointer           = const value_type*;
        using reference               = value_type&;
        using const_reference         = const value_type&;
        using iterator                = pointer;
        using const_iterator          = const_pointer;
        using reverse_iterator        = std::reverse_iterator<pointer>;
        using const_reverse_iterator  = std::reverse_iterator<const_pointer>;

        [[nodiscard]] constexpr pointer data() noexcept {
            return m_data;
        }
        [[nodiscard]] constexpr const_pointer data() const noexcept {
            return m_data;
        }

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
            return iterator{data() + elem_s};
        }
        [[nodiscard]] constexpr auto end() const noexcept {
            return const_iterator{data() + elem_s};
        }
        [[nodiscard]] constexpr auto cend() const noexcept {
            return const_iterator{data() + elem_s};
        }
        [[nodiscard]] constexpr auto rend() noexcept {
            return reverse_iterator{begin()};
        }
        [[nodiscard]] constexpr auto rend() const noexcept {
            return const_reverse_iterator{begin()};
        }
        [[nodiscard]] constexpr auto crend() const noexcept {
            return const_reverse_iterator{begin()};
        }
        
        // access
        [[nodiscard]] constexpr reference operator[](size_type index) noexcept {
            return m_data[index];
        }
        [[nodiscard]] constexpr const_reference operator[](size_type index) const noexcept {
            return m_data[index];
        }
        [[nodiscard]] constexpr reference at(size_type index) {
            out_of_range_check(index);
            return m_data[index];
        }
        [[nodiscard]] constexpr const_reference at(size_type index) const {
            out_of_range_check(index);
            return m_data[index];
        }
        [[nodiscard]] constexpr reference front() noexcept {
            return *begin();
        }
        [[nodiscard]] constexpr const_reference front() const noexcept {
            return *begin();
        }
        [[nodiscard]] constexpr reference back() noexcept {
            return *(end() - 1);
        }
        [[nodiscard]] constexpr const_reference back() const noexcept {
            return *(end() - 1);
        }

        // capacity
        [[nodiscard]] constexpr size_type size() const noexcept {
            return elem_s;
        }
        [[nodiscard]] constexpr size_type max_size() const noexcept {             
            return elem_s;
        }
        [[nodiscard]] constexpr bool empty() const noexcept {
            return size() == 0;
        }

        // utility
        constexpr void insert(size_type index, value_type value) {
            out_of_range_check(index);
            m_data[index] = value;
        }
        constexpr void fill(value_type value) noexcept {
            for (auto it = begin(); it != end(); ++it) {
                *it = value;
            }
        }
        constexpr void swap(array& other) noexcept {
            array<value_type, elem_s> temp;
            for (size_type i = 0; i < size(); ++i) {
                temp[i] = other[i];
                other[i] = m_data[i];
                m_data[i] = temp[i];
            }
        }

        // constructors
        array() {
            fill(0);
        }
    
    private:
        constexpr void out_of_range_check(size_type index) const {
            if (index >= elem_s) {
                throw std::out_of_range(sidlib::format(
                    "\nRANGE ERROR: [sidlib::array]\n\t     "
                    "Attempt to access index [{}] when max index is [{}]\n", index, elem_s - 1));
            }
        }

    private:
        value_type m_data[elem_s];
        
    };
}

#endif // SIDLIB_STATIC_ARRAY_HPP