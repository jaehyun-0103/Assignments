package assignment;

class Dice {
    private double face;
    public Dice() {
        this.face = face;
    }
    public int roll() {
        this.face = ((int) (Math.random() * 6) + 1);
        return (int) face;
    }
}

public class assignment3 {
    public static void main(String[] args) {
        Dice d = new Dice();
        System.out.println("주사위의 숫자 : " + d.roll());
    }
}