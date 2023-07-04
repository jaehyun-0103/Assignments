import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.StringTokenizer;

public class No_16506 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        String[] arr;
        String one = "0"; // 3bit의 공간을 원하는데 결과가 2bit일 때 앞에 추가
        String two = "00"; // 3bit의 공간을 원하는데 결과가 1bit일 때 앞에 추가
        String three = "000";  // 4bit의 공간을 원하는데 결과가 1bit일 때 앞에 추가

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String op = st.nextToken();
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            // opcode의 끝이 'C'로 끝나는지 아닌지 확인
            if (Objects.equals(op.charAt(op.length() - 1), 'C')) {
                arr = new String[6];
                arr[1] = "1";

                String rB = Integer.toBinaryString(c);
                if (rB.length() == 1)
                    rB = three.concat(rB);
                else if (rB.length() == 2)
                    rB = two.concat(rB);
                else if (rB.length() == 3)
                    rB = one.concat(rB);
                arr[5] = rB;
            } else {
                arr = new String[7];
                arr[1] = one;

                String rB = Integer.toBinaryString(c);
                if (rB.length() == 1)
                    rB = two.concat(rB);
                else if (rB.length() == 2)
                    rB = one.concat(rB);
                arr[5] = rB;
                arr[6] = one;
            }
            arr[2] = one;

            arr[0] = setting(op);

            String rD = Integer.toBinaryString(a);
            if (rD.length() == 1)
                rD = two.concat(rD);
            else if (rD.length() == 2)
                rD = one.concat(rD);
            arr[3] = rD;

            String rA = Integer.toBinaryString(b);
            if (rA.length() == 1)
                rA = two.concat(rA);
            else if (rA.length() == 2)
                rA = one.concat(rA);
            arr[4] = rA;

            for (String s : arr) {
                System.out.print(s);
            }
            System.out.println();
        }
    }
    public static String setting(String opcode) {
        if (Objects.equals(opcode, "ADD") || Objects.equals(opcode, "ADDC"))
            return "0000";
        else if (Objects.equals(opcode, "SUB") || Objects.equals(opcode, "SUBC"))
            return "0001";
        else if (Objects.equals(opcode, "MOV") || Objects.equals(opcode, "MOVC"))
            return "0010";
        else if (Objects.equals(opcode, "AND") || Objects.equals(opcode, "ANDC"))
            return "0011";
        else if (Objects.equals(opcode, "OR") || Objects.equals(opcode, "ORC"))
            return "0100";
        else if (Objects.equals(opcode, "NOT"))
            return "0101";
        else if (Objects.equals(opcode, "MULT") || Objects.equals(opcode, "MULTC"))
            return "0110";
        else if (Objects.equals(opcode, "LSFTL") || Objects.equals(opcode, "LSFTLC"))
            return "0111";
        else if (Objects.equals(opcode, "LSFTR") || Objects.equals(opcode, "LSFTRC"))
            return "1000";
        else if (Objects.equals(opcode, "ASFTR") || Objects.equals(opcode, "ASFTRC"))
            return "1001";
        else if (Objects.equals(opcode, "RL") || Objects.equals(opcode, "RLC"))
            return "1010";
        else if (Objects.equals(opcode, "RR") || Objects.equals(opcode, "RRC"))
            return "1011";
        return opcode;
    }
}