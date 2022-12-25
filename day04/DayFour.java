package day04;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;

public class DayFour {
    private static ArrayList<ArrayList<Integer>> schedule = new ArrayList<>();

    private static int countAnyOverlaps() {
        int totalPairs = 0;
        for (int i = 0; i < schedule.size(); i += 2) {
            ArrayList<Integer> elfOne = schedule.get(i);
            ArrayList<Integer> elfTwo = schedule.get(i + 1);
            for (Integer value : elfOne) {
                if (elfTwo.contains(value)) {
                    totalPairs++;
                    break;
                }
            }
        }
        return totalPairs;
    }

    private static int countPairs() {
        int overlapPairs = 0;

        for (int i = 0; i < schedule.size(); i += 2) {
            ArrayList<Integer> elfOne = schedule.get(i);
            ArrayList<Integer> elfTwo = schedule.get(i + 1);

            overlapPairs += elfOne.containsAll(elfTwo) || elfTwo.containsAll(elfOne) ? 1 : 0;
        }
        return overlapPairs;
    }

    private static void processSection(String line) {
        String[] sections = line.split(",");
        for (int i = 0; i < sections.length; i++) {
            String[] assignment = sections[i].split("-");

            int start = Integer.parseInt(assignment[0]);
            int end = Integer.parseInt(assignment[1]);

            ArrayList<Integer> elf = new ArrayList<>();
            for (int j = start; j <= end; j++) {
                elf.add(j);
            }
            schedule.add(elf);
        }

    }

    public static void main(String[] args) {

        StringBuilder path = new StringBuilder();
        path.append(System.getProperty("user.dir"));
        path.append("/day4/input.txt");
        try {
            File file = new File(path.toString());
            Scanner scan = new Scanner(file);
            while (scan.hasNext()) {
                String line = scan.nextLine();
                processSection(line);
            }
            System.out.println(countPairs());
            System.out.println(countAnyOverlaps());
            scan.close();
        } catch (FileNotFoundException e) {
            System.out.println("Wrong filename silly goose");
        }

    }
}
