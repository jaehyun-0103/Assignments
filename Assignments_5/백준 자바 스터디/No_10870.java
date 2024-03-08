import java.util.Scanner; // Scanner 클래스 호출

public class No_10870 {
    public static void main(String[] args) {
        int n = 0, res = 0; // n : n번째 피보나치 수, res : 피보나치 수 결과값

        Scanner in = new Scanner(System.in); // Scanner 객체 생성
        n = in.nextInt();          // 입력한 값을 n에 저장

        res = fib(n);              // 메소드 호출
        System.out.println(res);   // 메소드의 리턴값 출력
    }
    public static int fib(int n) { // 메소드 선언부
        if (n == 0)      // 만약 n이 0이라면
            return 0;    // 0 리턴
        else if (n == 1) // 만약 1이라면
            return 1;    // 1리턴
        else             // n이 0 또는 1 외의 값이라면
            return fib(n - 1) + fib(n - 2); // 재귀호출
    }
}