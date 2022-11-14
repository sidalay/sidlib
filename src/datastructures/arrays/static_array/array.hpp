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
        using difference_type         = std::ptrdiff_t;
        using reference               = value_type&;
        using const_reference         = const value_type&;
        using iterator                = value_type*;
        using const_iterator          = const value_type*;
        using reverse_iterator        = std::reverse_iterator<value_type*>;
        using const_reverse_iterator  = std::reverse_iterator<const value_type*>;
        
        T& operator[](size_t index) {
            return m_data[index];
        }
        const T& operator[](size_t index) const {
            return m_data[index];
        }
        
        T* data() {
            return m_data;
        }
        const T* data() const {
            return m_data;
        }

        constexpr size_t max_size() const {
            return S;
        }
        // front
        // back
        // empty
        // size
        // fill
        // swap
    private:
        T  m_data[S];
    };
}

#endif