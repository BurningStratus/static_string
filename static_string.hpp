
#include <cstring>
#include <cstdint>

// minimalistic fixed-size string with read/write possiblities,
template <size_t max_length>
class static_string {
public:
    // copy buffer into a static one
    static_string (const char *buf) 
    {
        size_t data_length = strlen (buf);

        // if buffer holds more data than is allocated, just fill the buffer.
        if (data_length > max_length) {
            memcpy (data_, buf, max_length);
            size_ = max_length;
        } else {
            // just copy the whole thing, if it is shorter.
            memcpy (data_, buf, data_length);
            size_ = data_length;
        }

        data_ [size_] = '\0';
    }

    explicit static_string (const uint8_t *buf) 
    {
        // signed <-> unsigned conversions are dangerous in C,
        // and reinterpret_cast should do the trick.
        size_t data_length = strlen (reinterpret_cast<const char *> (buf));

        // if buffer holds more data than is allocated, just fill the buffer.
        if (data_length > max_length)
        {
            memcpy (data_, buf, max_length);
            size_ = max_length;
        } else {

            // just copy the whole thing, if it is shorter.
            memcpy (data_, buf, data_length);
            size_ = data_length;
        }

        data_ [size_] = '\0';
    }

    // zero-initialize
    static_string (void) : size_ (0), data_ ()
    {}

    template <size_t M>
    static_string(const static_string<M>& str) {
        // copy other characters
        // make sure M <= N
        size_t to_replace = str.size ();
        if (to_replace > max_length_)
            to_replace = max_length_;

        memcpy ((void *)data_, str.c_str (), to_replace);
        data_[to_replace] = '\0';
        size_ = to_replace ;
    }

    size_t capacity () const {
        return max_length; 
    }
    size_t length () const {
        return strlen (data_);
    }
    size_t size () const {
        return strlen (data_);
    }
    const char *c_str () const {
        return data_;
    }
    char *data () {
        return data_;
    }

    bool append (const char *buf, size_t len)
    {
        if (len + size_ > max_length_)
            return true;

        memcpy (data_, buf, len);
        size_ += len;
        data_[size_] = '\0'; // null - terminate
        return false;
    }

    template <size_t M>
    bool append(const char (&str)[M]) // append an 'array', WITH length info
    {
        return append(str, M - 1);
    }
    template <size_t M>
    bool append(const uint8_t (&str)[M]) // append an 'array', WITH length info
    {
        return append(reinterpret_cast<const char[M]>(str), M - 1);
    }

    bool append(char c)
    {
        return append(&c, 1);
    }
    bool append(uint8_t c)
    {
        return append( reinterpret_cast<uint8_t>(&c), 1 );
    }

    static_string& operator+= (const static_string& rhs)
    {
        char *dest = & (data_ [size_]); // acquire a pointer with offset

        // copy only what fits
        size_t to_copy = rhs.size ();
        if ((to_copy + this->size ()) > max_length)
            to_copy = max_length - to_copy;

        memcpy (dest, rhs.data (), to_copy);
        size_ += to_copy;
    }

    static_string& operator=( const static_string& str )
    {
        size_t to_replace = str.size ();
        if (to_replace > max_length_)
            to_replace = max_length_;

        memcpy ((void *)data_, str.c_str (), to_replace);
        size_ = to_replace;
        data_[size_] = '\0';
    }

    template <size_t N, size_t M> bool
    friend operator==
    (const static_string<N>& lhs, const static_string<M>& rhs);

    char& operator[] (size_t i) {
        return data_ [i];
    }
    const char& operator[] (size_t i) const {
        return data_ [i];
    }

    template <size_t N, size_t M> static_string <N + M>
    friend operator+ (const static_string<N>& lhs, const static_string<M>& rhs);

#if 0
    template <size_t N> static_string <N>
    friend operator+ (const static_string<N>& lhs, const uint8_t rhs);

    template <size_t N> static_string <N>
    friend operator+ (const static_string<N>& lhs, const char *rhs);

    template <size_t N> static_string <N>
    friend operator+ (const static_string<N>& lhs, char rhs);

    template <size_t N, size_t M> static_string <N + M>
    friend operator+ (const static_string<N>& lhs, const static_string<M>& rhs);

    template <size_t N> static_string <N>
    friend operator+ (const uint8_t *lhs, const static_string<N>& rhs);

    template <size_t N> static_string <N>
    friend operator+ (const static_string<N>& lhs, const uint8_t *rhs);

    template <size_t N> static_string <N>
    friend operator+ (const char *lhs, const static_string<N>& rhs);
#endif

private: 
    // allocated on a stack (!)
    char data_ [max_length + 1]; 
    size_t size_ = 0;
    size_t max_length_ = max_length;
};
