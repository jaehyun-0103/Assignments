import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class No_11866 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[] arr = new int[N + 1];
        int[] ans = new int[N];
        int cnt = 0, cntN = 0;
        boolean isEnd = false;

        for (int i = 1; i <= N; i++) // N번 반복
            arr[i] = i;

        while (!isEnd) {        // 특수 조건일 때까지 무한 반복
            for (int j = 1; j <= N; j++) {
                cnt++;          // 이동 횟수를 계산하는 변수로 for문 시작시 1 증가
                if (arr[j] == 0) // 만약 방문한 배열이 0이라면
                    cnt--;      // 이동 횟수에 포함하지 않음
                if (cnt % K == 0 && arr[j] != 0) { // 만약 방문한 배열이 0이 아니고 K의 배수라면
                    ans[cntN] = arr[j]; // 그 배열의 값을 따로 빼내고
                    arr[j] = 0; // 0으로 바꿈
                    cntN++;     // 그리고 빼낸 값의 수 1 증가
                }
            }
            if (N == cntN) // 배열의 값을 모두 빼냈다면
                isEnd = true; // 반복문 종료
        }

        System.out.print("<");
        for (int m = 0; m < N - 1; m++) {
            System.out.print(ans[m] + ", ");
        }
        System.out.print(ans[N - 1]);
        System.out.print(">");
    }
}