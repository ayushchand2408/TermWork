class Q19 extends Thread {
    private String threadName;
    private int executionCount = 0;

    public Q19(String name) {
        this.threadName = name;
    }

    public void run() {
        try {
            while (executionCount < 5) { 
                executionCount++;
                System.out.println(threadName + " executed " + executionCount + " times.");
                Thread.sleep(500);
            }
            System.out.println(threadName + " has finished execution.");
        } catch (InterruptedException e) {
            System.out.println(threadName + " interrupted.");
        }
    }

    public static void main(String[] args) {
        Q19 csThread = new Q19("CSthread");
        Q19 itThread = new Q19("ITthread");

        csThread.start();
        itThread.start();
    }
}