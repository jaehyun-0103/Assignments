import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class No_9012 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int cntL, cntR; // '('와 ')'의 수
        int N = Integer.parseInt(st.nextToken());
        String[] split = new String[N]; // 괄호 문자열을 저장할 배열

        for (int i = 0; i < N; i++) {   // N번 반복
            st = new StringTokenizer(br.readLine());
            String S = st.nextToken();
            split[i] = S; // 괄호 문자열을 저장
        }

        for (int j = 0; j < N; j++) { // N번 반복
            cntL = cntR = 0; // '('와 ')'의 수를 0으로 초기화
            for (int k = 0; k < split[j].length(); k++) { // 괄호 문자열의 크기만큼 반복
                if (split[j].charAt(k) == '(') // 만약 '('라면
                    cntL++;  // cntL 1증가
                else         // 아니라면
                    cntR++;  // cntR 1증가
                if (cntL < cntR) break; // 그런데 만약 ')'가 더 많은 순간이 있다면 반복문 종료
            }
            if (cntL == cntR) // '('와 ')'의 수가 같다면
                System.out.println("YES");
            else              // '('와 ')'의 수가 같지 않다면
                System.out.println("NO");
        }
    }
}