#ifndef SIDLIB_STATIC_ARRAY
#define SIDLIB_STATIC_ARRAY

namespace sidlib {
    template<typename T, unsigned int S>
    struct array
    {
    public:
        constexpr unsigned int Size() const {return S;}
        
        T& operator[](unsigned int Index) {return m_Data[Index];}
        T* Data() {return m_Data;}

        const T& operator[](unsigned int Index) const {return m_Data[Index];}
        const T* Data() const {return m_Data;}
    private:
        T*              m_Iterator;
        T               m_Data[S];
    };
}

#endif