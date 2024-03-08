import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class No_2947 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] block = new int[5];     // 나무 조간 번호 순서를 저장할 배열
        int cnt; // 나무 조각의 위치를 바꾸는 횟수

        for (int i = 0; i < 5; i++) { // 5번 반복
            int T = Integer.parseInt(st.nextToken());
            block[i] = T; // 입력값을 배열에 저장
        }

        while (true) { // 무한반복
            cnt = 0;   // 나무 조각의 위치를 바꾸는 횟수를 0으로 초기화
            for (int j = 0; j < 4; j++)        // 4번 반복
                if (block[j] > block[j + 1]) { // 만약 j의 조각의 수가 j+1보다 크다면 스왑
                    int temp;
                    temp = block[j];
                    block[j] = block[j + 1];
                    block[j + 1] = temp;
                    System.out.printf("%d %d %d %d %d\n", block[0], block[1], block[2], block[3], block[4]);
                    cnt++;       // 나무 조각의 위치를 바꾸는 횟수 1 증가
                }
            if (cnt == 0) break; // 나무 조각의 위치를 바꾸는 횟수가 0이라면 무한반복 종료
        }
    }
}