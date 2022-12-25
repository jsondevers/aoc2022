package day10;

import java.io.File;
import java.io.FileNotFoundException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;

public class DayTen {

    private static int registerX = 1;
    private static int cycle = 0, resultPart1 = 0, pos = 0;
    private static String resultPart2 = "";

    public static void main(String[] args) {
        StringBuilder path = new StringBuilder();
        path.append(System.getProperty("user.dir"));
        path.append("/day10/input.txt");
        try {
            File file = new File(path.toString());
            Scanner scan = new Scanner(file);
            while (scan.hasNext()) {
                String cmd = scan.nextLine();

                var command = cmd.split(" ");
                if ("noop".equals(command[0])) {
                    doCycle();
                } else {
                    doCycle();
                    doCycle();
                    registerX += Integer.valueOf(command[1]);
                }

            }
            ;
            scan.close();
        } catch (FileNotFoundException e) {
            System.out.println("Wrong filename silly goose");
        }

        System.out.println("----- Day 10 -----");
        System.out.println("result part 1= " + resultPart1);
        System.out.println("result part 2:");
        System.out.println(resultPart2);
    }

    private static void doCycle() {
        if (cycle > 0 && cycle % 40 == 0) {
            pos = 0;
            resultPart2 += "\n";
        }
        resultPart2 += //
                pos == registerX || pos == registerX - 1 || pos == registerX + 1 //
                        ? "#"
                        : ".";
        pos++;
        cycle++;
        if (cycle == 20 || (cycle - 20) % 40 == 0) {
            resultPart1 += cycle * registerX;
        }
    };
}