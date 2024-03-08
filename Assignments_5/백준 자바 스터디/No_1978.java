import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class No_1978 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int cnt = 0;
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) { // N번 반복
            int num = Integer.parseInt(st.nextToken());
            if (num == 1) // 입력한 값이 1이면 continue
                continue;
            cnt++; // 소수 개수
            for (int j = 2; j < num; j++) {
                if (num % j == 0) { // 만약 2이상 자기자신 미만 사이에 나눠지는 수가 있다면
                    cnt--; // 소수 개수에 포함 안함
                    break;
                }
            }
        }
        System.out.println(cnt);
    }
}