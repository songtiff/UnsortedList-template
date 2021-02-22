
#include "UnsortedList.h"


template<class T>
UnsortedList<T>::UnsortedList() {
    length = 0;
    currentPos = -1;
}

template<class T>
void UnsortedList<T>::MakeEmpty() {
    length = 0;
}

template<class T>
bool UnsortedList<T>::IsFull() const {
    return length == MAX_ITEMS;
}

template<class T>
int UnsortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool UnsortedList<T>::Contains(T someItem) {
    for(int i = 0; i < length; i++)
        if(info[i] == someItem)
            return true;

    return false;
}

template<class T>
void UnsortedList<T>::PutItem(T item) {
    if (!IsFull())
        info[length++] = item;

}

template<class T>
void UnsortedList<T>::DeleteItem(T item) {
    for(int i = 0; i < length; i++)
        if(info[i] == item) {
            info[i] = info[length - 1];
            length--;
            return;
        }

}

template<class T>
void UnsortedList<T>::ResetIterator() {
    currentPos = -1;
}

template<class T>
int UnsortedList<T>::GetNextItem() {
    //beginner friendly way to protect from moving away from end of list
    if (currentPos >= length) {
        throw "Out of bounds.";
    }
    currentPos++;
    return info[currentPos];
}

