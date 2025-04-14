//package mxor;
import java.util.Scanner;

public class MXORLIB {

    private static int[] a;
    private static boolean inited = false;

    private static void init() {
        if (inited) {
            return;
        }
        inited = true;
        Scanner in = new Scanner(System.in);
        System.out.print("Enter n and array a to test: ");
        int n = in.nextInt();
        a = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            a[i] = in.nextInt();
        }
    }

    public static int get_n() {
        init();
        return a.length - 1;
    }

    public static int max_xor(int[] I, int[] J) {
        init();

        int ans = -1;
        for (int i : I) {
            for (int j : J) {
                if (i > a.length - 1 || i < 1 || j > a.length - 1 || j < 1 || i == j) {
                    System.out.println("Invalid request");
                    answer(-1, -1);
                }
                if ((a[i] ^ a[j]) > ans) {
                    ans = a[i] ^ a[j];
                }
            }
        }
        return ans;
    }

    public static void answer(int i, int j) {
        System.out.println("Answer: " + i + " " + j);
        System.exit(0);
    }
}
