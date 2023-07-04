import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class No_10989 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(st.nextToken());
        int[] num = new int[N]; // N개의 자연수를 저장할 배열

        for (int i = 0; i < N; i++) { // N만큼 반복
            st = new StringTokenizer(br.readLine());
            int T = Integer.parseInt(st.nextToken());
            num[i] = T;         // 입력한 자연수를 배열에 저장
        }

        Arrays.sort(num);       // 정렬

        for (int j = 0; j < N; j++) { // N만큼 반복
            bw.write(String.valueOf(num[j])); // 데이터를 버퍼에 저장
            bw.write("\n");
            /*
            write() 메소드는 문자 또는 문자열을 출력
            bw.write에는 System.out.println();과 같이 자동개행기능이 없음
            */
        }
        bw.flush(); // 버퍼에 저장된 데이터를 출력 스트림에 전송
    }
}