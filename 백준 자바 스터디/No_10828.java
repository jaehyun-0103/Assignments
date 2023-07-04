import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class No_10828 {
    public static int[] stack;  // 스택 배열
    public static int size = 0; // stack 배열의 크기
    public static String[] op;  // 명령어를 저장할 배열

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()); // 첫째 줄에 주어지는 명령의 수
        int[] pushNum = new int[N]; // 정수 X를 저장할 배열
        int cnt = 0; // pushNum 배열의 크기
        stack = new int[N];
        op = new String[N];

        for (int i = 0; i < N; i++) {   // N번 반복
            st = new StringTokenizer(br.readLine());
            String s1 = st.nextToken();
            op[i] = s1;                 // 명령어를 op 배열에 저장
            if (op[i].equals("push")) { // 만약 명령어가 push라면
                int K = Integer.parseInt(st.nextToken()); // push 다음에 있는 수를 입력받아
                pushNum[cnt] = K;       // pushNum 배열에 저장
                cnt++;                  // 배열의 크기 1 증가
            }
        }

        cnt = 0;
        for (int i = 0; i < N; i++)
            if (op[i].equals("push")) {
                push(pushNum[cnt]);
                cnt++;
            } else if (op[i].equals("pop")) System.out.println(pop());
            else if (op[i].equals("size")) System.out.println(size());
            else if (op[i].equals("empty")) System.out.println(empty());
            else if (op[i].equals("top")) System.out.println(top());
    }
    // push X: 정수 X를 스택에 넣는 연산
    static void push(int p) {
        size++;
        stack[size - 1] = p;
    }
    // pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력
    //      만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력
    static int pop() {
        if (empty() == 1)
            return -1;
        else {
            int res = stack[size - 1];
            size--;
            return res;
        }
    }
    // size: 스택에 들어있는 정수의 개수를 출력
    static int size() {
        return size;
    }
    // empty: 스택이 비어있으면 1, 아니면 0을 출력
    static int empty() {
        if (size == 0)
            return 1;
        else
            return 0;
    }
    // top: 스택의 가장 위에 있는 정수를 출력
    //      만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력
    static int top() {
        if (empty() == 1)
            return -1;
        else
            return stack[size - 1];
    }
}