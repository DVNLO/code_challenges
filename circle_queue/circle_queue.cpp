#include <cstddef>
#include <cassert>

template<typename T, std::size_t N>
class circle_queue
{
    T vals[N];
    T * head;
    T * tail;
    T * const BEGIN;
    T const * const END;

public:
    circle_queue();
    
    inline bool empty() const;
    inline size_t size() const;
    inline bool full() const;
    bool push(T const val);
    void pop();
    T front() const;
    
    ~circle_queue() = default;
};

template<typename T, std::size_t N>
circle_queue<T, N>::circle_queue() 
    : BEGIN{ vals }, END{ vals + N }
{
    head = nullptr;
    tail = nullptr;
}

template<typename T, std::size_t N>
bool circle_queue<T, N>::empty() const
{
    return head == nullptr 
            && tail == nullptr;
}

template<typename T, std::size_t N>
bool circle_queue<T, N>::full() const
{
    return !empty() 
        && head == tail;
}

template<typename T, std::size_t N>
std::size_t circle_queue<T, N>::size() const
{
    if(empty())
        return static_cast<std::size_t>(0);
    else if(head < tail)
        return static_cast<std::size_t>(tail - head);
    else if(head > tail)
        return N - static_cast<std::size_t>(head - tail);
    else    // !empty() && head == tail -> full() 
        return N;
}

template<typename T, size_t N>
bool circle_queue<T, N>::push(T const val)
{
    if(full())
        return false;
    if(empty())
    {
        head = BEGIN;
        tail = BEGIN;
    }
    *tail = val;
    ++tail;
    if(tail >= END)
        tail = BEGIN;
    return true;
}

template<typename T, std::size_t N>
void circle_queue<T, N>::pop()
{
    ++head;
    if(head >= END)
        head = BEGIN;
    if(head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
}

template<typename T, std::size_t N>
T circle_queue<T, N>::front() const
{
    return *head;
}

namespace test_circle_queue
{
    std::size_t const SIZE{ static_cast<std::size_t>(5) };
    
    bool test_default()
    {
        circle_queue<int, SIZE> q;
        return q.empty()
                && !q.size()
                && !q.full();
    }

    bool test_push()
    {
        circle_queue<int, SIZE> q;
        bool rc{ q.push(0) };
        return rc
                && !q.empty()
                && q.size() == static_cast<std::size_t>(1)
                && !q.full();
    }

    bool test_pop()
    {
        circle_queue<int, SIZE> q;
        bool rc{ q.push(1) };
        q.pop();
        return rc 
                && q.empty()
                && !q.size()
                && !q.full();
    }

    bool test_front()
    {
        circle_queue<int, SIZE> q;
        bool rc{ q.push(2) };
        return rc
                && q.front() == 2
                && !q.empty()
                && q.size() == static_cast<std::size_t>(1)
                && !q.full();
    }
    
    template<size_t N>
    bool load(circle_queue<int, N> & q,
                int const arr[N], 
                std::size_t const count)
    {
        std::size_t i{ 0 };
        bool rc{ true };
        while(i < N 
                && i < count)
        {
            rc = q.push(arr[i]);
            if(!rc)
                break;
            ++i;
        }
        return rc;
    }

    template<size_t N>
    void unload(circle_queue<int, N> & q,
                std::size_t const count)
    {
        std::size_t i{ 0 };
        while(i < N
                && i < count)
        {
            q.pop();
            ++i;
        }
    }

    bool test_rolling()
    {
        circle_queue<int, SIZE> q;
        int arr[SIZE] = { 0, 1, 2, 3, 4 };
        bool rc_load;
        for(std::size_t i{ 0 }; i < SIZE; ++i)
        {
            rc_load = load<SIZE>(q, arr, SIZE - i);
            if(!rc_load) 
                break;
            unload<SIZE>(q, SIZE - i - 1);
        }
        int roll_result[SIZE] = { 1, 2, 0, 1, 0 };
        bool rc_verify;
        for(std::size_t i{ 0 }; i < SIZE; ++i)
        {
            rc_verify = (roll_result[i] == q.front());
            if(!rc_verify)
                break;
            q.pop();
        }
        return rc_load 
                && rc_verify;
    }        
    
    void test_circle_queue()
    {
        using namespace test_circle_queue;
        assert(test_default());
        assert(test_push());
        assert(test_pop());
        assert(test_front());
        assert(test_rolling());
    }
}

int main()
{
    test_circle_queue::test_circle_queue();
}
