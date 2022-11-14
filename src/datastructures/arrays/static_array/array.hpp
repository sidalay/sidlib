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
        using reference               = value_type&;
        using const_reference         = const value_type&;
        using iterator                = value_type*;
        using const_iterator          = const value_type*;
        using reverse_iterator        = std::reverse_iterator<value_type*>;
        using const_reverse_iterator  = std::reverse_iterator<const value_type*>;

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
    
        T& operator[](size_type index) {
            return m_data[index];
        }
        const T& operator[](size_type index) const {
            return m_data[index];
        }

        T& at(size_type index) {
            return m_data[index];
        }
        const T& at(size_type index) const {
            return m_data[index];
        }
        
        T* data() {
            return m_data;
        }
        const T* data() const {
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

        // front
        // back
        // empty
        // fill
        // swap
    private:
        T  m_data[S];
    };
}

#endif