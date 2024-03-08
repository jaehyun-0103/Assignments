package assignment;

public class assignment18 {
    public static void main(String[] args) {
        String prov = "Time is money";
        String[] provArray = prov.split(" ");
        Runnable task1 = () -> {
            for (String word : provArray) {
                System.out.println("속담1 : " + word);
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                }
            }
        };
        new Thread(task1).start();

        Runnable task2 = () -> {
            for (String word : provArray) {
                System.out.println("속담2 : " + word);
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                }
            }
        };
        new Thread(task2).start();
    }
}
