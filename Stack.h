#ifndef STACK
#define STACK

#define NULL 0

template<class T>
struct Node {

    T val_;
    Node * next_;

    explicit Node(T val) {
        val_ = val;
        next_ = nullptr;
    }

    Node(T val, Node * next) {
        val_ = val;
        next_ = next;
    }
};

template <class T>
class Stack {

    Node<T> * head_;
    int size_;

    void DeleteRecursively(Node<T> * head) {
        if (head == nullptr)
        {
            return;
        }

        DeleteRecursively(head->next_);

        delete head;
    }

public:

    Stack() {
        head_ = nullptr;
        size_ = 0;
    }

    ~Stack() {
        Clear();
    }

    void Push(T val) {
        if (head_ == nullptr)
        {
            head_ = new Node<T>(val);
        }
        else
        {
            Node<T> * new_head = new Node<T>(val, head_);
            head_ = new_head;
        }
        size_++;
    }

    T Pop() {

        if (head_ == nullptr)
        {
            return NULL;
        }

        Node<T> * to_delete = head_;
        T val = head_->val_;

        head_ = head_->next_;
        size_--;

        delete to_delete;
        return val;
    }

    T Peek() {
        return head_ ? head_->val_ : NULL;
    }

    int Size() {
        return size_;
    }

    bool Empty() {
        return size_ == 0;
    }

    void Clear() {
        DeleteRecursively(head_);
        head_ = nullptr;
        size_ = 0;
    }
};

#endif
