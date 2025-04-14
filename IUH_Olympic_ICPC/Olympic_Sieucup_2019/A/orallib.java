//Đây là file ví dụ

public class orallib {

	private static int Jury_n = 10;

	public static int get_N(){
		return Jury_n;
	}

	public static int guess(int k) {
		if (k < 0 || k > Jury_n)
			return 0;
		return 1;
	}
}
