//package mxor;
public class MXOR {

    public static void main(String[] argv) {
        int n = MXORLIB.get_n();
        int x = -1, y = -1, best = -1;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int[] I = new int[1], J = new int[1];
                I[0] = i;
                J[0] = j;
                int tmp = MXORLIB.max_xor(I, J);
                if (tmp > best) {
                    best = tmp;
                    x = i;
                    y = j;
                }
            }
        }
        MXORLIB.answer(x, y);
    }

}
