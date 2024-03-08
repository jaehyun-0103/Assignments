import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class No_20920 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken()); // 단어의 개수 N을 입력 받음
        int M = Integer.parseInt(st.nextToken()); // 단어의 최소 길이 M을 입력 받음

        Map<String, Integer> wordMap = new HashMap<String, Integer>(); // 단어와 등장 횟수를 저장할 Map 객체 생성

        for (int i = 0; i < N; i++) {
            String word = br.readLine(); // 단어를 입력 받음
            if (word.length() < M) continue; // 단어의 길이가 M보다 작으면 건너뜀

            Integer count = wordMap.getOrDefault(word, 0); // 현재 단어의 등장 횟수를 가져옴, 단어가 없으면 0으로 초기화
            wordMap.put(word, count + 1); // 단어와 등장 횟수를 업데이트
        }

        List<String> words = wordMap.keySet().stream().sorted((o1, o2) -> {
            int c1 = wordMap.get(o1); // 단어 o1의 등장 횟수를 가져옴
            int c2 = wordMap.get(o2); // 단어 o2의 등장 횟수를 가져옴

            if (c1 == c2) {
                if (o1.length() == o2.length()) {
                    return o1.compareTo(o2); // 등장 횟수가 같고 길이도 같으면 사전 순으로 정렬
                }

                return o2.length() - o1.length(); // 등장 횟수가 같으면 길이가 긴 단어가 앞에 오도록 정렬
            }
            return c2 - c1; // 등장 횟수가 다르면 등장 횟수가 큰 단어가 앞에 오도록 정렬
        }).collect(Collectors.toList()); // 정렬된 단어들을 List로 변환

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.size(); i++)
            sb.append(words.get(i)).append("\n"); // 각 단어를 줄바꿈과 함께 StringBuilder에 추가
        System.out.println(sb); // 결과 출력
    }
}