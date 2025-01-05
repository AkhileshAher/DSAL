import java.util.*;

public class Progg {

    public void shell(int n, int a[]) {
        int i, j, temp, step;

        if (n % 2 == 0) {
            step = n / 2;
        } else {
            step = (n / 2) + 1;
        }

        while (step >= 1) {
            j = n - step;
            for (i = 0; i < j; i++) {
                if (a[i] > a[i + step]) {
                    temp = a[i];
                    a[i] = a[i + step];
                    a[i + step] = temp;
                }
            }
            step = step / 2;
        }
        print(n, a);
    }

    public void print(int n, int a[]) {
        System.out.println("\n\nSorted list is:\n");
        for (int i = 0; i < n; i++) {
            System.out.println(a[i]);
        }
    }

    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        Progg p = new Progg();

        System.out.println("Enter the number of elements you want:");
        int n = sc.nextInt();

        int[] a = new int[n];
        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        p.shell(n, a);
        sc.close();
    }
}
