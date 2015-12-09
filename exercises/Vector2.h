// ---------
// Vector2.h
// ---------

#ifndef Vector2_h
#define Vector2_h

#include <algorithm> // copy, fill
#include <cstddef>   // ptrdiff_t, size_t
#include <utility>   // swap

template <typename T>
class my_vector {
    friend bool operator == (const my_vector& lhs, const my_vector& rhs) {
        return (lhs.size() == rhs.size()) && std::equal(lhs.begin(), lhs.end(), rhs.begin());}

    public:
        using value_type      = T;

        using size_type       = std::size_t;
        using difference_type = std::ptrdiff_t;

        using       pointer   =       value_type*;
        using const_pointer   = const value_type*;

        using       reference =       value_type&;
        using const_reference = const value_type&;

        using       iterator  =       pointer;
        using const_iterator  = const_pointer;

    private:
        pointer _b;
        pointer _e;

    public:
        explicit my_vector (size_type s = 0, const_reference v = T()) :
                _b (s == 0 ? nullptr : new T[s]),
                _e (_b + s) {
            std::fill(_b, _e, v);}

        my_vector (const my_vector& rhs) :
                _b (rhs.size() == 0 ? nullptr : new T[rhs.size()]),
                _e (rhs.size() == 0 ? nullptr : _b + rhs.size()) {
            std::copy(rhs._b, rhs._e, _b);}

        my_vector& operator = (const my_vector& rhs) {
            my_vector that(rhs);
            std::swap(_b, that._b);
            std::swap(_e, that._e);
            return *this;}

        ~my_vector () {
            delete [] begin();}

        reference operator [] (size_type i) {
            return begin()[i];}

        const_reference operator [] (size_type i) const {
            return (*const_cast<my_vector<T>*>(this))[i];}

        iterator begin () {
            return _b;}

        const_iterator begin () const {
            return const_cast<my_vector<T>*>(this)->begin();}

        iterator end () {
            return _e;}

        const_iterator end () const {
            return const_cast<my_vector<T>*>(this)->end();}

        size_type size () const {
            return (begin() == nullptr) ? 0 : end() - begin();}};

#endif // Vector2_h
