import java.util.Scanner; // Scanner 클래스 호출

public class No_3460 {
    public static void main(String[] args) {
        int T = 0, n = 0, cnt = 0;  // T : 테스트 케이스의 개수, cnt : 이진수의 자릿수
        int []remain = new int[20]; // 나머지값을 저장할 배열

        /*
        (2의 20승 = 1048576) > (1000000 = 10의 6승)
        */

        Scanner in = new Scanner(System.in); // Scanner 객체 생성
        T = in.nextInt(); // 줄바꿈을 구분자로 첫 번째 자연수를 T에 저장

        while (T > 0) {              // T가 양수인 동안 반복
            cnt = 0;                 // cnt를 0으로 초기화
            n = in.nextInt();        // 줄바꿈을 구분자로 두 번째 양의 정수를 n에 저장

            while (true) {           // 무한반복
                remain[cnt] = n % 2; // n을 2로 나누었을 때 나머지값을 배열에 저장
                n /= 2;              // n을 2로 나눈 값을 n에 저장
                cnt++;               // cnt값 1 증가
                if (n == 0)          // n이 0이라면
                    break;           // 반복문 종료
            }

            for (int j = 0; j < cnt; j++)    // cnt번 반복
                if (remain[j] == 1)          // 배열값이 1이라면
                    System.out.print(j+" "); // 그 배열의 인덱스 출력

            T--;                  // T값 1 감소
            System.out.println(); // 줄바꿈
        }
    }
}