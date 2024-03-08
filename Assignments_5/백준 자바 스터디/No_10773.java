import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class No_10773 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int K = Integer.parseInt(st.nextToken());
        int[] num = new int[K]; // k개의 정수를 저장할 배열
        int size = 0, sum = 0;  // 크기와 합을 0으로 초기화

        for (int i = 0; i < K; i++) { // k만큼 반복
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            if (n != 0) {      // 만약 정수가 0이 아니라면
                num[size] = n; // 정수를 배열에 저장
                size++;        // 배열의 크기 1증가
            } else             // 정수가 0이라면
                size--;        // 배열의 크기 1감소
        }
        for (int j = 0; j < size; j++) // 배열의 크기만큼 반복
            sum += num[j];     // 배열의 값을 다 더함

        System.out.println(sum);
    }
}