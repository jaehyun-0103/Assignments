import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class No_10845 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        Queue queue = new Queue(N);

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String str = st.nextToken();

            // push일 때만 push 뒤에 값을 따로 읽고 나머지는 함수호출
            if (str.equals("push")) {
                int k = Integer.parseInt(st.nextToken());
                queue.push(k);
            } else if (str.equals("pop")) System.out.println(queue.pop());
            else if (str.equals("size")) System.out.println(queue.size());
            else if (str.equals("empty")) System.out.println(queue.empty());
            else if (str.equals("front")) System.out.println(queue.front());
            else if (str.equals("back")) System.out.println(queue.back());
        }
    }
}

// 큐 클래스 생성
class Queue {
    int front, rear;
    int arr[];

    public Queue(int size) {
        this.front = 0;
        this.rear = 0;
        this.arr = new int[size];
    }

    public void push(int num) {
        arr[rear] = num;
        rear++;
    }

    public int pop() {
        if (empty() != 1) {
            int res = arr[front];
            front++;
            return res;
        } else return -1;
    }

    public int size() {
        return rear - front;
    }

    public int empty() {
        if (rear - front == 0) {
            return 1;
        } else return 0;
    }

    public int front() {
        if (empty()==0) {
            return arr[front];
        } else return -1;
    }

    public int back() {
        if (empty()==0) {
            return arr[rear-1];
        } else return -1;
    }
}