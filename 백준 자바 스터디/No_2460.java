import java.util.Scanner; // Scanner 클래스 호출

public class No_2460 {
    public static void main(String[] args) {
        int on = 0, off = 0, max = 0; // on : 탄 사람 수, off : 내린 사람 수, max : 사람 수 최대값
        int[] sum = new int[11];      // i+1번역에서 타고 있는 사람수의 배열
        sum[0] = 0;                   // 배열 첫 번째에 0 저장

        Scanner in = new Scanner(System.in); // Scanner 객체 생성

        for (int i = 0; i < 10; i++) { // 10번 반복
            off = in.nextInt();        // 입력한 값 중 i+1번째 줄의 첫 번째 값을 off에 저장
            on = in.nextInt();         // 입력한 값 중 i+1번째 줄의 첫 번째 값을 on에 저장
            sum[i + 1] = sum[i] - off + on;  // i+1번역에서 타고 있는 사람 수 계산
        }

        for (int i = 1; i <= 10; i++) { // 10번 반복
            if (sum[i] > max)           // i번째 배열값이 최대값보다 크다면
                max = sum[i];           // 그 배열값이 최대값
        }

        System.out.println(max);        // 최대값 출력
    }
}