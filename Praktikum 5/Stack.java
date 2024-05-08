import java.util.ArrayList;
import java.util.List;

//Class Stack berikut merupakan suatu kelas GENERIC
//Stack disimpan dengan memanfaatkan ArrayList
//Element terakhir stack disimpan pada index paling kanan pada ArrayList
public class Stack<T> {

    private List<T> data;

    private int lastElmIdx, size;

    private final static int DEFAULT_STACK_SIZE = 500;

    // Constructor dengan size default
    public Stack() {
        this.data = new ArrayList<T>(DEFAULT_STACK_SIZE);
        this.lastElmIdx = -1;
        this.size = DEFAULT_STACK_SIZE;
    }

    // Constructore dengan size = n
    public Stack(int n) {
        this.data = new ArrayList<T>(n);
        this.lastElmIdx = -1;
        this.size = n;
    }

    // Copy constructor dari stack lain
    public Stack(final Stack<T> q) {
        this.data = new ArrayList<T>(q.size);
        this.lastElmIdx = q.lastElmIdx;
        this.size = q.size;
        for (int i = 0; i <= q.lastElmIdx; i++) {
            this.data.add(q.data.get(i));
        }
    }

    // Tambahkan elemen t ke dalam stack
    // Jika stack penuh, lempar exception "Stack is full"
    public void push(T t) throws Exception {
        if (isFull()) {
            throw new Exception("Stack is full");
        } else {
            data.add(t);
            lastElmIdx++;
        }
    }

    // Hapus elemen terakhir dari stack
    // Jika stack kosong, lempar exception "Stack is empty"
    public T pop() throws Exception {
        if (isEmpty()) {
            throw new Exception("Stack is empty");
        } else {
            T t = data.get(lastElmIdx);
            data.remove(lastElmIdx);
            lastElmIdx--;
            return t;
        }
    }

    // Cek apakah stack kosong
    public boolean isEmpty() {
        return lastElmIdx == -1;
    }

    // Cek apakah stack penuh
    public boolean isFull() {
        return lastElmIdx == size - 1;
    }
}