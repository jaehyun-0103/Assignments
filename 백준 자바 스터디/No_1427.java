import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class No_1427 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String str = st.nextToken();
        char[] chars = str.toCharArray(); // 입력한 값을 문자 하나하나 나눔

        Arrays.sort(chars); // 오름차순 정렬

        StringBuilder Answer = new StringBuilder(new String(chars)); // 변경 가능한 문자열로 변환
        Answer.reverse().toString(); // 내림차순으로 변경
        System.out.println(Answer);
    }
}