#include<iostream>
using namespace std;
class Customqueue {
public:
    Customqueue(int size) {
        this->n = size;
        arr = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }
    bool enqueue(int value) {
        if (count == n)
            return false;
        rear = (rear + 1) % n;
        arr[rear] = value;
        count++;
        return true;
    }
    bool dequeue() {
        if (count == 0)
            return false;
        count--;
        front = (front + 1) % n;
        return true;
    }
    void print() {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }

private:
    int* arr;       
    int n;  
    int front;     
    int rear;       
    int count;
};
int main() {
    Customqueue cq(5);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60);
    cq.print();
    cq.dequeue();
    cq.dequeue();
    cq.print();

}