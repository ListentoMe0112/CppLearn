template<class Arg, class Result>
struct unary_function{
    typedef Arg argument_type;
    typedef Result result_type;
};


template<class Arg1, class Arg2, class Result>
struct binary_function{
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result result_type;
};

/*
    STL规定每个Adaptable Function 都应该挑选适当者继承之，因为Function Adapter将会提问红色问题。
*/

template <class T>
struct less : public binary_function<T, T, bool>{
    bool operator() (const T& x, const T& y) const{
        return x < y;
    }
};