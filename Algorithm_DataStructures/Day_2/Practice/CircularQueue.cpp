#include<iostream>
using namespace std;
class Customqueue {
public:
    Customqueue(int size) {
        this->n = size;
        arr = new int[size];
        front = -1;
        rear = -1;
        count = 0;
    }
    bool enqueue(int value) {
        if (count == n)
            return false;
        else if (front==-1) {
            front = rear = 0;
            arr[rear] = value;
            count++;
            return true;
        }
        else if (rear == n - 1 && front!=0) {
            rear = 0;
            arr[rear] = value;
            count++;
            return true;
        }
        else
        {
            rear++;
            arr[rear] = value;
            count++;
            return true;
        }
        
        
    }
    bool dequeue() {
        if (count == 0)
            return false;
        else if (front == rear)
        {
            front = rear = -1;
            count--;
            return true;
        }
        else if (front == n - 1) {
            front = 0;
            count--;
            return true;
        }
        else {
            front++; 
            count--;
            return true;
        }
       
    }
    void print() {
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            for (int i = front; i <n; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << "\n";
    }

private:
    int* arr;
    int n;
    int front;
    int rear;
    int count;
};
int main() {
    Customqueue cq(6);
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