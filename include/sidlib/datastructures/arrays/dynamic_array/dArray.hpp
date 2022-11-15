#ifndef SIDLIB_DYNAMIC_ARRAY
#define SIDLIB_DYNAMIC_ARRAY

namespace sidlib 
{
    template <typename T>
    struct dArray
    {
    public:
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
        T m_Data = new T[]; 
    };
}

#endif