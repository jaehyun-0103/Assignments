import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class No_1316 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        char[] c1 = new char[100];
        char[] c2 = new char[100];
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            int index1 = 1, index2 = 0, index3 = 0; // index1 : c1 배열의 인덱스, index2 : c2 배열의 인덱스, index3 : charList의 인덱스
            st = new StringTokenizer(br.readLine());
            String word = st.nextToken();

            // 입력한 문자열을 각 문자로 나눠 배열에 저장
            for (int j = 0; j < word.length(); j++)
                c1[j] = word.charAt(j);

            // 연속된 문자를 하나로 병합
            for (int k = 0; k < word.length(); k++) {
                c2[index2] = c1[k];
                while (c2[index2] == c1[index1]) //
                    index1++;
                index2++;
                k = index1 - 1;
            }

            // 병합한 문자 배열을 list로 저장
            List<Character> charList = new ArrayList<>();
            for (char c : c2) {
                charList.add(c);
                index3++;
                if (index2 == index3)
                    break;
            }

            // list로 저장한 문자 배열에서 중복된 문자 제거
            List<Character> distinctList = new ArrayList<>(new HashSet<>(charList));

            // 원래 list의 크기와 중복된 문자를 제거한 list의 크기가 같은지 판별
            if (charList.size() == distinctList.size())
                cnt++;
        }
        System.out.println(cnt);
    }
}