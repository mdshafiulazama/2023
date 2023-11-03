import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for (int t = 1; t <= T; t++) {
            int N = sc.nextInt();
            int[] A = new int[N];
            for (int i = 0; i < N; i++) {
                A[i] = sc.nextInt();
            }

            long result = countNonBeautifulSubarrays(A);
            System.out.println("Case " + t + ": " + result);
        }
    }

    public static long countNonBeautifulSubarrays(int[] A) {
        int N = A.length;
        long nonBeautifulSubarrays = 0;
        long beautifulCount = 1; // Initialize with 1 as the first element is always a beautiful subarray

        for (int i = 1; i < N; i++) {
            if (A[i] == A[i - 1]) {
                beautifulCount++;
            } else {
                nonBeautifulSubarrays += (beautifulCount * (beautifulCount + 1)) / 2;
                beautifulCount = 1;
            }
        }

        nonBeautifulSubarrays += (beautifulCount * (beautifulCount + 1)) / 2;
        long totalSubarrays = (long)N * (N + 1) / 2;
        return totalSubarrays - nonBeautifulSubarrays;
    }
}
