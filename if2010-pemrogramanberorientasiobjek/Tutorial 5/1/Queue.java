// Queue.java

public class Queue<T> {
    private static final int MAX_CAPACITY = 20;
    private final T[] data;
    private int head, tail;

    // Ctor queue (kosong) dengan alokasi kapasitas maksimum
    public Queue() {
        this.data = (T[]) new Object[MAX_CAPACITY];
        this.head = 0;
        this.tail = 0;
    }

    // Ctor queue terisi dari array dengan alokasi kapasitas maksimum.
    // Copy array dari indeks ke-0 hingga terakhir (data.length)
    // Boleh dilakukan secara copy reference object (bukan reference array)
    public Queue(T[] data) {
        this.data = (T[]) new Object[MAX_CAPACITY];
        this.head = 0;
        this.tail = data.length;

        for (int i = 0; i < data.length; i++) {
            this.data[i] = data[i];
        }
    }

    // Mengintip element paling depan pada queue.
    // Jika queue kosong, return null
    public T peek() {
        if (this.tail == this.head) {
            return null;
        }

        return this.data[this.head];
    }

    // Mengeluarkan elemen paling depan dari queue.
    // Jika queue kosong, return null
    public T pop() {
        if (this.tail == this.head) {
            return null;
        }

        T var = this.data[head];
        this.head++;
        return var;
    }

    // Menambahkan elemen ke dalam queue.
    // Prekondisi: tail < MAX_CAPACITY - 2 (tidak perlu divalidasi)
    public void push(T o) {
        this.data[this.tail] = o;
        this.tail++;
    }

    // Menghitung panjang queue.
    public int size() {
        return this.tail - this.head;
    }

    // Getter attribute
    public T[] getData() {
        return this.data;
    }
    public int getHead() {
        return this.head;
    }
    public int getTail() {
        return this.tail;
    }
}