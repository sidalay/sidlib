#ifndef SIDLIB_DYNAMIC_ARRAY_HPP
#define SIDLIB_DYNAMIC_ARRAY_HPP

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
        using difference_type           = ptrdiff_t;
        using pointer                   = value_type*;
        using const_pointer             = const value_type*;
        using reference                 = value_type&;
        using const_reference           = const value_type&;
        using iterator                  = pointer;
        using const_iterator            = const_pointer;
        using reverse_iterator          = std::reverse_iterator<pointer>;
        using const_reverse_iterator    = std::reverse_iterator<const_pointer>;        

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
            return iterator{data() + m_size};
        }
        [[nodiscard]] constexpr auto end() const noexcept {
            return const_iterator{data() + m_size};
        }
        [[nodiscard]] constexpr auto cend() const noexcept {
            return const_iterator{data() + m_size};
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
            return m_size;
        }
        [[nodiscard]] constexpr size_type capacity() const noexcept {
            return m_capacity;
        }
        [[nodiscard]] constexpr bool empty() const noexcept {
            return size() == 0;
        }

        // utility
        constexpr void push_back(const value_type& value) {
            if (m_size >= m_capacity) {
                realloc(m_capacity + (m_capacity/2));
            }
            new(&m_data[m_size++]) value_type(std::move(value));
        }
        constexpr void push_back(value_type&& value) {
            if (m_size >= m_capacity) {
                realloc(m_capacity + (m_capacity/2));
            }
            new(&m_data[m_size++]) value_type(std::move(value));
        }
        constexpr void pop_back() {
            if (m_size > 0) {
                m_data[--m_size].~value_type();
            }
        }

        template<typename... args>
        constexpr value_type& emplace_back(args&&... arg) {
            if (m_size >= m_capacity) {
                realloc(m_capacity + (m_capacity/2));
            }
            return m_data[m_size++] = value_type(std::forward<args>(arg)...);
        }

        constexpr void clear() {
            for (size_type i = 0; i < m_size; ++i) {
                m_data[i].~value_type();
            }
            m_size = 0;
        }

        // constructor
        darray() {
            realloc(2);
        }
        ~darray() {
            clear();
            ::operator delete(m_data, m_capacity * sizeof(value_type));
        }

        // reserve
        // shrink
        
        // erase
        // remove
        // insert
    private:   
        constexpr void out_of_range_check(size_type index) const {
            if (index >= m_size) {
                throw std::out_of_range(sidlib::format(
                    "\nRANGE ERROR: [sidlib::darray]\n\t     "
                    "Attempt to access index [{}] when number of elements is [{}]\n", index, m_size));
            }
        }

        constexpr void realloc(size_type new_capacity) {
            value_type* new_block = (pointer)::operator new(new_capacity * sizeof(value_type));

            if (new_capacity < m_size) {
                m_size = new_capacity;
            }

            for (size_type i = 0; i < m_size; ++i) {
                new(&new_block[i]) value_type(std::move(m_data[i]));
            }

            for (size_type i = 0; i < m_size; ++i) {
                m_data[i].~value_type();
            }

            ::operator delete(m_data, m_capacity * sizeof(value_type));
            m_data = new_block;
            m_capacity = new_capacity;
        }

    private:
        pointer m_data{nullptr};
        size_type m_size{0};
        size_type m_capacity{0};
    };
}

#endif // SIDLIB_DYNAMIC_ARRAY_HPP