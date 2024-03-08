import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;


public class No_11053 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[] arr = new int[N]; // 수열을 저장할 배열 선언
        int[] memo = new int[N]; // 수열의 길이를 저장할 배열 선언

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            memo[i] = 1; // 수열의 길이는 최소 1이기 때문

            for (int j = 0; j < i; j ++) {
                if(arr[j] < arr[i]) {
                    memo[i] = Math.max(memo[i], memo[j] + 1);
                }
            }

        }
        Arrays.sort(memo); // 오름차순 정렬
        System.out.println(memo[memo.length-1]);
    }
}