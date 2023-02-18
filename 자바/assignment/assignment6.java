package assignment;

class Circle {
    int radius;
    Circle(int radius) {
        this.radius = radius;
    }
    void show() {
        System.out.println("반지름이 " + radius + "인 원이다.");
    }
}

class ColoredCircle extends Circle {
    String color;
    ColoredCircle(int radius, String color) {
        super(radius);
        this.color = color;
    }
    @Override
    void show() {
        System.out.println("반지름이 " + radius + "인 " + color + " 원이다.");
    }
}

public class assignment6 {
    public static void main(String[] args) {
        String color = "빨간색";
        Circle c1 = new Circle(5);
        Circle c2 = new ColoredCircle(10, color);

        c1.show();
        c2.show();
    }
}