package assignment;

class SharedProv {
    public synchronized void Prov(String name, String prov) {
        String[] provArray = prov.split(" ");
        for (String word : provArray) {
            System.out.println(name + " : " + word);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
            }
        }
    }
}

class ProvThread extends Thread {
    private String name;
    private String prov;
    private SharedProv provthread;
    public ProvThread(String name, String prov, SharedProv provthread) {
        this.name = name;
        this.prov = prov;
        this.provthread = provthread;
    }
    public void run() {
        provthread.Prov(name, prov);
    }
}

public class assignment19 {
    public static void main(String[] args) {
        SharedProv p = new SharedProv();
        new ProvThread("속담1", "Time is money", p).start();
        new ProvThread("속담2", "Time is money", p).start();
    }
}