
#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front ? true : false;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Error: Queue is full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty\n";
            return;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Error: Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Error: Queue is empty\n";
            return;
        }
        int i;
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            cout << arr[i] << " ";
        }
        cout << arr[i] << endl;
    }

  


bool isPalindrome(Queue &obj, int f, int r, int s) {
    if (s == 0) {
        return true;
    } else if (f > r) {
        return true;
    } else if (obj.peek() == obj.arr[r]) {
        obj.dequeue();
        return isPalindrome(obj, f + 1, r - 1, s - 2);
    } else {
        return false;
    }
}
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(2);
    q.enqueue(1);

    cout <<  q.isPalindrome(q, 0, 4, 5);

    return 0;
}
