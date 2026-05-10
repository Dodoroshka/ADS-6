// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
private:
    struct Item {
        T data;
        Item* next;
    };
    Item* head,* tail;

    Item* create(const T& data) {
        Item* item = new Item;
        item->data = data;
        item->next = nullptr;
        return item;
    }

public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    ~TPQueue() {
        while (head)
            pop();
    }
    void push(const T& data) {
        Item* item = create(data);
        if (!head)
            head = tail = item;
        else if (head->data.prior > data.prior) {
            item->next = head;
            head = item;
        } else {
            Item* curr = head;
            while (curr->next != nullptr && curr->next->data.prior <= data.prior)
                curr = curr->next;
            item->next = curr->next;
            curr->next = item;
            if (item->next == nullptr)
                tail = item;
        }
    }
    void pop() {
        if (!head) {
            throw std::string("Empty");
        }
        Item* temp = head->next;
        delete head;
        head = temp;
        if (!head) {
            tail = nullptr;
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
