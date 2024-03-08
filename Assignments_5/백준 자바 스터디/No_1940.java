import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class No_1940 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine()); // 재료의 수
        int M = Integer.parseInt(br.readLine()); // 필요한 수
        int[] uniqueNum = new int[N]; // 고유번호를 저장할 1차원 배열
        StringTokenizer st = new StringTokenizer(br.readLine());
        int sum = 0; // 조건에 맞는 조합의 개수

        for (int i = 0; i < N; i++)
            uniqueNum[i] = Integer.parseInt(st.nextToken());

        // 모든 경우의 수 계산
        for (int i = 0; i < N - 1; i++)
            for (int j = i + 1; j < N; j++)
                if (uniqueNum[i] + uniqueNum[j] == M)
                    sum++;

        System.out.println(sum);
    }
}