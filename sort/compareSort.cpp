#include <cstdlib>
#include <utility>
#include <ctime>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <cstdint>

template<class Iter> void insert_sort(Iter begin, Iter end) {
    for (Iter cur = begin; cur != end; ++cur) {
        Iter p = cur;
        while (begin <= --p && *cur < *p);
        ++p;
        if (p != cur) {
            typename std::iterator_traits<Iter>::value_type v = *cur;
            Iter next_cur = cur;
            ++next_cur;
            std::copy_backward(p, cur, next_cur);
            *p = v;
        }
    }
}

template<class Iter> void insert_sort_no_copy(Iter begin, Iter end) {
    for (Iter cur = begin; cur != end; ++cur) {
        Iter p = cur;
        while (begin <= --p && *cur < *p); 
        ++p;
        typename std::iterator_traits<Iter>::value_type v = *cur;
        Iter next_p = p;
        ++next_p;
    }
}

template<class Iter> void binary_insert_sort(Iter begin, Iter end) {
    for (Iter cur = begin; cur != end; ++cur) {
        Iter p = std::upper_bound(begin, cur, *cur);
        if (p != cur) {
            typename std::iterator_traits<Iter>::value_type v = *cur;
            Iter next_cur = cur;
            ++next_cur;
            std::copy_backward(p, cur, next_cur);
            *p = v;
        }
    }
}

template<class Iter> void select_sort(Iter begin, Iter end) {
  for (Iter cur = begin; cur != end; ++cur) {
      Iter  minp = cur;
      for (Iter p = cur; p < end; ++p) {
          if (*p < *minp) {
              minp = p;
          }
      }
      std::swap(*minp, *cur);
  }
}

// from https://kjellkod.wordpress.com/2012/02/06/exploring-c11-part-1-time/
class StopWatch
{
public:
    typedef std::chrono::high_resolution_clock clock;
    typedef std::chrono::microseconds microseconds;
    typedef std::chrono::milliseconds milliseconds;

private:
    clock::time_point start_;
public:
    StopWatch() : start_(clock::now()){}
    clock::time_point restart() { start_ = clock::now(); return start_;}
    microseconds elapsedUs()    { return intervalUs(clock::now(), start_);}
    milliseconds elapsedMs()    { return intervalMs(clock::now(), start_);}
private:
    microseconds intervalUs(const clock::time_point& t1, const clock::time_point& t0)
    {
        return std::chrono::duration_cast<microseconds>(t1 - t0);
    }

    milliseconds intervalMs(const clock::time_point& t1,const clock::time_point& t0)
    {
        return std::chrono::duration_cast<milliseconds>(t1 - t0);
    }
};

struct LargeStruct {
    static const int ELEMENT_COUNT = 100;
    int v[ELEMENT_COUNT];
    LargeStruct() {
        v[0] = 0;
    }
    LargeStruct(int n) {
        v[0] = n;
    }
    LargeStruct& operator=(int n) {
        v[0] = n;
        return *this;
    }
};

std::ostream& operator<<(std::ostream& out, const LargeStruct& t) {
    out << t.v[0];
    return out;
}

bool operator<(const LargeStruct& lhs, const LargeStruct& rhs) {
    return lhs.v[0] < rhs.v[0];
}

struct LargeStructSlowAssign {
    static const int ELEMENT_COUNT = 100;

    int v[ELEMENT_COUNT];
    LargeStructSlowAssign() {
        v[0] = 0;
    }
    LargeStructSlowAssign(int n) {
        v[0] = n;
    }
    LargeStructSlowAssign& operator=(int n) {
        v[0] = n;
        return *this;
    }
    LargeStructSlowAssign& operator=(const LargeStructSlowAssign& rhs) {
        for (int j = 0; j < ELEMENT_COUNT; ++j) {
            v[j] = rhs.v[j];
        }
        return *this;
    }
};

std::ostream& operator<<(std::ostream& out, const LargeStructSlowAssign& t) {
    out << t.v[0];
    return out;
}

bool operator<(const LargeStructSlowAssign& lhs, const LargeStructSlowAssign& rhs) {
    return lhs.v[0] < rhs.v[0];
}

void dump(int ms, const char* sort_method, const char* tname, int count) {
    std::cout << sort_method << "\t" << tname << "\t" << ms << "\t" << count << std::endl;
}
template<class T>
void sort_compare(const char* tname, const std::vector<int> &raw_data) {
    StopWatch sw;
    std::vector<T> to_sort;

    to_sort.assign(raw_data.begin(), raw_data.end());
    sw.restart();
    insert_sort(std::begin(to_sort), std::end(to_sort));
    dump(sw.elapsedMs().count(), "insert_sort", tname, to_sort.size());


    to_sort.assign(raw_data.begin(), raw_data.end());
    sw.restart();
    binary_insert_sort(std::begin(to_sort), std::end(to_sort));
    dump(sw.elapsedMs().count(), "binary_insert_sort", tname, to_sort.size());

    to_sort.assign(raw_data.begin(), raw_data.end());
    sw.restart();
    select_sort(std::begin(to_sort), std::end(to_sort));
    dump(sw.elapsedMs().count(), "select_sort", tname, to_sort.size());

    to_sort.assign(raw_data.begin(), raw_data.end());
    sw.restart();
    std::sort(std::begin(to_sort), std::end(to_sort));
    dump(sw.elapsedMs().count(), "std::sort", tname, to_sort.size());
}

int main() {
#define COMPARE(x, y) sort_compare<x>(#x, y)
    srand(time(NULL));
    for (int n = 10000; n <= 30000; n += 10000) {
        std::vector<int> raw_data(n);
        for (int i = 0; i < n; ++i) {
            raw_data[i] = rand();
        }
        COMPARE(int, raw_data);
        COMPARE(LargeStruct, raw_data);
        COMPARE(LargeStructSlowAssign, raw_data);
    }
    return 0;
}