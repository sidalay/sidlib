#ifndef SIDLIB_STATIC_ARRAY
#define SIDLIB_STATIC_ARRAY

#include <iterator>
#include <cstddef>

namespace sidlib 
{
    template<typename T, size_t S>
    struct array
    {
    public:
        using value_type              = T;
        using size_type               = size_t;
        // using difference_type         = std::ptrdiff_t;
        using pointer                 = value_type*;
        using const_pointer           = const value_type*;
        using reference               = value_type&;
        using const_reference         = const value_type&;
        using iterator                = pointer;
        using const_iterator          = const_pointer;
        using reverse_iterator        = std::reverse_iterator<pointer>;
        using const_reverse_iterator  = std::reverse_iterator<const_pointer>;

        constexpr auto begin() {
            return iterator{m_data};
        }
        constexpr auto begin() const {
            return const_iterator{m_data};
        }

        constexpr auto end() {
            return iterator{m_data + S};
        }
        constexpr auto end() const {
            return const_iterator{m_data + S};
        }
        
        // access
        constexpr reference operator[](size_type index) {
            return m_data[index];
        }
        constexpr const_reference operator[](size_type index) const {
            return m_data[index];
        }

        constexpr reference at(size_type index) {
            return m_data[index];
        }
        constexpr const_reference at(size_type index) const {
            return m_data[index];
        }

        constexpr reference front() {
            return *m_data;
        }
        constexpr const_reference front() const {
            return *m_data;
        }

        constexpr reference back() {
            return m_data[S - 1];
        }
        constexpr const_reference back() const {
            return m_data[S - 1];
        }
        
        constexpr pointer data() {
            return m_data;
        }
        constexpr const_pointer data() const {
            return m_data;
        }

        // how many elements are currently held
        constexpr size_type size() const { // TODO   
            size_type count;             
            return count;
        }
        // how many elements can be held
        constexpr size_type max_size() const {             
            return S;
        }

        // empty
        // fill
        // swap
    private:
        T  m_data[S];
    };
}

#endif