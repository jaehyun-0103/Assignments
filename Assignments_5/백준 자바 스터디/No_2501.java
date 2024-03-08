import java.util.Scanner; // Scanner 클래스 호출

public class No_2501 {
    public static void main(String[] args) {
        int N = 0, K = 0, cnt = 0;      // 1<=k<=N, cnt : 약수 개수
        int[] divisor = new int[10000]; // 약수 정보를 저장할 배열

        /*
        초기화된 배열의 인자들이 가지는 초기값은 0
        따라서 약수가 없을 때 자동으로 0 출력
        */

        Scanner in = new Scanner(System.in); // Scanner 객체 생성
        N = in.nextInt(); // 띄어쓰기를 구분자로 첫 번째 자연수를 N에 저장
        K = in.nextInt(); // 띄어쓰기를 구분자로 두 번째 자연수를 K에 저장

        for (int i = 1; i <= N; i++) {  // N번 반복
            if (N % i == 0) {           // N이 i로 나눠진다면
                cnt++;                  // cnt값 1 증가
                divisor[cnt] = i;       // N을 나눌 수 있는 i 값을 배열에 저장
            }
        }

        System.out.println(divisor[K]); // k번째 배열값 출력
    }
}