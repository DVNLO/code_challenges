#include <cstdio>
#include <cstdlib>

struct node
{
    int data;
    node * next{ nullptr };
};

struct ll
{
    node * head{ nullptr };
};

ll construct_linked_list(std::size_t const SIZE)
{
    ll ret;
    if(!SIZE)
    {
        return ret; // the default initialized ll
    }
    ret.head = new node;
    node * current = ret.head;
    current->data = static_cast<int>(SIZE);
    std::size_t nodes_remaining{ SIZE - 1 }; // SIZE >= 1
    while(nodes_remaining)
    {
        current->next = new node;
        current = current->next;
        current->data = static_cast<int>(nodes_remaining);
        --nodes_remaining;
    }
    return ret;
}

// the following will reverse our forward singly linked list
void reverse_linked_list(ll & val)
{
    if(!val.head)
    {
        return; // empty list;
    }
    node * head{ val.head->next };
    node * mid{ val.head };
    node * tail{ nullptr };
    while(head)
    {
        mid->next = tail;
        tail = mid;
        mid = head;
        head = head->next;
    }
    mid->next = tail;
    val.head = mid;
}

void print_linked_list(ll const & val)
{
    node const * current = val.head;
    while(current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

struct dnode
{
    int data;
    dnode * next{ nullptr };
    dnode * previous{ nullptr };
};

struct dll
{
    dnode * head;
};

dll construct_double_linked_list(std::size_t const SIZE)
{
    dll ret;
    if(!SIZE)
    {
        return ret;
    }
    ret.head = new dnode;
    dnode * lead{ ret.head };
    dnode * follow{ nullptr };
    lead->data = static_cast<int>(SIZE);
    std::size_t remaining_nodes{ SIZE - 1 };
    while(remaining_nodes)
    {
        follow = lead;
        lead->next = new dnode;
        lead = lead->next;
        lead->data = static_cast<int>(remaining_nodes);
        lead->previous = follow;
        --remaining_nodes;
    }
    return ret;
}

void print_double_linked_list(dll const & val)
{
    dnode * current = val.head;
    while(current)
    {
        std::printf("%d ", current->data);
        current = current->next;
    }
}

void reverse_double_linked_list(dll & val)
{
    if(!val.head)
    {
        return;
    }
    dnode * lead{ val.head };
    dnode * follow{ nullptr };
    dnode * tmp{ nullptr };
    while(lead)
    {
        follow = lead;
        lead = lead->next;
        tmp = follow->next;
        follow->next = follow->previous;
        follow->previous = tmp;
    }
    val.head = follow;
}

int main(int const argc, char const * const argv[])
{
    if(argc < 2)
    {
        std::exit(EXIT_FAILURE);
    }
    std::size_t const SIZE{ static_cast<std::size_t>(strtoul(const_cast<char const *>(argv[1]), nullptr, 10)) };
    ll a = construct_linked_list(SIZE);
    print_linked_list(a);
    reverse_linked_list(a);
    print_linked_list(a);
    std::puts("\n------------------");  // std::puts appends trailing '\n'
    dll b = construct_double_linked_list(SIZE);
    print_double_linked_list(b);
    reverse_double_linked_list(b);
    print_double_linked_list(b);
    std::puts("\n------------------");  // std::puts appends trailing '\n'
}

