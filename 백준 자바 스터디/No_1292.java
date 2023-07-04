import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class No_1292 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int T = 0, res = 0, index = 1, sum = 0;
        int[] arr;

        // 시그마 공식을 토대로 배열의 크기인 res+1과 B번째에 있을 수 T 확인
        while (B >= res) {
            T++;
            res = (T * (T + 1)) / 2;
        }

        // 수열 설정
        arr = new int[res + 1];
        for (int i = 1; i <= T; i++) {
            for (int j = 0; j < i; j++) {
                arr[index] = i;
                index++;
            }
        }

        // 수열의 합
        for (int k = A; k <= B; k++) {
            sum += arr[k];
        }

        System.out.println(sum);
    }
}