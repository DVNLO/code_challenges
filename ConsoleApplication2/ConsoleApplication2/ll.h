

#ifndef LL_h
#define LL_h

#include <cstdio>

namespace cs_ll{
    template <class T>
    class LL {
    public:
        class Empty_List_Error{};
        typedef size_t size_type;
        typedef T value_type;
        LL();
        LL(const LL& listToCopy);
        LL operator=(const LL& listToAssign);
        ~LL();
        bool empty() const;
        size_type size() const;
        void clear();
        void pop_front();
        void push_front(const value_type& x);
        value_type& front();
        const value_type& front() const;
        void insert(const value_type& insertMe);
        
    private:
        void copyList(const LL& listToCopy);
        struct node {
            value_type data;
            node* next;
        };
        node* list;
        
        
    public:
        class iterator {
        public:
            iterator(node* initial = NULL) {
                current = initial;
            }
            
            value_type& operator*() const {
                return current->data;
            }
            
            iterator& operator++() {
                current = current->next;
                return *this;
            }
            
            iterator operator++(int) {
                iterator original(current);
                current = current->next;
                return original;
            }
            
            bool operator==(iterator other) const {
                return current == other.current;
            }
            
            bool operator !=(iterator other) const {
                return current != other.current;
            }
        private:
            node* current;
        };
        
        
    public:
        class const_iterator  {
        public:
            const_iterator(const node* initial = NULL) {
                current = initial;
            }
            
            const value_type& operator*() const {
                return current->data;
            }
            
            const_iterator& operator++() {
                current = current->next;
                return *this;
            }
            
            const_iterator operator++(int) {
                const_iterator original(current);
                current = current->next;
                return original;
            }
            
            bool operator==(const const_iterator other) const {
                return current == other.current;
            }
            
            bool operator !=(const const_iterator other) const {
                return current != other.current;
            }
        private:
            const node* current;
        };  // end of iterator class declarations.  LL class continues below.
        
        iterator begin() {
            return iterator(list);
        }
        
        iterator end() {
            return iterator();
        }
        
        const_iterator begin() const {
            return const_iterator(list);
        }
        
        const_iterator end() const {
            return const_iterator();
        }
        
    };
    
    
}


#endif
