class SharedResource {
    private int value;
    private boolean isProduced = false;

    synchronized void produce(int v) {
        try {
            while (isProduced) {
                wait(); 
            }
            value = v;
            System.out.println("Producer produced: " + value);
            isProduced = true;
            notify(); 
        } catch (InterruptedException e) {
            System.out.println("Producer interrupted.");
        }
    }

    synchronized void consume() {
        try {
            while (!isProduced) {
                wait(); 
            }
            System.out.println("Consumer consumed: " + value);
            isProduced = false;
            notify(); 
        } catch (InterruptedException e) {
            System.out.println("Consumer interrupted.");
        }
    }
}

class Producer extends Thread {
    private SharedResource resource;

    public Producer(SharedResource resource) {
        this.resource = resource;
    }

    public void run() {
        for (int i = 1; i <= 5; i++) { 
            resource.produce(i);
            try {
                Thread.sleep(500); 
            } catch (InterruptedException e) {
                System.out.println("Producer sleep interrupted.");
            }
        }
    }
}

class Consumer extends Thread {
    private SharedResource resource;

    public Consumer(SharedResource resource) {
        this.resource = resource;
    }

    public void run() {
        for (int i = 1; i <= 5; i++) { 
            resource.consume();
            try {
                Thread.sleep(500); 
            } catch (InterruptedException e) {
                System.out.println("Consumer sleep interrupted.");
            }
        }
    }
}

public class Q20 {
    public static void main(String[] args) {
        SharedResource resource = new SharedResource();
        Producer producer = new Producer(resource);
        Consumer consumer = new Consumer(resource);

        producer.start();
        consumer.start();
    }
}