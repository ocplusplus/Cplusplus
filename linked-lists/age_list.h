#ifndef AGE_LIST_H
#define AGE_LIST_H

struct Node {
    int age;
    Node* next;
};

class AgeList {
private:
    Node* head;

public:
    AgeList();
    ~AgeList();

    void insertAge(int newAge);
    void deleteAge(int targetAge);
    bool searchAge(int targetAge);
    void displayList();
};

#endif
