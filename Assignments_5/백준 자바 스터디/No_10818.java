import java.util.Scanner; // Scanner 클래스 호출

public class No_10818 {
    public static void main(String[] args) {
        int N = 0, num = 0; // N : 정수의 개수, num : 입력한 정수들 중 하나
        int max, min;

        Scanner in = new Scanner(System.in);     // Scanner 객체 생성
        N = in.nextInt();   // 줄바꿈을 구분자로 첫 번째 정수를 N에 저장
        num = in.nextInt(); // 띄어쓰기를 구분자로 첫 번째 정수를 num에 저장

        max = min = num;    // 첫 번째로 읽은 값을 max와 min으로 설정

        for (int i = 0; i < N - 1; i++) { // 정수의 개수보다 1 적은 횟수만큼 반복
            num = in.nextInt(); // 띄어쓰기를 구분자로 i+2번째 정수를 num에 저장
            if (num > max)      // 만약 num이 max보다 크다면
                max = num;      // max에 num 저장
            if (num < min)      // 만약 num이 min보다 작다면
                min = num;      // min에 num 저장
        }
        System.out.printf("%d %d\n", min, max);  // 최소값, 최대값 출력
    }
}