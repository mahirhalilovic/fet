#include <iostream>

namespace my {

    template<typename T>
    void swap(T &first, T &second) {

        T temp = first;
        first = second;
        second = temp;
    }

    template<typename T>
    void sort(T begin, T end, bool condition = false) {

        auto i = begin;
        auto j = begin;
        auto n = end;

        for(; begin != end - 1; i++)
            for(; j != end - i - 1; begin++)
                if(condition)
                    swap(*j, *(j + 1));
    }
}