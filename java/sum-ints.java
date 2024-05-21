import java.util.Random;

class SumInts {
    static public void main(String args[]) {
        int[] nums = new int[1000000];
        Random random = new Random();
        for (int i = 0; i < nums.length; i++) {
            nums[i] = random.nextInt();
        }

        long sum = 0;
        long start = System.nanoTime();
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        long duration = System.nanoTime() - start;
        System.out.println("total time: " + duration / 1e3 + " MicroSec");
        System.out.println(sum);
    }
}
