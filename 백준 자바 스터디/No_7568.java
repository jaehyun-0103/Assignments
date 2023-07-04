import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class No_7568 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int[][] arr = new int[N][2];

        // 몸무게, 키를 2차원 배열에 저장
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }

        // 자기보다 몸무게와 키 모두 큰 배열이 존재할 때 등수가 1 내려감
        for (int i = 0; i < N; i++) {
            int rank = 1;
            for (int j = 0; j < N; j++)
                if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
                    rank++;
            System.out.print(rank + " ");
        }
    }
}