#include <stdio.h>
#include <stdlib.h>
struct Queue {
    // Định nghĩa cấu trúc dữ liệu Queue
	char front, rear,size;
    signed char capacity;
	int *array;
    // Bao gồm các thành phần như front, rear, size, capacity, và array.
};

struct Queue* createQueue(unsigned capacity) {
    // Triển khai hàm tạo Queue mới
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = -1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) {
    // Triển khai hàm kiểm tra Queue có đầy không
	int key=0;
	if((queue->capacity)==(queue->size)){
		key=1;
	}
    return key;
}

int isEmpty(struct Queue* queue) {
    // Triển khai hàm kiểm tra Queue có trống không
	int key=0;
	if((queue->capacity)==0){
		key=1;
	}
    return key;
}

void enqueue(struct Queue* queue, int item) {
    // Triển khai hàm thêm phần tử vào Queue
	if(isFull(queue)==0){
		queue->array[queue->rear+1]=item;
		queue->rear++;
		queue->capacity++;
	}
}

int dequeue(struct Queue* queue) {
    // Triển khai hàm lấy phần tử từ Queue
	int k;
	if(isEmpty(queue)==0){
		k=queue->array[queue->front];
		queue->front++;
		queue->capacity--;
	}
	return k;
}

int main() {
    struct Queue* queue = createQueue(5);

    // Thêm phần tử vào Queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // Lấy phần tử ra khỏi Queue và in ra
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));

    // Thêm phần tử mới vào Queue
    enqueue(queue, 50);

    // In ra phần tử ở đầu và cuối Queue
    printf("Front item is %d\n", queue->array[queue->front]);
    printf("Rear item is %d\n", queue->array[queue->rear]);

    return 0;
}
